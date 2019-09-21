#pragma once
#include <iostream>
using namespace std;
struct Member
{
	int Num;
	Member* Next;
};
class List
{
public:
	Member* StartPos;
	Member* EndPos;
	Member* CurrentPos;
	int Lenth;
public:
	List();
	~List();
	void Append(int num);
	void Print();
};