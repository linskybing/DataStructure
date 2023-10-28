#include <iostream>
#define MAX_SIZE 200000
using namespace std;

class chain;

class node {
    friend class chain;
 
    public:
        int number;
        node* nextnode;
        node(int n):number(n), nextnode(NULL){}
};

class chain {
    public:
        node* first;
        node* last;
        int height;
        bool flag;
        chain():first(NULL), last(NULL), height(-1), flag(false){}

        void add(int n){
            node* newnode = new node(n);

            if(last) {
                last->nextnode = newnode;
                last = newnode;
            }
            else {
                first = last = newnode;
            }
        }

        void printNode() {
            for(node* it = first; it != NULL; it = it->nextnode) {
                cout << it->number << " ";
            }

            cout << endl;
        }

        void recycle(){
            node* previous = NULL;
            node* it = first;
            while(it) {
                previous = it;
                it = it->nextnode;
                if(previous)
                    delete previous;
            }
            first = last = NULL;
            height = -1;
        }
};

int dfs(chain* tree_list, int position) {

    tree_list[position].flag = true;

    if(tree_list[position].height != -1) return tree_list[position].height;

    if(tree_list[position].first == NULL) {
        tree_list[position].height = 0;
        return 0;
    }

    node* current = tree_list[position].first;
    int deep = 0;
    int max = 0;
    for(;current != NULL; current = current->nextnode) {
        //cout << position << " to " << current->number << ":" << tree_list[current->number].flag << endl;
        deep = dfs(tree_list, current->number) + 1;
        if(deep > max) max = deep;
    }

    tree_list[position].height = max;

    return max;

}

int main() {
    int cases;
    cin >> cases;

    while(cases--) {
        int node_number;
        cin >> node_number;

        chain* tree_list = new chain[node_number+2];


        int node_one, node_two;

        for(int i = 0; i < node_number-1; i++) {
            cin >> node_one >> node_two;
            tree_list[node_one].add(node_two);
        }
        for(int i = 1; i <= node_number; i++) {
            dfs(tree_list, i);
        }

        /*for(int i = 1; i <= node_number; i++) {
            cout << i << ": ";
            cout << tree_list[i].height << endl;
        }
        cout << endl; */

        int max = 0;

        for(int i = 1; i <= node_number; i++){
            node* current = tree_list[i].first;

            int first_max = 0;
            int second_max = 0;
            tree_list[i].flag = true;
            for(;current != NULL; current = current->nextnode){
                int temp = tree_list[current->number].height + 1;

                if(temp > first_max) {
                    second_max = first_max;
                    first_max = temp;
                }
                else if(temp > second_max) second_max = temp;
            }

            if((first_max + second_max) > max) max = first_max + second_max;
        }

        cout << max << endl;

        for(int i = 1; i <= node_number; i++) {
            tree_list[i].recycle();
        }

        delete [] tree_list;
    }

}