#include "cards.h"

cards::cards()
{
	this->clear();
}

cards::~cards()
{
	//delete[] numbers;
	//delete[] called;
}

void cards::write(int location, int number)
{
	this->numbers[location] = number;
	this->called[location] = false;
}
void cards::print()
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
bool cards::check()
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
void cards::mark(int mark)
{
	for (int i = 0; i < 25; i++)
		if (this->numbers[i] == mark)
			this->called[i] = true;
}
void cards::clear()
{
	for (int i = 0; i < 25; i++)
	{
		this->numbers[i] = 0;
		this->called[i] = false;
	}
}
