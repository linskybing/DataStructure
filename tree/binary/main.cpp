#include <iostream>

using namespace std;

class bst {
    public:
        int key;
        bst* left;
        bst* right;

    bst(): left(NULL), right(NULL){}
    bst(int value): key(value), left(NULL), right(NULL){}

    void insert(int key) {
        bst* current = this;
        bst* parent = nullptr;
        bst* newNode = new bst(key);
        while(current) {
            parent = current;
            if(current->key < key){
                current = current->right;
            }
            else if(current->key > key) {
                current = current->left;
            }
            else {
                current = NULL;
            }
        }

        if (key > parent->key) parent->right = newNode;
        else if (key < parent->key) parent->left = newNode;
    }

    bool search(int key) {
        bst* current = this;
        while (current) {
            if(key > current->key) {
                current = current->right;
            }
            else if(key < current->key) {
                current = current->left;
            }
            else {
                return true;
            }
        }
        return false;
    }

    bst* find_max() {
        bst* current = this;
        bst* parent = NULL;

        while(current) {
            parent = current;
            current = current->right;
        }

        return parent;
    }

    bst* find_min() {
        bst* current = this;
        bst* parent = NULL;

        while(current) {
            parent = current;
            current = current->left;
        }
        return parent;
    }

    void delete_node(int key) {
        bst* cur = this;
        bst* par = NULL;

        while(cur && cur->key != key) {
            par = cur;
            if(cur->key < key) cur = cur->right;
            else if(cur->key > key) cur = cur->left;
        }

        if(par == NULL) {
            
        }
   
    }
    void inorder(){
        
        if (this->left) this->left->inorder();
        cout << this->key << endl;
        if (this->right) this->right->inorder();
        
    }

    void preorder() {
        cout << this->key << endl;
        if(this->left) this->left->inorder();
        if(this->right) this->right->inorder();
    }
    
    void postorder() {
        if (this->left) this->left->postorder();
        if (this->right) this->right->postorder();
        cout << this->key << endl;
    }
};

int main() {
    string action;
    int count = 0;
    bst* root = nullptr;
    while(cin >> action) {

        if (action == "insert") {
            int key;
            cin >> key;
            if (count == 0) {
                bst* newNode = new bst(key);
                root = newNode;
            }
            else {
                root->insert(key);
            }
            count ++;
        }
        else if (action == "delete") {
            int key;
            cin >> key;
            root->delete_node(key);
            count --;
        }
        else if (action == "preorder") {
            if (root) root->preorder();
        }
        else if (action == "postorder") {
            if (root) root->postorder();
        }
        else if (action == "inorder") {
            if (root) root->inorder();
        }
        else if (action == "search") {
            int key;
            cin >> key;
            cout << ((root->search(key))? "Found" : "Not Found" )<< endl;
        }

    }
}