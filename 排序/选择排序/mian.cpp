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

void SelectSort(int* a, int len)
{
	//�Ӵ�������(0-len-1)��ѡ����С�ģ��ŵ���һ��Ԫ�ش�
	//�Ӵ�������(1-len-1)��ѡ����С�ģ��ŵ���һ��Ԫ�ش�
	//...
	//�Ӵ�������(len-2-len-1)��ѡ����С�ģ��ŵ���һ��Ԫ�ش�
	//ʱ�临�Ӷȣ�(n-1)+(n-2)+(n-3)+...+(1) = n^2/2,�����ð�ݵ��Ż���ֻ�ǽ��������ļ��٣�n^2/2 + n��O(n^2)
	//��len-1��
	int temp;
	int minIdx;
	for (int i = 0; i < len -1; i++)
	{
		//�Ӵ��������У�i - len-1����ѡ����С�ģ��ŵ�iԪ�ش���������
		temp = a[i];

		minIdx = i;
		for (int j  = i; j < len; j++)
		{
			minIdx = a[j] < a[minIdx] ? j : minIdx; //�ҵ���Сֵ���±�
		}
		a[i] = a[minIdx];
		a[minIdx] = temp;
	}
}

int main(int argc, char *args[])
{
	int arr[10] = { 1,9,66,0,33,5,2,88,666,233 };

	Print(arr, 10);
	SelectSort(arr, 10);
	Print(arr, 10, false);
	return 0;
}