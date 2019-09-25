#include "List.h"
//构造函数
//变量初始化置零
List::List()
{
	StartPos = 0;
	EndPos = 0;
	CurrentPos = 0;
	Lenth = 0;
}

//析构函数
//变量清零
List::~List()
{
	StartPos = 0;
	EndPos = 0;
	CurrentPos = 0;
	Lenth = 0;
}

//将元素添至链表末尾
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

//输出链表所有元素
void List::Print()
{
	if (this->StartPos == 0)
	{
		//如果是空链表输出NULL
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