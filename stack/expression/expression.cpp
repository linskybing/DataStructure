#include <iostream>
#include <stack>
#define err(a,b,op) cout << a << " " << op << " "  << b << endl;
using namespace std;

int icp(char c) {
    switch (c)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    default:
        return 0;
    }
}

bool isOperand(char c) {
    return !(c == '+' || c == '-' || c == '*' || c == '/');
}

template <class T>
string Postfix (string e, stack<T> s) {
    string result = "";
    for (auto it = e.begin(); it < e.end(); it++) {
        if (*it >= 'A' && *it <= 'Z') {
            result += *it;
        }
        else if (*it == ')') {
            for (;s.top() != '('; s.pop()) {
                result += s.top();
            }
            s.pop();
        }
        else if (*it == '(') {
            s.push(*it);
        }
        else {            
            for (;!s.empty() && icp(s.top()) >= icp(*it); s.pop()) {
                result += s.top();
            }           

            s.push(*it);
        }
    }

    for (; !s.empty(); s.pop()) {
        result += s.top();
    }

    return result;    
}

int main() {
    string e;
    cin >> e;
    stack<char> s;
    string temp  = Postfix(e,s);
    cout << "Postfix: " << temp << endl;
}