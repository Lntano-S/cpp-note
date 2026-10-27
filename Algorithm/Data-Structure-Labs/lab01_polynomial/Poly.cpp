/*
1、实验内容

编写程序，对两个一元多项式进行加法运算。

要求：将一元多项式采用单链表存储结构，实现如下功能：
1）从键盘输入（或从文件读入）一元多项式的各项系数和指数，输入时按指数从低到高输入，创建一元多项式链表；
2）输出创建后的一元多项式，输出形式形如：1+2x-6x^8+12x^17；
3）任意输入的两个多项式进行加法运算，并输出，形式同上。
2、算法思想
	
3、存储结构描述及说明

4、函数原型及说明
*/

#include <iostream>
using namespace std;

class Polynomial 
{
private:

    struct Node 
    {
        double coef;    // 系数
        int expn;       // 指数
        Node* next;     // 指向下一项

        Node(double c, int e,Node* n = nullptr) 
            : coef(c), expn(e), next(n) {}
    };

    Node* head; // 头结点

public:
    // 构造函数：建空表
    Polynomial() : head(new Node(0, 0)) {}  

    // 析构函数：释放内存
    ~Polynomial()   
    {
        Node* p = head;

        while(p != nullptr) 
        {
            Node* t = p;
            p = p->next;
            delete t;
        }
    }  

    // 成员函数1：创建新多项式
    void CreatePoly(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            Node* s = new Node(0, 0);
            cin >> s->coef >> s->expn;
            
            Node* pre = head;
            Node* q = head->next;

            while (q != nullptr && q->expn < s->expn)
            {
                pre = q;
                q = q->next;
            }

        s->next = q;
        pre->next = s;
        }
    }

    // 成员函数2：多项式相加，重载“+”运算
    Polynomial operator+(const Polynomial& other)
    {
        Polynomial result;      // 装相加结果的空表
        Node* r = result.head;  // r 结果链表的尾指针


        Node* p = head->next;
        Node* q = other.head->next;

        while(p != nullptr && q != nullptr) 
        {
            if (p->expn < q->expn)  // p的指数小，先进r
            {
                r->next = new Node(p->coef, p->expn); // 新结点，接新项
                r = r->next; // 结果链表结点数 + 1
                p = p->next; // p 指向 p(x) 的下一项
            }

            else if (p->expn > q->expn) // q的指数小，先进r
            {
                r->next = new Node(q->coef, q->expn); // 新结点，接新项
                r = r->next; // 结果链表结点数 + 1
                q = q->next; // q 指向 q(x) 的下一项 
            }

            else 
            {
                double sum = p->coef + q->coef; // p q指数相同，相加后进r
                if (sum != 0)
                {
                    r->next = new Node(sum, p->expn);
                    r = r->next; // 结果链表结点数 + 1
                }
                // 相加是不是 0 都一起指向各多项式的下一项
                p = p->next;
                q = q->next;
            }
        }

        // while 循环结束时，说明有一个多项式走完了
        for (; p != nullptr; p = p->next)
        {
            r->next = new Node(p->coef, p->expn);
            r = r->next;
        }

        for (; q != nullptr; q = q->next)
        {
            r->next = new Node(q->coef, q->expn);
            r = r->next;
        }

        return result;
    }

    // 成员函数3：输出多项式
    void print()
    {
        Node* p = head->next;

        if (p == nullptr) // 空多项式——0
        {
            cout << "0";
            return;
        }

        bool first = true;

        // 1. 符号
        while (p != nullptr)
        {
            double c = p->coef;
            int e = p->expn;

            if (first)
            {
                if (c < 0) cout << '-';
            }
            else
            {
                cout << (c < 0 ? '-' : '+');
            }

        // 2. 系数
        double a = (c < 0) ? -c : c;
        if (e == 0)
        {
            cout << a;
        }
        else
        {
            if (a != 1) cout << a;

            // 3. 变量 x 和指数
            cout << 'x';
            if (e != 1) cout << '^' << e;
        }

        first = false;
        p = p->next;
        }
    }
};

int main(void)
{
    int m, n;

    cin >> m;
    Polynomial a;
    a.CreatePoly(m);

    cin >> n;
    Polynomial b;
    b.CreatePoly(n);

    cout << "多项式 A: ";  a.print();  cout << endl;
    cout << "多项式 B: ";  b.print();  cout << endl;

    Polynomial c = a + b;
    cout << "相加后：";    c.print();  cout << endl;

    return 0;
}
