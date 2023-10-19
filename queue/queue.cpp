#include <iostream>

using namespace std;

template <class T>
class queue {
    public:

        queue():rear(0),front(0),capacity(7) {
            q = new T[capacity];
        }

        bool isEmpty() {
            return (rear == front);
        }

        void push(T const data) {
            if (((rear + 1) % capacity == front)) {
                changeSize();
            }

            rear = (rear + 1) % capacity;
            q[rear] = data;
        }

        void pop() {
            if (isEmpty()) throw "Queue is empty.";

            front = (front + 1) % capacity;

            q[front].~T();
        }

        T front_e() {
            if (isEmpty()) throw "Queue is empty.";

            return q[(front+1) % capacity];
        }
        
        T rear_e() {
            if (isEmpty()) throw "Queue is empty.";

            return q[rear];
        }

        void changeSize() {
            T* temp = new T[2*capacity];

            int start = (front + 1) % capacity;

            if (start < 2) {
                copy(q + start, q + start + capacity -1, temp);
            }
            else {
                copy(q + start, q + capacity, temp);
                copy(q, q + rear + 1, temp + capacity - start);
            }

            front = 2*capacity -1;
            rear = capacity - 2;
            capacity *= 2;
            delete [] q;
            q= temp;
        }

        void print_all(){
            while (!isEmpty()) {
                cout << front_e() << " ";
                pop();
            }
        }
    private:
        int rear;
        int front;
        int capacity;
        T* q;
};

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    q.print_all();
}