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
for ()
```