#include <iostream>

using namespace std;

template <class T> class Chain;

template <class T>
class Node {
    friend class Chain<T>;
    public:
        Node(T value):data(value) ,left(NULL), right(NULL){}
    private:
        T data;
        Node<T>* left;
        Node<T>* right;
};

template <class T>
class Chain {
    public:
        Chain():index(NULL){}

        

        void findNode(int pos) {
            int count = -1;
            Node<T>* it = index;
            if(index) {
                for(;count != pos && it != NULL; count++, it = it->nextNode);
                return it;
            }
            return NULL;
        }
    private:
        Node<T>* index;
};

int main () {

}