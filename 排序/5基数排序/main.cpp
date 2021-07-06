#include <iostream>
using namespace std;

//isBefore-ȱʡ����
void Print(int* a, int len, bool isBefore = true)
{
	if (isBefore)
		printf("before sort:");
	else
		printf("after  sort:");
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");
}

//����Ҫ���������� , ������������
//�����׵�ַ ����Ԫ�ظ��� ���Ԫ��ֵ
void RadixSort(int* a, int len, int max)
{
	//���ñȽϺ��ƶ�
	//�����������㷨��ʱ�临�Ӷ� O(n)
	//���������±���Ȼ����  
	//ȱ�㣺1.ֻ����Ӧ��������2.�����ظ���3.�п��ܿռ临�Ӷȳ���

	int *pTemp = new int[max + 1]; //������0
	int k = 0;

	//��ʼ����ʱ����
	for (int i = 0; i < max + 1; i++)
	{
		pTemp[i] = -1;
	}


	for (int i = 0; i < len; i++)
	{
		pTemp[a[i]] = a[i];
	}

	for (int i = 0; i < max + 1; i++)
	{
		if (-1 != pTemp[i])
		{
			a[k] = pTemp[i];
			k++;
		}
	}

	delete[] pTemp;
}

int main(int argc, char *args[])
{
	int arr[10] = { 1,9,66,0,33,5,2,88,666,233 };

	Print(arr, 10);
	RadixSort(arr, 10, 666);
	Print(arr, 10, false);
	return 0;
}