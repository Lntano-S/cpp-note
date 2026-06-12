#include <iostream>
class MyVector
{
private:
    int* data_;   // 指向动态数组的指针
    int  size_;   // 当前元素个数
    int  cap_;    // 当前容量（已分配内存能容纳的元素个数）

public:
    // ---------- 构造 / 析构 ----------
    // 默认构造：空数组
    MyVector() : data_(nullptr), size_(0), cap_(0) {}

    // 构造包含 n 个 0 的数组
    explicit MyVector(int n)
        : data_(new int[n]()), size_(n), cap_(n) {}

    // 析构：释放动态内存
    ~MyVector()
    {
        delete[] data_;
    }

    // 拷贝构造函数：执行深拷贝
    MyVector(const MyVector& other) : size_(other.size_), cap_(other.cap_)
    {
        if (other.cap_ > 0)
        {
            data_ = new int[other.cap_];
            for (int i = 0; i < other.size_; ++i)
                data_[i] = other.data_[i];
        }
        else
        {
            data_ = nullptr;
        }
    }

    // ---------- 容量与大小 ----------
    int size()     const
    {
        return size_;
    }
    int capacity() const
    {
        return cap_;
    }

    // 预留空间：如果 new_cap 大于当前容量，则分配更大内存
    void reserve(int new_cap)
    {
        if (new_cap > cap_)
        {
            int* new_data = new int[new_cap];
            for (int i = 0; i < size_; ++i)
                new_data[i] = data_[i];
            delete[] data_;
            data_ = new_data;
            cap_  = new_cap;
        }
    }

    // ---------- 元素访问 ----------
    int get(int i) const
    {
        return data_[i];
    }
    int& get(int i)
    {
        return data_[i];
    }

    // ---------- 修改操作 ----------
    // 末尾添加元素，容量翻倍扩容
    void push_back(int val)
    {
        if (size_ == cap_)
        {
            int new_cap = (cap_ == 0) ? 1 : 2 * cap_;
            reserve(new_cap);
        }
        data_[size_++] = val;
    }

    // 移除末尾元素
    void pop_back()
    {
        if (size_ > 0)
            --size_;
    }
};

int main()
{
    MyVector v;
    std::cout << "初始 size: " << v.size() << " capacity: " << v.capacity() << '\n';

    // 添加元素
    for (int i = 1; i <= 5; ++i)
        v.push_back(i * 10);
    std::cout << "添加5个元素后: ";
    for (int i = 0; i < v.size(); ++i)
        std::cout << v.get(i) << ' ';
    std::cout << "\nsize: " << v.size() << " capacity: " << v.capacity() << '\n';


    // 使用默认拷贝构造函数进行浅拷贝
    MyVector v2(v);

    std::cout << "\nv2 copied from v \n";
    for (int i = 0; i < v.size(); ++i)
        std::cout << v2.get(i) << ' ';
    std::cout << "\nsize: " << v2.size() << " capacity: " << v2.capacity() << '\n';

    std::cout << "\nAFTER: v2[0]=999 \n";
    v2.get(0) = 999;     // 修改 v2 的第一个元素
    std::cout << "v2.get(0) = " << v2.get(0) << "\n";
    std::cout << "v.get(0) = " << v.get(0) << "\n";

    return 0;
}