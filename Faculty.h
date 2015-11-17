#ifndef FACULTY_H_
#define FACULTY_H_
#include "ListNode.h"
#include <string>

using namespace std;


class Faculty {
public:	
	DLinkedList<int>* adviseeList;

	Faculty();

	Faculty(string n, int i, string l, string d, DLinkedList<int>* a) {
		name = n;
		ID = i;
		level = l;
		department = d;
		adviseeList = a;
	}

	~Faculty();

	//accessors
	string getName();
	int getID();
	string getLevel();
	string getDepartment();
	int getAdviseeListSize();

	//mutators
	void setName(string n);
	void setID(int id);
	void setLevel(string l);
	void setDepartment(string d);

	void addToAdviseeList(int id);
	int deleteFromAdviseeList(int id);
	int deleteFromAdviseeList();

	//operator overloaders
	bool operator <(const Faculty& s);
	bool operator >(const Faculty& s);
	bool operator ==(const Faculty& s);
	friend ostream& operator <<(ostream& os, Faculty obj); 

private:
	int ID;
	string name;
	string level;
	string department;
	
};

#endif 
