#include<iostream>
using namespace std;
void Quick_Sort(int array[], int start, int last)
{
	int i = start;
	int j = last;
	int temp = array[i];
	if (i < j)
	{
		while (i < j)
		{
			while (i < j && array[j] <= temp)
				j--;
			if (i < j)
			{
				array[i] = array[j];
				i++;
			}

			while (i < j && temp < array[i])
				i++;
			if (i < j)
			{
				array[j] = array[i];
				j--;
			}

		}
		array[i] = temp;
		Quick_Sort(array, start, i - 1);
		Quick_Sort(array, i + 1, last);
	}
}

int main()
{
	int N;
	int num = 0;
	cin >> N;
	int Piece[10001];
	memset(Piece,-1,sizeof(int)*10001);
	for(int i=0;i<N;i++)
	{
		cin >> Piece[i];
		num = num + Piece[i];
	}
	Quick_Sort(Piece,0,N-1);
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		num = num - Piece[i];
		if (num == 0)
			break;
		sum = sum+num + Piece[i];
	}
	cout << sum;
	system("Pause");
}

