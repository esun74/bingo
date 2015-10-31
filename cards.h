#ifndef CARDS      
#define CARDS

#include <iostream>
#include <iomanip>
#include <cstring>
#include <list>
using namespace std;

class deck {
public:
	deck();
	~deck();
	deck(int numberofcards);

	void write(int nthcard, int location, int number);
	void print();
	bool check();
	void mark(int mark);
	void clear();

	template <typename T>
	T * numbertopointer(int number);

private:
	int cardcount;
	class cards {
	public:
		cards();
		~cards();
		void cardwrite(int location, int number);
		void cardprint();
		bool cardcheck();
		void cardmark(int mark);
		void cardclear();

	private:
		int *numbers;
		bool *called;
	};
	cards *data;
};

#endif
