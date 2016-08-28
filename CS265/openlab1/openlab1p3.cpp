/*
	Author: Michael Ranciglio
	Date: 1/27/2016
	Purpose: To preform various tasks related to structure declaration
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

enum Cards {Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack,
	Queen, King, Ace};

enum Suits {Hearts, Diamonds, Spades, Clubs}; //reminder that hearts is 0
											// diamonds is 1, spades 2, clubs 3
struct Card
{
	bool isassigned;
	unsigned int number;
	Cards value;
	Suits suit;
};

const int DECK_SIZE = 52;

typedef Card Deck[DECK_SIZE];

void initdeck(Deck d1);

void filldeck(Deck d1);

bool cardexists(Deck d1, Cards c, Suits s);

void singlecard(Deck d1);

void listdeck(Deck d1);

int main()
{
	Deck d1;

	srand(time(0));

	singlecard(d1);
	initdeck(d1);
	filldeck(d1);
	listdeck(d1);

	return 0;
}

/*
	Function initdeck
	Purpose: To initialize the deck with ordered card values
	Preconditions: None
	Postconditions: Deck is ready for other functions
*/

void initdeck(Deck d1)
{
	for (int a = 0; a < DECK_SIZE; a++)
	{
		d1[a].isassigned = false;
		d1[a].number = (a + 1);
	}
}

/*
	Function filldeck
	Purpose: To fill the deck with Cards
	Preconditions: intideck
	Postconditions: All cards will be declared
*/

void filldeck(Deck d1)
{
	int x;
	int y;
	Cards c;
	Suits s;

	for (int a = 0; a < DECK_SIZE; a++)
	{
		if (d1[a].isassigned == false) //check if singlecard already assigned a value
		{
			do { //ensure that the card hasn't already been generated
				x = rand() % 13 + 2;
				switch(x)
				{
					case 2:
						c = Two;
						break;
					case 3:
						c = Three;
						break;
					case 4:
						c = Four;
						break;
					case 5:
						c = Five;
						break;
					case 6:
						c = Six;
						break;
					case 7:
						c = Seven;
						break;
					case 8:
						c = Eight;
						break;
					case 9:
						c = Nine;
						break;
					case 10:
						c = Ten;
						break;
					case 11:
						c = Jack;
						break;
					case 12:
						c = Queen;
						break;
					case 13:
						c = King;
						break;
					case 14:
						c = Ace;
						break;
					default:
						cout << "Something went wrong with value generation" << endl;
						break;
				}
				y = rand() % 4;
				switch(y)
				{
					case 0:
						s = Hearts;
						break;
					case 1:
						s = Diamonds;
						break;
					case 2:
						s = Spades;
						break;
					case 3:
						s = Clubs;
						break;
					default:
						cout << "Something went wrong with suit generation" << endl;
						break;
				}
			} while(cardexists(d1, c, s));

			d1[a].value = c;
			d1[a].suit = s;
		}
	}
}

/*
	Function cardexists
	Purpose: To check if the card exists anywhere in the deck already
	Preconditions: Should be called in the fill deck function
	Postconditions: None
*/

bool cardexists(Deck d1, Cards c, Suits s)
{
	bool retvar;

	retvar = false; //default to false

	for (int a = 0; a < DECK_SIZE; a++)
	{
		if(d1[a].value == c && d1[a].suit == s) //if the card exists
			retvar = true;						//set retvar to true
	}

	if(retvar)	//if retvar is true return true, else return false
		return true;
	else
		return false;
}

/*
	Function singlecard
	Purpose: To fill a single card in the deck
	Preconditions: initdeck
	Postconiditons: Will take up one card slot
*/

void singlecard(Deck d1)
{
	unsigned int a, x, y;
	Cards c;
	Suits s;

	do //guard from bad values
	{
		cout << "Which card would you like to fill (1-52)?" << endl;
		cin >> a;
	} while(a < 1 || a > 52);
	a = a - 1;

	do //guard from bad values
	{
		cout << "Please enter card value (2-10, 11 jack, 12 queen, 13 king, 14 ace): ";
		cin >> x;

		switch(x) //store x as the enum
		{
			case 2:
				c = Two;
				break;
			case 3:
				c = Three;
				break;
			case 4:
				c = Four;
				break;
			case 5:
				c = Five;
				break;
			case 6:
				c = Six;
				break;
			case 7:
				c = Seven;
				break;
			case 8:
				c = Eight;
				break;
			case 9:
				c = Nine;
				break;
			case 10:
				c = Ten;
				break;
			case 11:
				c = Jack;
				break;
			case 12:
				c = Queen;
				break;
			case 13:
				c = King;
				break;
			case 14:
				c = Ace;
				break;
			default:
				cout << "Something went wrong with value generation" << endl;
				break;
		}
	} while(x < 2 || x > 14);

	do //guard from bad values
	{
		cout << "Please enter suit (0 heart, 1 diamond, 2 spade, 3 club): ";
		cin >> y;

		switch(y) //store y as the enum
		{
			case 0:
				s = Hearts;
				break;
			case 1:
				s = Diamonds;
				break;
			case 2:
				s = Spades;
				break;
			case 3:
				s = Clubs;
				break;
			default:
				cout << "Invaild option, please enter a valid suit." << endl;
				break;
		}
	} while(y < 0 || y > 3);

	d1[a].value = c;
	d1[a].suit = s;
	d1[a].isassigned = true; //mark the card as exempt from function filldeck
}

/*
	Function listdeck
	Purpose: To list the deck
	Preconditions: initdeck, filldeck
	Postconditions: None
*/

void listdeck(Deck d1)
{
	string value, suit;
	for (int a = 0; a < DECK_SIZE; a++)
	{
		switch(d1[a].value) //stores the value to a string for printing
		{
			case Two:
				value = "Two";
				break;
			case Three:
				value = "Three";
				break;
			case Four:
				value = "Four";
				break;
			case Five:
				value = "Five";
				break;
			case Six:
				value = "Six";
				break;
			case Seven:
				value = "Seven";
				break;
			case Eight:
				value = "Eight";
				break;
			case Nine:
				value = "Nine";
				break;
			case Ten:
				value = "Ten";
				break;
			case Jack:
				value = "Jack";
				break;
			case Queen:
				value = "Queen";
				break;
			case King:
				value = "King";
				break;
			case Ace:
				value = "Ace";
				break;
			default:
				cout << "Failure with naming card values" << endl;
				break;
		}
		switch(d1[a].suit) //stores the suit to a string for printing
		{
			case Hearts:
				suit = "Hearts";
				break;
			case Diamonds:
				suit = "Diamonds";
				break;
			case Spades:
				suit = "Spades";
				break;
			case Clubs:
				suit = "Clubs";
				break;
			default:
				cout << "Failure in naming suit" << endl;
				break;
		}
		cout << "Card # " << d1[a].number << " " << value << " of " << suit << endl;
	}
}
