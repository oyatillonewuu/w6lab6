#pragma once
#include <string>
using namespace std;

class RuntimeException{
private:
    string msg;
public:
    RuntimeException(const string& m);
    string getMessage()const;
};

class StackEmpty: public RuntimeException{
public:
    StackEmpty(const string& m = "Stack is empty!");
};

class StackFull : public RuntimeException{
public:
    StackFull (const string& m = "Stack is full!");
};

template <typename E>
class ArrayStack {
private:
    E* S;
    // array holding the stack
    int cap; // capacity
    int t;
    // index of top element
public:
    ArrayStack(int c=100);
    ~ArrayStack();
    // constructor
    int size() const;
    // number of elements
    bool empty() const;
    // is stack empty?
    const E& top() const; // return top
    void push(const E& e); // push
    void pop();
    // pop
};

#include "arraystack.inl"