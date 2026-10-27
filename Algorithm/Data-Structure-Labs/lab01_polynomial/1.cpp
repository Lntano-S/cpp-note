#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

struct Node
{
    int data1;
    int data2;
    Node *next;
};

struct Nodefirst
{
    int data;
    string name;
    int g_count = 0;
    Node *head;
    Node *now=NULL;

    Nodefirst()
    {
        head = new Node;
        head->next = NULL;
        now=head;
    }
    void createNode(int data1,int data2)
    {
        g_count++;
        Node *newNode = new Node;
        now->next = newNode;
        now=newNode;
        newNode->data1 = data1;
        newNode->data2 = data2;
        newNode->next = NULL;
    }

    ~Nodefirst()
    {
        Node *p = head;
        while (p != nullptr)
        {
            Node *temp = p;
            p = p->next;
            delete temp;
        }
    }
};


void printList(Node *head)
{
    if(head->next==nullptr)
    {
        cout<<"该链表内无数据，请输入数据"<<endl;
    }
    else
    {
        bool first = true;
        for (Node *p = head->next; p != nullptr; p = p->next)
        {
            if (p->data1 == 0) continue;
            if (first) 
            {
                if (p->data1 < 0) cout << "-";
                first = false;
            } 
            else 
            {
                cout << (p->data1 < 0 ? "-" : "+");
            }

            int c = abs(p->data1);


            if (p->data2 == 0)
            {
                cout << c;                                 
            } 
            else 
            {
                if (c != 1)
                cout << c << "x";
                else
                cout << "x";                             
                if (p->data2 != 1) cout << "^" << p->data2;   
            }
            //cout << (abs(p->data1)==1?"":to_string(abs(p->data1))) << "x^" << p->data2;
        }
        if (first) cout << "0"; 
        cout<<endl;
    }
}

// Nodefirst *add(Nodefirst *list1,Nodefirst *list2)
// {
//     Nodefirst *list3=new Nodefirst;
//     Node *p1=list1->head->next;
//     Node *p2=list2->head->next;
//     while(p1!=nullptr)
//     {
//         int count=1;
//         while(p2!=nullptr)
//         {
//             if(p1->data2==p2->data2)
//             {
//                 list3->createNode(p1->data1+p2->data1,p1->data2);
//                 count--;
//                 break;
//             }
//             p2=p2->next;
//         }
//         list3->createNode(p1->data1,p1->data2);
//         p1=p1->next;
//     }
//     return list3;
// }

Nodefirst *add(Nodefirst *list1,Nodefirst *list2)
{
    int a[100]={0};
    int b[100]={0};

    Node *p1 = list1->head->next;
    Node *p2 = list2->head->next;

    while(p1 != NULL)
    {
        a[p1->data2] += p1->data1;
        p1 = p1->next;
    }

    while(p2 != NULL)
    {
        b[p2->data2] += p2->data1;
        p2 = p2->next;
    }
    Nodefirst *list3 = new Nodefirst;
    for(int i=0;i<100;i++)
    {
        a[i] += b[i];
        if(a[i] != 0)
        {
            list3->createNode(a[i],i);
        }
    }
    return list3;
}

void shuru(Nodefirst *list)
{
    cout << "===请输入多项式里的单项,输入 0 0 表示结束===~" << endl;

    while (true)
    {
        int a, b;
        cout << "请输入单项的系数和指数：";

        if (!(cin >> a >> b)) break;
        if(a == 0)
        {
            if (a == 0 && b == 0) break;
            cout << "提示：系数为0无意义" << endl;
        }
        list->createNode(a, b);
    }
}

// void clearList(Nodefirst *list)
// {
//     Node *p = list->head;
//     while (p != nullptr)
//     {
//         Node *temp = p;
//         p = p->next;
//         delete temp;
//     }
//     list->head = nullptr;
//     list->now = nullptr;
// }

int main()
{
    cout<<"请输入两个多项式"<<endl;
    Nodefirst *list1 = new Nodefirst;
    Nodefirst *list2 = new Nodefirst;
    shuru(list1);
    printList(list1->head);
    shuru(list2);
    printList(list2->head);
    Nodefirst *list3=add(list1,list2);
    printList(list3->head);

    delete list1;
    delete list2;
    delete list3;

    return 0;
}