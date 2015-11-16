#include <iostream>
#include <stdlib.h>
#include "Database.h"

using namespace std

Database :: Database()
{
	studentTable = new BinarySearchTree<Student*>();

	facultyTable = new BinarySearchTree<Faculty*>();
}

Database :: ~Database()
{
	
}

void Database :: PrintAllStu()
{
	// Runs through and prints students in order of ID# least to greatest
	if (studentTable.getSize() = 0)
	{
		cout << "you dont have any students" << endl;
	}
	else
	{
		studentTable->print();
	}
}

void Database :: PrintAllFac()
{
	// Runs through and prints faculty in order of ID# least to greatest
	if (facultyTable.getSize() = 0)
	{
		cout << "This is mayhem there are no advisors"
	}
	else
	{
		facultyTable->print();
	}
}

int Database :: FindStu(int stuID)
{
	// Finds a student by their ID #
	s = studentTable->search(stuID);
	operator << (cout,s);
	
}

int Database :: FindFac(int facID)
{
	//Finds a Faculty by their ID#
	f = facultyTable->search(facID);
	operator << (cout, f);
}

int Database :: AddStu()
{
	//creates a new student and adds them to the BST
	string holder;
	string stuName;
	int stuID;
	double stuGPA;
	string stuYear;
	string stuMajor;
	int advID;

	cout<< "What is the student's name?" << endl;
	getline(cin,stuName);
	
	cout<< "What is the student's ID number?" << endl;
	getline(cin,holder)
	stuID = atoi(holder.c_str());
	
	cout << "What is the student's GPA?" << endl;
	getline(cin,holder)
	stuGPA = atof(holder.c_str());

	cout << "What year is the student?" << endl;
	getline(cin,stuYear);

	cout << "What is the student's major" << endl;
	getline(cin,stuMajor);

	cout << "What is the student's advisor's ID number?" << endl;
	getline(cin,holder);
	advID = atoi(holder.c_str());
	
	Student *s = new Student(stuName, stuID, stuGPA, stuYear, stuMajor, advID);
	studentTable->add(s);
	cout << "hey (after add)" << endl; //will add s, but will not make s the root.............
	studentTable->print();
	return 1;
	//Rollback
}

int Database :: DeleteStu(int stuID)
{
	// finds a student by their ID number and deletes them from the tree
	s = studentTable -> search(stuID);
	studentTable->remove(s);
	return 1;
	//Rollback
}

int Database :: AddFac()
{
	//creates a new faculty and adds them to the BST
	string holder;
	string facName;
	int facID;
	string facLevel
	string facDepartment;
	DLinkedList<int>* adviseeList;
	int adviseeID
	

	cout<< "What is the faculty member's name?" << endl;
	getline(cin,facName);
	
	cout<< "What is the faculty member's ID number?" << endl;
	getline(cin,holder)
	facID = atoi(holder.c_str());
	
	cout << "What is the faculty member's level?" << endl;
	getline(cin,facLevel)

	cout << "What deparment is the faculty member in?" << endl;
	getline(cin,facDepartment);
	
	cout << "What are the ID numbers of the faculty member's advisees? (after each number hit enter)" << endl;
	bool check = true;
	while(getline(cin,holder))
	{
		adviseeID = atoi(holder.c_str());
		adviseeList->insertFront(adviseeID);
				
	}
	
	
	Faculty *f = new Faculty(facName, facID, facLevel, facDepartment, adviseeList);
	facultyTable->add(f);
	cout << "hey (after add)" << endl; //will add s, but will not make s the root.............
	facultyTable->print();
	return 1;
	//Rollback
}

int Database :: DeleteFac(int facID, advTransferID)
{
	// finds a faculty by their ID # and deletes them form the tree, takes there advisees and gives
	// them to another faculty member
	F = facultyTable->search(facID);
	facultyTable->remove(F);
	//advTransfer = facultyTable->search(advTransferID);
	//find one ID front F advisee list
	ChangeStuAdvisor(frontID, advTransferID);
	facultyTable->remove();
	return 1;
	//Rollback
}


int Database :: ChangeStuAdvisor(int stuID, int facID)
{
	//finds a student by ID, removes student from their advisor, finds a new advisor by ID,
	//adds the student to the new advisor 
	s = studentTable -> search(stuID);
	newF = facultyTable -> search(facID);
	if(s.getAdvisor() != NULL)
	{
		RemoveAdvisee(stuID)
		
	}
	newF->addToAdviseeList(stuID);
	
	// if the student has no advisor, it skips the second step

	//Rollback
}

int Database :: RemoveAdvisee(int stuID)
{
	//finds a student by ID, removes them from their advisor
	oldF = facultyTable -> search(s.getAdvisor());
	oldF->deleteFromAdviseeList(stuID);
	// is the faculty ID necessary?

	//Rollback
}

int Database :: Rollback()
{
	// takes back the last action that changed the tree up to five times

}

int Database :: Exit()
{
	//maybe not needed here, could do this in Menu with break
}
