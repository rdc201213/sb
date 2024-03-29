
#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<iostream>
using namespace std;


class Student
{
friend class List;
private:
	Student* Last;
	Student* Next;
	int StudentID;
	string StudentName;
	string StudentSex;
	int StudentAge;
	string TestName;
public:
	Student(int ID,
		string Name,
		string Sex,
		int Age,
		string Test);
	Student(int ID,
		string Name,
		string Sex,
		int Age,
		string Test,
		Student* LastStudent);
	~Student();
	void Print();
	
};

#endif
