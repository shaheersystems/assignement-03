#ifndef NODE_H
#define NODE_H
#include "LinkedList.h"
class Node
{
	friend class LinkedList;
private:
	int data;
	Node* next;
public:
};


#endif
