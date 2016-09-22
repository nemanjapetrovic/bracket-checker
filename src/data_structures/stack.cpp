#include <iostream>
#include "stack.h"

template <class T>
Stack<T>::Stack()
{
    this->data = NULL;
    this->size = this->top = 0;
};

template <class T>
Stack<T>::Stack(int size)
{
    this->size = size;
    this->top = -1;
    this->data = new T[this->size]();
};

template <class T>
Stack<T>::~Stack()
{
    if(this->data)
    {
        delete[] this->data;
    }
};

template <class T>
void Stack<T>::push(T item)
{
    if(this->top == this->size-1)
    {
        throw "Stack overflow!";
    }
    else
    {
        this->top++;
        this->data[this->top] = item;
    }
};

template <class T>
T Stack<T>::pop()
{
    if(isEmpty())
    {
        throw "Stack is empty!";
    }
    else
    {
        T tmp = this->data[this->top];
        this->data[top] = 0;
        this->top--;
        return tmp;
    }
};

template <class T>
int Stack<T>::getTop()
{
    if(isEmpty())
    {
        throw "Stack is empty!";
    }
    else
    {
        return this->data[this->top];
    }
};

template <class T>
bool Stack<T>::isEmpty()
{
    return (this->top == -1);
};

template <class T>
int Stack<T>::numberOfElements()
{
    return this->top + 1;
};

template <class T>
int Stack<T>::getSize()
{
    return this->size;
};

template <class T>
void Stack<T>::print()
{
    for(int i = this->size - 1 ; i >= 0 ; --i)
    {
        std::cout<<"stack ["<<i<<"] = "<<this->data[i]<<std::endl;
    }
};
