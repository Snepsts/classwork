// Fig. 10.16: fig10_16.c
// MODIFIED BY MICHAEL RANCIGLIO FOR PROBLEM 10.7
// Representing cards with bit fields in a struct
#include <stdio.h>
#include <stdlib.h>
#define CARDS 52

// bitCard structure definition with bit fields
struct bitCard {
	unsigned int face : 4; // 4 bits; 0-15
	unsigned int suit : 2; // 2 bits; 0-3
	unsigned int color : 1; // 1 bit; 0-1
}; // end struct bitCard

typedef struct bitCard Card; // new type name for struct bitCard

void fillDeck( Card * const wDeck ); // prototype
void deal( const Card * const wDeck ); // prototype
void shuffle( Card * const wDeck ); // prototype

int main( void )
{
	Card deck[ CARDS ]; // create array of Cards

	fillDeck( deck );
	shuffle( deck );
	deal( deck );


} // end main

// initialize Cards
void fillDeck( Card * const wDeck )
{
	size_t i; // counter

	// loop through wDeck
	for ( i = 0; i < CARDS; ++i ) {
		wDeck[ i ].face = i % (CARDS / 4);
		wDeck[ i ].suit = i / (CARDS / 4);
		wDeck[ i ].color = i / (CARDS / 2);
	} // end for
} // end function fillDeck

// output cards in two-column format; cards 0-25 subscripted with
// k1 (column 1); cards 26-51 subscripted with k2 (column 2)
void deal( const Card * const wDeck )
{
	size_t k1; // subscripts 0-25
	size_t k2; // subscripts 26-51

	// define color names
	const char *color[2];
	color[0] = "Red";
	color[1] = "Black";

	// define suit names
	const char *suit[4];
	suit[0] = "Hearts";
	suit[1] = "Diamonds";
	suit[2] = "Clubs";
	suit[3] = "Spades";

	// define face names
	const char *face[16];
	face[0] = "Two"; face[1] = "Three"; face[2] = "Four"; face[3] = "Five";
	face[4] = "Six"; face[5] = "Seven"; face[6] = "Eight"; face[7] = "Nine";
	face[8] = "Ten"; face[9] = "Jack"; face[10] = "Queen"; face[11] = "King";
	face[12] = "Ace"; face[13] = ""; face[14] = ""; face[15] = "";

	// loop through wDeck
	for ( k1 = 0, k2 = k1 + 26; k1 < CARDS / 2; ++k1, ++k2 ) {
		printf( "%s %s of %s\t", color[ wDeck[ k1 ].color ], face[ wDeck[ k1 ].face ], suit[ wDeck[ k1 ].suit ] );
		printf( "%s %s of %s\n", color[ wDeck[ k2 ].color ], face[ wDeck[ k2 ].face ], suit[ wDeck[ k2 ].suit ] );
	} // end for
} // end function deal

// shuffle cards
void shuffle( Card * const wDeck )
{
	size_t i; // counter
	size_t j; // variable to hold random value between 0 - 51
	Card temp; // define temporary structure for swapping Cards

	// loop through wDeck randomly swapping Cards
	for ( i = 0; i < CARDS; ++i ) {
		j = rand() % CARDS;
		temp = wDeck[ i ];
		wDeck[ i ] = wDeck[ j ];
		wDeck[ j ] = temp;
	} // end for
} // end function shuffle

/* Output:
Black Ten of Spades	Red Queen of Hearts
Red Two of Hearts	Black Jack of Clubs
Red Seven of Diamonds	Black Five of Clubs
Red Seven of Hearts	Red Eight of Diamonds
Red Four of Hearts	Black Nine of Clubs
Black Eight of Spades	Red Eight of Hearts
Black Ace of Clubs	Red Four of Diamonds
Red Nine of Diamonds	Red King of Hearts
Red Ten of Diamonds	Black Three of Clubs
Black Six of Clubs	Black Seven of Clubs
Red Six of Diamonds	Black Queen of Spades
Black Six of Spades	Black Four of Spades
Black Two of Clubs	Red Queen of Diamonds
Red Five of Hearts	Black King of Spades
Black Eight of Clubs	Red Ten of Hearts
Black Ace of Spades	Black Seven of Spades
Black Jack of Spades	Red Two of Diamonds
Black King of Clubs	Red Nine of Hearts
Black Nine of Spades	Red Jack of Diamonds
Red King of Diamonds	Black Ten of Clubs
Red Five of Diamonds	Red Ace of Diamonds
Red Six of Hearts	Black Two of Spades
Red Jack of Hearts	Red Three of Hearts
Black Four of Clubs	Red Ace of Hearts
Black Five of Spades	Red Three of Diamonds
Black Queen of Clubs	Black Three of Spades
*/
