#include "Caculator.h"

void Caculator::AddOperand(double value)
{
	stack_num.push(value);
}

void Caculator::DoOpreate(char op)
{
	double left, right, value;
	bool result;
	result = Get2Oprands(left, right);
	if (result == true)
	{
		switch (op)
		{
		case '+':
			value = left + right;
			stack_num.push(value);
			break;
		case '-':
			value = left - right;
			stack_num.push(value);
			break;
		case '*':
			value = left * right;
			stack_num.push(value);
			break;
		case '/':
			if (right == 0.0)
			{
				cerr << "除数为0\n";
				erro = 1;
				Clear();
			}
			else 
			{
				value = left / right;
				stack_num.push(value);
			}
			break;
		case'^':
			value = pow(left,right);
			stack_num.push(value);
			break;
		case'%':
			value = int(left) % int(right);
			stack_num.push(value);
			break;
		default:
			break;
		}
	}
	else
	{
		Clear();
	}
}

bool Caculator::Get2Oprands(double& left, double& right)
{
	if (stack_num.empty())
	{
		erro = 1;
		return false;
	}
	right=stack_num.top();
	stack_num.pop();
	if (stack_num.empty())
	{
		erro = 1;
		return false;
	}
	left = stack_num.top();
	stack_num.pop();
	return true;
}

void Caculator::Run() 
{
	char ch;
	int sign = 0;
	stack_op.push('#');
	cin.get(ch);
	if (ch=='-')
	{
		sign = 1;
		cin.get(ch);
	}
	else if (ch == '+')
	{
		sign = 0;
		cin.get(ch);
	}
	while (ch != '\n')
	{
		double num = 0.0;
		while (isdigit(ch))
		{
			num = num * 10 + ch - '0';
			cin.get(ch);
		}
		if (num != 0.0)
		{
			if (sign == 1)
				num = -num;
			stack_num.push(num);
			sign = 0;
		}
		else 
		{
			char ch1;
			if (ch == '(')
			{
				cin.get(ch1);
				if (ch1 == '+')
				{
					sign = 0;
				}
				else if (ch1 == '-')
				{
					sign = 1;
				}
				else
				{
					cin.putback(ch1);
				}
			}
			ch1 = stack_op.top();
			if (icp(ch) > isp(ch1))
			{
				stack_op.push(ch);
			}
			else
			{
				if (icp(ch) == isp(ch1))
				{
					stack_op.pop();
				}
				else
				{
					while (icp(ch) < isp(ch1))
					{
						DoOpreate(ch1);
						stack_op.pop();
						ch1 = stack_op.top();
					}
					if (icp(ch) == isp(ch1))
					{
						stack_op.pop();
					}
					else
					{
						stack_op.push(ch);
					}
				}
			}
			cin.get(ch);
		}	
	}
	while (!stack_op.empty())
	{
		ch = stack_op.top();
		DoOpreate(ch);
		stack_op.pop();
	}
	if (erro != 0)
	{
		cout << "表达式有误，无法得出结果";
		return;
	}
	cout << stack_num.top()<<'\n';
	Clear();
}

int Caculator::isp(char ch)
{
	switch (ch)
	{
	case '#':
		return 0;
	case'(':
		return 1;
	case'+':case'-':
		return 3;
	case'*':case'/':case'%':
		return 5;
	case'^':
		return 6;
	case')':
		return 8;
	default:
		return 0;
	}
}

int Caculator::icp(char ch)
{
	switch (ch)
	{
	case '#':
		return 0;
	case'(':
		return 8;
	case'+':case'-':
		return 2;
	case'*':case'/':case'%':
		return 4;
	case'^':
		return 7;
	case')':
		return 1;
	default:
		return 0;
	}
}