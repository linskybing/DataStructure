#include <iostream>
#define err(a) cout << #a << " " << a << endl;
using namespace std;

template <class T> class Chain;

template <class T>
class Node {
    friend class Chain<T>;
    public:
        Node(int value): data(value), left(NULL), right(NULL){}
    private:
        Node<T>* left;
        Node<T>* right;
        T data;
};
template <class T>
class Chain {
    public:
        Chain(): first(NULL), last(NULL), index(-1){}
        void insertNode(int pos ,T value){
            Node<T>* newNode = new Node<T>(value);

            if(last) { //nonempty
                // update last
                Node<T>* it = findNode(pos-1);
                newNode->left = it;
                newNode->right = it->right;
                //careful it->right
                it->right = newNode;
                //careful newNode->right == NULL
                if(newNode->right) {
                    newNode->right->left = newNode;
                }
                if(index == pos || index == -1) last = newNode;
            }
            else {
                first = last = newNode;
            }
            //be carefule
            index++;

        }

        void deleteNode(int pos, int m) {
            Node<T>* temp = findNode(pos);
            //delete
            temp->left->right = temp->right;
            temp->right->left = temp->left;

            if(pos > m){
                //add
                temp->right = first;
                temp->left = last;
                last->right = temp;
                first->left = temp;
            }
            else {
                delete temp;
                temp = NULL;
            }
        }

        void showNode(int v1, int v2) {
            if(v1 <= v2) {
                Node<T>* it = findNode(v1);
                for(int i = v1; i < v2 && it != NULL; i++, it = it->right){
                    cout << it->data << " ";
                }
                if(it) cout << it->data << endl;
            }
            else {
                Node<T>* it = findNode(v1);
                for(int i = v1; i > v2 && it != NULL; i--, it = it->left) {
                    cout << it->data << " ";
                }
                if(it) cout << it->data << endl;
            }
        }

        //be careful
        Node<T>* findNode(int pos) {
            Node<T>* temp = first;

            if(pos >= 0){
                for(int i = 0; i != pos && temp != NULL; i++, temp = temp->right);
            }
            else {
                for(int i = 0; i != pos && temp != NULL; i--, temp = temp->left);
            }

            return temp;

        }

        void printNode() {
            Node<T>* it = first;
            cout << "Chain : ";
            for(int i = 0; i <= index && it != NULL; i++, it = it->right) {
                cout << it->data << " ";
            }
            cout << endl;
        }
    private:
        Node<T>* first;
        Node<T>* last;
        int index;
};

int main() {
    Chain<int> chain;

    char c;
    int v1, v2;

    while(cin >> c >> v1 >> v2) {
        cin.ignore();

        switch (c)
        {
        case 'i':
            chain.insertNode(v1, v2);
            //chain.printNode();
            break;
        case 'd':
            chain.deleteNode(v1, v2);
            //chain.printNode();
            break;
        case 's':
            //chain.printNode();
            chain.showNode(v1, v2);
            break;
        default:
            break;
        }
    }
}
