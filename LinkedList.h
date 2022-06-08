//Muhammad Shaheer
//Bitf20m005
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
class LinkedList
{
private:
	Node* head;
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList&);
	bool insert(int);
	void display();
	bool search(int);
	bool remove(int);
	void sort();
	void reverse();
	int countNodes();
	void emptyLinkedList();
};
#endif
