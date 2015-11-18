#ifndef DATABASE_H_
#define DATABASE_H_
#include <iostream>
#include "Student.h"
#include "Faculty.h"
#include "Database.h"


using namespace std;

class Menu
{
	public:
		Menu();
		~Menu();
		int input();
		void printOptions();
		int UserInputs();
		void execute();
		Database d;
		string holder;

};


#endif
