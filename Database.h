#ifndef DATABASE_H_
#define DATABASE_H_
#include <iostream>
#include "BinaryTree.h"
#include "GenStack.h"
#include "Faculty.h"
#include "Student.h"
#include <string>

using namespace std;

class Database
{
	public:
		Database();
		~Database();
		
		BinarySearchTree<Student> *studentTable;
		BinarySearchTree<Faculty> *facultyTable;
		GenStack<BinarySearchTree<Student>> *studentRollStack;
		GenStack<BinarySearchTree<Faculty>> *facultyRollStack;
	
		void PrintAllStu();
		void PrintAllFac();
		int FindStu(int iD);
		int FindFac(int iD);
		int FindFacByStu(int stuID);
		int FindStusByFac(int facID);
		int AddStu();
		int DeleteStu(int iD);
		int AddFac();
		int DeleteFac(int iD, int advTransferID);
		int ChangeStuAdvisor(int stuID, int facID);
		int RemoveAdvisee(int stuID);
		int Rollback();
		int Exit();
		
		void serializeStudents(string outFile);
		//void serializeFaculty(string outFile);
		void bfsS();
		void bfsF();
		BinarySearchTree<Student>* deserializeStudents(string inFile);
		//BinarySearchTree<Faculty>* deserializeFaculty(string inFile);
};
