#include <iostream>
#include "Database.h"

using namespace std

Database :: Database()
{
	// Creates the BST
}

Database :: ~Database()
{
	//Destroys BST
}

void Database :: PrintAllStu()
{
	// Runs through and prints students in order of ID# least to greatest
}

void Database :: PrintAllFac()
{
	// Runs through and prints faculty in order of ID# least to greatest
}

int Database :: FindStu(int stuID)
{
	// Finds a student by their ID #
}

int Database :: FindFac(int facID)
{
	//Finds a Faculty by their ID#
}

int Database :: AddStu()
{
	//creates a new student and adds them to the BST
	//Rollback
}

int Database :: DeleteStu(int stuID)
{
	// finds a student by their ID number and deletes them from the tree
	//Rollback
}

int Database :: AddFac()
{
	//creates a new faculty and adds them to the BST
	//Rollback
}

int Database :: DeleteFac(int facID)
{
	// finds a faculty by their ID # and deletes them form the tree
	//Rollback
}

int Database :: ChangeStuAdvisor(int stuID, int facID)
{
	//finds a student by ID, removes student from their advisor, finds a new advisor by ID,
	//adds the student to the new advisor 

	//Rollback
}

int Database :: RemoveAdvisee(int stuID, int facID)
{
	//finds a student by ID, removes them from their advisor
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
