#include <iostream>

using namespace std;

template <class T> BinaryTree;

template <class T>
class Node {
    friend class BinaryTree<T>;
    private:
        Node<T>* lChild = nullptr;
        Node<T>* rChild = nullptr;
        T data;
    public:
        Node(T val): data(val){}
};

template <class T>
class BinaryTree {
    private:
        Node<T>* root = nullptr;

    public:
        void insert(T val) {
            Node<T>* newNode = new Node<T>(val);

            if(!root){
                root = newNode;
                return;
            }

            Node<T>* it = root;
            Node<T>* parent = nullptr;
            while(it) {
                parent = it;
                if(val > it->data) {
                    it = it->rChild;
                }
                else {
                    it = it->lChild;
                }
            }
            if(val > parent->data) parent->rChild = newNode;
            else parent->lChild = newNode;            
        }

        void inorder(Node<T>* it) {
            if(it) {
                inorder(it->left);
                cout << it->data << " ";
                inorder(it->rChild);
            }
        }
};

int main() {
    string str;
    
}