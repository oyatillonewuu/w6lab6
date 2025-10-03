#pragma once

template <typename E>
class SLinkedList;

template <typename E>
class SNode{
private:
    E elem;
    SNode* next;
    friend class SLinkedList<E>;
};


template <typename E>
class SLinkedList {
private:
    SNode<E>* head;
public:
    SLinkedList();
    ~SLinkedList();
    bool empty() const;
    void addFront(const E& e);
    void addBack(const E& e);
    int size();
    void print() const;

    E& front() const;
    void removeFront();
    void removeBack();
    int removeAll(const E& e);
    void reverse();
};

#include "slinkedlist.inl"
