/*
	Author: Michael Ranciglio
	Date: 1/21/2016
	Purpose: To count the mailboxes open or closed in the problem for clab1
*/

#include <iostream>
#include <cstdlib>

using namespace std;

enum door {open, closed};

struct mailbox
{
	unsigned number;
	door mboxdoor;
};

const int MAX_MAILBOXES = 150;

void initmboxdoors(mailbox mbox[]);

void openmboxdoors(mailbox mbox[]);

void closemboxdoors(mailbox mbox[]);

void listclosedmboxdoors(mailbox mbox[]);

int main()
{
	mailbox mbox[MAX_MAILBOXES];

	initmboxdoors(mbox);
	openmboxdoors(mbox);
	closemboxdoors(mbox);
	listclosedmboxdoors(mbox);

	return 0;
}

/*
	Function initmboxdoors
	Purpose: To initialize the mailboxes and set them all as closed & set their
				numbers
	Preconditions: N/A
	Postconditions: Sets all doors to closed (1)
*/

void initmboxdoors(mailbox mbox[])
{
	for(int a = 0; a < MAX_MAILBOXES; a++)
	{
		mbox[a].mboxdoor = closed;
		mbox[a].number = (a + 1);
	}
}

/*
	Function openmboxdoors
	Purpose: To open every even numbered mailbox (odd in terms of array value)
	Preconditions: All doors should be closed (run initmboxdoors first)
	Postconditions: Every even (odd array value) mbox door will be open
*/

void openmboxdoors(mailbox mbox[])
{
	for(int a = 1; a < MAX_MAILBOXES; a = a + 2)
	{
		mbox[a].mboxdoor = open;
	}
}

/*
	Function closemboxdoors
	Purpose: To close a certain pattern of mbox doors, and open any closed ones
				in said pattern
	Preconditions: Every even numbered door should be open and odd closed
					(run initmboxdoors and openmboxdoors first)
	Postconditions: All doors that should be closed will be closed
*/

void closemboxdoors(mailbox mbox[])
{
	for(int i = 3; i <= MAX_MAILBOXES; i++) //start at every third, so i = 3 in 1-250 logic
	{
		for(int a = (i - 1); a < MAX_MAILBOXES; a = a + i) // a = (i - 1) because array is from 0-249 instead of the 1-250 logic we're using with i
		{
			if (mbox[a].mboxdoor == open)
				mbox[a].mboxdoor = closed;
			else if (mbox[a].mboxdoor == closed)
				mbox[a].mboxdoor = open;
			else
			{
				cout << "Something went wrong with function closemboxdoors, please check that all functions have been called correctly. Exiting program." << endl;
				exit(1);
			}
		}
	}
}

/*
	Function listclosedmboxdoors
	Purpose: To list the closed mailbox doors and their number to show the
				completion of the puzzle
	Preconditions: All other functions must have been run in their specified
					order for this one to work properly.
	Postconditions: None, the program is complete.
*/

void listclosedmboxdoors(mailbox mbox[])
{
	for(int a = 0; a < MAX_MAILBOXES; a++)
	{
		if(mbox[a].mboxdoor == closed)
			cout << "Mailbox Door " << mbox[a].number << " is closed." << endl;
	}
}
