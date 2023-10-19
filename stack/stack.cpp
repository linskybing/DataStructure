#include <iostream>
#define err(a) cout << #a << ": " << a << endl;
using namespace std;

template <class T>
class stack {
    public:
        stack(): capacity(10), index(-1){
            s = new T[capacity];
        }

        void push(T data) {
            if (index == capacity-1) {
                chageCapacity(2*capacity);
            }

            s[++index] = data;
        }

        T& top() {
            if (!isEmpty()){
                return s[index];
            }
            else {
                throw "Stack is empty.";
            }
        }

        void pop() {
            if (isEmpty()) throw "Stack is empty.";
            
            s[index--].~T();
        }

        void chageCapacity(int c) {
            T* temp  = new T[c];
            copy(s, s + capacity, temp);            
            delete [] s;
            s = temp;
            capacity = c;
        }

        bool isEmpty() {
            return (index == -1);
        }

    
    private:
        int capacity;
        T* s;
        int index;
};


int main() {
    stack<int> s;
    err(s.top());
}