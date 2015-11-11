#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>

using namespace std;

class Student {
public:
	Student() {
		name = "";
		ID = 0;
		GPA = 0.0;
		level = "";
		major = "";
		advisor = 0;
	}

	~Student() {}

	//accessors
	string getName();
	int getID();
	double getGPA();
	string getLevel();
	string getMajor();
	int getAdvisor();

	//mutators
	void setName(string n);
	void setID(int id);
	void setGPA(double gpa);
	void setLevel(string l);
	void setMajor(string m);
	void setAdvisor(int a);

	//overloaders
	//operator: ostream& operator<<(ostream& os, const T& obj); come back to this (compiler doesnt like the T)

private:
	string name;
	int ID;
	double GPA;
	string level;
	string major;
	int advisor;
};

#endif /* STUDENT_H_ */
