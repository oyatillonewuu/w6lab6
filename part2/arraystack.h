class RuntimeException{
private:
    string msg;
public:
    RuntimeException(const string& m);
    string getMessage()const;
};

class StackEmpty: public RuntimeException{
public:
    StackEmpty(const string& m);
};

class StackFull : public RuntimeException{
public:
    StackFull (const string& m):RuntimeException(m){}
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
    // constructor
    int size() const;
    // number of elements
    bool empty() const;
    // is stack empty?
    const E& top() const throw(StackEmpty); // return top
    void push(const E& e) throw(StackFull); // push
    void pop() throw(StackEmpty);
    // pop
};
