#include <iostream>
#include <stack>
#define SIZE 30
#define err(a) cout << #a << ": " << a << "\n"

using namespace std;
using ll = unsigned long long;

class term {
    public:
        ll row;
        ll col;
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    term* matrix = new term[SIZE + 2*t + 1];

    stack<ll> s;

    for(ll i = 0; i < t; i++){
        char a;        
        cin >> a; 
        ll index = (a - 'A');   

        cin >> matrix[index].row >> matrix[index].col;
    }

    ll q;
    cin >> q;

    for(ll i = 0; i < q; i++){
        string e;
        ll sum = 0;
        ll temp = 0; 

        bool flag = false;

        cin >> e;
        for(auto it = e.begin(); it < e.end(); it++) {  
            if(*it == ')') {
                ll m2 = s.top();
                s.pop();                
                ll m1 = s.top();
                s.pop();

                if(matrix[m2].row != matrix[m1].col) {
                    flag = true;
                    break;
                }

                sum += matrix[m1].row * matrix[m1].col * matrix[m2].col;

                matrix[SIZE + temp].row = matrix[m1].row;
                matrix[SIZE + temp].col = matrix[m2].col;

                s.push(ll(SIZE + (temp++)));
            }
            else if(*it != '(') {
                s.push(ll(*it - 'A'));
            }
        }

        if(flag) cout << "error" << endl;
        else cout << sum << endl;
    }
}