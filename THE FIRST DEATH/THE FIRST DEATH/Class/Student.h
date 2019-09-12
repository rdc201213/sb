
#ifndef STUDENT_H
#define STUDENT_H

#include<string>

using namespace std;

class Student
{
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
	Student(Student* LastStudent,
		int ID,
		string Name,
		string Sex,
		int Age,
		string Test);
	~Student();
	Student* Find();
	void Insert();
	void Change();
	void Delete();
};

#endif
