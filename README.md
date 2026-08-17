# C++ 学习笔记

大一 C++ 课程的完整学习记录：课程笔记、课后作业实现、算法练习。用 Obsidian 管理，Markdown 为主。

## 目录结构

```
C++ Markdown/    课程笔记（Day_1 ~ Day_6）
C++ Homework/    课后作业源码（按章节组织）
算法/            算法与指针进阶练习
```

## 内容一览

### C++ Markdown/

Day_1 ~ Day_6 的课程笔记，覆盖：

- Day_1：Hello World 与基础语法
- Day_2：Boolean Logic、If-Else、Switch-Case
- Day_3：循环
- Day_4：Vector 与 String
- Day_5：函数
- Day_6：指针与引用

### C++ Homework/

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

### 算法/

算法与指针进阶练习：链表（Linklist）、函数指针、模板（template）、继承与多态、滑动窗口、最大公约数等。

## 编译运行

环境：Linux + g++，C++ 标准建议 `-std=c++17`。

```bash
# 以 Loops 的一个作业为例
g++ "C++ Homework/Loops/1饮料换购.cpp" -o demo
./demo
```

## 说明

- 编译产物（`output/`、`build/` 等）已被 `.gitignore` 排除，不入库
- 笔记文件建议用 Obsidian 打开，配合 Excalidraw 绘图查看
