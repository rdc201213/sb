
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
	cout << "�����ɹ�,�б�����\n";
	StudentList.Print();
	int Switch = 1;
	while (Switch)
	{
		cout << "��ѡ��Ҫִ�еĲ���: 1:���� 2:ɾ�� 3:���� 4:�޸� 5:��ӡ�б� 0:����\n";
		cin >> num;
		switch (num)
		{
		case 0:
			Switch = 0;
			cout << "�ѽ����������������б�\n";
			break;
		case 1:
			int Pos;
			cout << "����������Ҫ����Ŀ����Ŀ��ţ��������Ա����䣬��������Լ�����λ��\n";
			cin >> StudentID >> StudentName >> StudentSex >> StudentAge >> TestName>>Pos;
			StudentList.Insert(Pos,new Student(StudentID, StudentName, StudentSex, StudentAge, TestName));
		case 2:
			cout << "��ѡ��ɾ����ʽ: 1:��ѧ��ɾ�� 2:������ɾ��\n";
			cin >> num;
			switch (num)
			{
			case 1:
				cout << "������Ҫɾ��ѧ����ѧ��\n";
				cin >> StudentID;
				StudentList.Delete(StudentID);
				break;
			case 2:
				cout << "������Ҫɾ��ѧ��������\n";
				cin >> StudentName;
				StudentList.Delete(StudentName);
				break;
			default:
				cout << "ָ��������˳�\n";
				break;
			}
			break;
		case 3:
			cout << "��ѡ����ҷ�ʽ: 1:��ѧ�Ų��� 2:����������\n";
			cin >> num;
			switch (num)
			{
			case 1:
				cout << "������Ҫ���ҵ�ѧ��\n";
				cin >> StudentID;
				StudentList.Find(StudentID);
				break;
			case 2:
				cout << "������Ҫ���ҵ�����\n";
				cin >> StudentName;
				StudentList.Find(StudentName);
				break;
			default:
				cout << "ָ��������˳�\n";
				break;
			}
			break;
		case 4:
			cout << "��ѡ���޸ķ�ʽ: 1:��ѧ���޸� 2:�������޸�\n";
			cin >> num;
			switch (num)
			{
			case 1:
				cout << "������Ҫ�޸�ѧ����ѧ��\n";
				cin >> StudentID ;
				StudentList.Change(StudentID);
				break;
			case 2:
				cout << "������Ҫ�޸�ѧ��������\n";
				cin >> StudentName;
				StudentList.Change(StudentName);
				break;
			default:
				cout << "ָ��������˳�\n";
				break;
			}
			break;
		case 5:
			StudentList.Print();
			break;
		default:
			cout << "ָ���������������\n";
			break;
		}
	}
}
