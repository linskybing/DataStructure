#include <iostream>

using namespace std;

class bst {
    public:
        int key;
        bst* right;
        bst* left;

        bst(int value):key(value), right(NULL), left(NULL){}

        bst* insert(bst* root, int value) {
            if (!root) {
                return new bst(value);
            }
            else if (value > root->key) {
                root->right = insert(root->right, value);
            }
            else {
                root->left = insert(root->left, value);
            }
            return root;
        }

        bst* find_min(bst* root) {
            bst* it = root;
            while(it && it->left) it = it->left;

            return it;

        }
        
        bst* search(bst* root, int value) {
            if (!root) {
                return NULL;
            }
            else if (value > root->key) {
                return search(root->right, value);
            }
            else if (value < root->key) {
                return search(root->left, value);
            }
            else {
                return root;
            }
        }

        bst* delete_node(bst* root, int key) {
            if(!root) {
                return NULL;
            }
            else if (key > root->key) {
                root->right = delete_node(root->right, key);
            }
            else if (key < root->key) {
                root->left = delete_node(root->left, key);
            }
            else {
                if (root->left && root->right) {
                    bst* temp = find_min(root->right);
                    root->key = temp->key;
                    root->right = delete_node(root->right, temp->key);
                }
                else if(root->left) {
                    bst* temp = root->left;
                    delete root;
                    return temp;
                }
                else if(root->right) {
                    bst* temp = root->right;
                    delete root;
                    return temp;
                }
                else {
                    delete root;
                    return NULL;
                }
            }

            return root;
        }

        void inorder() {
            if(this->left) this->left->inorder();
            cout << this->key << endl;
            if(this->right) this->right->inorder();
        }

        void postorder() {
            if(this->left) this->left->postorder();
            if(this->right) this->right->postorder();
            cout << this->key << endl;
        }
};

int main() {
    bst* root = nullptr;
    string action;
    int count = 0;
    while(cin >> action) {
        int key;

        if (action == "insert") {
            cin >> key;
            if (count == 0) {
                root = new bst(key);
            }
            else {
                root->insert(root, key);
            }
            count ++;
        }
        else if (action == "search") {
            cin >> key;
            if (root->search(root, key)) {
                cout << "Found" << endl;
            }
            else {
                cout << "Not Found" << endl;
            }
        }
        else if (action == "delete") {
            cin >> key;
            root->delete_node(root, key);
            count --;
        }
        else if (action == "postorder") {
            root->postorder();
        }
        else if (action == "inorder") {
            root->inorder();
        }
        else {
            return 0;
        }
    }
    return 0;
}