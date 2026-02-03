# Day 3 : Loops

## 3.1 While Loops

- 基本语法：
```cpp
while (condition) {
	//代码块
}
```
> 注意！代码块中一定要有能改变条件的语句，否则会成为死循环

C++ 的 while 循环基本与 Python 一致

### 俯卧撑计数器

```Python
def main() -> None:
	count: int = 0
	
	while count < 5:
		print(f"加油！继续！你做了：{count + 1}个俯卧撑了！！")
		count += 1
	
	print ("做完了！累死了！")
```

```cpp
int main(void) {
	int count = 0;
	
	while (count < 5) {
		std::cout << "加油！继续！你做了 " << count + 1 << " 个俯卧撑了" << std::endl;
		
		count++;
		//'++' 相当于 Python 中的"增强赋值运算符"——'+= 1'
		//i++ 是在变量本身的基础上直接开始加1，++i 是先 +1 再开始 'i += 1' 
	}
	
	std::out << "做完了！累死了！" << std::endl;
	
	return 0;
}
```

## 3.2 For Loops

- 基本语法：
```cpp
// 1. 确定次数循环 —— 传统 for 循环
for (变量初始化; 结束条件; 更新变量) {
	//循环体代码
}

// 2.非确定次数循环 —— 基于范围，由容器决定
for (元素类型 变量名: 容器名) {
	//循环体代码
}
```

- 与 Python 的类似点：
	1. 都可以遍历 **"整数序列"** 或者 **容器**
	2. 死循环写法：`while (true)` —— 之前对死循环没什么印象
- 与 Python 的不同点：
	1. 确定次数循环：C++ 中的步长控制和条件设置更灵活，绝非单纯的整数序列
	2. 非确定次数循环：仅语法不同

### 倒计时发射火箭

```Python
def main() -> None:
	for i in range(10, 0, -1):
		print(f"T-minus {i}...")
	print("Houston, we have lift-off!")
	
if __name__ == "__main__":
	main()
```

```cpp
int main(void) {
	for (int i = 10; i > 0; i--) {
		std::cout << "T-minus " << i << "..." << std::endl;	
	}
	
	std::cout << "Houston, we have lift-off!" << std::endl;
	
	return 0;
}
```
## 3.3 Break & Continue

用法几乎与 Python 相同：

- `break` : 跳出整个循环，执行循环后面的代码
- `continue` : 跳过本次循环剩下的代码，进入下一轮循环

### 小于9的奇数输出
```Python
def main() -> None:
	for i in range(0, 10):
		if i % 2 == 0:
			continue
		elif i == 9:
			break
		print(i)
		
if __name__ == "__main__":
	main()
```

```cpp
#incluude <iostream>

int main(void) {
	for (int i = 0; i < 10)
		if (i % 2 == 0) {
			contine;
		} else if (i == 9) {
			break:
		}
		std::cout << i << std::endl;
		
	return 0;
}
```

---
# 实践：猜数字游戏 (Guess the Number)

**任务描述：**
1.  程序在心里“想”好一个 1 到 100 之间的整数（为了简单，你可以先在代码里写死一个数，比如 `int secret = 42;`。以后我们学随机数）。
2.  进入一个死循环 `while(true)`。
3.  提示用户：“猜猜是多少？”
4.  用户输入一个数字。
5.  判断：
    *   如果你猜的 > 秘密数字：打印“太大了！”
    *   如果你猜的 < 秘密数字：打印“太小了！”
    *   如果你猜对了：打印“牛逼！猜对了！” 然后用 `break` 结束循环。
6.  (加分项) 统计用户一共猜了多少次，最后打印出来。

```cpp
#include <iostream>

int main(void) {
	int secret = 42;
	int guess;
	int count = 0;
	
	while (true) {
		std::cout << "请输入你的猜测(1-100): " << std::endl;
		std::cin >> guess;
		count++;
		
		if (guess > secret) {
			std::cout << "太大了" << std::endl;
		} else if (guess < secret) {
			std::cout << "太小了" << std::endl;
		} else {
			std::cout << "恭喜你，仅用 " << count << " 次就猜出答案！";
			break;
		}
	}
	return 0;
}
```