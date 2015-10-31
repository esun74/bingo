#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
#include "cards.h"
using namespace std;

void usefile();
void userentry();
void calls(cards data);

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
	int thing;
	cards data;
	ifstream infile;
	infile.open("cards.txt");
	if (infile.fail())
		cout << "Could not open file!" << endl;
	else
	{
		int location = 0;
		for (int i = 0; i < 5; i++)
			for (int ii = 0; ii < 5; ii++)
			{
				infile >> thing;
				data.write(location, thing);
				location++;
			}
	}
	infile.close();
	calls(data);
}

void userentry()
{
	system("cls");
	cards data;
	int thing, location = 0;
	cout << "Enter card numbers" << endl;
	for (int i = 0; i < 5; i++)
	{
		data.print();
		cout << "Enter line " << i + 1 << endl;
		for (int ii = 0; ii < 5; ii++)
		{
			cin >> thing;
			data.write(location, thing);
			location++;
		}
		system("cls");
	}
	calls(data);
}

void calls(cards data)
{
	int thing;
	bool winning = false;
	while (!winning)
	{
		data.print();
		cout << "Enter called number" << endl;
		cin >> thing;
		data.mark(thing);
		system("cls");
		winning = data.check();
	}
	data.print();
	cout << "BINGO!!!" << endl;
}
