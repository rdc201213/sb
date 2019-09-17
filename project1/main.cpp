
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
	cout << "创建成功,列表如下\n";
	StudentList.Print();
	int Switch = 1;
	while (Switch)
	{
		cout << "请选择要执行的操作: 1:插入 2:删除 3:查找 4:修改 5:打印列表 0:结束\n";
		cin >> num;
		switch (num)
		{
		case 0:
			Switch = 0;
			cout << "已结束程序，正在销毁列表\n";
			break;
		case 1:
			int Pos;
			cout << "请依此输入要插入的考生的考号，姓名，性别，年龄，报考类别以及插入位置\n";
			cin >> StudentID >> StudentName >> StudentSex >> StudentAge >> TestName>>Pos;
			StudentList.Insert(Pos,new Student(StudentID, StudentName, StudentSex, StudentAge, TestName));
		case 2:
			cout << "请选择删除方式: 1:按学号删除 2:按姓名删除\n";
			cin >> num;
			switch (num)
			{
			case 1:
				cout << "请输入要删除学生的学号\n";
				cin >> StudentID;
				StudentList.Delete(StudentID);
				break;
			case 2:
				cout << "请输入要删除学生的姓名\n";
				cin >> StudentName;
				StudentList.Delete(StudentName);
				break;
			default:
				cout << "指令错误，已退出\n";
				break;
			}
			break;
		case 3:
			cout << "请选择查找方式: 1:按学号查找 2:按姓名查找\n";
			cin >> num;
			switch (num)
			{
			case 1:
				cout << "请输入要查找的学号\n";
				cin >> StudentID;
				StudentList.Find(StudentID);
				break;
			case 2:
				cout << "请输入要查找的姓名\n";
				cin >> StudentName;
				StudentList.Find(StudentName);
				break;
			default:
				cout << "指令错误，已退出\n";
				break;
			}
			break;
		case 4:
			cout << "请选择修改方式: 1:按学号修改 2:按姓名修改\n";
			cin >> num;
			switch (num)
			{
			case 1:
				cout << "请输入要修改学生的学号\n";
				cin >> StudentID ;
				StudentList.Change(StudentID);
				break;
			case 2:
				cout << "请输入要修改学生的姓名\n";
				cin >> StudentName;
				StudentList.Change(StudentName);
				break;
			default:
				cout << "指令错误，已退出\n";
				break;
			}
			break;
		case 5:
			StudentList.Print();
			break;
		default:
			cout << "指令错误，请重新输入\n";
			break;
		}
	}
}
