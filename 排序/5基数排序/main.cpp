#include <iostream>
using namespace std;

//isBefore-缺省参数
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

//必须要有三个参数 , 必须是正整数
//数组首地址 数组元素个数 最大元素值
void RadixSort(int* a, int len, int max)
{
	//不用比较和移动
	//是最快的排序算法，时间复杂度 O(n)
	//利用数组下标天然有序  
	//缺点：1.只能适应正整数；2.不能重复；3.有可能空间复杂度超高

	int *pTemp = new int[max + 1]; //可能有0
	int k = 0;

	//初始化临时数组
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