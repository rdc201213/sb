#include"List.h"

//比较函数
void Compare(List List1,List List2,List* List3)
{

	if (List1.Lenth == 0 || List2.Lenth == 0)
	{
		//如果List1或List2有一个为空那么交集为空
		cout << "NULL";
		return;
	}
	else
	{
		List1.CurrentPos = List1.StartPos;
		List2.CurrentPos = List2.StartPos;
		while(List1.CurrentPos!=0&&List2.CurrentPos!=0)
		{
			//遍历链表元素
			//因为两个链表为有序链表，按照以下方式滚动对比
			if (List1.CurrentPos->Num > List2.CurrentPos->Num)
			{
				//当前List1元素大于List2元素
				//寻找List2下一个元素
				List2.CurrentPos = List2.CurrentPos->Next;
			}
			else if (List1.CurrentPos->Num < List2.CurrentPos->Num)
			{
				//当前List1元素小于List2元素
				//寻找List1下一个元素
				List1.CurrentPos = List1.CurrentPos->Next;
			}
			else
			{
				//出现相同元素加入List3
				//List1和List2同时后移一位
				List3->Append(List1.CurrentPos->Num);
				List1.CurrentPos = List1.CurrentPos->Next;
				List2.CurrentPos = List2.CurrentPos->Next;
			}
		}
	}
}

int main()
{
	int Num;
	List List1, List2;
	List* List3=new List;
	cin >> Num;
	while (Num!=-1)
	{
		List1.Append(Num);
		cin >> Num;
	}
	cin >> Num;
	while (Num!=-1)
	{
		List2.Append(Num);
		cin >> Num;
	}
	Compare(List1, List2,List3);
	List3->Print();
}

