#ifndef FACULTY_H_
#define FACULTY_H_
#include "listnode.h"
#include <string>

using namespace std;

class Faculty {
public:	
	DLinkedList<int>* adviseeList;

	Faculty() {}
	~Faculty() {}

	//accessors
	string getName();
	int getID();
	string getLevel();
	string getDepartment();

	//mutators
	void setName(string n);
	void setID(int id);
	void setLevel(string l);
	void setDepartment(string d);

	void addToAdviseeList(int id);
	void deleteFromAdviseeList(int id);

	//operator overloaders
	bool operator <(const Faculty& fac);
private:
	int ID;
	string name;
	string level;
	string department;
	
};

#endif 
