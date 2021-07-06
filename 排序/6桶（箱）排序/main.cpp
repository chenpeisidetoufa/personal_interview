#include <iostream>
using namespace std;

#define AREA 1000 //(0~999)

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

//area-���ݷ�Χ
void BucketSort(int* a, int len, int area)
{
	//��˼�룺���ݷ�Ϊ����Ͱ��Ͱ�������������㷨����
	//����ʹ��10����λ��˼��
	int idx;
	int k;
	for (int i = 1; i <= area; i*=10)
	{
		//1.����10�����ӣ����ҳ�ʼ��Ϊ-1
		int *pTemp = new int[10 * len];
		for (int j = 0; j < 10 * len; j++)
			pTemp[j] = -1;
		//2.�Ѵ��������е����ݣ������ɷŵ�������ȥ
		for (int j = 0; j < len; j++)
		{
			idx = a[j] / i % 10;  //��λ��ʮλ����λ...�ϵ���ֵ
			*(pTemp + (idx * 10) + j) = a[j];//��ά�����ʾpTemp[idx][j]
		}
		//3.�����Ⱥ���������������ݷŵ�����������ȥ
		k = 0;
		for (int j = 0; j < 10 * len; j++)
		{
			if (-1 != pTemp[j])
			{
				a[k++] = pTemp[j];

			}
		}
		//4.�ͷ��ڴ�
		delete[] pTemp;
	}
}

int main(int argc, char *args[])
{
	int arr[10] = { 1,9,66,0,33,5,2,88,666,233 };
	Print(arr, 10);
	BucketSort(arr, 10, AREA);
	Print(arr, 10, false);
	return 0;
}