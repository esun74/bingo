#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "cards.h"
using namespace std;

void usefile();
void userentry();
void calls(deck bingo);

int main()
{
	char input;
	cout << "Do you want to use a file? Y/N" << endl;
	cin >> input;

	if (toupper(input) == 'Y')
		usefile();
	else
		userentry();
	return 0;
}

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
	if (infile.fail())
	{
		cout << "Could not open file!" << endl;
		userentry();
	}
		
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

void userentry()
{
	system("cls");
	int countcards;
	cout << "How many cards do you have?" << endl;
	cin >> countcards;
	system("cls");
	deck bingo(countcards);
	int thing, location = 0;
	cout << "Enter card numbers" << endl;
	for (int nthcard = 0; nthcard < countcards; nthcard++)
	{
		for (int i = 0; i < 5; i++)
		{
			bingo.print();
			cout << "Enter line " << i + 1 << endl;
			for (int ii = 0; ii < 5; ii++)
			{
				cin >> thing;
				bingo.write(nthcard, location, thing);
				location++;
			}
			system("cls");
		}
	}
	calls(bingo);
}

void calls(deck bingo)
{
	int thing;
	bool winning = false;
	while (!winning)
	{
		bingo.print();
		cout << "Enter called number" << endl;
		cin >> thing;
		bingo.mark(thing);
		system("cls");
		winning = bingo.check();
	}
	bingo.print();
	cout << "BINGO!!!" << endl;
	char response;
	cout << "Do you want to play again? Y/N" << endl;
	cin >> response;
	if (toupper(response) == 'Y')
	{
		bingo.~deck();
		main();
	}
}
