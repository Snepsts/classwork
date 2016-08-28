#include <iostream>
#include <string>
#include "CheckADT.h"

using namespace std;

int main()
{
	CheckADT me; //declaration
	me.Open(); //initialization from keyboard
	cout << me.CurrentBalance() << endl; //should be 0
	me.Deposit(10000);
	cout << me.CurrentBalance() << endl; // should be 10,000
	me.Withdrawal(5000);
	cout << me.CurrentBalance() << endl; // should be 5,000
	me.Check(1500, 500);
	cout << me.CurrentBalance(); // should be 4,500
	
	return 0;
}
