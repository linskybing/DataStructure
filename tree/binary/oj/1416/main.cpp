#include <iostream>

using namespace std;
class bst;
bst* target = NULL;


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
            else if (value < root->key){
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

        int size_tree(int size) {
            if (this->left && this->right) {
                int result = this->left->size_tree(size) + this->right->size_tree(size) + 1;
                if (result == size) target = this;
                return result;
            }
            else if(this->left) {
                int result = this->left->size_tree(size) + 1;
                if (result == size) target = this;
                return result;
            }
            else if(this->right) {
                int result = this->right->size_tree(size) + 1;
                if (result == size) target = this;
                return result;
            }
            else {
                if (1 == size) target = this;
                return 1;
            }
        }
};
int main() {
    bst* root = nullptr;
    string action;
    int count = 0;
    while(cin >> action) {
        int key;

        if (action == "Insert") {
            cin >> key;
            if (count == 0) {
                root = new bst(key);
            }
            else {
                root->insert(root, key);
            }
            count ++;
        }
        else if (action == "Size") {
            int size;
            cin >> size;
            target = NULL;
            root->size_tree(size);
            if(target) cout << root->size_tree(size) << endl;
            else cout << -1 << endl;

        }
        else {
            return 0;
        }
    }
    return 0;
}