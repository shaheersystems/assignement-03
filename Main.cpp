//Muhammad Shaheer
//Bitf20m005
#include<iostream>
#include "LinkedList.h"
using namespace std;

int main() // Driver programe
{
	LinkedList list;
	cout << "\t1. Insert values\n";
	cout << "\t2. Remove a value\n";
	cout << "\t3. Search a value\n";
	cout << "\t4. Display the Linked List\n";
	cout << "\t5. Sort the Linked List\n";
	cout << "\t6. Reverse the Linked List\n";
	cout << "\t7. Empty the Linked List\n";
	cout << "\t8. Exit\n";
	int num = 0;
	int choice = 0;
	do {
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1)
		{
			cout << "Enter the values to be inserted [insert -999 to terminate]: ";
			do
			{
				cin >> num;
				if (num != -999)
				{
					list.insert(num);
				}
			} while (num != -999);
		}
		else if (choice == 2)
		{
			cout << "Enter the value to be removed: ";
			cin >> num;
			if (list.remove(num))
			{
				cout << num << " has been removed from the list\n";
			}
			else
			{
				cout << "ERROR: " << num << " is not found in the linked list\n";
			}
		}
		else if (choice == 3)
		{
			cout << "Enter the value to be searched:";
			cin >> num;
			if (list.search(num))
			{
				cout << "The number " << num << " is present in the list!!\n";
			}
			else
			{
				cout << "ERROR: " << num << " is not found in the linked list\n";
			}
		}
		else if (choice == 4)
		{
			list.display();
		}
		else if (choice == 5)
		{
			list.sort();
			cout << "The list has been sorted\n";
			list.display();
		}
		else if(choice == 6)
		{
			list.reverse();
			cout << "The list has been reversed!!\n";
			list.display();
		}
		else if (choice == 7)
		{
			list.emptyLinkedList();
			cout << "All the values have been removed from the linked list!\n";
		}
	} while (choice != 8);
	return 0;
}