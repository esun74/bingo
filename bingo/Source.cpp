#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "cards.h"
using namespace std;

void usefile();
void calls(deck bingo);

int main()
{
	usefile();
	return 0;
}

// reads in the bingo sheets from a file
void usefile()
{
	system("cls");
	int countcards;
	cout << "How many cards do you have?" << endl;
	cin >> countcards;
	system("cls");
	int thing;
	deck bingo(countcards);
	ifstream infile;
	infile.open("cards.txt");
	if (infile.fail()) cout << "Could not open file!" << endl;
	else
	{
		for (int nthcard = 0; nthcard < countcards; nthcard++)
		{
			int location = 0;
			for (int i = 0; i < 5; i++)
				for (int ii = 0; ii < 5; ii++)
				{
					infile >> thing;
					bingo.write(nthcard, location, thing);
					location++;
				}
		}
	}
	infile.close();
	calls(bingo);
}

// takes the user's input and checks if any of the sheets have the number and whether there is a bingo or not
void calls(deck bingo)
{
	int thing;
	bool winning = false;
	for (;;)
	{
		bingo.check();
		cout << "Enter called number" << endl;
		cin >> thing;
		bingo.mark(thing);
		system("cls");
	}
}