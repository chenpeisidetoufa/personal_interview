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

//���飬��Ҫ�����м�λ��
void Group(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int temp = a[left];
	int l = left;
	int r = right;

	while (l < r)
	{
		while (l < r && a[r] > temp)    //��Ų�ұ�
		{
			r--;
		}
		a[l] = a[r];   //��right����left
		while (l < r && a[l] <= temp)  //��Ų�ұ�
		{
			l++;
		}
		a[r] = a[l];   //��left����right
	}
	a[l] = temp;
	//�ݹ�
	Group(a, left, l - 1);
	Group(a, l + 1, right);
}


void QuickSort(int* a, int len) 
{
	Group(a, 0, len - 1);
}

int main(int argc, char *args[])
{
	int arr[10] = { 1, 78, 5, 36, 0, 22, 13, 8, 3, 4 };
	Print(arr, 10);
	QuickSort(arr, 10);
	Print(arr, 10, false);
	return 0;
}