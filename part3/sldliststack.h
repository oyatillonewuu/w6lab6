// Exceptions (same as for ArrayStack)
class RuntimeException{
    string msg;
public:
    RuntimeException(const string& m): msg(m) {}
    string getMessage() const { return msg; }
};

class StackEmpty : public RuntimeException{
public:
    StackEmpty(const string& m = "Stack is empty!"): RuntimeException(m) {}
};

// Assume SLinkedList<E> provides: addFront(const E&), removeFront(),
// front() const, empty() const.
template <typename E>
class LinkedStack {
private:
    SLinkedList<E> S; // stack as a singly linked list (top at front)
    int n; // number of elements
public:
    LinkedStack():
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
        
    }
};