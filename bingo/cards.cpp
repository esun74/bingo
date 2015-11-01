#include "cards.h"


deck::deck()
{
	this->data = new cards[1];
	cardcount = 1;
}

deck::~deck()
{
	delete[] data;
}

deck::deck(int numberofcards)
{
	this->data = new cards[numberofcards];
	cardcount = numberofcards;
}
deck::cards::cards()
{
	this->numbers = new int[30];
	this->called = new bool[30];
	this->cardclear();
}

template <typename T>
T * deck::numbertopointer(int number)
{
	T *cardpoint = (this->data + number);
	return cardpoint;
}

void deck::write(int nthcard, int location, int number)
{
	this->numbertopointer<cards>(nthcard)->cardwrite(location, number);
}
void deck::print()
{
	for (int i = 0; i < this->cardcount; i++)
		this->numbertopointer<cards>(i)->cardprint();
}
bool deck::check()
{
	bool bingo = false;
	for (int i = 0; i < this->cardcount; i++)
		if (this->numbertopointer<cards>(i)->cardcheck())
			bingo = true;
	return bingo;
}
void deck::mark(int mark)
{
	for (int i = 0; i < this->cardcount; i++)
		this->numbertopointer<cards>(i)->cardmark(mark);
}
void deck::clear()
{
	for (int i = 0; i < this->cardcount; i++)
		this->numbertopointer<cards>(i)->cardclear();
}

void deck::cards::cardwrite(int location, int number)
{
	this->numbers[location] = number;
	this->called[location] = false;
}
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
void deck::cards::cardmark(int mark)
{
	for (int i = 0; i < 25; i++)
		if (this->numbers[i] == mark)
			this->called[i] = true;
}
void deck::cards::cardclear()
{
	for (int i = 0; i < 25; i++)
	{
		this->numbers[i] = 0;
		this->called[i] = false;
	}
}