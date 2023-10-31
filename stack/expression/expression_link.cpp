#include <iostream>

using namespace std;

template <class T> class Stack;

template <class T>
class Node {
    friend class Stack<T>;
    
    public:
        Node(T value, Node<T>* nextPointer = NULL):data(value), nextNode(nextPointer){}
    private:
        T data;
        Node<T>* nextNode;
};

template <class T>

class Stack {
    public:

        Stack():index(NULL) {}

        void push(T value) {
            Node<T>* temp = new Node<T>(value);
            temp->nextNode = index;
            index = temp;
        }

        void pop() {
            Node<T>* temp = index;
            index = index->nextNode;
            delete temp;
            temp = NULL;
        }

        T top() {
            return index->data;
        }

        bool empty() {
            return index == NULL;
        }
        
    private:
        Node<T>* index;
};
int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();

}