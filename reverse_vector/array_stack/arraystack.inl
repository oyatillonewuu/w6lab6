#include <string>
#include "arraystack.h"
using namespace std;


RuntimeException::RuntimeException(const string& m)
    : msg{ m }
{};

std::string RuntimeException::getMessage() const {
    return msg;
}

StackEmpty::StackEmpty(const string& m)
    : RuntimeException(m)
{};

StackFull::StackFull(const string& m)
    : RuntimeException(m)
{};

template <typename E>
ArrayStack<E>::ArrayStack(int c)
{
    S = new int[c];
    cap = c;
    t = -1;
}

template <typename E>
ArrayStack<E>::~ArrayStack() {
    delete[] S;
}

template <typename E>
int ArrayStack<E>::size() const {
    return t + 1;
}

template <typename E>
bool ArrayStack<E>::empty() const {
    return t == -1;
}

template <typename E>
const E& ArrayStack<E>::top() const {
    if (empty()) {
        throw StackEmpty();
    }
    return S[t];
}

template <typename E>
void ArrayStack<E>::push(const E& e) {
    if (t + 1 >= cap) throw StackFull();
    S[++t] = e;
}

template <typename E>
void ArrayStack<E>::pop() {
    if (empty()) throw StackEmpty();
    t--;
}