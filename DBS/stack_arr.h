#ifndef __STACK__ARR__MYSELF__
#define __STACK__ARR__MYSELF__
#include <iostream>
namespace room3 {
class stack;
typedef int ElementType;
class stack {
public:
    stack(int init_size = 100)
        : size(init_size) //default 100 [0,99]
        , top(-1)
    {
        initialization();
    }
    stack(const stack& other)
        : size(other.size)
        , top(other.top)
    {
        initialization();
        copy(this, other);
    }
    stack& operator=(const stack& other)
    {
        this->size = other.size;
        this->top = other.top;
        copy(this, other);
        return *this;
    }
    ~stack()
    {
        delete[] S;
    }
    // operation
    ElementType& pop();
    bool push(ElementType e);
    ElementType& front();
    void clear();
    bool empty();
    bool full();
    int getLen();
    int getAva();
    void list();

private:
    int size; //ok,you but have to write in initialization list
    int top; //'default -1' means stack is null
    int* S; //here should better int arr[size];
    void initialization()
    {
        if (0 == size)
            return;
        S = new int[size];
    }
    void copy(stack* ths, const stack& other)
    {
        if (0 == ths->size)
            return;
        for (int i = 0; i < ths->size; ++i)
            ths->S[i] = other.S[i];
    }
};
inline ElementType& stack::pop()
{
    if (!empty())
        return S[top--];
    return S[size];
}
inline bool stack::push(ElementType e)
{
    if (full())
        return false;
    S[++top] = e;
    return true;
}
inline ElementType& stack::front()
{
    if (!empty())
        return S[top];
    return S[size];
}
inline void stack::clear()
{
    top = -1;
}
inline bool stack::empty()
{
    if (-1 == top)
        return true;
    return false;
}
inline bool stack::full()
{
    if (top < size - 1) //better than 'top == size - 1'
        return false;
    return true;
}
inline int stack::getLen()
{
    return top + 1;
}
inline int stack::getAva()
{
    return size - top - 1;
}
inline void stack::list()
{
    if (-1 == top) {
        return;
    }
    std::cout << "[" << S[0];
    for (int i = 1; i <= top; i++) {
        std::cout << ',' << S[i];
    }
    std::cout << ']' << std::endl;
}
}

#endif //__STACK__ARR_MYSELF