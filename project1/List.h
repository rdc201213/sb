#pragma once
#include"Student.h"
#include<iostream>
using namespace std;
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
	Student* Find();
	void Insert();
	void Change();
	void Delete();
	Student* CurrentPos;
	void Print();
};