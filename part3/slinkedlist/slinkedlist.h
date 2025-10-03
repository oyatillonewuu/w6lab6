#pragma once

template <typename E>
class SNode{
private:
    E elem;
    // was: string
    IntNode* next;
    friend class IntLinkedList;
};


template <typename E>
class SLinkedList{
private:
    SNode<E>* head;
public:
    SLinkedList();
    ~SLinkedList();
    bool empty() const;
    void addFront(const E& e);
    void addBack(const E& e);
    int size();
    void print();
    int sum();
    double average();

    // Problems
    
    const E& front() const;
    void removeFront();
    void removeBack();
    int removeAll(const E& e); // returns the number of nodes removed
    void reverse();
};
