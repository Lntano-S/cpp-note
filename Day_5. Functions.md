# Day 5 : Functions

## 5.1 函数

### 5.1.1 规范化声明

和变量的声明类似，我们可以在主函数代码上游进行函数的声明（C++ 编译器从上往下编译代码），即使声明的函数没有 **"初始化"** ，但是想在 `main()` 函数中使用其他函数，就必须在前面进行声明

- 基本语法：
```cpp
<返回值类型> func_name (参数类型 参数) {
	//函数体代码
	return <返回值> ；//有返回值就写，没有返回值（只实现打印等功能）
}
```

### 简单的两数之和

```cpp
#include <iostream>

int add_nums(int a, int b);

int main(void) {
	std::cout << add_nums(1, 2);
	return 0;
}

	//在 main() 函数下游补充函数内容
int add_nums(int a, int b) {
	return a + b;
}
```

### 5.1.2 两类常见函数

### void func —— 无返回值的函数，相当于 Python 中的 `-> None`

**以实现打印功能为例**

```cpp
#include <iostream>
#include <string>

void say_hello(std::string name) {
	std::cout << "Hello, " << name << std::endl;
}

int main(void) {
	say_hello("Tianyu Shu");
	
	return 0;
}
```

### return func —— 有返回值的函数

1. 返回值为简单类型：`int, double, char, bool` 等
2. 返回值为复杂类型：使用命名空间的类型 `std::string, std::vector` 等

#### 简单的容器元素添加引出的：传值 & 传引用

```Python
def add_language_to_list(languages: list[str], language: str):
	languages.append(language)
	return languages

def main() -> None:
	languages: list[str] = ['C', "Python"]
	new_languages: list[str] = add_language_to_list(languages, "C++")
	
	for language in languages:
	print(language, end=" ")
	print("")
	
	for language in new_languages:
	print(language, end=" ")
	print("")

if __name__ == "__main__":
	main()
```

**Python 输出结果**
```
C Python C++
C Python C++
```

```cpp
#include <iostream>
#include <vector>
#include <string>

/*
std::vector<std::string> add_language_to_vector(std::vector<std::string> languages, std::string language) {
	languages.push_back(language);
	return languages;
} 
	这里涉及到 using namespace namespace_name 的使用，否则一堆的 "std::" 让整个函数看起来很臃肿，并且在使用后，我们仍然可以写 std::cout 这种
*/

using namespace std

vector<string> add_language_to_vector(vector<string> languages, string language) {
	languages.pusg_back(language);
	return languages;
}

int main(void) {
	vector<string> languages = {"C", "Python"}; //必须用 "C" ,不能用 'C'
	vector<string> new_languages = add_language_to_vector(languages, "C++");
	
	for (string language: languages) {
		cout << language << " ";
	}
	cout << endl;
	
	for (string language: new_languages) {
		cout << language << " ";
	}
	cout << endl;
	
	return 0;
}
```

**C++ 输出结果**
```
C Python 
C Python C++
```

**两种语言的输出结果不同**
- 在 Python 中，两行打印都是基于 `new_languages` ，即 Python 的函数传参方式为 **传引用** —— 传的是参数本身，参数本身会发生改变
- 在 C++ 中，第一行是基于 `languages` ，第二行是基于 `new_languages` ，即 C++ 的函数传参方式为 **传值** ——  将参数本身复制后传进去，参数本身不发生改变

#### 再写一个例子

```cpp
#include <iostream>

void try_to_change(int x) {
    x = 999; // 这里的 x 只是原来那个的一份复印件
    std::cout << "函数内部: " << x << std::endl;
}

int main(void) {
    int num = 10;
    int new_nums = try_to_change(num);
    
    std::cout << "函数外部: " << num << std::endl; 
    // 输出依然是 10 并没有变成 999
    std::cout << new_nums << std::endl;
    //输出 999
    return 0;
}

```

---
# 实践

写一个简单的计算器，但是**必须用函数封装**
**任务描述：**

1. 写一个 `void show_menu()`：打印菜单（1.加 2.减 3.乘 4.除）。
2. 写四个函数：`double add(double a, double b)`, `subtract(...)`, `multiply(...)`, `divide(...)`
    - 注意：在除法函数里检查分母是不是 0，如果是 0，打印报错并返回 0。
3. 在 `main` 函数里：
    - 调用 `show_menu()`。
    - 让用户输入选项和两个数字。
    - 根据选项调用对应的函数，并打印结果。

```cpp
#include <iostream>
#include <vector>

void show_menu() {
	std::cout << "1.加 2.减 3.除 4.乘" << std::endl;
}

double add(double a, double b) {
	return a + b;
}

double substract(double a, double b) {
	return a - b;
}

double multiply(double a, double b)  {
	return a * b;
}

double divide(double a, double b) {
	if (b != 0) {
		return a / b
	} else if (b == 0) {
		std::cout << "除数不能为0,请重新输入" << std::endl;
		return 0;
	}
}

int main(void) {
	int choice;
	int a;
	int b;
	
	show_menu();
	std::cout << "请输入你的选择：" << std::endl;
	std::cin >> choice;
	std::cout << "请分别输入两个实数" << std::endl;
	std::cin >> a;
	std::cin >> b;
	
	switch (choice) {
		case 1:
			std::cout << "两数之和为" << add(a, b) << std::endl;
			break;
			
		case 2:
			std::cout << "两数之差为" << substract(a, b) << std::endl;
			break;
			
		case 3:
			std::cout << "两数之商为" << divide(a, b) << std::endl;
			break;
			
		case 4:
			std::cout << "两数之积为" << multiply(a, b) << std::endl;
			break;
	}
	return 0;
}
```
