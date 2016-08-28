/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 2/2/16
	Data Type: CheckADT, an object that contains a checking account, name,
	balance, etc.
	Operations:
		CheckADT(); - The Constructor
		Open(); - The initialization function that allows the user to input
	his own information from the keyboard.
		CurrentBalance(); - This function returns the current balance in the
	CheckADT object.
		Deposit(double amount); - The purpose of this function is to add to the
	balance.
		Withdrawal(double amount); - Removes money from the balance
		Check(double amount); - Removes money + OVER_DRAFT_FEE
*/

#ifndef __CHECKADT_H__
#define __CHECKADT_H__

#include <iostream>
#include <string>

using namespace std;

const double OVER_DRAFT_FEE = 15.00;

class CheckADT
{
public:
/*	Task: Constructor */
	CheckADT();
/*	Function Open();

	Task: Enter the AccountNo and CustomerInfo from the keyboard
	Initialize the balance to 0 */
	void Open();
/*	Function CurrentBalance();

	Task: Return the current balance */
	double CurrentBalance();
/*	Function Depost(double amount);

	Task: Add amount to balance

	Recieves: amount to add to balance

	Precondition: amount > 0

	Postcondition: amount is added to balance */
	void Deposit(double amount);
/*	Function Withdrawal(double amount);

	Task: Subtract amount from balance

	Recieves: amount to subtract from balance

	Precondition: amount > 0

	Postcondition: if amount <= balance then subtract amount from balance
	else post message of insufficent funds */
	void Withdrawal(double amount);
/*	Function Check(int ChkNo, double amount);

	Task: Take out current amount & sometimes OVER_DRAFT_FEE when needed

	Receives: amount of check to be deducted from balance. Note ChkNo is not
	currently used in the function, but it is included for future use. There
	may be a warning concerning this.

	Precondition: amount > 0

	Postcondition: if amount > balance:
	1) Prints message that account is overdrawn and an overdraftfee will be
	assessed
	2) Subtracts OVER_DRAFT_FEE from balance
	In any case, it subtracts amount from balance */
	void Check(int ChkNo, double amount);
/*	Overloaded operator <<

	Task: Overload the << operator to make it easier to read output in main */
	friend ostream & operator<<(ostream & out, const CheckADT & c);

private:
	double balance;
	string name;
	string ssNo;
	int accountNo;
};

#endif
