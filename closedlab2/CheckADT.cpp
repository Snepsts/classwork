#include "CheckADT.h"

CheckADT::CheckADT()
// Constructor
{
	name = " "; ssNo = " "; balance = 0; accountNo = 0;
}

void CheckADT::Open()
/*	Task: Enter the AccountNo and CustomerInfo from the keyboard
	Initialize the balance to 0 */
{
	cout << "\nEnter account number (1000-9999): ";
	cin >> accountNo;
	cout << "\nEnter customer name (no spaces). (Max 20 char) ";
	cin.ignore (256, '\n'); // Clear rest of line and eol chars for getline
	getline (cin, name); // Use getline to allow for spaces in name
	cout << "\nEnter customer SSNO (9 digits) ";
	cin >> ssNo;
	balance = 0;
}

double CheckADT::CurrentBalance()
// Task: Return the Current Balance
{
	return balance;
}

void CheckADT::Deposit(double amount)
// Task: Add amount to balance
{
	balance = amount + balance;
}

void CheckADT::Withdrawal(double amount)
//Task: Subtract amount from balance
{
	balance = balance - amount;
}

void CheckADT::Check(int ChkNo, double amount)
//Task: Subtract amount & sometimes OVER_DRAFT_FEE when needed
{
	if (amount <= balance)
		balance = balance - amount;
	else
	{
		cout << "Account is overdrawn. Overdraft fee will be applied." << endl;
		balance = balance - (amount + OVER_DRAFT_FEE);
	}
}

ostream & operator<<(ostream & out, const CheckADT & c)
//Task:	To make main more readable by simplifying << output
{
	out << "Account Number: " << c.accountNo << endl;
	out << "Name: " << c.name << endl;
	out << "Social Security Number: " << c.ssNo << endl;
	out << "Balance: " << c.balance << endl;
	return out;
}
