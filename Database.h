#include <iostream>
#include "BinaryTree.h"
#include "Faculty.h"
#include "Student.h"

using namespace std;

class Database
{
	Public:
		Database();
		~Database();
		
		BinarySearchTree<Student*> *studentTable;
		BinarySearchTree<Faculty*> *facultyTable;
	
		void PrintAllStu();
		void PrintAllFac();
		int FindStu(int iD);
		int FindFac(int iD);
		int AddStu();
		int DeleteStu(int iD);
		int AddFac();
		int DeleteFac(int iD);
		int ChangeStuAdvisor(int stuID, int facID);
		int RemoveAdvisee(int stuID, int facID)
		int Rollback();
		int Exit();

};
