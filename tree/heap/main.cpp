#include <iostream>
#define max_size 500
using namespace std;

template <class T>
class Tree{
    private:
        T* node_list;
        int index;
    public:
        Tree():index(-1){
            node_list = new T[max_size];
            fill(node_list, node_list + max_size, -1);
        }

        void insertNode(T data) {
            node_list[++index] = data;
            adjust(index);
        }

        void adjust(int it){
            while(it != 0) {
                int parent = (it-1) / 2; 
                if(node_list[it] > node_list[parent]){
                    int temp = node_list[it];
                    node_list[it] = node_list[parent];
                    node_list[parent] = temp;
                }
                else {
                    break;
                }

                it = parent;
            }
        }

        int pop() {
            int temp = node_list[0];

            node_list[0] = node_list[index];
            node_list[index--] = -1;
            int current = 0;

            while(1) {
                if(node_list[current * 2 + 1] > node_list[current * 2 + 2]) {
                    current  = current * 2 + 1;
                }
                else {
                    current = current * 2 + 2;
                }

                if(node_list[current] != -1) adjust(current);
                else break;
            }

            return temp;
        }

        void heap_sort() {
            while(index != -1) {
                cout << pop() << " ";
            }
        }
        void printarray() {
            for(int i = 0; i <= index; i++) {
                cout << node_list[i] << " ";
            }
            cout << endl;
        }
        
};

int main() {
    Tree<int> t;

    int n;
    cin >> n;
    while(n--) {
        int temp;
        cin >> temp;
        t.insertNode(temp);
    }

    t.heap_sort();
}