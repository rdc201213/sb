#include"List.h"

//�ȽϺ���
void Compare(List List1,List List2,List* List3)
{

	if (List1.Lenth == 0 || List2.Lenth == 0)
	{
		//���List1��List2��һ��Ϊ����ô����Ϊ��
		cout << "NULL";
		return;
	}
	else
	{
		List1.CurrentPos = List1.StartPos;
		List2.CurrentPos = List2.StartPos;
		while(List1.CurrentPos!=0&&List2.CurrentPos!=0)
		{
			//��������Ԫ��
			//��Ϊ��������Ϊ���������������·�ʽ�����Ա�
			if (List1.CurrentPos->Num > List2.CurrentPos->Num)
			{
				//��ǰList1Ԫ�ش���List2Ԫ��
				//Ѱ��List2��һ��Ԫ��
				List2.CurrentPos = List2.CurrentPos->Next;
			}
			else if (List1.CurrentPos->Num < List2.CurrentPos->Num)
			{
				//��ǰList1Ԫ��С��List2Ԫ��
				//Ѱ��List1��һ��Ԫ��
				List1.CurrentPos = List1.CurrentPos->Next;
			}
			else
			{
				//������ͬԪ�ؼ���List3
				//List1��List2ͬʱ����һλ
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

