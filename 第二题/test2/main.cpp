#include <iostream>
using namespace std;

//�Ƿ����
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
	//�жϴ治����
	int revnum = 0;
	int baseTemp;
	for (int i = 2; i <= 16; i++)
	{
		int len = 0;
		baseTemp = tenBase;
		while (baseTemp != 0)
		{
			//��'0'�������ֶ�Ӧ��asc��
			str[len++] = baseTemp % i + '0';
			//int�ض�
			baseTemp = baseTemp / i;
		}
		//�ַ�����
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