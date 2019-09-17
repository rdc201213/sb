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
		cout << "创建失败，请重试\n";
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
	EndPos->Last = NewStudent;
	NewStudent->Last = EndPos;
	EndPos = NewStudent;
}

void List::Print()
{
	CurrentPos = StartPos;
	while (CurrentPos != EndPos) 
	{
		CurrentPos->Print();
		CurrentPos=CurrentPos->Next;
	}
	CurrentPos->Print();
}

Student* List::Find(int ID)
{
	CurrentPos = StartPos;
	while (CurrentPos != EndPos) 
	{
		if (CurrentPos->StudentID == ID)
		{
			cout << "已找到该学生:\n";
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
		cout << "没有找到符合条件的考生\n";
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
			cout << "已找到该学生:\n";
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
		cout << "没有找到符合条件的考生\n";
		return 0;
	}
}

void List::Insert(int Pos,Student* NewStudent)
{
	if (Pos > Lenth)
	{
		cout << "已超过当前列表总长度，该学员已被添加至列表最后一位\n";
		this->Append(NewStudent);
	}
	else if (Pos == 1)
	{
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

void List::Change(int ID)
{
	Student* TempStudent = this->Find(ID);
	if (TempStudent == 0)
	{
		return;
	}
	else 
	{
		cout<< "请依此输入考生的考号，姓名，性别，年龄，报考类别\n";
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
		cout << "请依此输入考生的考号，姓名，性别，年龄，报考类别\n";
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
		cout << "是否确认删除？ 按y确认 其他键返回\n";
		cin >> Juge;
		if (Juge == 'Y'||Juge=='y') 
		{
			if (TempStudent == StartPos)
			{
				TempStudent->Next->Last = TempStudent->Last;
				StartPos = TempStudent->Next;
				delete TempStudent;
				cout << "已成功删除\n";
			}
			else if (TempStudent == EndPos)
			{
				TempStudent->Last->Next = TempStudent->Next;
				EndPos = TempStudent->Last;
				delete TempStudent;
				cout << "已成功删除\n";
			}
			else
			{
				TempStudent->Last->Next = TempStudent->Next;
				TempStudent->Next->Last = TempStudent->Last;
				delete TempStudent;
				cout << "已成功删除\n";
			}
		}
		else
		{
			cout << "已终止删除进程\n";
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
		cout << "是否确认删除？ 按y确认 其他键返回\n";
		cin >> Juge;
		if (Juge == 'Y' || Juge == 'y')
		{
			if (TempStudent == StartPos)
			{
				TempStudent->Next->Last = TempStudent->Last;
				StartPos = TempStudent->Next;
				delete TempStudent;
				cout << "已成功删除\n";
			}
			else if (TempStudent == EndPos)
			{
				TempStudent->Last->Next = TempStudent->Next;
				EndPos = TempStudent->Last;
				delete TempStudent;
				cout << "已成功删除\n";
			}
			else
			{
				TempStudent->Last->Next = TempStudent->Next;
				TempStudent->Next->Last = TempStudent->Last;
				delete TempStudent;
				cout << "已成功删除\n";
			}
		}
		else
		{
			cout << "已终止删除进程\n";
		}
	}
}