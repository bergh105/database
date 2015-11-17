#include <iostream>
#include "Student.h"
#include "Faculty.h"
#include "BinaryTree.h"
#include "Database.h"

using namespace std;

int main() {

	cout << "Here we have the main function." << endl;
/*
	Student *s = new Student();

	s->setName("Kelly");
	s->setLevel("Sophomore");
	s->setGPA(4.0);
	s->setID(3);
	s->setAdvisor(3456);
	s->setMajor("Communications");

	cout << s->getName() << endl;

	Student *s2 = new Student("Adrienne", 7, 4.0, "Junior", "CIS", 45);

	cout << s->operator<(s2) << endl; // < overloader

	operator<<(cout, s); // << overloader
*/
	Database *d = new Database();

	d->AddStu();
	d->AddStu();
	d->AddStu();

	d->PrintAllStu();

	delete d;
	
	return 0;
}
