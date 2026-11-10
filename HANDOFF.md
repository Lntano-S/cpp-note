# 交接说明

给 Windows 端继续开发用。记录截至 2026-10-27 的状态。

## 一、这是什么仓库

`cpp-note`：大一 C++ 课程的学习记录。Obsidian 管理笔记，代码按章节和实验组织。

- 远程：https://github.com/Lntano-S/cpp-note
- 分支：`main`

## 二、目录结构

```
cpp-note/
├── Cpp-Notes/                 课程笔记 Day_1 ~ Day_6、Class & Object.md
├── Cpp-Homework/              课后作业，10 个章节
├── Algorithm/
│   ├── 滑动窗口.cpp、最大公约数.cpp、Linklist.cpp
│   ├── pointer_函数指针.cpp、pointer_继承与多态.cpp、pointer_模板（template）.cpp
│   ├── temp.cpp
│   └── Data-Structure-Labs/
│       ├── 教学大纲.docx
│       ├── 数据结构实验指导.doc
│       ├── 数据结构实验报告内容模板.doc
│       ├── 软件实验报告模板－数据结构.doc
│       ├── lab01_polynomial/       实验一
│       └── lab02_expression/       实验二
├── Review/                    期末复习
├── README.md
└── .gitignore
```

## 三、实验一：一元多项式加法（已完成）

文件：`Algorithm/Data-Structure-Labs/lab01_polynomial/Poly.cpp`

### 已实现

| 部件 | 说明 |
|---|---|
| 存储结构 | 带头结点的单链表，按指数升序 |
| `Node` | 嵌套在 `Polynomial` 的 private 里，`coef` / `expn` / `next` |
| 构造 / 析构 | 构造函数建空表；析构逐结点 delete |
| `CreatePoly(int n)` | 插入式建表，不依赖输入有序 |
| `operator+` | 两条有序链归并，新建结点、不复用原链 |
| `print()` | 符号 / 系数 / x 与指数，三段处理 |
| `main()` | 读两个多项式，打印后输出和 |

### 已验证

- `A = 1 + 2x`、`B = 3x + 4x²` → `1+5x+4x^2`
- 部分抵消：`1+x` 与 `-1` → `x`
- 完全抵消：`x` 与 `-x` → `0`
- 空多项式参与：`0` 与 `3x^2` → `3x^2`

### 遗留问题

1. **没有拷贝构造和拷贝赋值。** 类里有裸指针，`Polynomial c = a + b;` 目前靠 NRVO 侥幸跑通。真发生拷贝就是浅拷贝，两个对象指向同一条链，析构两次直接崩。补 Rule of Three 是正解。
2. **`CreatePoly` 不跳过系数为 0 的项。** 输入 `0 5` 会进链，打印时冒出 `+0`。
3. **`operator+` 和 `print` 没有 `const`。** 两者都只读，加上更规范。
4. **缩进有几处乱的**：`CreatePoly` 里 `s->next = q;` 那两行没缩进；`print` 的第 2、3 段也没跟 `while` 对齐。

## 四、实验二：表达式求值（进行中）

目录：`Algorithm/Data-Structure-Labs/lab02_expression/`

题目：用栈求一个任意输入的表达式的值，支持个位数或多位数，小数可选，要求自定义存储结构。

已定：**支持小数**，一步到位。

设计：模板类 `Stack<T>`，全部写在单个文件 `expr.cpp` 里，不分头文件。操作数栈用 `Stack<double>`，运算符栈用 `Stack<char>`。

### 已完成

- `expr.cpp` 已就位（原 `main.cpp` 改名，`Stack.h` 已删除）
- 栈的骨架：`MAXSIZE = 100`、`T data[MAXSIZE]`、`int top`、构造函数 `top(-1)`
- `main` 里留了 `Stack<double> opnd;` 和 `Stack<char> optr;` 的位置

### 还没写

**五个成员函数，一个都没有：**

```cpp
bool empty() const;          // top == -1
bool full()  const;          // top == MAXSIZE - 1
void push(const T& e);       // 先判满
T    pop();                  // 先判空
T    getTop() const;         // 只看不弹
```

**优先级表**：7×7，行是栈顶运算符，列是当前读到的运算符，值决定"算、压、弹"。

**主循环**：读字符，数字进操作数栈，运算符比优先级。

## 五、下一步（按顺序）

1. 把 `Stack` 五个成员函数写进 `expr.cpp`：`empty`、`full`、`push`、`pop`、`getTop`
2. 自测：`push(1) push(2) push(3)`，三次 `pop` 得 `321`
3. 数字解析：整行读进 `string`，逐字符扫，支持多位数与小数
4. 优先级表：7×7，`+ - * / ( ) #`
5. 主循环，`1+2*3` 跑出 `7`，`1.5+2.25*3` 跑出 `8.25`
6. 实验报告四节：算法思想、存储结构描述及说明、函数原型及说明

## 六、编码约定

- `#include <iostream>` + `using namespace std;`
- 成员函数体写在类内
- 用初始化列表
- 中文分点注释
- 类名大驼峰，成员变量裸名（`head`、`top`，不加尾下划线）
- `int main(void)`

## 七、Windows 端要配的几件事

### 1. 拉代码

```powershell
git clone https://github.com/Lntano-S/cpp-note.git
```

### 2. 中文文件名显示

仓库里大量中文路径。Windows 上不配的话，`git status` 会把它们显示成八进制转义：

```powershell
git config --global core.quotepath false
```

### 3. 编译器

Windows 没有 g++，三个选择：

- **MSYS2**：装完执行 `pacman -S mingw-w64-ucrt-x86_64-gcc`，最接近 Linux 环境
- **MinGW-w64**：直接下载解压，把 `bin` 加进 PATH
- **WSL**：在 Windows 里跑 Linux，和现在的环境完全一致

推荐 MSYS2 或 WSL。Git Bash 自带的那份 g++ 版本可能太老，编 `-std=c++17` 容易出问题。

### 4. 源文件编码

`.cpp` 里有中文注释，文件本身是 UTF-8。g++ 默认按 UTF-8 读，没问题；MSVC 默认按 GBK，会乱码。

用 g++ 就不用管。用 MSVC 得加 `/utf-8`。

### 5. 编译产物

`.gitignore` 里已经有 `*.exe`、`*.o`、`*.obj`、`*.out`，Windows 编出来的东西不会进暂存区，**不用改**。

只提醒一句：MSYS2 下 `g++ main.cpp -o expr` 生成 `expr.exe`，被 `*.exe` 挡住；万一哪天编出没有扩展名的可执行文件，`git status` 里会看到它，手动补一条路径就行。

### 6. 换行符

如果 Git 提示 `LF will be replaced by CRLF`，说明 `core.autocrlf` 是 `true`。对这个仓库没影响，可以不管。

### 7. Obsidian 库要重新打开

`.obsidian/` 不在版本库里（个人配置不同步）。clone 下来之后，那个文件夹不会被 Obsidian 自动认成库。

要用笔记就在 Obsidian 里选“打开文件夹作为仓库”，指向 `cpp-note`。第一次打开会重新生成 `.obsidian/`，但插件、主题、快捷键都得手动装一遍。

## 八、拉下来先验环境

```bash
# 实验一
cd Algorithm/Data-Structure-Labs/lab01_polynomial
g++ Poly.cpp -o poly
./poly
# 输入：2 / 1 0 / 2 1 / 2 / 3 1 / 4 2
# 应输出三行：1+2x、3x+4x^2、1+5x+4x^2
```

```bash
# 实验二，现在只能验语法
cd ../lab02_expression
g++ expr.cpp -o expr
# 没有输出就是对的
```

两条都过，环境就齐了。
