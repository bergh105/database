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
		//first action: create new database
		//second action: deserialize() into that database
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

	//d->serializeStudents("studentTable.bin"); //this works
	//d->deserializeStudents("studentTable.bin"); //this works
	cout << "\n TEST serializeFaculty \n" << endl;
	d->serializeFaculty("facultyTable.bin");
	//d->deserializeFaculty("facultyTable.bin");

	delete d;
	
	return 0;
}

/*

#include <iostream>
#include "Student.h"
#include "Faculty.h"
#include "BinaryTree.h"
#include "Database.h"
#include "Menu.h"

using namespace std;

int main() {

	
	Menu *m = new Menu();
	m->execute();
	
	return 0;
}
*/
