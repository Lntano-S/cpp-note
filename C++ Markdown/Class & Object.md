## 一、引入 —— 学生管理系统

```python
class Student:
	# 类属性
    count: int = 0
    
    # 构造函数
    def __init__(self, name: str, score: float, age: int):
        self.name: str = name
        self.score: float = score
        self.__age: int = age
        Student.count += 1
    
    # 实例方法 —— 访问私有属性"age"
    def get_age(self) -> int:
        return self.__age
    
    # 实例方法 —— 判断是否及格
    def is_qualified(self) -> None:
        if self.score >= 60:
            print("及格")
    
    # 实例方法 —— 显示属性信息
    def show_info(self) -> None:
        print("----------")
        print(f"姓名：{self.name}\n分数：{self.score}\n年龄：{self.__age}")
            
    # 类方法
    @classmethod
    def get_count(cls):
        return cls.count
    
def main() -> None:    
	dc1 = Student("舒天宇", 90, 19)
	dc2 = Student("姚奕枫", 74, 18)
	
	print(f"总数：{Student.count}")
	print(dc1.name, dc1.score, dc1.get_age())
	print(dc2.name, dc2.score, dc2.get_age())
	print(Student.get_count())
	
	dc1.is_qualified()
	dc1.show_info()
	dc2.is_qualified()
	dc2.show_info()
	
if __name__ == "__main__":
	main()
```


```cpp
#include <iostream>
#include <string>

using namespace std;

class Student {
// 私有: 一般装成员变量 & 内部辅助函数
private:
	int age;
	string name;
	double score;
	static int count;
	
// 公有：外部提供功能的函数
public:
	Student(int _age,
			const string& _name,
			double _score) :
			age(_age),
			name(_name),
			score(_score)
	
	
	
}
```

## 二、结构拆解

# EX_1 : 统计点的个数

```cpp
#include <iostream>

using namespace std;

class Point {
private:
    int x, y;
    static int count;

public:
	// 构造函数
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {
        count++;
    }

    // 拷贝构造函数：传已有对象的地址
    Point(const Point& p) {
        x = p.x;
        y = p.y;
        count++;
    }
    
    // 析构函数：销毁对象时进行的操作

    int getX() {return x;}
    int getY() {return y;}

    static void showCount();
};
```

### 1. 构造函数 —— 使用 *初始化列表* 进行实例化

#### 1.1 默认构造函数 ( Default Constructor )

- **特点：** 可以不传任何参数就调用的构造函数

#### 1.2 带参构造函数 ( Parameterized Constructor )

- **特点：** 接受一个或多个参数，在创建对象时提供具体数据
- **基本语法：**
```cpp
// 这是一个既充当 "默认" ，也充当 "带参" 的构造函数
Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
// 我们几乎不写空的默认构造函数
```

#### 1.3 拷贝构造函数 ( Copy Constructor )

- **特点：** 接受一个同类型对象的 **常引用** （`const` 引用）作为参数，通过现有对象克隆出一个新对象
- **基本语法：** 
```cpp
// 注意使用初始化列表
Point(const Point& p) : x(p.x), y(p.y) {
	count++;
}
```

> **引用** 的本质是给原本的对象 **起 “别名”**，这样传入对象时无需复制新对象，这避免了拷贝结构的无限死循环
### 2. 析构函数 —— Destructor

- **特点：** 销毁对象时进行清理工作的特殊成员函数
- **销毁对象的方式：** 
	1.  **存放在 “栈（Stack）” 上的对象 —— 自动销毁**
	
	```cpp
	// 在 main 函数中声明
	int main(void) {
		// ----------
		Point a(x, y);
		Point c;
		// ----------
		return 0;
	} // <--- 代码运行到此 “大括号” 时，系统自动销毁。
	  // 这是因为程序运行离开它们所在的 {} 作用域时，它们的生命周期就结束了，系统会自动调用析构函数，销毁对象，回收它们占用的内存
	```

	2. **存放在 “堆（Heap）” 上的对象 —— 手动销毁**

	```cpp
	// 在 main 函数中声明
	int main(void) {
		// ----------
		// 使用 new 关键字申请内存，创建新对象
		Point* p = new Point(1, 2);
		// ----------
		// 在适当位置使用 delete 关键字手动释放内存
		delete p;
		// ----------
		return 0;
	}
	```

- **基本语法：** 
```cpp
class Mystring {
private:
	char* data;
public:
	// 构造函数
	Mystring(int size) : data(new char[size]) {}
	
	// 析构函数
	~Mystring() {
		delete[] data
	}	
};
```

- **`new char[size]`** —— 向操作系统在 **堆（Heap）** 中申请一块连续的内存空间，这块空间的大小刚好能连着放下 `size` 个 `char`
- **`delete[] data`** —— 
# EX_2 : 矩形类

```cpp
#include <iostream>

using namespace std;

class Rectangle {
public:
    Rectangle(void);
    Rectangle(float length, float width);
    ~Rectangle(void);

    float getArea();
    float getGirth();

private:
    float mLength;
    float mWidth;
};

Rectangle::Rectangle() : mLength(0.0), mWidth(0.0) {} 

Rectangle::Rectangle(float len, float wid) : mLength(len), mWidth(wid) {}

Rectangle::~Rectangle() {}

float Rectangle::getArea() {
    return mLength * mWidth;
}

float Rectangle::getGirth() {
    return (mLength + mWidth) * 2;
}


int main(void) {
    int len, wid;
    cout << "Input the length and Width: ";
    cin >> len >> wid;

    Rectangle rec(len, wid);

    cout << "The Area is: " << rec.getArea() << "\n"
         << "The Premeter: " << rec.getGirth() << "\n";

    return 0;
}
```



运算符重载  返回值是对象
## 静态成员变量 以及 静态函数

### 1. 静态成员变量：

用 `static` 关键字修饰类的成员变量


### 2. 静态成员函数

- **特点：** 访问静态成员变量，静态成员变量在栈底部的静态区，而建立的对象在栈顶部的动态区，便于函数运行完之后进行销毁




this 指针

友元函数

如何使两个数组的值相等