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

void SelectSort(int* a, int len)
{
	//从待排数组(0-len-1)中选择最小的，放到第一个元素处
	//从待排数组(1-len-1)中选择最小的，放到第一个元素处
	//...
	//从待排数组(len-2-len-1)中选择最小的，放到第一个元素处
	//时间复杂度：(n-1)+(n-2)+(n-3)+...+(1) = n^2/2,相对于冒泡的优化，只是交换次数的减少，n^2/2 + n，O(n^2)
	//共len-1轮
	int temp;
	int minIdx;
	for (int i = 0; i < len -1; i++)
	{
		//从待排数组中（i - len-1）中选择最小的，放到i元素处（交换）
		temp = a[i];

		minIdx = i;
		for (int j  = i; j < len; j++)
		{
			minIdx = a[j] < a[minIdx] ? j : minIdx; //找到最小值的下标
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