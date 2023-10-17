#include <iostream>

using namespace std;
template <class T> class Chain;

template <class T>
class Node {
    friend class Chain<T>;
    public:
        Node(T value):data(value),nextNode(NULL){}

    private:
        T data;
        Node* nextNode;
};

template <class T>
class Chain{
    public:
        Chain():first(NULL), last(NULL){}

        void addNode(T value) {
            Node<T>* temp = new Node<T>(value);
            if(first) {
                last->nextNode = temp;
                last = temp;
            }
            else{
                first = last = temp;
            }
        }

        void insertNode(int position, T value) {
            int now = 0;
            Node<T>* temp = new Node<T>(value);
            if(position == 0 || first == NULL) {
                temp->nextNode = first;
                first = temp;
            }
            else {
                Node<T>* it = first;
                for (; (now+1) != position && it != NULL; now++, it = it->nextNode);
                if(it) {
                    temp->nextNode = it->nextNode;
                    it->nextNode = temp;
                }
                else {
                    throw "OUT OF RANGE";
                }

            }
        }

        Node<T>* findNode(T value){
            Node<T> *it = first;
            for(; it != NULL && it->nextNode->data != value; it = it->nextNode);
            return it;
        }

        void deleteNode(T value) {
            Node<T> *it = findNode(value);

            if(it) {
                Node<T>* temp = it->nextNode;
                it->nextNode = temp->nextNode;

                if(last == temp) last = it;
                if(first == temp) first = last = NULL;

                delete temp;
            }
        }

        void printNode(){
            for(Node<T>* it = first; it != NULL; it=it->nextNode){
                cout << it->data << endl;
            }
        }
    private:
        Node<T>* first;
        Node<T>* last;
};

int main() {
    Chain<int> a;
    a.addNode(1);
    a.addNode(2);
    a.addNode(3);
    a.addNode(4);
    a.addNode(5);

    a.deleteNode(3);
    a.deleteNode(2);
    a.printNode();
}