#include <iostream>
using namespace std;

//是否回文
bool isRev(char* str, int length) 
{
	for (int i = 0; i < length - i - 1; i++)
	{
		if (str[i] != str[length - i - 1])
		{
			return false;
		}
	}
	return true;
}


int main()
{
	int tenBase;
	cin >> tenBase;
	char str[30];
	//判断存不存在
	int revnum = 0;
	int baseTemp;
	for (int i = 2; i <= 16; i++)
	{
		int len = 0;
		baseTemp = tenBase;
		while (baseTemp != 0)
		{
			//加'0'返回数字对应的asc码
			str[len++] = baseTemp % i + '0';
			//int截断
			baseTemp = baseTemp / i;
		}
		//字符串串
		str[len] = '\0';
		if (isRev(str, len))
		{
			revnum++;
			cout << i << endl;
		}
	}
	if (revnum == 0)
	{
		cout << -1 << endl;
	}
	return 0;
}