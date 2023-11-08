#include <iostream>
#include <iomanip>
using namespace std;
int avg_n = 0;
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
            cout << this->key << " ";
            if(this->right) this->right->inorder();
        }

        void postorder() {
            if(this->left) this->left->postorder();
            if(this->right) this->right->postorder();
            cout << this->key << " ";
        }

        float sum_level(int level, int current_level = 1) {
            
            if(level != current_level) {
                int left_sum = 0;
                int right_sum = 0;
                if(this->right) right_sum = this->right->sum_level(level, current_level + 1);
                if(this->left) left_sum = this->left->sum_level(level, current_level + 1);
                return (right_sum + left_sum);
            }
            else {
                avg_n++;
                return this->key;
            }
        }

        int GetMax() {
            if(this->left && this->right) {
                int left = this->left->GetMax();
                int right = this->right->GetMax();
                return max(left + 1, right + 1);
            }
            else if(this->left) {
                return this->left->GetMax() + 1;
            }
            else if(this->right) {
                return this->right->GetMax() + 1;
            }
            else {
                return 1;
            }
        }
};

int main() {
    bst* root = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        if (i == 0) {
            root = new bst(key);
        }
        else {
            root->insert(root, key);
        }
    }
    int action_n;
    cin >> action_n;

    for (int i = 0; i < action_n; i++) {
        string action;
        cin >> action;

        if (action == "AverLevel") {
            int level;
            cin >> level;
            if (level == 0 || !root || root->GetMax() < level){
                cout << 0 << endl;
            }
            else if (root) {
                avg_n = 0;
                cout << setiosflags(ios::fixed) << setprecision(3) << root->sum_level(level) / avg_n  << endl;
            }
        }
        else if (action == "SumLevel") {
            int level;
            cin >> level;
            if (level == 0 || !root || root->GetMax() < level){
                cout << 0 << endl;
            }
            else if (root) {
                cout.precision(0);
                cout << root->sum_level(level) << endl;
            }
        }
        else if (action == "P") {
            if(root) {
                root->inorder();
                cout << endl;
            }
            else {
                cout << "NULL" << endl;
            }
        }
        else if (action == "GetMax") {
            if(root)
                cout << root->GetMax() << endl;
            else
                cout << 0 << endl;
        }
    }

}