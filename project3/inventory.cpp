/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 3/9/16
*/

#include <iostream>
#include <string>
#include "inventory.h"

inventory::inventory()
{ //Task: To construct the inventory object
	serialNum = 0; manufactDate = ""; lotNum = 0;
}

int inventory::getSerialNum() const
{ //Task: To return serialNum
	return serialNum;
}

string inventory::getManufactDate() const
{ //Task: To return manufactDate
	return manufactDate;
}

int inventory::getLotNum() const
{ //Task: To return lotNum
	return lotNum;
}

void inventory::setInventory(int cNum, string manDate, int lNum)
{ //Task: To set the members of the inventory object to the parameters
	serialNum = cNum; manufactDate = manDate; lotNum = lNum;
}

void inventory::operator=(const inventory& i)
{ //Task: To allow assigning inventory with another inventory (i) with = operator
	this->serialNum = i.serialNum; this->manufactDate = i.manufactDate; this->lotNum = i.lotNum;
}

ostream& operator<<(ostream& out, const inventory& i)
{ //Task: To simplifiy << operator in main for easy printing
	out << "Serial Number: " << i.serialNum << endl;
	out << "Manufacture Date: " << i.manufactDate << endl;
	out << "Lot Number: " << i.lotNum << endl;

	return out;
}
