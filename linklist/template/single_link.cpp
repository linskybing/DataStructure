#include <iostream>
#define err(a) cout << #a << " " << a << endl;
using namespace std;

template <class T> class Chain;

template <class T>

class Node {
    friend class Chain<T>;
    public:
        Node(int value):data(value), left(NULL), right(NULL){}
    private:
        T data;
        Node<T>* left;
        Node<T>* right;
};

template <class T>
class Chain {
    public:
        Chain():first(NULL), last(NULL){}

        void addNode(T value) {
            cout << value << endl;
            Node<T>* temp = new Node<T>(value);
            cout << temp << endl;
            if(last) {
                temp->right = first;
                temp->left = last;
                last->right = temp;
                first->left = temp;
                last = temp;
            }
            else {
                first = last = temp;
            }
        }

        void insertNode(int pos, T value) {
            Node<T>* it = findNode(pos);
            Node<T>* newNode = new Node<T>(value);
            
            if(it == first) {
                newNode->right = first;
                newNode->left = last;
                it->left = newNode;
                it->right = newNode;
                first = newNode;
            }
            else if(it == last){
                newNode->right = first;
                newNode->left = last;
                last->right = newNode;
                first->left = newNode;
                last = newNode;
            }
            else {
                newNode->right = it;
                newNode->left = it->left;
                it->left->right = newNode;
                it->left = newNode;
            }
        }

        void deleteNode(int pos) {
            Node<T>* it = findNode(pos);
            it->left->right = it->right;
            it->right->left = it->left;

            if(it == first) {
                first = it->right;
            }
            else if(it == last){
                last = it->left;
            }

            delete it;
            it = NULL;
        }

        Node<T>* findNode(int pos) {
            int index = -1;
            Node<T>* it = first;

            for(;it != NULL && (index+1) != pos; it = it->right);

            return it;
        }

        void printNode() {
            int round = 0;

            for(Node<T>* it = first; round != 2; it = it->right) {
                cout << it->data << endl;
            }
        }
    private:
        Node<T>* first;
        Node<T>* last;
};

int main() {
    Chain<int> c;
    err(1);
    c.addNode(1);
    //c.addNode(2);
    //c.addNode(3);
    //c.addNode(4);
    //c.printNode();
}