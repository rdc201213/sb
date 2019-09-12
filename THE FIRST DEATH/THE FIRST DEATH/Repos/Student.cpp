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

Student::Student(Student* LastStudent,
	int ID,
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
	Last = LastStudent;
	Next = nullptr;
}
Student::~Student()
{

}
Student* Student::Find()
{
}
void Student::Change()
{

}
void Student::Delete()
{}
void Student::Insert()
{}