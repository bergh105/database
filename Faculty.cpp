#include "Faculty.h"
#include <iostream>
#include <string>

using namespace std;

string Faculty::getName() {
	return name;
}

int Faculty::getID() {
	return ID;
}

string Faculty::getLevel() {
	return level;
}

string Faculty::getDepartment() {
	return department;
}

void Faculty::setName(string n) {
	name = n;
}

void Faculty::setID(int id) {
	ID = id;
}

void Faculty::setLevel(string l) {
	level = l;
}

void Faculty::setDepartment(string d) {
	department = d;
}

void Faculty::addToAdviseeList(int id) {
	adviseeList->insertBack(id);
}

//Operator Overloaders:
bool Faculty::operator <(const Faculty& fac) {
	if(ID > fac.ID) {
		return true;
	}
	return false;
}

bool Faculty::operator >(const Faculty& fac) {
	if(ID < fac.ID) {
		return true;
	}
	return false;
}

bool Student::operator ==(const Faculty& fac) {
	if(ID == fac.ID) {
		return true;
	}
	return false;
}

ostream& operator<<(ostream& os, Faculty *obj) {
	cout << obj->name << "\n" << obj->ID << "\n" << obj->level << "\n" << obj->department << endl;
	return os;
}
//doesnt actually work..
