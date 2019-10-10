#include"Caculator.h"
using namespace std;

int main()
{
	Caculator test;
	char op;
	cout << "欢迎使用本简易计算器，表达式请使用正确的符号\n"
		<< "加号:+  减号:-  乘号:*  除号:/  乘方:^  取余:%  括号:()  等号:=\n";
	while (true) 
	{
		cout << "请输入表达式:\n";
		test.Run();
		cout << "是否继续?(Y , N)\n";
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