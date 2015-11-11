#include <iostream>
#include "Student.h"
#include "Faculty.h"

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

};
