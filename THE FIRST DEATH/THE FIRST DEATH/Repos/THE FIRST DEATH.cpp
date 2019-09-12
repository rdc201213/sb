
#include <iostream>

int main()
{
	cout << "首先建立考生信息系统！\n"
	     << "请输入考生人数：";
	int num;
	int StudentID;
	string StudentName;
	string StudentSex;
	int StudentAge;
	string TestName;
	cin >> num;
	if (num == 0)
	{
		cout << "Please enter a number greater than zero";
	}
	cout << '\n' << "请依此输入考生的考号，姓名，性别，年龄，报考类别\n";
	for (int i = 0; i < num; i++)
	{
		if (i == 0) 
		{
			cin >> StudentID >> StudentName >> StudentSex >> StudentAge >> TestName;
			Student FirstStudent=Student(StudentID, StudentName, StudentSex, StudentAge, TestName);
		}
		else
		{
			;
		}
	}
}

