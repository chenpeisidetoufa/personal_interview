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

void BubbleSort(int* a, int len)
{
	//从第一、二个到len-1、len比较相邻的两个元素，如果是小的在后，就交换
	//一轮过后 第len个数据就是最大的
	//时间复杂度：(n-1)+(n-2)+(n-3)+...+(1) = n^2/2,假如每次都交换，运算次数再*2，时间复杂度为O(n^2)
	int temp;
	for (int i = 0; i < len - 1; i++) //外层循环 len1-1轮
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