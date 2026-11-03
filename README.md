# C++ 学习笔记

大一 C++ 课程的完整学习记录：课程笔记、课后作业、算法练习与数据结构实验。用 Obsidian 管理，Markdown 为主。

## 目录结构

```
Cpp-Notes/                      课程笔记
Cpp-Homework/                   课后作业源码（按章节组织）
Algorithm/                      算法练习
  Data-Structure-Labs/          数据结构课程实验
Review/                         期末复习
```

## 内容一览

### Cpp-Notes/

Day_1 ~ Day_6 的课程笔记，覆盖：

- Day_1：Hello World 与基础语法
- Day_2：Boolean Logic、If-Else、Switch-Case
- Day_3：Loops
- Day_4：Vector 与 String
- Day_5：Functions
- Day_6：Pointer 与 Reference

另附 `Class & Object.md`，以及 CyberFeng 语音智能助手后端模块的汇报稿。

### Cpp-Homework/

按章节组织的作业实现：

| 章节 | 内容 |
|------|------|
| 顺序结构 | 基础输入输出与计算 |
| If-Else | 条件判断、分段函数、闰年判断 |
| Loops | 循环练习：饮料换购、数列求和、回文数等 |
| Functions | 函数封装 |
| Pointer | 指针与引用练习 |
| Vector | 容器练习：最大值最小值、逆序存放等 |
| Class & Object | 类与对象、类的继承、综合练习（公交卡） |
| 运算符重载 | 复数加法、Money 类输入输出重载 |
| 虚函数 | 图形抽象类的派生 |
| 综合练习 | MyVector 实现 |

### Algorithm/

算法与指针进阶练习：链表、函数指针、模板、继承与多态、滑动窗口、最大公约数等。

#### Algorithm/Data-Structure-Labs/

数据结构课程实验。题目与要求见 `数据结构实验指导.doc`，报告模板也在同一层。

| 实验 | 主题 | 源码 |
|------|------|------|
| 实验一 | 一元多项式的加法运算 | `lab01_polynomial/Poly.cpp` |
| 实验二 | 表达式求值（栈） | `lab02_expression/` |

### Review/

期末复习材料。`综合1.cpp` 是综合练习的参考实现，`未命名.md` 是复习草稿。

## 编译运行

标准统一用 `-std=c++17`。两端都能直接编译，clone 下来不需要额外配置，文件名和路径里的中文也不用处理。

| 平台 | 工具链 |
|------|--------|
| Linux | 系统 g++，包管理器安装 |
| Windows | w64devkit 自带 g++，含 gdb、make、cmake |

两端命令只差两处：Windows 的产物要带 `.exe` 后缀，运行时前面加 `.\`。下面每段给出两边写法。

### 普通作业

Linux：

```bash
g++ "Cpp-Homework/Loops/1饮料换购.cpp" -std=c++17 -o demo
./demo
```

Windows（PowerShell）：

```powershell
g++ "Cpp-Homework\Loops\1饮料换购.cpp" -std=c++17 -o demo.exe
.\demo.exe
```

### 实验一（一元多项式）

Linux：

```bash
cd Algorithm/Data-Structure-Labs/lab01_polynomial
g++ Poly.cpp -std=c++17 -o poly
./poly
```

Windows（PowerShell）：

```powershell
cd Algorithm\Data-Structure-Labs\lab01_polynomial
g++ Poly.cpp -std=c++17 -o poly.exe
.\poly.exe
```

### 实验二（表达式求值）

Linux：

```bash
cd Algorithm/Data-Structure-Labs/lab02_expression
g++ main.cpp -std=c++17 -o expr
./expr
```

Windows（PowerShell）：

```powershell
cd Algorithm\Data-Structure-Labs\lab02_expression
g++ main.cpp -std=c++17 -o expr.exe
.\expr.exe
```

### Windows 侧的已知差异

- 编译产物带 `.exe` 后缀，`.gitignore` 已用 `*.exe` 覆盖，不会误入库
- 中文文件名与中文路径可直接使用，Git 在 UTF-8 与 NTFS 之间自动转换
- 程序输出的是 UTF-8 字节，而 Windows 默认控制台代码页是 936，直接运行会显示成乱码。手动运行前先执行 `chcp 65001`，或者用 `.vscode/tasks.json` 里的运行任务（已自动处理）
- `std::thread` 可用，w64devkit 的 GCC 是 posix 线程模型
- 换行符交给 Git 处理：Windows 侧检出为 CRLF、提交时转回 LF，Linux 侧始终是 LF。两端的 `core.autocrlf` 保持各自默认值，不要手动改
- 大小写不敏感：同一目录下不要出现只有大小写差别的文件名

## 约定

- 编译产物（`output/`、`build/`、`*.exe`、无扩展名的可执行文件）由 `.gitignore` 排除，不入库
- 编辑器配置 `.vscode/`、Obsidian 配置 `.obsidian/` 均不入库
- 笔记建议用 Obsidian 打开，配合 Excalidraw 绘图查看
- 同一个文件不要在两台机器上同时改：一端改完先 `git push`，换端前先 `git pull --ff-only`
