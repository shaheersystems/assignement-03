//Muhammad Shaheer
//Bitf20m005
#include<iostream>
#include "LinkedList.h"
using namespace std;
LinkedList::LinkedList()
{
	head = nullptr;
}
LinkedList::~LinkedList()
{
	Node* current = head;
	while (current != nullptr)
	{
		head = head->next;
		delete current;
		current = head;
	}
}

LinkedList::LinkedList(const LinkedList& orig)
{
	if (orig.head == nullptr) // If original list is empty!!
	{
		head = nullptr;
	}
	else
	{
		head = new Node;
		head->data = orig.head->data;
		Node* t1 = (orig.head)->next;
		Node* t2 = head;
		while (t1 != nullptr)
		{
			t2->next = new Node;
			t2 = t2->next;
			t2->data = t1->data;
			t1 = t1->next;
		}
		t2->next = nullptr;
	}

}
bool LinkedList::insert(int val) // insert at the first of the list
{
	Node* current = new Node;
	current->data = val;
	current->next = head;
	head = current;
	return true;
}

int LinkedList::countNodes() // Function to count the nodes presnet in the linked list
{
	int count = 0;
	Node* curr = head;
	while (curr != nullptr)
	{
		count++;
		curr = curr->next;
	}
	return count;
}
void LinkedList::display()
{
	if (head == nullptr) // If the list is empty!!
	{
		cout << "The list is empty!!!\n";
	}
	else // Otherwise
	{
		Node* current = head;
		cout << "The list contains following " << countNodes() << " elements: ";
		while (current != nullptr) // Traverse and display whole list
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
}

bool LinkedList::search(int key)
{
	if (head == nullptr) // Of list is empty returns false
	{
		return false;
	}
	else
	{
		Node* current = head;
		while (current != nullptr) // Travesrse list
		{
			if (current->data == key) // If key is found returns true immidiately
			{
				return true;
			}
			current = current->next; 
		}
		return false; // Returns false if key's not found
	}
}

bool LinkedList::remove(int val)
{
	Node* current = head, * prev = nullptr;
	while (current != nullptr && current->data != val) // Traverse untill the value is not found and list is not finished
	{
		prev = current;
		current = current->next;
	}
	if (current == nullptr) // If the list was finished and values wasn't found
	{
		return false;
	}
	else if (current == head) // If the value is at first node
	{
		head = head->next;
	}
	else // remove the node in which value is found
	{
		prev->next = current->next;
	}
	delete current; // Deleting the node
	current = nullptr;
	return true;
}
void LinkedList::sort()
{

	Node* current = head;
	Node* prev2 = nullptr;
	while (current != nullptr)
	{
		Node* min = current;
		Node* prev = current;
		Node* prev1 = nullptr;
		Node* temp = current->next;
		while (temp != nullptr)
		{
			if (temp->data < min->data)
			{
				min = temp;
				prev1 = prev;
			}
			prev = temp;
			temp = temp->next;
		}
		if (min != current)
		{
			if (prev1 != nullptr)
			{
				prev1->next = min->next;
			}
			min->next = current;
		}
		current = min->next;
		if (prev2 != nullptr)
		{
			prev2->next = min;
		}
		else
		{
			head = min;
		}
		prev2 = min;
	}

}
void LinkedList::reverse() 
{
	if (head == nullptr) // if list is empty
	{
		cout << "The list is empty!!\n";
	}
	else
	{
		Node* current = head;
		Node* previous = nullptr;
		Node* temp = nullptr;
		while (current != nullptr)
		{
			temp = current->next; // temporary node for traverse
			current->next = previous;
			previous = current;
			current = temp;
		}
		head = previous; // assginig last element of the list to the head [tail is new head after reversal]
	}
}

void LinkedList::emptyLinkedList() // to empty the list
{
	if (head != nullptr) // if list isn't already empty
	{
		head = nullptr;
	}
}