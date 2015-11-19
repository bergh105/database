#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

string Student::getName() {
	return name;
}

int Student::getID() {
	return ID;
}

double Student::getGPA() {
	return GPA;
}

string Student::getLevel() {
	return level;
}

string Student::getMajor() {
	return major;
}

int Student::getAdvisor() {
	return advisor;
}

void Student::setName(string n) {
	name = n;
}

void Student::setID(int id) {
	ID = id;
}

void Student::setGPA(double gpa) {
	GPA = gpa;
}

void Student::setLevel(string l) {
	level = l;
}

void Student::setMajor(string m) {
	major = m;
}

void Student::setAdvisor(int a) {
	advisor = a;
}

//Operator Overloaders:
bool Student::operator <(const Student& s) {
	if(ID < s.ID) {
		return true;
	}
	return false;
}

bool Student::operator >(const Student& s) {
	if(ID > s.ID) {
		return true;
	}
	return false;
}

bool Student::operator ==(const Student& s) {
	if(ID == s.ID) {
		return true;
	}
	return false;
}

bool Student::operator !=(const Student& s) {
	if(ID != s.ID) {
		return true;
	}
	return false;
}

ostream& operator<<(ostream& os, Student obj) { 
	cout << "name" << obj.getName() << "\n" << "id: " << obj.getID() << "\n" << obj.getGPA() << "\n" << obj.getLevel() << "\n" << obj.getMajor() << "\n" << obj.getAdvisor() << endl;
	return os;
}
