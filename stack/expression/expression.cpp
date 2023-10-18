#include <iostream>
#include <stack>
#define err(a,b,op) cout << a << " " << op << " "  << b << endl;
using namespace std;
typedef unsigned long long ll;

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
    case '^':
        return 3;
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
        if (*it >= '0' && *it <= '9') {
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
            char last = *it;            
            for (;(!s.empty() && icp(s.top()) >= icp(*it)) && (s.top() != '^' || last != '^'); s.pop()) {
                result += s.top();
                last = s.top();
            }           

            s.push(*it);
        }
    }

    for (; !s.empty(); s.pop()) {
        result += s.top();
    }

    return result;    
}

int Evl (string e) {
    stack<int> temp;
    for (auto it = e.begin(); it < e.end(); it++) {
        if(*it >= '0' && *it <= '9') {
            temp.push((*it - '0'));
        }
        else {
            int b = temp.top();
            temp.pop();
            int a = temp.top();
            temp.pop();         
            int result = 0;

            switch (*it)
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            case '^':
                result = 1;
                for (int i = 0; i < b; i++) {
                    result *= a;
                }
                break;
            default:
                break;
            }

            temp.push(result);
        }
    }

    return temp.top();
}

int main() {
    string e;
    int flag = 0;
    while(cin >> e){        
        stack<char> s;
        if(flag) cout << '\n';
        else flag = 1;
        string temp  = Postfix(e,s);
        cout << e << endl;
        cout << temp << endl;
        cout << Evl(temp);
    }
}