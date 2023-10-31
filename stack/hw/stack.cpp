#include <iostream>
#define SIZE 100000
#define err(a) cout << #a << ":" << a << endl;

using namespace std;

class Pair {
    public:
        char c;
        int index;
};

template <typename T>
class Stack {
    public:
        Stack(int c = SIZE): capacity(c),index(-1){
            datastack = new T[capacity];
        }

        void push(char v, int i) {

            Pair temp;
            temp.c = v;
            temp.index = i;
            datastack[++index] = temp;
        }

        T top() {
            if(empty()) throw invalid_argument( "stack is empty" );

            return datastack[index];

        }

        void pop() {
            if(!empty()) {
                datastack[index--].~T();
            }
        }

        bool empty() {
            return index == -1;
        }

        void clear() {
            delete [] datastack;
            index = -1;
            datastack = new T[capacity];
        }

    private:
        int index;
        int capacity;
        T* datastack;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    Stack<Pair> s;
    char* str = new char[SIZE];

    cin >> n;
    cin.ignore();

    while(n--){
        cin.getline(str, SIZE);
        int count = 0, max = 0, index = 0, invalid = 0;

        for(char* it = str; *it != '\0'; it++, index++) {
            if (*it == '(') {
                s.push(*it, index);
            }
            else {
                if(!s.empty()) {
                    s.pop();
                }
                else {
                    if(invalid == 0){
                        count = index - invalid;
                    }
                    else {
                        count = index - invalid - 1;
                    }

                    if(count > max) max = count;
                    invalid = index;
                }
            }
        }

        for(; !s.empty(); s.pop()) {
            count = index - s.top().index - 1;
            if(count > max) max = count;
            index = s.top().index;
        }

        count = index - invalid;
        if(count > max) max = count;

        cout << char(((max/2)%26)+'a');
    }
    cout << '\n';
    return 0;
}
