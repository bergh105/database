#include <iostream>
#include <stdlib.h>
#include "Menu.h"
#include "Database.h"

using namespace std;
Menu :: Menu()
{
	
}
Menu :: ~Menu()
{

}


int Menu :: input()
{
	string userIn;
	int i;
	getline(cin,userIn);
	i = atoi (userIn.c_str());
	return i;

}

void Menu :: printOptions()
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


int Menu :: UserInputs()
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

void Menu :: execute()
{

	// each case refers to a different action, call appropriate methods
	int i = UserInputs();
	switch(i)
	{
		case 1:
		{//print all students
			d.PrintAllStu();
		}
		case 2:
		{//print all fac
			d.PrintAllFac();
		}
		case 3:
		{
		//find stu
			cout<< "What is the ID number of the student you are looking for?" << endl;
			getline(cin,holder);
			d.FindStu(atoi(holder.c_str()));
		}
		case 4:
		{
			cout<< "What is the ID number of the faculty you are looking for?" << endl;
			getline(cin,holder);
			d.FindFac(atoi(holder.c_str()));
		}
		case 5:
		{
			cout<<"What is the student's ID number?"<<endl;
			getline(cin,holder);
			d.FindFacByStu(atoi(holder.c_str()));
		}
		case 6:
		{
			cout << "What is the Faculty's ID number?" << endl;
			getline(cin,holder);
			d.FindStusByFac(atoi(holder.c_str()));
		}
		case 7:
		{
			d.AddStu();
		}
		case 8:
		{
			cout << "What is the student's ID number?" << endl;
			getline(cin,holder);
			d.DeleteStu(atoi(holder.c_str()));
		}
		case 9:
		{
			d.AddFac();
		}
		case 10:
		{
			cout << "What is the ID number of the faculty?" << endl;
			string advTransfer;
			getline(cin,holder);
			cout << "What is the ID number of the faculty who is taking on the advisees?" << endl;
			getline(cin,advTransfer);
			d.DeleteFac(atoi(holder.c_str()),atoi(advTransfer.c_str()));
		}
		case 11:
		{
			string facID;
			cout << "What is the ID number of the student?" << endl;
			getline(cin,holder);
			cout << "What is the ID number of their new advisor?" << endl;
			getline(cin,facID);
			d.ChangeStuAdvisor(atoi(holder.c_str()),atoi(facID.c_str()));
		}
		case 12:
		{
			cout << "What is the ID number of the student?" << endl;	
			getline(cin,holder);
			d.RemoveAdvisee(atoi(holder.c_str()));
		}
		case 13:
		{
			//ROLLBACK
		}
		case 14:
		{
			//SAVE AND EXIT
		}
		default:
		{
			execute();		
		}
	}

}









