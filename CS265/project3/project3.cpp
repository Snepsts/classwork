/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 3/9/16
*/

#include <iostream>
#include <string>
#include "queue.h"
#include "inventory.h"

using namespace std;

/* function listoptions
	Purpose: To list the options available to the user.
	Receives: N/A
	Preconditions: N/A
	Postconditions: Prints options to cout */
void listoptions();

int main()
{
	inventory invItem;
	queue invQueue;
	bool whilevar;
	char choose;
	int cNum, lNum;
	string manDate;

	listoptions();

	do
	{
		cout << "Please enter your choice: ";
		cin >> choose;

		switch(choose)
		{
		case 'a':
			cout << "Adding new item to back of inventory queue.\n";
			cout << "Please enter the Serial Number: ";
			cin >> cNum;
			cout << "Please enter the Manufacture Date: ";
			cin >> manDate;
			cout << "Please enter the Lot Number: ";
			cin >> lNum;
			invItem.setInventory(cNum, manDate, lNum);
			invQueue.enqueue(invItem);
			whilevar = true;
			break;

		case 'd':
			listoptions();
			whilevar = true;
			break;

		case 'r':
			cout << "Removing the front inventory item.\n";
			cout << "Front item's contents: \n";
			cout << invQueue.front();
			invQueue.dequeue();
			whilevar = true;
			break;

		case 'q':
			cout << "Thank you for using this program!\n";
			if (!invQueue.empty())
			{
				cout << "Printing contents of inventory queue: \n";
				cout << invQueue;
			}
			whilevar = false;
			break;

		default:
			cout << "That is not a valid option.\n";
			whilevar = true;
			break;
		}
	} while(whilevar);

	return 0;
}

void listoptions()
{ //Task: To print the options to cout
	cout << "a - Add to back of inventory.\n";
	cout << "d - Display the options.\n";
	cout << "r - Remove from front of inventory.\n";
	cout << "q - Quit program.\n";
}
