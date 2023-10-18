#include <iostream>

using namespace std;

template <class T>
class Chain {
    public:
        Chain(): front(NULL), rear(NULL){}

        void addNode(T value) {
            Node* newNode = new Node(value);
            if(rear) {
                rear->nextNode = newNode;
                rear = newNode;
            }
            else {
                rear = newNode;
                front = rear = newNode;
            }
        }

        void printChain(){
            for (Node* it = front; it != NULL; it = it->nextNode){
                cout << it->data << endl;
            }
        }
    private:
        class Node{
            public:
                T data;
                Node* nextNode;

                Node (T value, Node* next = NULL): data(value), nextNode(next){}
        };

        Node* front;
        Node* rear;
};

int main() {
    Chain<int> a;
    a.addNode(1);
    a.addNode(2);
    a.addNode(3);
    a.addNode(3);

    a.printChain();
}
    
