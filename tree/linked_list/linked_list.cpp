#include <iostream>
#define MAX_SIZE 500
using namespace std;


template <class T> class Tree;
template <class T> class Queue;
template <class T>
class Node {
    friend class Tree<T>;
    friend class Queue<T>;
    private:
        T data;
        Node<T>* leftchild;
        Node<T>* rightchild;
        Node<T>* parent;
    public:
        Node(T value):data(value), leftchild(NULL), rightchild(NULL){}
};

template <class T>
class Queue {
    private:
        Node<T>** queue;
        int rear;
        int front;
    public:
        Queue():front(-1), rear(-1) {
            queue = new Node<T>* [MAX_SIZE];
        }

        void enQueue(Node<T>* node) {
            rear = (rear+1) % MAX_SIZE;
            queue[rear] = node;
        }

        Node<T>* deQueue() {
            front = (front+1) % MAX_SIZE;
            return queue[front];
        }

        bool isEmpty() {
            return rear == front;
        }
};

template <class T>
class Tree {
    public:
        Node<T>* root;
    public:
        Tree():root(NULL){}

        Node<T>* findSpace() {
            Node<T>* current = root;
            Node<T>* parent = NULL;

            while(current) {

                parent = current;
                if (current->leftchild) {
                    current = current->rightchild;
                }
                else {
                    current = current->leftchild;
                }
            }

            return parent;
        }

        void insertNode(T data) {
            Node<T>* newNode = new Node<T>(data);
            Node<T>* parent = findSpace();

            if (root) {
                newNode->parent = parent 
                if(parent->leftchild) {
                    parent->rightchild = newNode;
                }
                else {
                    parent->leftchild = newNode;
                }
            }
            else {
                root = newNode;
            }
        }

        void printTree() {

            Queue<T> q;
            Node<T>* current = root;

            if (!current) return;
            q.enQueue(current);

            while (!q.isEmpty()) {
                current = q.deQueue();
                if (current->leftchild) q.enQueue(current->leftchild);
                if (current->rightchild) q.enQueue(current->rightchild);

                cout << current->data << " ";
            }
        }

        void preorder(Node<T>* it){
            if(it) {
                cout << it->data << " ";
                preorder(it->leftchild);
                preorder(it->rightchild);
            }
        }

        void inorder(Node<T>* it) {
            if(it) {
                inorder(it->leftchild);
                cout << it->data << " ";
                inorder(it->rightchild);
            }
        }

        void postorder(Node<T>* it) {
            if (it) {
                postorder(it->leftchild);
                postorder(it->rightchild);
                cout << it->data << " ";
            }
        }

        Node<T>* getRoot() {
            return root;
        }
};

int main () {
    Tree<char> t;

    char c;
    while (cin >> c) {
        t.insertNode(c);
    }
    t.preorder(t.getRoot());
    cout << endl;
    t.inorder(t.getRoot());
    cout << endl;
    t.postorder(t.getRoot());
    cout << endl;
    t.printTree();
}