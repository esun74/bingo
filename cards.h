#ifndef CARDS      
#define CARDS

#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

// the deck represents multiple bingo sheets and the cards represent individual sheets
// hence the naming: a deck of cards
class deck {
public:

	// default constructor
	deck();

	// destructor - I don't implement the rest of the big three since there is no need to copy decks or sheets
	// goes through and destructs all the cards before destructing the deck
	~deck();

	// constructor that specifies how many cards to create in the deck
	deck(int numberofcards);

	// to change a number into a pointer - used to change i into a pointer to the corresponding card
	template <typename T>
	T * numbertopointer(int number);

	// write into the cards - specifies the card number, the location, and the number to insert (overwrites the original number)
	void write(int nthcard, int location, int number);

	// prints out all cards in the deck
	void print();

	// checks all cards in the deck for a bingo
	void check();

	void patterncheck(bool *pattern);

	// searches all cards in the deck for the number "mark" and flips the corresponding bool 
	void mark(int mark);

	

	// clears all 
	void clear();

	// the individual bingo sheets
	class cards {
	public:
		// constructs a blank sheet - 25 zeros 
		cards();

		// destructs the card - deletes numbers and called
		~cards();

		// writes in to the individual card
		void cardwrite(int location, int number);

		// prints the card
		void cardprint();

		// checks the card
		bool cardcheck();

		bool cardcheckpattern(bool *pattern);

		// searches the card and marks it if found
		void cardmark(int mark);

		// clears the card
		void cardclear();

	private:

		// array of 25 integers - forms a 5 x 5 bingo sheet
		int *numbers;

		// array of 25 bools - is true when the corresponding number on the bingo sheet has been called
		bool *called;
	};
private:

	// keeps track of the number of cards in the deck
	int cardcount;

	

	// array of cards - size specified by user, 1 by default
	cards *data;
};

#endif