/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 4/3/16
*/

#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <iomanip>

using namespace std;

const int NUM_OF_CANDIDATES = 5; //5 candidates

struct vote
{
	string c_name;
	int votes;
	double pvotes;
};

/* function EnterVoteInfo
	Purpose: To allow vote input capped at NUM_OF_CANDIDATES
	Receives: list<vote> type the list of votes, and the double type of total votes
	Preconditions: N/A
	Postconiditons: c_name and votes are set by user, calls FindPercentages */
void EnterVoteInfo(list<vote>& vlist, double& totalvotes);

/* function FindPercentages
 	Purpose: To calculate the percentages of each candidates votes
	Receives: list<vote> type and double type of total votes, same as EnterVoteInfo
	Preconditions: Should have already called EnterVoteInfo
	Postconditions: pvotes is now set for each vote in vlist */
void FindPercentages(list<vote>& vlist, const double& totalvotes);

/* function CompareVotes
	Purpose: To provide a bool function for vlist.sort() function
	Receives: Two votes, both const to prevent modification
	Preconditions: Should be called with vlist.sort(CompareVotes)
	Postconiditons: Returns true if v1 is greater in vote count, else false */
bool CompareVotes(const vote& v1, const vote& v2);

int main()
{
	list<vote> vlist; //Vote list
	vote temp; //Temp variable used in for & winner to save memory
	double totalvotes = 0; //Total vote count variable

	EnterVoteInfo(vlist, totalvotes);
	vlist.sort(CompareVotes); //Sort the candidates by votes/percentage of votes

	cout << fixed << setprecision(2); //Round pvotes to 2 decimal points
	cout << "Candidate\t   Votes Received\tPercentage of Votes\n";
	for (list<vote>::iterator i = vlist.begin(); i != vlist.end(); i++)
	{
		temp = *i;
		cout << temp.c_name;
		if (temp.c_name.length() >= 8) //more than 8 chars only needs one tab
			cout << "\t\t";
		else if (temp.c_name.length() < 8) //less than 8 chars needs two tabs
			cout << "\t\t\t";
		cout << temp.votes << "\t\t\t" << temp.pvotes << endl;
	}
	cout << fixed << setprecision(0); //Make sure totalvotes has zero decimal places
	cout << "Total:\t\t\t" << totalvotes << endl;
	/*Instead of individually calculating the winner, he/she should already be
	in front thanks to vlist.sort(); being previously called */
	temp = vlist.front();
	cout << "The winner of the Election is " << temp.c_name << endl;

	return 0;
}

void EnterVoteInfo(list<vote>& vlist, double& totalvotes)
{
	vote temp; //temp vote variable
	temp.pvotes = 0; //initialize the percentage at zero
	for (int i = 0; i < NUM_OF_CANDIDATES; i++)
	{
		cout << "Please enter candidate #" << i+1 << "\'s last name: ";
		cin >> temp.c_name;
		cout << "Please enter candidate #" << i+1 << "\'s number of votes: ";
		cin >> temp.votes;
		totalvotes = totalvotes + temp.votes;
		vlist.push_back(temp);
	}

	FindPercentages(vlist, totalvotes); //Call the function right after enter
}

void FindPercentages(list<vote>& vlist, const double& totalvotes)
{
	vote temp; //another temp vote variable
	double tempd; //temp double variable to convert votes to double for pvotes calculating

	for (list<vote>::iterator i = vlist.begin(); i != vlist.end(); i++)
	{
		temp = *i;
		tempd = temp.votes; //Store/convert votes in temp double value
		temp.pvotes = (tempd / totalvotes) * 100; //Calculate percentage
		*i = temp;
	}
}

bool CompareVotes(const vote& v1, const vote& v2)
{
	return (v1.votes > v2.votes); //return true if first has more votes, else false
}
