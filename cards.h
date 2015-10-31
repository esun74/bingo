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
	~cards();
	void write(int location, int number);
	void print();
	bool check();
	void mark(int mark);
	void clear();  

private:
	int *numbers = new int[30];
	bool *called = new bool[30];
};


#endif
