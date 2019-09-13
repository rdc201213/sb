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
	delete this;
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
		cout << "´´½¨Ê§°Ü£¬ÇëÖØÊÔ\n";
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