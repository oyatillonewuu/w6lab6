#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include "linkedstack/sldliststack.h"
using namespace std;

bool validBrackets(const string& input) {
    LinkedStack<char> stack;
    set<char> brackets = {'{', '}', '(', ')', '[', ']'};
    unordered_map<char, char> bracket_pairs = {
        {'}', '{'},
        {')', '('},
        {']', '['}
    };

    for (char ch: input) {
        if (brackets.find(ch) == brackets.end()) continue;
        if (bracket_pairs.find(ch) != bracket_pairs.end()) {
            if (stack.empty()) {
                return false;
            }

            if (stack.top() != bracket_pairs.at(ch)) return false;
            stack.pop();
        } else {
            stack.push(ch);
        }
    }

    return stack.empty();
}

int main(void) {
    string input;
    getline(cin, input);
    cout << ((validBrackets(input) == true) ? "Valid":"Invalid") << endl;
}
