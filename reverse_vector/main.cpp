#include <iostream>
#include <vector>
#include "array_stack/arraystack.h"
using namespace std;


void inputVector(vector<int>& dest) {
    int size;
    cout << "Enter size: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        int inp;
        cin >> inp;
        dest.push_back(inp);
    }

    return;
}

void reverseVector(vector<int>& vec) {
    ArrayStack<int> stack(vec.size());

    for (int n: vec) {
        stack.push(n);
    }

    for (int i = 0; i < vec.size(); i++) {
        vec[i] = stack.top();
        stack.pop();
    }

    return;
}

void printVector(const vector<int>& vec) {
    for (int n: vec) {
        cout << n << " ";
    }
}


int main(void) {
    vector<int> vec;
    inputVector(vec);
    reverseVector(vec);
    printVector(vec);
    return 0;
}
