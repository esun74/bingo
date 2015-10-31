#ifndef CARDS      
#define CARDS

#include <iostream>
#include <iomanip>
#include <cstring>
#include <list>
using namespace std;
class cards {
public:
	cards();

	void write(int location, int number);
	void print();
	bool check();
	void mark(int mark);
	void clear();  

private:
	int *numbers = new int[25];
	bool *called = new bool[25];
};


#endif
