#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <list>
#include "cards.h"
using namespace std;

void usefile();
void normalcalls(deck bingo);
void abnormalcalls(deck bingo);

int main()
{
	usefile();
	return 0;
}

// reads in the bingo sheets from a file
void usefile()
{
	system("cls");
	int countcards, thing;
	cout << "How many cards do you have?" << endl;
	cin >> countcards;
	system("cls");
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
	char reply;
	do {
		cout << "Is it normal bingo? Y/N" << endl;
		cin >> reply;
		if (toupper(reply) == 'Y')
			normalcalls(bingo);
		else if (toupper(reply) == 'N')
			abnormalcalls(bingo);
	} while (toupper(reply) != 'Y' && toupper(reply) != 'N');
}

// takes the user's input and checks if any of the sheets have the number and whether there is a bingo or not
void normalcalls(deck bingo)
{
	int thing;
	for (;;)
	{
		bingo.check();
		cout << "Enter called number" << endl;
		cin >> thing;
		bingo.mark(thing);
		system("cls");
	}
}

void abnormalcalls(deck bingo)
{
	int temp;
	bool *pattern = new bool[25];
	cout << "Enter pattern (0/1)" << endl;
	for (int i = 0; i < 25; i++)
	{
		cin >> temp;
		pattern[i] = static_cast<bool>(temp);
	}
	int thing;
	for (;;)
	{
		bingo.patterncheck(pattern);
		cout << "Enter called number" << endl;
		cin >> thing;
		bingo.mark(thing);
		system("cls");
	}
}