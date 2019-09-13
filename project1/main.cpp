
#include <iostream>
#include"Student.h"
#include"List.h"
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
	while (num == 0)
	{
		cout << "Please enter a number greater than zero\n"<< "请输入考生人数：";
		cin >> num;
	}
	List StudentList ;
	cout << '\n' << "请依此输入考生的考号，姓名，性别，年龄，报考类别\n";
	for (int i = 0; i < num; i++)
	{
		cin >> StudentID >> StudentName >> StudentSex >> StudentAge >> TestName;
		StudentList.Append(StudentID, StudentName, StudentSex, StudentAge, TestName, StudentList.CurrentPos);
	}
	StudentList.Print();
}

