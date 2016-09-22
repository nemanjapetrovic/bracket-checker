#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template <class T>
class Stack
{
    private:
        int size;
        int top;
        T *data;
    public:
        Stack();
        Stack(int size);
        ~Stack();
        void push(T item);
        T pop();
        int getTop();
        bool isEmpty();
        int numberOfElements();
        int getSize();
        void print();
};

#endif // STACK_H_INCLUDED
