#include <iostream>
#include "arraystack.h"
using namespace std;

int main() {
    try {
        ArrayStack<int> s(3);  // stack of capacity 3
        cout << "Initially empty? " << (s.empty() ? "yes" : "no") << endl;

        // Push some values
        s.push(10);
        s.push(20);
        cout << "Size after 2 pushes: " << s.size() << endl;
        cout << "Top element: " << s.top() << endl;

        s.push(30);
        cout << "Pushed 30. Size: " << s.size() << endl;

        // Attempt push beyond capacity
        cout << "Trying to push another element (should throw StackFull)..." << endl;
        s.push(40);
    }
    catch (const StackFull& e) {
        cout << "Caught exception: " << e.getMessage() << endl;
    }

    try {
        ArrayStack<int> s2(2);
        s2.push(5);
        s2.push(6);
        cout << "Top: " << s2.top() << endl;
        s2.pop();
        cout << "After one pop, top: " << s2.top() << endl;
        s2.pop();
        cout << "Stack is now empty, next pop should throw..." << endl;
        s2.pop();  // should throw
    }
    catch (const StackEmpty& e) {
        cout << "Caught exception: " << e.getMessage() << endl;
    }
}
