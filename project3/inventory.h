/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 3/9/16
	Data Type: inventory to store values for an object representing an "inventory"
	Functions:
		get(membernamehere): Returns member, accessor.
		setInventory: Sets the inventory object members to parameters passed by user.
friend	ostream& operator<<: Outputs the members to ostream out.
*/

#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <iostream>
#include <string>

using namespace std;

class inventory
{
public:
	/* Constructor
	Purpose: To construct */
	inventory();

	/* function getSerialNum
	Purpose: Accessor for serialNum member
	Receives: N/A
	Preconditions: N/A
	Postconditions: Returns serialNum member */
	int getSerialNum() const;

	/* function getManufactDate
	Purpose: Accessor for manufactDate member
	Receives: N/A
	Preconditions: N/A
	Postconditions: Returns manufactDate member */
	string getManufactDate() const;

	/* function getLotNum
	Purpose: Accessor for lotNum
	Receives: N/A
	Preconditions: N/A
	Postconditions: Returns lotNum */
	int getLotNum() const;

	/* function setInventory
	Purpose: Mutator/to set the member variables to the parameters
	Receives: ints cNum/lNum and string manDate
	Preconditions: N/A
	Postconditions: Sets corresponding member variables to the parameters passed */
	void setInventory(int cNum, string manDate, int lNum);

	/*function overloaded = operator
	Purpose: To define what invItem1 = invItem2 means. To allow use of = operator.
	Receives: inventory item i
	Preconditions: N/A
	Postconditions: this->inventory item's members now equal that of the i object passed through parameters */
	void operator=(const inventory& i);

	/* function overloaded << operator
	Purpose: To output the inventory object to ostream object
	Receives: inventory i
	Preconditions: N/A
	Postconditions: Returns ostream object to print member information of object i */
	friend ostream& operator<<(ostream& out, const inventory& i);

private:
	int serialNum, lotNum;
	string manufactDate;
};

#endif
