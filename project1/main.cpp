
#include <iostream>
#include"Student.h"
#include"List.h"
int main()
{
	cout << "���Ƚ���������Ϣϵͳ��\n"
		<< "�����뿼��������";
	int num;
	int StudentID;
	string StudentName;
	string StudentSex;
	int StudentAge;
	string TestName;
	cin >> num;
	while (num == 0)
	{
		cout << "Please enter a number greater than zero\n"<< "�����뿼��������";
		cin >> num;
	}
	List StudentList ;
	cout << '\n' << "���������뿼���Ŀ��ţ��������Ա����䣬�������\n";
	for (int i = 0; i < num; i++)
	{
		cin >> StudentID >> StudentName >> StudentSex >> StudentAge >> TestName;
		StudentList.Append(StudentID, StudentName, StudentSex, StudentAge, TestName, StudentList.CurrentPos);
	}
	StudentList.Print();
}

