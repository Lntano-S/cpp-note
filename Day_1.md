# Day 1 : "Hello World" & 基础语法
---
## 1.1 "Hello World" 代码剖析

```cpp
#include <iostream>

int main(void) {
	std::cout << "Hello World" << std::endl;
}
```
### 1.1.1 预处理器指令（包含头文件）

- 基本语法：`#include <Headers_name>`
	- 与 Python 的**类似点**："头文件"相当于"库"，有助于实现代码功能模块化
	- 与 Python 的**不同点**：C++ 的 `#include` 是**预处理器的文本替换**（将头文件`.h`的文本拷贝到此文件）， 而 Python 的 `import` 是**模块化加载对象**（对象即为库名称）

### 1.1.2 main函数 —— 操作系统的入口

- **基本语法**：

```cpp
int main(void) {
	//多行代码
	return 0；
}
```

 - 代码剖析：
	1. **为什么必须是`int`？**: `main` 函数的返回值被称作 **退出码** or **返回状态**
		 -  `return 0`: 表明程序运行成功
		 -  `return 非0`: 程序出问题了，相应代码有对应的问题
	2. **`void` (n. 空白)** : 表示没有形参，一定写上，追求规范
	3. **`{}`** : 包裹所有语句
		  -  与 Python 的**类似点**： C++ 中的一个 `{}` 相当于 Python 中的一级缩进
		  -  与 Python 的**不同点**： 区别于对缩进（空格）敏感的 Python，C++ 没有严格意义上的缩进，程序运行时会自动忽略正常语句之外的所有空格，只识别并运行以 `;` 作分隔的语句。但是为了代码的清晰美观，我们还是在 C++ 中合理使用"缩进"

### 1.1.3 打印语句引出的 Input & Output

```cpp
std::cout << "Hello World" << std::endl;

std::cout << "Please enter your name: ";
std::cin >> user_name;
```

- **基本语法**：`Namespace_name::function` ， `::` (作用域解析符) 以及 `<<`、`>>` (流式运算符)
- **逐句剖析**：`std` 是 Namespace 名，`::` 是作用域解析符，`std` 中的函数 `cout`——相当于  `print()`，`cin` —— 相当于 `input()`，`endl` —— 相当于 `/n` 换行

## 1.2 Headers & Namespace

前面提到，`#include` 是把 `.h` 文件中的所有代码拷贝过来。而这些复制过来的代码，有一些带着"标签"，也即 Namespace (命名空间)。

- 与 Python 的**类似点**：显式访问 (以 `math 库` 和 `iostream 头文件` 为例)
	- Python 是 `math.sqrt()` ，C++ 是 `std::cout` ，符号前是对象，符号后是函数、方法等

- 与 Python 的**不同点**：
	1. **符号**：在 Python 中`.` 号称作 **属性访问操作符 (Attribute Access Operator)**， `.` 号适用于**一切访问操作**；在 C++ 中， `::` 号称作 **作用域解析符 (The Double Colon)**，用来访问**作用域/命名空间/类 静态成员**

		-  特别地，在 C++ 中
			-    **访问作用域/命名空间/类静态成员**：用 `::`（作用域解析符）。
					*   例如：`std::cout` 或 `MyClass::static_method()`
			*   **访问对象的成员**：用 `.`（点操作符）。
				* 例如：`my_obj.run()`
			*   **访问指针指向对象的成员**：用 `->`（箭头操作符）。

	2. **函数名等可能出现的冲突**：
		- 在 Python 中，为避免冲突，我们一般在 `import math` 后，使用 `math.sqrl()` 语句；或者直接用蛇形命名法对函数进行重命名，如 `from math import sqrl as math_sqrl`
		- 在 C++ 中，我们使用"标签" —— Namespace，来区分不同 Headers 中的相同函数名，例如：

```cpp
#include "sound_lib.h"
#include "graphics_lib.h"

int main() {
    Sound::init();    // 明确告诉编译器：调用音效库的初始化
    Graphics::init(); // 明确告诉编译器：调用绘图库的初始化
    return 0;
}
```

> Namespace 就像一个仓库，不同的 Headers 可以往同一个仓库中装函数；而不同的 Namespace 中可能含有**名字**相同的函数，这时务必说明它们来自哪个 Namespace 。
### 1.3 Variables

#### 1.3.1 变量的声明 & 初始化

- **基本语法**：
	- **声明**：`variable_type variable_name`
	- **声明并初始化**：`variable_type variable_name = variable_value` 

现阶段来看，除了在使用 `std::cin` 获取 Input 的时候只用声明变量，其他时候最好声明并且初始化，否则会导致编译器在内存里分配一个毫无意义的随机内存，可能出现 bug 。

#### 1.3.2 变量分类

```cpp
#include <iostream>
#include <string>  //引入 string 库，使用 std::string 来表示字符串类型

int main(void) {
	// 1.整数
	int user_name; //仅声明
	int user_age = 19; //声明并初始化
	
	// 2.双精度浮点数
	double price = 19.99; //C++ 中一般不使用 float
	
	// 3.字符
	char ch = 'a'; //必须使用单引号
	
	// 4.字符串
	std::string name = "Tianyu Shu"； //字符串类型位于 std 命名空间中
	
	// 5.布尔值
	bool is_upset = false; //布尔值用小写
	
	// 6.其他
	age = 20; //更新变量的 value ,无需带类型
	const std::string friend = "Yifeng Yao"; //用 const 进行限定，此变量无法被修改，强行修改会报错
	
	return 0；
}
```

---
# 实践

写一个算月薪的程序：

1. 创建一个新的 .cpp 文件。
2. 定义变量用来存储：
	- 员工姓名 (string)
	- 日薪 (double)
	- 本月工作天数 (int)
3. 让程序询问用户，依次输入上面三个信息。
4. 计算：月薪 = 日薪 * 工作天数。
5. 输出格式如下（例子）：
```
=== Salary Slip ===
Employee: Jack
Days Worked: 20
Total Salary: 4000
```

```cpp
#include <iostream>
#include <string>

int main(void) {

	std::string name;
	double daily_salary;
	int work_days;
	
	std::cout << "Please enter your name: ";	
	std::cin >> name;	
	std::cout << "Please enter your age: ";	
	std::cin >> daily_salary;	
	std::cout << "Please enter your work_days: ";
	std::cin >> work_days;
	
	std::cout << "=== Salary Slip ===" << std::endl;	
	std::cout << "Employee: " << name << std::endl;	
	std::cout << "Days worked: " << work_days << std::endl;	
	std::cout << "Total Salary: " << work_days * daily_salary << std::endl;
	
	return 0;
}
```