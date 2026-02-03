# Day 4 : Vector & String
---
## 4.1 Vector —— 容器

C++ 中的动态数组相当于 Python 中的列表

- 基本语法：
```cpp
#include <vector> //使用 std::vector 需要包含这个头文件

std::vector<数据类型> vector_name = {元素}
```
### 4.1.1 序列操作

#### **相似操作**

| 操作   | Python (`list`) | C++ (`std::vector`)                                 | 备注                                                            |
| :--- | :-------------- | :-------------------------------------------------- | ------------------------------------------------------------- |
| 索引访问 | `v[i]`          | `v[i]`                                              |                                                               |
| 访问首尾 | `v[0]`，`v[-1]`  | `v.front()` 或 `v[0]`，`v.back()` 或 `v[v.size() - 1]` | C++ 不支持负数索引                                                   |
| 修改元素 | `v[i] = x`      | `v[i] = x;`                                         |                                                               |
| 末尾添加 | `v.append(x)`   | `v.push_back(x);`                                   |                                                               |
| 获取长度 | `len(v)`        | `v.size();`                                         | C++ 返回 `size-t` 类型 —— `unsigned long int` (无符号长整型)            |
| 末尾删除 | `v.pop()`       | `v.pop_back();`                                     | C++ 的 `pop_back()` 无返回值，且无法实现指定索引删除                           |
| 清空序列 | `v.clear()`     | `v.clear();`                                        |                                                               |
| 判断为空 | `if not v:`     | `if (v.empty())`                                    | Python 中的空容器等同于 `False` ，C++ 中的 `empty()` 是 vector 头文件自带的成员函数 |

#### **差异操作**

| 操作     | Python (`list`)             | C++ (`std::vector`)                              | 备注                                                    |
| :----- | :-------------------------- | :----------------------------------------------- | ----------------------------------------------------- |
| 切片     | `v[1:4]`                    | `vector<int> sub(v.begin() + 1, v.begin() + 4);` | C++ 要用到 `.begin()` ，返回一个指向容器第一个元素的迭代器，`sub()` 表示返回子容器 |
| 插入     | `v.insert(i, x)`            | `v.insert(v.begin() + i, x);`                    | C++ 需要迭代器中的位置，而非简单的索引下标                               |
| 合并     | `v1 + v2` 或 `v1.extend(v2)` | `v1.insert(v1.end(), v2.begin(), v2.end());`     | C++ 可以实现对 `v2` 进一步切片之后再合并，相当灵活                        |
| 删除指定位置 | `del v[i]`                  | `v.erase(v.begin() + i);`                        |                                                       |
| 查找元素   | `if x in v`                 | `std::find(v.begin(), v.end(), x) != v.end();`   | **C++ 需要包含 `<algorithm>` 算法库头文件**                     |
| 元素排序   | `v.sort()`                  | `std::sort(v.begin(), v.end());`                 | C++ 中的排序是全局函数，Python 的排序只属于对象                         |
| 序列反转   | `v.reverse()` 或 `v[::-1]`   | `std::reverse(v.begin(), v.end());`              | C++ 可以实现特定切片（子容器）的反转                                  |
| 统计个数   | `v.count(x)`                | `std::count(v.begin(), v.end(), x);`             |                                                       |

### 4.1.2 Iterator —— 迭代器

迭代器类似于指针，指向容器中某个元素的位置

1. **成对出现的 `.begin()` 与 `.end()`**
	它们的同时出现定义了一个 **左开右闭** 的区间 `[begin, end)`
	- **`v.begin()`** : 指向迭代器中的第一个元素
	- **`v.end()`** : 指向迭代器中最后一个元素之后的那个**空位**

2. 迭代器的使用：
	- **取出对应位置的值（解引用）：** `*v.begin()` 获取第一个位置上的元素
	- **移动位置：** `v.begin(）+ i`

3. 在序列操作中的体现：
	- **元素排序：**`std::sort(v.begin(), v.end());` （告诉算法从那个位置开始排，到哪个位置结束）
	- **元素插入：**`v.insert(v.begin() + i, x);` （在第 i + 1 个位置插入元素 x）
	- **元素删除：**`v.erase(v.begin() + i);` （删除第 i + 1 个位置的元素）

### 4.1.3 `size_t` 在传统 for 循环中的应用 —— 借助容器"长度"

在 C++ 中，所有标准库（如 `std::vector` , `std::string`）的 `.size()` 函数返回的类型都是 `size_t` ，用来代替 `unsigned long int`

#### 用传统 for 循环遍历容器

```Python
def main() -> None:
	nums: list[int] = [1, 3, 5, 7, 9]
	for i in range(len(nums)):
		print(nums[i])
		
if __name__ == "__main__":
	main()
```

```cpp
#include <iostream>
#include <vector>
int main(void) {
	std::vector<int> nums = {1, 3, 5, 7, 9};
	for (std::size_t i = 0; i < nums.size(); i++) {
		std::cout << nums[i] << std::endl;
	}
	return 0;
}
```

## 4.2 String


