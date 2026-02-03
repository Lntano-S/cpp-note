# Day 2 : Boolean Logic, If - Else, Switch - Case
---
## 2.1 Boolean Logic

### 2.1.1 布尔运算

- 与 Python 的**相同点**：都用来判断布尔表达式的真假，所用到的比较运算符一致
	- 比较运算符：`==`, `!=`, `<`, `>`, `<=`, `>=`
- 与 Python 的**不同点**：
	1. C++ 中的真（true）、假（false）是小写
	2. 逻辑运算符（与或非）:
		- `&&` 相当于 Python 中的 and，左右同时成立时返回 true
		- `||` 相当于 Python 中的 or，左右条件有一个成立时返回 true
		- `!`   相当于 Python 中的 not，条件的对立面

### 2.1.2 If - Else 分支语句

- 基本语法：
```cpp
if (condition_1) {
	//代码块，条件为 true 时运行
} else if (condition_2) {
	//代码块，条件为 true 时运行
} else {
	//代码块，上述条件均为 false 时运行
}
```

- 与 Python 的**不同点**：`elif` 要写成 `else if`

## 2.2 Switch - Case

- 基本语法：
```cpp
#include <iostream>

int main(void) {
	int choice;
	std::cout << "1. 信息1\n2. 信息2\n3. 信息3\n请输入选项：";
	std::cin >> choice;
	
	switch (choice) {
		//判断输入的字符
		case 1：
			//代码块
			break;//必须 break，否则会自动运行下一个 case 的代码
		case 2:
			//代码块
			break;
		case 3：
			//代码块
			break;
		default: //输入的字符不在选项当中时，运行该"默认代码块"
			//代码块
			break;
	}
	
	return 0;
}

```

- 与 `if-else` 的区别：

| 特点   | `if-else`         | `switch-case`             |
| :--- | :---------------- | :------------------------ |
| 表达式  | 任意，支持复杂条件判断       | 仅`int`, `char` 类型的简单判断    |
| 执行逻辑 | 挨个条件判断，时间复杂度 O(n) | 直接定位目标 `case`, 时间复杂度 O(1) |
> 特别的，Python 现在有类似的 `match-case` 结构，下面进行重写

```Python
def main() -> None:
	choice: int = int(input("1. 信息1\n2. 信息2\n3. 信息3\n请输入选项："))
	
	match choice:
		case 1：
			#代码块，无须讨厌的 break
		case 2:
			#代码块
		case 3：
			#代码块
		case _: #相当于 default, 输入的字符不在选项当中时，运行该"默认代码块"
			#代码块

		#match-case 还常用于'状态机'，以网页状态为例
		def get_http_status(code)
			match code:
				case 200：
					return "OK"
				case 404:
					return "Not Found"
				case _:
					return "Internet Error"

if __name__ == "__main__":
	main()
```

---
# 实践

学了两天，我们来做一个小游戏吧

编写一个程序，模拟一个地牢探险的场景。

1. 程序开始，打印：“你来到了地牢门口，面前有两条路：左边(1)是漆黑的走廊，右边(2)有火光。”
2. 让用户输入 1 或 2。
3. **如果选 1**：
    - 打印：“你踩到了机关！掉血 50。”
    - 定义一个变量 hp = 50。        
    - 继续判断：如果此时 hp > 0，打印“你还活着”，否则打印“你死了”。
4. **如果选 2**：
    - 打印：“你发现了一个宝箱！打开吗？(y/n)”
    - 接收一个字符 char 输入。
    - 如果是 y：打印“获得屠龙刀，通关！”
    - 如果是 n：打印“你错过了宝藏，但也平安无事。”
5. **如果输入其他的**：打印“你在这个世界迷路了，被饿死了。”

```cpp
#include <iostream>

int main(void) {
	int choice;	
	int hp = 50;

	std::cout << "你来到了地牢门口，面前有两条路：左边(1)是漆黑的走廊，右边(2)有火光。清输入你的选择：";
	std::cin >> choice;
	
	switch(choice) {
	
		case 1:
			std::cout << "你踩到了机关! 掉血50。" << std::endl;		
			hp -= 50;
	
			if (hp > 0) {
				std::cout << "你还活着。";
			} else {
				std::cout << "你死了。";
			}
			break;
	
		case 2:
			char ch;
			std::cout << "你发现了一个宝箱！打开吗？(y/n)" << std::endl;
			std::cin >> ch;
	
			switch(ch) {
				case 'y':
					std::cout << "获得屠龙刀，通关！";
					break;
			
				case 'n':
					std::cout << "你错过了宝藏，但也平安无事。";
					break;
			}
			break;  
	
		default:
			std::cout << "你在这个世界迷路了，被饿死了。";
			break;
	}
	
	return 0;
}
```