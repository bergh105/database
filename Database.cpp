#include <iostream>
#include <stdlib.h>
#include <string>
#include "Database.h"
#include "Student.h"
#include "Faculty.h"
#include "BinaryTree.h"
#include "GenStack.h"

using namespace std;

Database :: Database()
{
	studentTable = new BinarySearchTree<Student>();
	studentRollStack = new GenStack<BinarySearchTree<Student>>(5);
	facultyTable = new BinarySearchTree<Faculty>();
	facultyRollStack = new GenStack<BinarySearchTree<Faculty>(5);
}

Database :: ~Database()
{
	
}

void Database :: PrintAllStu()
{
	// Runs through and prints students in order of ID# least to greatest
	if (studentTable->getSize() == 0)
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
	if (facultyTable->getSize() == 0)
	{
		cout << "This is mayhem there are no advisors" << endl;
	}
	else
	{
		facultyTable->print();
	}
}

int Database :: FindStu(int stuID)
{
	// Finds a student by their ID #
	Student s; 
	s.setID(stuID);
	Student S = studentTable->search(s);
	cout << S << endl; //fixed operator overloaders, this should work now. if not, use next line
	//operator << (cout,s);
	return 1;
	
}

int Database :: FindFac(int facID)
{
	//Finds a Faculty by their ID#
	Faculty f;
	f.setID(facID);
	Faculty F = facultyTable->search(f);
	cout << F << endl; //fixed overloader, this should work now
	//operator << (cout, f);
	return 1;
}

int Database :: FindFacByStu(int stuID)
{
	Student s; 
	s.setID(stuID);
	Student S = studentTable->search(s);
	FindFac(S.getAdvisor());
	
}

int Database :: FindStusByFac(int facID)
{
	Faculty f;
	f.setID(facID);
	Faculty F = facultyTable->search(f);
	
	int i = F.deleteFromAdviseeList();
	if( i!=0)
	{	
		FindStu(i);
	}
	else
	{
		cout << "there is an issue, that faculty has no advisees" << endl;
	}
	while(i!=0)
	{
		FindStu(i);
	}
}

int Database :: AddStu()
{
	//creates a new student and adds them to the BST
	studentRollStack.push(studentTable);
	facultyRollStack.push(facultyTable); // rollback


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
	getline(cin,holder);
	stuID = atoi(holder.c_str());
	
	cout << "What is the student's GPA?" << endl;
	getline(cin,holder);
	stuGPA = atof(holder.c_str());

	cout << "What year is the student?" << endl;
	getline(cin,stuYear);

	cout << "What is the student's major" << endl;
	getline(cin,stuMajor);

	cout << "What is the student's advisor's ID number?" << endl;
	getline(cin,holder);
	advID = atoi(holder.c_str());
	
	//Student *s = new Student(stuName, stuID, stuGPA, stuYear, stuMajor, advID);
	Student s(stuName, stuID, stuGPA, stuYear, stuMajor, advID); // because cant be a BST of pointers anymore
	studentTable->add(s);
	ChangeStudentAdvisor(stuID, advID);
	return 1;
	//Rollback
}



int Database :: DeleteStu(int stuID)
{
	// finds a student by their ID number and deletes them from the tree

	studentRollStack.push(studentTable);
	facultyRollStack.push(facultyTable); // rollback
	
	Student s; 
	s.setID(stuID);
	Student S = studentTable->search(s);
	studentTable->remove(S);
	RemoveAdvisee(stuID);
	return 1;
	// remove student from advisor
	//Rollback
}

int Database :: AddFac()
{
	//creates a new faculty and adds them to the BST

	studentRollStack.push(studentTable);
	facultyRollStack.push(facultyTable); // rollback

	string holder;
	string facName;
	int facID;
	string facLevel;
	string facDepartment;
	DLinkedList<int>* adviseeList;
	int adviseeID;
	

	cout<< "What is the faculty member's name?" << endl;
	getline(cin,facName);
	
	cout<< "What is the faculty member's ID number?" << endl;
	getline(cin,holder);
	facID = atoi(holder.c_str());
	
	cout << "What is the faculty member's level?" << endl;
	getline(cin,facLevel);

	cout << "What deparment is the faculty member in?" << endl;
	getline(cin,facDepartment);
	
	cout << "What are the ID numbers of the faculty member's advisees? (after each number hit enter)" << endl;
	bool check = true;
	while(getline(cin,holder))
	{
		adviseeID = atoi(holder.c_str());
		ChangeStudentAdivor(adviseeID, facID);
		adviseeList->insertFront(adviseeID);
				
	}
	
	
	//Faculty *f = new Faculty(facName, facID, facLevel, facDepartment, adviseeList);
	Faculty f(facName, facID, facLevel, facDepartment, adviseeList);
	facultyTable->add(f);
	return 1;
	//Rollback
}

int Database :: DeleteFac(int facID, int advTransferID)
{
	// finds a faculty by their ID # and deletes them from the tree, takes their advisees and gives
	// them to another faculty member

	studentRollStack.push(studentTable);
	facultyRollStack.push(facultyTable); // rollback

	Faculty f;
	f.setID(facID);
	Faculty F = facultyTable->search(f);
	facultyTable->remove(F);
	f.setID(advTransferID);
	Faculty advTransfer = facultyTable->search(f);
	while(F.getAdviseeListSize() != 0)
	{
		int frontID = F.deleteFromAdviseeList()	;	
		ChangeStuAdvisor( frontID, advTransferID);
		
		
	}	
	facultyTable->remove(F);
	return 1;
	//Rollback
}

int Database :: RemoveAdvisee(int stuID)
{
	//finds a student by ID, removes them from their advisor

	studentRollStack.push(studentTable);
	facultyRollStack.push(facultyTable); // rollback

	Student s; 
	s.setID(stuID);
	Student S = studentTable->search(s);
	Faculty f;
	f.setID(S.getAdvisor());
	Faculty F = facultyTable->search(f);
	Faculty oldF = facultyTable -> search(F);
	oldF.deleteFromAdviseeList(stuID);
	// is the faculty ID necessary?

	//Rollback
}

int Database :: ChangeStuAdvisor(int stuID, int facID)
{
	//finds a student by ID, removes student from their advisor, finds a new advisor by ID,
	//adds the student to the new advisor 

	studentRollStack.push(studentTable);
	facultyRollStack.push(facultyTable); // rollback

	Student s; 
	s.setID(stuID);
	Student S = studentTable->search(s);
	
	Faculty f;
	f.setID(S.getAdvisor());
	Faculty newF = facultyTable->search(f);
	if(s.getAdvisor() != NULL)
	{
		RemoveAdvisee(stuID);
		
	}
	S.setAdvisor(facID);
	newF.addToAdviseeList(stuID);
	
	// if the student has no advisor, it skips the second step

	//Rollback
}



int Database :: Rollback()
{
	// takes back the last action that changed the tree up to five times
	if(!studentRollStack.isEmpty())
	{
		studentTable = studentRollStack.pop();
		facultyTable = facultyRollStack.pop();
	}
	else
	{
		cout << "Rollback unavaialbe, either you haven't changed anything or you really screwed up" << endl;

	}

}

int Database :: Exit()
{
	//maybe not needed here, could do this in Menu with break
}

void Database::serializeStudents(string outFile) {
	ofstream myfile(outFile, ios::out | ios::trunc | ios::binary);

	if (!myfile.is_open()) {
		cout << "Error opening file." << endl;
	}
	else {
		GenQueue<TreeNode<Student>*> *q;
		q = studentTable->bfs();

		TreeNode<Student>* current;

		while(!q->isEmpty()) {
			cout << "begin while loop" << endl;
			//access first Node in queue
			current = q->remove();

			//write Student attributes from current node (from front of queue) to binary file
			//write string to match read string
			unsigned len;

			string n = current->data.getName();
			cout << "write attr to file:" << endl;
			len = n.size();
			myfile.write(reinterpret_cast<const char*>(&len), sizeof(len));
			myfile.write(n.c_str(), len);

			int i = current->data.getID();
			cout << "write attr to file:" << endl;
			myfile.write(reinterpret_cast<const char*>(&i), sizeof(int));

			double g = current->data.getGPA();
			cout << "write attr to file:" << endl;
			myfile.write(reinterpret_cast<const char*>(&g), sizeof(double));

			string l = current->data.getLevel();
			cout << "write attr to file:" << endl;
			len = l.size();
			myfile.write(reinterpret_cast<const char*>(&len), sizeof(len));
			myfile.write(l.c_str(), len);

			string m = current->data.getMajor();
			cout << "write attr to file:" << endl;
			len = m.size();
			myfile.write(reinterpret_cast<const char*>(&len), sizeof(len));
			myfile.write(m.c_str(), len);

			int a = current->data.getAdvisor();
			cout << "write attr to file:" << endl;
			myfile.write(reinterpret_cast<const char*>(&a), sizeof(int));
		}
		
		myfile.close();
	}
}

BinarySearchTree<Student>* Database::deserializeStudents(string inFile) {
	studentTable = new BinarySearchTree<Student>();
	ifstream file(inFile, ios::in | ios::binary);

	if(!file.is_open()) {
		cout << "error opening file." << endl;
	}
	else {
		cout << "deserialize:" << endl;
		// THE CODE REPEATS THE WHILE LOOP one extra time, without inputting any of the strings only numbers. while loop runs 4x
		int c = file.peek();
		while(c != EOF) { 
			string tName, tLevel, tMajor;
			int tID, tAdv;
			double tGPA;
			cout << "read in & add to studentTable -- name, id, gpa, level, major, advisor id: " << endl;
			//get length of name string in file -- file.read((char*)&tName, sizeof(string));
			unsigned len;
			file.read(reinterpret_cast<char*>(&len), sizeof(len));
			if(len >0){
				char* buffer = new char[len];
				file.read(buffer, len);
				tName.append(buffer, len);
				delete[] buffer;
			}
			cout << tName << ", ";

			file.read((char*)&tID, sizeof(int));
			cout << tID << ", ";
			file.read((char*)&tGPA, sizeof(double));
			cout << tGPA << ", ";

			
			file.read(reinterpret_cast<char*>(&len), sizeof(len));
			if(len >0){
				char* buffer = new char[len];
				file.read(buffer, len);
				tLevel.append(buffer, len);
				delete[] buffer;
			}
			cout << tLevel << ", ";

			
			file.read(reinterpret_cast<char*>(&len), sizeof(len));
			if(len >0){
				char* buffer = new char[len];
				file.read(buffer, len);
				tMajor.append(buffer, len);
				delete[] buffer;
			}
			cout << tMajor << ", ";

			file.read((char*)&tAdv, sizeof(int));
			cout << tAdv << endl;

			Student s(tName, tID, tGPA, tLevel, tMajor, tAdv);
			//make sure that the program initializes studentTable to empty every time so that
			//this function does not just add the same students in again, but reloads the old table.
			studentTable->add(s);
			c = file.peek();
		}
	}
	file.close();

	cout << "new student table: " << endl;
	studentTable->print();
	return studentTable;
}
