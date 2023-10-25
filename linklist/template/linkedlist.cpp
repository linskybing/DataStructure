#include <iostream>
#define err(a) cout << #a << " " << a << endl;
using namespace std;

template <class T> class Chain;

template <class T>

class Node {
    friend class Chain<T>;
    private:
        Node<T>* left;
        Node<T>* right;
        T data;
    public:
        Node(int value):left(NULL), right(NULL), data(value){}
};

template <class T>
class Chain {
    private:
        Node<T>* root;
        int index;

    public:
        Chain(): root(NULL), index(-1){}

        Node<T>* findNode(int pos) {
            Node<T>* it = root;

            if(pos >= 0) {

                for (int i = 0; i != pos && it != NULL; i++, it = it->right);

            }
            else{
                for (int i = 0; i != pos && it != NULL; i--, it = it->left);
            }
            return it;
        }

        void insertNode(int pos, T value) {

            Node<T>* it;
            Node<T>* newNode = new Node<T>(value);
            index ++;
            if(root == NULL) {
                root = newNode;
                root->right = root;
                root->left = root;
                return;
            }

            if(pos == -1) {
                it = findNode(-1);
            }
            else{
                it = findNode(pos-1);
            }

            newNode->left = it;
            newNode->right = it->right;
            it->right->left = newNode;
            it->right = newNode;

            if(pos == 0) {
                root = newNode;
            }
            
        }

        void deleteNode(int pos, int m) {
            Node<T>* it = findNode(pos);
            
            it->left->right = it->right;
            it->right->left = it->left;

            if (it->data >= m) {
                insertNode(-1, it->data);
                if(pos == 0) {
                    root = root->right;
                }
            }
            else {
                if(pos == 0) {
                    root = root->right;
                }
                delete it;
                it = NULL;
            }

            index--;
        }

        void showNode(int v1, int v2) {
            Node<T>* it = findNode(v1);
            if(it == NULL) return;
            if(v1 <= v2) {
                for(int i = v1; i < v2 && it != NULL; i++, it = it->right){
                    cout << it->data << " ";
                }

                if(it) cout << it->data << " " << endl;
            }
            else{
                for(int i = v1; i > v2 && it != NULL; i--, it = it->left) {
                    cout << it->data << " ";
                }

                if(it) cout << it->data << " " << endl;
            }
        }

        void printNode() {
            cout << "===ALL====" << endl;
            showNode(0, index);
            cout << "===" << endl;
        }

};

int main() {
    Chain<int> chain;
    char c;
    int v1, v2;
    while(cin >> c >> v1 >> v2) {
        switch (c)
        {
        case 'i':
            chain.insertNode(v1, v2);
            //chain.printNode();
            break;
        case 'd':
            chain.deleteNode(v1, v2);
            break;
        case 's':
            chain.showNode(v1, v2);
            break;
        default:
            break;
        }
    }
}