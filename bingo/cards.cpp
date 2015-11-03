#include "cards.h"

// creates a deck with one card as the default constructor
deck::deck()
{
	this->data = new cards[1];
	cardcount = 1;
}

// destructs the deck - don't need to destruct arrays?
deck::~deck()
{
	//for (int i = 0; i < cardcount; i++)
		//this->numbertopointer<cards>(i)->~cards();
	//delete[] data;
}

// creates "numberofcards" cards in the deck
deck::deck(int numberofcards)
{
	this->data = new cards[numberofcards];
	cardcount = numberofcards;
}

// makes a pointer which copies the pointer in the deck pointing to the card we want
// using a template because if I use cards * deck::numbertopointer(int number) it says that "identifier 'cards' is unidentified"
// might be weird but it works
template <typename T>
T * deck::numbertopointer(int number)
{
	T *cardpoint = (this->data + number);
	return cardpoint;
}

// creates the card and sets 25 zeroes in it
deck::cards::cards()
{
	this->numbers = new int[25];
	this->called = new bool[25];
	this->cardclear();
}

// destructs the card - don't need to destruct arrays?
deck::cards::~cards()
{
	//delete[] this->numbers;
	//delete[] this->called;
}

// basically uses cardwrite on the nth card
void deck::write(int nthcard, int location, int number)
{
	this->numbertopointer<cards>(nthcard)->cardwrite(location, number);
}

// prints all cards
void deck::print()
{
	for (int i = 0; i < this->cardcount; i++)
		this->numbertopointer<cards>(i)->cardprint();
}

// checks all cards - if any check is true, then there is a bingo
bool deck::check()
{
	bool bingo = false;
	for (int i = 0; i < this->cardcount; i++)
		if (this->numbertopointer<cards>(i)->cardcheck())
			bingo = true;
	return bingo;
}

// uses cardmark on all cards
void deck::mark(int mark)
{
	for (int i = 0; i < this->cardcount; i++)
		this->numbertopointer<cards>(i)->cardmark(mark);
}

// uses cardclear on all cards
void deck::clear()
{
	for (int i = 0; i < this->cardcount; i++)
		this->numbertopointer<cards>(i)->cardclear();
}

// overwrites "location" in the int array with "number" basically
void deck::cards::cardwrite(int location, int number)
{
	this->numbers[location] = number;
	this->called[location] = false;
}

// prints the sheet numbers and the bool side by side
void deck::cards::cardprint()
{
	for (int i = 0; i < 25; i++)
	{
		cout << left << setw(5) << this->numbers[i];
		if ((i + 1) % 5 == 0) 
		{
			cout << "               ";
			for (int ii = 0; ii < 5; ii++)
			{
				if (!this->called[i + ii - 4]) 
					cout << left << setw(5) << "O"; 
				else 
					cout << left << setw(5) << "X";
			}
			cout << endl;
		}
	}
	cout << endl;
}

// checks the card to see if there are any winning rows, columns, or diagonals
bool deck::cards::cardcheck()
{
	bool call = false;
	this->called[12] = true;
	for (int i = 0; i < 5; i++)
	{
		call = 
			  (this->called[i + 00] 
			&& this->called[i + 05] 
			&& this->called[i + 10]
			&& this->called[i + 15]
			&& this->called[i + 20])
			|| 
			  (this->called[i * 5 + 0]
			&& this->called[i * 5 + 1]
			&& this->called[i * 5 + 2]
			&& this->called[i * 5 + 3]
			&& this->called[i * 5 + 4])
			? true : false; 
		if (call) return true;
	}
	call = 
		  (this->called[0]
		&& this->called[6]
		&& this->called[12]
		&& this->called[18]
		&& this->called[24])
		|| 
		  (this->called[4]
		&& this->called[8]
		&& this->called[12]
		&& this->called[16]
		&& this->called[20])
		? true : false;
	return call;
}

// goes through the array to see if any is equal to "mark" - if it is, change the bool to true
void deck::cards::cardmark(int mark)
{
	for (int i = 0; i < 25; i++)
		if (this->numbers[i] == mark)
			this->called[i] = true;
}

// overwrites all numbers to 0 and bools to false in this card
void deck::cards::cardclear()
{
	for (int i = 0; i < 25; i++)
	{
		this->numbers[i] = 0;
		this->called[i] = false;
	}
}