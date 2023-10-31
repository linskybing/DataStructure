#include <iostream>
#define MAX_SIZE 500
using namespace std;
class Queue {
    private:
        int* index_queue;
        int rear;
        int front;
    public:
        Queue():rear(-1), front(-1){
            index_queue = new int[MAX_SIZE];
        }

        void push(int data) {  
            rear = (rear+1) % MAX_SIZE;
            index_queue[rear] = data; 
        }

        int pop() {
            front = (front + 1) % MAX_SIZE;
            return index_queue[front];
        }

        bool isEmpty() {
            return rear == front;
        }
};
template <class T>

class Tree {
    private:
        T* node_list;
        int index;
    public:
        Tree():index(-1) {
            node_list = new T[MAX_SIZE];
            fill(node_list, node_list+MAX_SIZE, '0');
        }

        void insertNode(T data) {
            node_list[++index] = data;
        }

        void printnode() {
            for (int i = 0; i <= index; i++) {
                cout << node_list[i] << " ";
            }
        }

        void preorder(int it) {
            if(node_list[it] != '0') {
                cout << node_list[it] << " ";
                preorder(it * 2 + 1);
                preorder(it * 2 + 2);
            }
        }

        void postorder(int it) {
            if(node_list[it] != '0') {
                postorder(it * 2 + 1);
                postorder(it * 2 + 2);
                cout << node_list[it] << " ";
            }
        }

        void inorder(int it) {
            if(node_list[it] != '0') {
                inorder(it * 2 + 1);
                cout << node_list[it] << " ";
                inorder(it * 2 + 2);
            }
        }

        void levelorder(int it) {
            Queue q;
            if(node_list[it] == -1) return;

            q.push(it);
            int current = 0;
            while(!q.isEmpty()) {
                current = q.pop();
                if(node_list[current * 2 + 1] != '0') q.push(current * 2 + 1);
                if(node_list[current * 2 + 2] != '0') q.push(current * 2 + 2);

                cout << node_list[current] << " ";
            }
        }

        void printarray() {
            for (int i = 0; i <= index; i ++) {
                cout << node_list[i] << " ";
            }
        }
};

int main() {
    Tree<char> t;

    int n;
    cin >> n; 
    while(n--) {
        char temp;
        cin >> temp;
        t.insertNode(temp);
    }

    t.levelorder(0);
}