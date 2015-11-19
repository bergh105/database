#include "Faculty.h"
#include <iostream>
#include <string>

using namespace std;

Faculty :: Faculty()
{
	name = "John Doe";
	ID = 0;
	level = "Low";
	department = "Comm";
	
	
}

Faculty :: ~Faculty()
{}

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

int Faculty :: getAdviseeListSize()
{
	return adviseeList.getSize();
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

int Faculty:: deleteFromAdviseeList(int id)
{
	if(adviseeList.getSize()==0)
	{
		return 0;
	}	
	else
	{
		return adviseeList->remove(id);
	}

}

int Faculty:: deleteFromAdviseeList()
{
	if(adviseeList.getSize()==0)
	{
		return 0;
	}	
	else
	{
		return adviseeList->removeFront();
	}
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

bool Faculty::operator ==(const Faculty& fac) {
	if(ID == fac.ID) {
		return true;
	}
	return false;
}

bool Faculty::operator !=(const Faculty& fac) {
	if(ID != fac.ID) {
		return true;
	}
	return false;
}


ostream& operator<<(ostream& os, Faculty *obj) {
	cout << obj->name << "\n" << obj->ID << "\n" << obj->level << "\n" << obj->department << endl;
	return os;
}
//doesnt actually work..
