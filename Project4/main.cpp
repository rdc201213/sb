#include"Caculator.h"
using namespace std;

int main()
{
	Caculator test;
	char op;
	cout << "��ӭʹ�ñ����׼����������ʽ��ʹ����ȷ�ķ���\n"
		<< "�Ӻ�:+  ����:-  �˺�:*  ����:/  �˷�:^  ȡ��:%  ����:()  �Ⱥ�:=\n";
	while (true) 
	{
		cout << "��������ʽ:\n";
		test.Run();
		cout << "�Ƿ����?(Y , N)\n";
		cin >> op;
		if (op == 'Y' || op=='y')
		{
			getchar();
			continue;
		}
		else
		{
			break;
		}
	}
	system("Pause");
}