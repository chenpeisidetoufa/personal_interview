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

void InsertSort(int* a, int len)
{
	//�ӵڶ���ֵ��ʼ��ǰ���������
	//���ݴ������ֵ
	//�Ƚ�ǰ��һλ������ȴ�����ֵ��ֱ����ǰ����
	//�������ƣ�һֱ��ǰ��û���������ҵ��ȴ�����ֵС����ֹͣ
	//�����ݴ�Ĵ�����ֵ�ŵ����ʵ�λ��
	//ʱ�临�Ӷȣ��������������ж�һ�Σ��Ƚ�һ�Σ�2n;����ӵ��������һ��Ųһ�����ڶ���Ų������n^2/2�� O(n^2)
	int temp;
	int j;
	for (int i= 1; i < len; i++)
	{
		temp = a[i];
		j = i - 1; //j��i-1��ʼ
		while (j >= 0 && a[j] > a[i])
		{
			a[j + 1] = a[j]; //���󸲸�
			j--;
		}
		a[j + 1] = temp; //temp���ǻ���
	}
}

int main(int argc, char *args[])
{
	int arr[10] = { 1,9,66,0,33,5,2,88,666,233 };

	Print(arr, 10);
	InsertSort(arr, 10);
	Print(arr, 10, false);
	return 0;
}