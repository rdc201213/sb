#include<iostream>
using namespace std;
int main()
{
	int num=0,temp=0;
	int A[1001], B[1001];
	int Acount=0, Bcount=0;
	memset(A, -1, sizeof(int) * 1001);
	memset(B, -1, sizeof(int) * 1001);
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> temp;
		if (temp % 2 == 0)
		{
			B[Bcount] = temp;
			Bcount++;
		}
		else
		{
			A[Acount] = temp;
			Acount++;
		}
	}
	int count = 1;
	if (Acount != 0)
	{
		cout << A[0];
		A[0] = -1;
		for (int i = 1, j = 0; (i < Acount||j<Bcount); )
		{
			if (A[i] != -1)
			{
				cout <<' '<< A[i];
				A[i] = -1;
				i++;
			}
			count++;
			if (count == 2 && B[j] != -1)
			{
				cout << ' '<<B[j];
				B[j] = -1;
				j++;
				count = 0;
			}
		}
	}
	else 
	{
		for (int i = 0; i < Bcount; i++)
		{
			cout << B[i];
			if (i != Bcount-1)
			{
				cout << ' ';
			}
		}
	}
	system("Pause");
}