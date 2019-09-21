#include"List.h"
List::List()
{
	StartPos = 0;
	EndPos = 0;
	CurrentPos = 0;
	Lenth = 0;
}

List::~List()
{
	CurrentPos = StartPos;
	while (CurrentPos != EndPos)
	{
		Student* TempPos = CurrentPos;
		CurrentPos=CurrentPos->Next;
		TempPos->~Student();
	}
	StartPos = 0;
	EndPos = 0;
	CurrentPos = 0;
}

void List::Append(int ID,
	string Name,
	string Sex,
	int Age,
	string Test,
	Student* Last)
{
	Student* TempPos = new Student(ID, Name, Sex, Age, Test, Last);
	if (TempPos == 0)
	{
		cout << "����ʧ�ܣ�������\n";
	}
	else 
	{
		if (StartPos == 0)
		{
			StartPos = TempPos;
		}
		if (CurrentPos == 0)
		{
			CurrentPos = TempPos;
		}
		else 
		{
			CurrentPos->Next = TempPos;
			CurrentPos = TempPos;
		}
		EndPos = CurrentPos;
		Lenth++;
	}
}

void List::Append(Student* NewStudent)
{
	EndPos->Next = NewStudent;
	NewStudent->Last = EndPos;
	EndPos = NewStudent;
	Lenth++;
}

void List::Print()
{
	CurrentPos = StartPos;
	while (CurrentPos != EndPos) 
	{
		CurrentPos->Print();
		CurrentPos=CurrentPos->Next;
	}
	if (EndPos != 0)
	{
		EndPos->Print();
	}
}

Student* List::Find(int ID)
{
	CurrentPos = StartPos;
	while (CurrentPos != EndPos) 
	{
		if (CurrentPos->StudentID == ID)
		{
			cout << "���ҵ���ѧ��:\n";
			CurrentPos->Print();
			return CurrentPos;
		}
		else
		{
			CurrentPos = CurrentPos->Next;
		}
	}
	if (CurrentPos->StudentID == ID)
	{
		CurrentPos->Print();
		return CurrentPos;
	}
	else
	{
		cout << "û���ҵ����������Ŀ���\n";
		return 0;
	}
}

Student* List::Find(string Name)
{
	CurrentPos = StartPos;
	while (CurrentPos != EndPos)
	{
		if (CurrentPos->StudentName == Name)
		{
			cout << "���ҵ���ѧ��:\n";
			CurrentPos->Print();
			return CurrentPos;
		}
		else
		{
			CurrentPos = CurrentPos->Next;
		}
	}
	if (CurrentPos->StudentName == Name)
	{
		CurrentPos->Print();
		return CurrentPos;
	}
	else
	{
		cout << "û���ҵ����������Ŀ���\n";
		return 0;
	}
}

void List::Insert(int Pos,Student* NewStudent)
{
	if (Lenth == 0)
	{
		StartPos = NewStudent;
		EndPos = NewStudent;
	}
	else
	{
		if (Pos > Lenth)
		{
			cout << "�ѳ�����ǰ�б��ܳ��ȣ���ѧԱ�ѱ�������б����һλ\n";
			this->Append(NewStudent);
		}
		else if (Pos == 1)
		{
			StartPos->Last = NewStudent;
			NewStudent->Next = StartPos;
			StartPos = NewStudent;
		}
		else if (Pos < 1) 
		{
			cout << "���ڲ���λ��С�ڵ���0��ѧԱ�ѱ��������һλ\n"
				<< "�뾡����Ҫ����С�ڵ���0����\n";
			StartPos->Last = NewStudent;
			NewStudent->Next = StartPos;
			StartPos = NewStudent;
		}
		else
		{
			CurrentPos = StartPos;
			for (int i = 1; i < Pos; i++)
			{
				CurrentPos = CurrentPos->Next;
			}
			NewStudent->Last = CurrentPos->Last;
			NewStudent->Next = CurrentPos;
			CurrentPos->Last->Next = NewStudent;
			CurrentPos->Last = NewStudent;
		}
	}
	Lenth++;
}

void List::Change(int ID)
{
	Student* TempStudent = this->Find(ID);
	if (TempStudent == 0)
	{
		return;
	}
	else 
	{
		cout<< "���������뿼���Ŀ��ţ��������Ա����䣬�������\n";
		cin >> TempStudent->StudentID >> TempStudent->StudentName >> TempStudent->StudentSex
			>> TempStudent->StudentAge >> TempStudent->TestName;
	}
}

void List::Change(string Name)
{
	Student* TempStudent = this->Find(Name);
	if (TempStudent == 0)
	{
		return;
	}
	else
	{
		cout << "���������뿼���Ŀ��ţ��������Ա����䣬�������\n";
		cin >> TempStudent->StudentID >> TempStudent->StudentName >> TempStudent->StudentSex
			>> TempStudent->StudentAge >> TempStudent->TestName;
	}
}

void List::Delete(int ID)
{
	Student* TempStudent = this->Find(ID);
	if (TempStudent == 0)
	{
		return;
	}
	else
	{
		char Juge;
		cout << "�Ƿ�ȷ��ɾ���� ��yȷ�� ����������\n";
		cin >> Juge;
		if (Juge == 'Y'||Juge=='y') 
		{
			if (TempStudent == StartPos && TempStudent == EndPos)
			{
				delete TempStudent;
				StartPos = 0;
				EndPos = 0;
				CurrentPos = 0;
				Lenth--;
				cout << "�ѳɹ�ɾ��\n";
			}
			else if (TempStudent == StartPos)
			{
				TempStudent->Next->Last = TempStudent->Last;
				StartPos = TempStudent->Next;
				delete TempStudent;
				Lenth--;
				cout << "�ѳɹ�ɾ��\n";
			}
			else if (TempStudent == EndPos)
			{
				TempStudent->Last->Next = TempStudent->Next;
				EndPos = TempStudent->Last;
				delete TempStudent;
				Lenth--;
				cout << "�ѳɹ�ɾ��\n";
			}
			else
			{
				TempStudent->Last->Next = TempStudent->Next;
				TempStudent->Next->Last = TempStudent->Last;
				delete TempStudent;
				Lenth--;
				cout << "�ѳɹ�ɾ��\n";
			}
		}
		else
		{
			cout << "����ֹɾ������\n";
		}
	}
}

void List::Delete(string Name)
{
	Student* TempStudent = this->Find(Name);
	if (TempStudent == 0)
	{
		return;
	}
	else
	{
		char Juge;
		cout << "�Ƿ�ȷ��ɾ���� ��yȷ�� ����������\n";
		cin >> Juge;
		if (Juge == 'Y' || Juge == 'y')
		{
			if (TempStudent == StartPos && TempStudent == EndPos)
			{
				delete TempStudent;
				StartPos = 0;
				EndPos = 0;
				CurrentPos = 0;
				Lenth--;
				cout << "�ѳɹ�ɾ��\n";
			}
			else if (TempStudent == StartPos)
			{
				TempStudent->Next->Last = TempStudent->Last;
				StartPos = TempStudent->Next;
				delete TempStudent;
				Lenth--;
				cout << "�ѳɹ�ɾ��\n";
			}
			else if (TempStudent == EndPos)
			{
				TempStudent->Last->Next = TempStudent->Next;
				EndPos = TempStudent->Last;
				delete TempStudent;
				Lenth--;
				cout << "�ѳɹ�ɾ��\n";
			}
			else
			{
				TempStudent->Last->Next = TempStudent->Next;
				TempStudent->Next->Last = TempStudent->Last;
				delete TempStudent;
				Lenth--;
				cout << "�ѳɹ�ɾ��\n";
			}
		}
		else
		{
			cout << "����ֹɾ������\n";
		}
	}
}