
## 一、核心功能概述

本项目实现了一个全流程的语音交互系统，核心流程为：**前端语音采集 -> 语音转文字（STT）-> 大模型思考（LLM）-> 文字转语音（TTS）** ，而 `CyberFeng.py` 是把他们集合起来。

- **核心技术栈**
	1. FunASR（STT）：阿里的开源语音识别库
	2. vLLM & Qwen2.5（LLM）：大模型加速
	3. GPT-SoVITS（STT）：语音合成服务器

## 二、语音转文字模块（`stt.py`）

该模块负责将来自 **单片机端** 的音频文件处理成模型可识别的文本。

### 1. 核心流程

- **音频格式标准化** ：`sbuprocess` 运行外部命令，利用 `FFmpeg` 将音频格式统一转换为 16000Hz 单声道采样
- **语音识别模型推理** ：使用阿里的开源 `paraformer-zh` 模型进行高精度的语音文件转写

### 2. 核心代码 —— FFmpeg 音频格式转换

```python
def convert_audio(self, 
				  raw_path: str, 
				  output_path: str
	) -> tuple[str, str]:
	"""
	4. 使用 FFmpeg 将音频格式转换为 API 支持的格式
	
	Args:
		raw_path (str): 单片机端的音频文件路径
		output_path (str): 转换后的音频文件路径

	Returns:
		tuple[str, str]
	"""

	# 首先获取一下文件名 方便给接下来生成的文件命名
	# Path 类中，stem 属性直接对应文件名，无需切割
	filename: str = Path(raw_path).stem
	# 配置输出文件的路径以及名字
	# 使用 FFmpeg 的命令，用 "," 替代命令行中的 " "
	command = [
		"ffmpeg", "-y",      # 表明使用 FFmpeg
		"-f", "s16le",       # 采样深度
		"-ar", "16000",      # 声音频率设置：16000Hz
		"-ac", "1",          # 声道设置：单声道
		"-i", str(raw_path), str(output_path) # 输入和输出文件
	]
	
	# 直到开始做项目才发现 try-except 的重要性
	try:
	# 调用子进程来处理音频文件
	# 运行上面的命令，相当于在终端里按回车
		subprocess.run(command, check=True, capture_output=True)
		
		print(f"转换成功: {output_path}")
		return str(output_path), filename
	except subprocess.CalledProcessError as e:	
		print(f"转换失败: {e}")

		if e.stderr:
			print(f"错误详情: {e.stderr.decode()}")
		return "", filename
```

### 3. 过程中的技术难点 & 心得

-  **现代文件路径处理库** ：利用 **`pathlib` 库** 的面向对象特性，通过访问属性来避免潜在 bug
-  **容错率** ：使用 **`try-except`** 结构捕获异常，防止程序崩溃
-  **显存管理** ：使用 **`torch.cuda.empty_cache()`** 解决模型卸载时的显存占用问题
-  **数据存储** ：引用 `json` 库，把数据存储在 LLM 能看懂的 **键值对** 当中

## 三、 大语言模型模块（`llm.py`）

该模块负责理解 **语音转写内容** 的意图，生成符合初始化人设的回复

### 1. 核心流程

- **模型加速：** 使用 `vllm`，加速模型处理，从 **HuggingFace** 上下载模型
- **人设设定：** 通过 `role_prompt` 规定 AI 的身份、语气、字数限制

### 2. 核心代码 —— LLM 生成文本回答

```python
def get_response(self, text: str, filename: str) -> Optional[str]:
        """
        用来产出对话

        Args:
            text: 输入文本
            filename: 文件名
        Returns:
            answer_text: llm回复
        """
        if self.tokenizer is None or self.llm is None:
            print("模型未启动")
            return

        assert self.tokenizer is not None
        assert self.llm is not None

        # AI 对话的标准格式：系统指令 + 用户提问
        messages = [
            {"role": "system", "content": self.role_prompt},
            {"role": "user", "content": text},
        ]

        # 把 messages 列表转成模型能看懂的格式
        prompt_text = self.tokenizer.apply_chat_template(
            messages, 
		    tokenize=False, # 提示词无需分词
            add_generation_prompt=True
        )

        # 生成回答
        response = self.llm.generate([prompt_text], self.sampling_params)
        # 提取回答中的文字
        answer_text: str = str(response[0].outputs[0].text)
        
        request_output: vllm.RequestOutput = response[0]
        raw_data_dict: dict = {
            "request_id": request_output.request_id,
            "prompt": request_output.prompt,
            "generated_text": request_output.outputs[0].text,
            "finish_reason": request_output.outputs[0].finish_reason,
            "finished": request_output.finished,
        }
        
        # 需要的结果保存在字典中
        data_to_save = {
            "input": text,
            "output": answer_text,
            "raw_data": raw_data_dict,
        }

        # 和 STT 文件中的逻辑类似，让 LLM 的输出保留在 json 文件里面
        save_dir = Path.cwd() / "json" / "llm_output"
        save_dir.mkdir(parents=True, exist_ok=True)
        full_path = save_dir / f"{filename}.json"
        with full_path.open("w", encoding="utf-8") as f:
            json.dump(data_to_save, f, ensure_ascii=False, indent=4)
        print(f"LLM输出已保存至{full_path}")
        return str(answer_text)
```

### 3. 过程中的技术难点 & 心得

- **模型参数：**  调整`temperature` 和 `top_p` 设置回答的随机性与准确性
- **`@property` 装饰器：** 把一个 **类方法** "伪装"成一个 **类属性** （因为 **Status** 通常被视为对象的一个属性，而不是一个动作，这样更自然）
- **调试 `llm.py` :**  在 `if __name__ == "__main__:"` 结构中调试 LLM 的生成功能
 
## 四、 语音合成模块（`tts.py`）

该模块通过网络请求驱动远程 **GPT-SoVITS 服务器** ，实现个性化声音克隆

### 1. 核心架构

- **继承机制：** **`TTS`** 父类处理网络请求，**`Infer`** 子类处理文字转语音推理，其他子类负责控制服务器和模型
- **快捷调用：** 新增 `@classmethod simple` 方法，简化调用 GPT-SoVITS 服务器需要的参数

### 2. 关键代码 —— 保存来自 GPT-SoVITS 服务器的音频文件

```python
def save_audio(self, filename: str) -> Path | str:
        """保存声音文件

        Args:
            filename (str): 文件名

        Returns:
            Path | str: 文件路径 or 空
        """
        save_dir = Path.cwd() / "audio" / "trans"
        save_dir.mkdir(parents=True, exist_ok=True)

        full_path = save_dir / filename

        response = self.post()

        if response and response.status_code == 200:
            with full_path.open("wb") as f:
                f.write(response.content)
            print(f"音频保存至：{full_path}")
            return full_path
        else:
            print(f"保存失败：{response.status_code if response else 'No Response'}")
            return ""
```
### 3. 过程中的技术难点 & 心得

- **了解计算机网络相关知识：** 
	1. **POST 请求：** 向服务器发送大量数据（此文件是 JSON 格式）
	2. **GET 请求**： 向服务器索取数据

## 五、功能集成模块（`CyberFeng.py`）

该模块将上述功能进行整合。

### 1. 数据管理

- 使用 `@dataclass CyberFengData` 统一存储路径、中间文本、相应结果等状态

### 2. 链式调用设计

- 通过 `CyberFeng.py` 中核心方法`choose_audio()` 、`stt()` 、`llm()` 、`tts()`末尾的 **`return self`** 实现极简的逻辑表达，下面是一个简单举例

```python
cf = CyberFeng()
cf.start_service()

# 分步调用
cf.choose_audio("input.wav", "temp.wav")
cf.stt()
cf.llm()
cf.tts()

# 链式调用：就像流水线一样,清晰明了
cf.choose_audio("input.wav", "temp.wav").stt().llm().tts()
```

>  上面的这个示例实现了一行代码一行顶四行，一气呵成地完成了从原始文件录入到最终合成语音的全过程。**这不仅提高了代码的可读性，使其具备了‘流式接口’的特征，更重要的是，它通过统一的对象状态管理，确保了数据在传递过程中的一致性。**
### 3. 核心代码 —— .stt().llm().tts() 的接力 & 串联

#### 1 ) 定义端：CyberFeng.py 中的接力

```python
def stt(self) -> Self:
        """语音转文字：将输入音频通过 STT 模型转换为文本，结果存储在 datas 中，支持链式调用。

        转写结果保存至 datas.transfered_text，文件名保存至 datas.filename。

        Returns:
            Self: 返回自身实例，支持链式调用。

        Raises:
            RuntimeError: 当 STT 或 LLM 模型未正常初始化时抛出。
        """
        if not self.get_status:
            raise RuntimeError("模型没有被正常初始化！")

        self.datas.transfered_text, self.datas.filename = (
            self.stt_service.process_audio(
                str(self.datas.input_audio_path), str(self.datas.trans_audio_path)
            )
        )

        return self

    def llm(self) -> Self:
        """大语言模型推理：将 STT 转写的文本送入 LLM 获取回复，结果存储在 datas 中，支持链式调用。
           推理结果保存至 datas.llm_response。

        Returns:
            Self: 返回自身实例，支持链式调用。

        Raises:
            RuntimeError: 当 STT 或 LLM 模型未正常初始化时抛出。
        """
        if not self.get_status:
            raise RuntimeError("模型没有被正常初始化！")
        self.datas.llm_response = str(
            self.llm_service.get_response(
                self.datas.transfered_text, self.datas.filename
            )
        )
        return self

    def tts(self) -> Self:
        """文字转语音：将 LLM 的回复通过 TTS 服务合成为音频文件，输出路径存储在 datas 中，支持链式调用。

        合成音频的保存路径存储至 datas.output_audio_path。

        Returns:
            Self: 返回自身实例，支持链式调用。
        """
        infer: Infer = Infer(
            _gpt_url=self.datas.tts_addr,
            _text=str(self.datas.llm_response),
            _text_lang="zh",
            _ref_audio_path=self.datas.ref_audio_path,
            _prompt_lang="zh",
            _prompt_text=self.datas.ref_text,
        )
        filename_with_ext = (
            f"{self.datas.filename}.mp3"
            if not self.datas.filename.endswith(".mp3")
            else self.datas.filename
        )
        self.datas.output_audio_path = infer.save_audio(filename_with_ext)

        return self
```

#### 2 ) 执行端：WebAPI.py 中的串联

```python
# webAPI.py 的 chat_endpoint 函数中
cf.choose_audio(raw_file_path, out_file_path).stt().llm().tts()
```
## 六、 总结与展望
### 1. 已实现功能
- 完整的端到端语音对话。
- 模块化设计，各部分可独立维护或更换。

### 2. 待优化方向
- **延迟优化**：引入流式传输（Streaming）减少用户等待时间。
- **长短期记忆**：为 LLM 加入上下文管理功能。

## 七、Q & A