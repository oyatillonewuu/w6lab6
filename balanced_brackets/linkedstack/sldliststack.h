#pragma once
#include <string>
#include "slinkedlist/slinkedlist.h"
using namespace std;



class RuntimeException{
private:
    string msg;
public:
    RuntimeException(const string& m)
        : msg{ m}
    {}
    string getMessage() const {
        return msg;
    }
};

class StackEmpty : public RuntimeException{
public:
    StackEmpty(const string& m = "Stack is empty!")
        : RuntimeException(m)
    {}
};

template <typename E>
class LinkedStack {
private:
    SLinkedList<E> S;
    int n;
public:
    LinkedStack()
        : n {0}
    {};

    int size() const {
        return n;
    }

    bool empty() const {
        return n == 0;
    }

    const E& top() const {
        if (empty()) throw StackEmpty();
        return S.front();
    }

    void push(const E& e) {
        S.addFront(e);
        n++;
    }

    void pop() {
        if (empty()) throw StackEmpty();
        S.removeFront();
        n--;
    }

    void print() const {
        S.print();
    }
};
