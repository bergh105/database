#include <iostream>
#include "Student.h"
#include "Faculty.h"
#include "BinaryTree.h"
#include "Database.h"

using namespace std;

bool exists(const string& name) {
	ifstream infile(name);
	return infile.good();
}

int main() {

	if( exists("studentTable.bin") ) {
		cout << "Student table file already exists. Load data from previous use." << endl;
		// deserialize()
	}
	else {
		cout << "first time running program." << endl;
		//create new database
	}
	if( exists("facultyTable.bin")) {
		cout << "Faculty table file already exists. Load data from previous use" << endl;
		// deserialize()
	}
	else {
		cout << "no faculty file exists" << endl;
		//create new database
	}

	Database *d = new Database();

	d->AddStu();
	d->AddStu();
	d->AddStu();

	d->AddFac();
	//d->AddFac();

	d->serializeStudents("studentTable.bin");
	d->deserializeStudents("studentTable.bin");

	//d->serializeFaculty("facultyTable.bin");
	//d->deserializeFaculty("facultyTable.bin");

	delete d;
	
	return 0;
}
