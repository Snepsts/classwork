/*
	Author: Michael Ranciglio
	Date: 1/27/2016
	Purpose: To preform various tasks related to structure declaration
*/

#include <iostream>
#include <cstdlib>

using namespace std;

enum Cards {Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack,
	Queen, King, Ace};

enum Suits {Hearts, Diamonds, Spades, Clubs}; //reminder that hearts is 0
											// diamonds is 1, spades 2, clubs 3
struct Card
{
	unsigned int number;
	Cards value;
	Suits suit;
};

const int DECK_SIZE = 52;

typedef Card Deck[DECK_SIZE];

void initdeck(Deck d1);

void filldeck(Deck d1);

bool cardexists(Deck d1, Cards x, Suits y);

void singlecard(Deck d1);

void listdeck(Deck d1);

int main()
{
	Deck d1;

	srand(time(0));

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
	int x, y;

	for (int a = 0; a < DECK_SIZE; a++)
	{
		do {
			x = rand() % 13 + 2;
			y = rand() % 4;
		} while(cardexists(d1, x, y));

		d1[a].value = x;
		d1[a].suit = y;
	}
}

/*
	Function cardexists
	Purpose: To check if the card exists anywhere in the deck already
	Preconditions: Should be called in the fill deck function
	Postconditions: None
*/

bool cardexists(Deck d1, int x, int y)
{
	bool retvar;

	for (int a = 0; a < DECK_SIZE; a++)
	{
		if(d1[a].value == x && d1[a].suit == y)
			retvar = true;
	}

	if(retvar)
		return true;
	else
		return false;
}

/*
	Function singlecard
	Purpose: To fill a single card in the deck
	Preconditions: None
	Postconiditons: Will take up one card slot
*/

void singlecard(Deck d1)
{
	unsigned int x;

	cout << "Which card would you like to fill (1-52)?" << endl;
	cin >> x;
	x = x - 1;

	cout << "Please enter suit (0 heart, 1 diamond, 2 spade, 3 club): ";
	cin >> d1[x].suit;
	cout << "Please enter card value (2-10, 11 jack, 12 queen, 13 king, 14 ace): ";
	cin >> d1[x].value;
}

/*
	Function listdeck
	Purpose: To list the deck
	Preconditions: Deck must be filled
	Postconditions: None
*/

void listdeck(Deck d1)
{
	for (int a = 0; a < DECK_SIZE; a++)
	{
		cout << "Card # " << d1[a].number << " " << d1[a].value << " of " << d1[a].suit << endl;
	}
}
