#include <iostream>

using namespace std;

class Node {
private:
	int element;
	Node* next;
	Node* previous;
public:
	Node() { this->element = 0; this->next = NULL; this->previous = NULL; }
	Node(int a) { this->element = a; this->next = NULL; this->previous = NULL; }

	friend class LinkedList;
};

class LinkedList {
private:
	Node* root;
public:
	LinkedList() { this->root = NULL; }
	void insert(int v2, int v3);
	void deletion(int v2, int v3);
	void show(int v2, int v3);
};

void LinkedList::insert(int v2, int v3) {

	Node* newnode = new Node(v3);
	Node* current = this->root;
	if (current == NULL) {
		this->root = newnode;
		return;
	}
	if (v2 == -1) {
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newnode;
		newnode->previous = current;
	}
	else if (v2 == 0) {
		this->root = newnode;
		newnode->next = current;
		newnode->previous = this->root;
		current->previous = newnode;
	}
	else {
		for (int i = 0; i < v2 - 1; i++) {
			current = current->next;
		}

		if (current->next != NULL) {
			Node* next_node = current->next;
			current->next = newnode;
			newnode->previous = current;
			newnode->next = next_node;
			next_node->previous = newnode;
		}
		else {
			current->next = newnode;
			newnode->previous = current;
		}
	}
}

void LinkedList::deletion(int v2, int v3) {
	
	Node* current = this->root;
	Node* next_node;
	if (v2 == 0) {
		next_node = current->next;
		next_node->previous = this->root;
		this->root = next_node;
	}
	else {
		for (int i = 0; i < v2; i++) {
			current = current->next;
		}
		Node* previous_node = current->previous;
		if (current->next == NULL) {
			previous_node->next = NULL;
		}
		else {
			previous_node = current->previous;
			next_node = current->next;
			previous_node->next = next_node;
			next_node->previous = previous_node;
		}
	}
	
	if (current->element >= v3) {
		Node* newnode = new Node(current->element);
		Node* para = current;
		int check = 0;
		while (para->next != NULL) {
			para = para->next;
			check++;
		}
		if (check == 0) {
			para = para->previous;
		}
		para->next = newnode;
		newnode->previous = para;
	}

	delete current;
}

void LinkedList::show(int v2, int v3) {
	if (v2 <= v3) {
		Node* current = this->root;
		for (int i = 0; i < v2; i++) {
			current = current->next;
		}
		for (int j = v2; j <= v3; j++) {
			cout << current->element << " ";
			if (current->next != NULL) {
				current = current->next;
			}
		}
		cout << endl;
	}
	else {
		Node* current = this->root;
		for (int i = 0; i < v2; i++) {
			current = current->next;
		}
		for (int j = v2; j >= v3; j--) {
			cout << current->element << " ";
			if (current->previous != NULL) {
				current = current->previous;
			}
		}
		cout << endl;
	}
}

int main() {
	LinkedList list;
	char op;
	int v2, v3;
	while (cin>> op >> v2 >> v3) {
		switch (op)
		{
		case 'i':
			list.insert(v2, v3);
			break;
		case 'd':
			list.deletion(v2, v3);
			break;
		case 's':
			list.show(v2, v3);
			break;
		default:
			break;
		}
	}
	return 0;
}