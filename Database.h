#include <iostream>
#include "BinaryTree.h"
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

};
