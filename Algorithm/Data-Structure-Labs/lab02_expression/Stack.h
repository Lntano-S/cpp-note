#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
private:
    static const int MAXSIZE = 100;
    T data[MAXSIZE];
    int top;

public:
    Stack() : top(-1) {}
};

#endif