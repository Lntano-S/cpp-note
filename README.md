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

环境：Linux + g++，标准用 `-std=c++17`。

普通作业：

```bash
g++ "Cpp-Homework/Loops/1饮料换购.cpp" -std=c++17 -o demo
./demo
```

实验一：

```bash
cd Algorithm/Data-Structure-Labs/lab01_polynomial
g++ Poly.cpp -std=c++17 -o poly
./poly
```

实验二：

```bash
cd Algorithm/Data-Structure-Labs/lab02_expression
g++ main.cpp -std=c++17 -o expr
./expr
```

## 约定

- 编译产物（`output/`、`build/`、无扩展名的可执行文件）由 `.gitignore` 排除，不入库
- 编辑器配置 `.vscode/`、Obsidian 配置 `.obsidian/` 均不入库
- 笔记建议用 Obsidian 打开，配合 Excalidraw 绘图查看
