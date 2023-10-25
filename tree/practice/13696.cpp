#include <iostream>

template <class T> class Tree;

template <class T>
class Node {
    friend class tree;
    private:
        int number;
        Node<T>* subNode;

    public: 
        Node(int n):number(n){
            Node<T>
        }
};

template <class T>
class Tree {
    private:
        Node<T>* nodeList;
        int totalNode;
    public:
        Tree(int total  = 10), totalNode(total) {
            Node<T>* nodeList = new Node<T>[total+1];
        }



};