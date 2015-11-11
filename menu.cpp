#include <iostream>
#include <stdlib.h>
//and all other stuff to be named

using namespace std;
menu :: menu()
{

}
menu :: ~menu()
{

}


int menu :: input()
{
	string userIn;
	int i;
	getline(cin,userIn);
	i = atoi (userIn);
	return i;

}

void menu :: printOptions()
{
	cout << " 1. Print all student and their information " << endl;
	cout << " 2. Print all Faculty and their information " << endl;
	cout << " 3. Find student by ID # " << endl;
	cout << " 4. Find faculty by ID # " << endl;
	cout << " 5. Find student's faculty advisor " << endl;
	cout << " 6. Display advisor's students " << endl;
	cout << " 7. Add a new Student " << endl;
	cout << " 8. Delete a Student " << endl;
	cout << " 9. Add a faculty member " << endl;
	cout << " 10. Delete a faculty member " << endl;
	cout << " 11. Change a student's advisor " << endl;
	cout << " 12. Remove a student from an advisor " << endl;
	cout << " 13. Rollback " << endl;
	cout << " 14. Exit " << endl;

}


int menu :: UserInputs()
{
	cout << "choose an action from the above list" << endl;
	int i = input();
	if (i < 15 && i>0)
		return i;
	else
	{
		UserInputs();
	}	

}

void execute()
{

	// each case refers to a different action, call appropriate methods
	int i = UserInputs();
	switch(i)
	{
		case 1:
		{}
		case 2:
		{}
		case 3:
		{}
		case 4:
		{}
		case 5:
		{}
		case 6:
		{}
		case 7:
		{}
		case 8:
		{}
		case 9:
		{}
		case 10:
		{}
		case 11:
		{}
		case 12:
		{}
		case 13:
		{}
		case 14:
		{}
		default:
		{
			execute();		
		}
	}

}


