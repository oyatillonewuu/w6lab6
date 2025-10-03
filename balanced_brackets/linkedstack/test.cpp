#include <iostream>
#include "sldliststack.h"
using namespace std;


int main(void) {
    LinkedStack<int> intStack;
    cout << intStack.empty() << endl;
    intStack.push(1);
    cout << intStack.size() << endl;
    intStack.pop();
    cout << intStack.empty() << endl;
    cout << intStack.size() << endl;
    intStack.push(2);
    intStack.push(2);
    intStack.pop();
    intStack.print();
    intStack.pop();
    return 0;
}
