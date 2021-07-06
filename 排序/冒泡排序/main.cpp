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

void BubbleSort(int* a, int len)
{
	//�ӵ�һ��������len-1��len�Ƚ����ڵ�����Ԫ�أ������С���ں󣬾ͽ���
	//һ�ֹ��� ��len�����ݾ�������
	//ʱ�临�Ӷȣ�(n-1)+(n-2)+(n-3)+...+(1) = n^2/2,����ÿ�ζ����������������*2��ʱ�临�Ӷ�ΪO(n^2)
	int temp;
	for (int i = 0; i < len - 1; i++) //���ѭ�� len1-1��
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			 if (a[j] > a[j + 1])
			 {
				 temp = a[j];
				 a[j] = a[j + 1];
				 a[j + 1] = temp;
			 }
		}
		Print(a, len);
	}
}

int main(int argc, char *args[])
{
	int arr[10] = { 1,9,66,0,33,5,2,88,666,233 };

	Print(arr, 10);
	BubbleSort(arr, 10);
	Print(arr, 10, false);
	return 0;
}