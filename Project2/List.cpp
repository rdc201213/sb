#include "List.h"
List::List()
{
	StartPos = 0;
	EndPos = 0;
	CurrentPos = 0;
	Lenth = 0;
}
List::~List()
{
	StartPos = 0;
	EndPos = 0;
	CurrentPos = 0;
	Lenth = 0;
}

void List::Append(int Num)
{
	Member* Temp=new Member;
	Temp->Num = Num;
	Temp->Next = 0;
	if (StartPos == 0)
	{
		StartPos = Temp;
		CurrentPos = StartPos;
		EndPos = Temp;
	}
	else
	{
		CurrentPos->Next = Temp;
		CurrentPos = Temp;
		EndPos = Temp;
	}
	Lenth++;
}

void List::Print()
{
	if (this->StartPos == 0)
	{
		cout << "NULL\n";
		return;
	}
	else
	{
		this->CurrentPos = this->StartPos;
		while (this->CurrentPos!=this->EndPos)
		{
			cout << this->CurrentPos->Num << ' ';
			this->CurrentPos = this->CurrentPos->Next;
		}
		cout << this->CurrentPos->Num;
		return;
	}
}