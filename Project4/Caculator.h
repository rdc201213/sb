#pragma once
#include <stack>
#include <math.h>
#include <iostream>
#include<iostream>
using namespace std;
class Caculator 
{
public:
	Caculator(){};
	void Run();
	void Clear() 
	{ 
		while (!stack_num.empty()) { stack_num.pop(); } 
		while (!stack_op.empty()) { stack_op.pop(); }
	};
	int erro = 0;
private:
	stack<double> stack_num;
	stack<char> stack_op;
	void AddOperand(double value);
	bool Get2Oprands(double& left,double& right);
	void DoOpreate(char op);
	int isp(char ch);
	int icp(char ch);
};