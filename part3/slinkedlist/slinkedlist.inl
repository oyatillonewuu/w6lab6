#include <iostream>
#include "slinkedlist.h"
using namespace std;


template <typename E>
SLinkedList<E>::SLinkedList(): head(nullptr) {}

template <typename E>
SLinkedList<E>::~SLinkedList(){
    // My addition
    while (head) {
        SNode<E>* tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <typename E>
bool SLinkedList<E>::empty() const{
    return head == nullptr;
}

template <typename E>
E& SLinkedList<E>::front() const {
    return head;
}

template <typename E>
void SLinkedList<E>::addFront(const E& e){
    SNode<E>* n = new SNode<E>();
    n->elem = e;
    n->next = head;
    head = n;
}

template <typename E>
void SLinkedList<E>::addBack(const E& e){
    SNode<E> *node = new SNode<E>();
    node->elem = e;
    node->next = nullptr;
    if(empty()){
        head = node;
        return;
    }
    SNode<E> *h = head;
    while(h->next != nullptr){
        h = h->next;
    }
    h->next = node;
}


template <typename E>
int SLinkedList<E>::size() {
    SNode<E>* h = head;
    int count = 0;
    while(h != nullptr){
        count++;
        h = h->next;
    }
    return count;
}

template <typename E>
void SLinkedList<E>::print() const {
    SNode<E> *h = head;
    if(empty()){
        return;
    }
    while(h!=nullptr){
        cout<< h->elem <<" ";
        h = h->next;
    }
}

template <typename E>
void SLinkedList<E>::removeFront() {
    if (empty()) return;
    SNode<E>* tmp = head;
    head = head->next;
    delete tmp;
}

template <typename E>
void SLinkedList<E>::removeBack() {
    if (empty()) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    SNode<E>* prev = head;
    SNode<E>* target = head->next;

    while (target->next) {
        prev = target;
        target = target->next;
    }

    delete target;
    prev->next = nullptr;
}

template <typename E>
int SLinkedList<E>::removeAll(const E& x) {
    if (empty()) return 0;
    int count = 0;

    // Remove x's at front
    while (head && head->elem == x) {
        SNode<E>* tmp = head;
        head = head->next;
        delete tmp;
        count++;
    }

    // If head becoms empty or head
    // originally was a single node.
    if (!head || !(head->next)) {
        return count;
    }

    // The above loop guarantees we now
    // don't have any x at front.
    SNode<E>* prev = head;
    SNode<E>* mover = head->next;

    while (mover) {
        if (mover->elem == x) {
            prev->next = mover->next;
            delete mover;
            mover = prev->next;
            count++;
            continue;
        }
        prev = mover;
        mover = mover->next;
    }
    return count;
}

template <typename E>
void SLinkedList<E>::reverse() {
    if (empty() || head->next == nullptr) return;

    SNode<E>* prev = head;
    SNode<E>* current = head->next;
    head->next = nullptr;

    while (current) {
        SNode<E>* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

