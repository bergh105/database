#include <iostream>
#include "Student.h"
#include "Faculty.h"
#include "BinaryTree.h"
#include "Database.h"

using namespace std;

int main() {

	cout << "Here see a main method in its natural habitat." << endl;

	Student *s = new Student();

	s->setName("Kelly");
	s->setLevel("Sophomore");
	s->setGPA(4.0);
	s->setID(3);
	s->setAdvisor(3456);
	s->setMajor("Communications");

	cout << s->getName() << endl;

	Student *s2 = new Student("Adrienne", 7, 4.0, "Junior", "CIS", 45);

	cout << s->operator<(s2) << endl; //this is how you have to call the operator overloader

	//Database *d = new Database();

	//d->AddStu();
	
	return 0;
}
