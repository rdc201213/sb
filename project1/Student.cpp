#include "Student.h"
//两种构造函数以应对不同需求
Student::Student(int ID,
	string Name,
	string Sex,
	int Age,
	string Test)
{
	StudentID = ID;
	StudentName = Name;
	StudentSex = Sex;
	StudentAge = Age;
	TestName = Test;
	Last = nullptr;
	Next = nullptr;
}

Student::Student(int ID,
	string Name,
	string Sex,
	int Age,
	string Test,
	Student* LastStudent)
{
	StudentID = ID;
	StudentName = Name;
	StudentSex = Sex;
	StudentAge = Age;
	TestName = Test;
	Last = LastStudent;
	Next = nullptr;
}

//析构函数
//清零所有变量
Student::~Student()
{
	StudentID = 0;
	StudentName = '\0';
	StudentSex = '\0';
	StudentAge =0;
	TestName = '\0';
	Last = 0;
	Next = 0;;
}

//输出该节点信息
void Student::Print()
{
	cout << this->StudentID <<" "<< this->StudentName << " "
		<< this->StudentSex << " " << this->StudentAge << " "
		<< this->TestName << '\n';
}