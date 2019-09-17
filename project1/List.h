#pragma once
#include"Student.h"
class List
{
private:
	Student* StartPos;
	Student* EndPos;
	int Lenth;
public:
	List();
	~List();
	void Append(int ID,
		string Name,
		string Sex,
		int Age,
		string Test,
		Student* Last);
	void Append(Student* NewStudent);
	Student* Find(int ID);
	Student* Find(string name);
	void Insert(int Pos, Student* NewStudent);
	void Change(int ID);
	void Change(string Name);
	void Delete(int ID);
	void Delete(string Name);
	void Print();
	Student* CurrentPos;
};