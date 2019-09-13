#include "Student.h"
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
Student::~Student()
{
	;
}
void Student::Print()
{
	cout << this->StudentID <<" "<< this->StudentName << " "
		<< this->StudentSex << " " << this->StudentAge << " "
		<< this->TestName << '\n';
}