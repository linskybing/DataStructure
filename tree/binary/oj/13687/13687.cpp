// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
using namespace std;
class BST
{
    int key;
    BST *left, *right;
    
    public:
    // Default constructor.
    BST();
    // Parameterized constructor.
    BST(int);
    BST* Insert(BST*, int);
    BST* deleteNode(BST*,int);
    BST* minValueNode(BST*);
    BST* searchValue(BST*,int);
    void Inorder(BST*);
    void Postorder(BST*);
    //void Preorder(BST*);
};
 
// Default Constructor definition.
BST ::BST()
: key(0)
, left(NULL)
, right(NULL)
{
}
 
// Parameterized Constructor definition.
BST ::BST(int value)
{
    key = value;
    left = right = NULL;
}
 
// Insert function definition.
BST* BST ::Insert(BST* root, int key)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(key);
    }
    
    // Insert data.
    if (key > root->key)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.
        
        // Process right nodes.
        root->right = Insert(root->right, key);
    }
    else
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.
        
        // Process left nodes.
        root->left = Insert(root->left, key);
    }
 
    // Return 'root' node, after insertion.
    return root;
}
 
// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->key << endl;
    Inorder(root->right);
}
 
//Postorder traversal function.
void BST ::Postorder(BST* root)
{
    if (!root) {
        return;
    }
    Postorder(root->left);
        Postorder(root->right);
        cout << root->key << endl;
    }
 
//minValueNode
BST* BST::minValueNode(BST* root){
    BST* current = root;
 
    while (current && current->left!=NULL)
        current = current->left;
 
    return current;
}
//deleteNode
BST* BST::deleteNode(BST* root,int key){
    if (root == NULL)
        return NULL;
    else if (key > root->key){
        root->right = deleteNode(root->right,key);
        return root;
    }
    else if (key < root->key){
        root->left = deleteNode(root->left, key);
        return root;
    }
    else{
        if (root->left == NULL && root->right == NULL){
            return NULL;
        }
        else if (root->left == NULL){
            BST* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL){
            BST* temp = root->left;
            delete root;
            return temp;
        }
        //delete the node which has two childs
        else{
            BST* tmp = minValueNode(root->right);
            root->key = tmp->key;
            root->right = deleteNode(root->right,tmp->key);
            return root;
        }
 
    }
}
//searchValue
BST* BST::searchValue(BST* root,int key){
    if (root == NULL)
        return NULL;
    else if (key > root->key)
        return searchValue(root->right,key);
    else if (key < root->key)
        return searchValue(root->left,key);
    else
        return root;
}
// Driver code
int main()
{
BST b, *root = NULL;
    string cmd;
    int count = 0;
    while(cin >> cmd){
        if(cmd == "insert"){
            int x;
            cin >> x;
            if (count == 0)
                root = b.Insert(root,x);
            else
                b.Insert(root,x);
            count+=1;
        }else if(cmd == "delete"){
            int x;
            cin >> x;
            b.deleteNode(root,x);
            count-=1;
        }else if(cmd == "inorder"){
            b.Inorder(root);
        }else if(cmd == "search"){
            int x;
            cin >> x;
            if(b.searchValue(root,x))
                cout<<"Found"<<endl;
            else
                cout<<"Not Found"<<endl;
        }else if(cmd == "postorder"){
            b.Postorder(root);
        }else if(cmd == "exit"){
            return 0;
        }
    }
    return 0;
}