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

void InsertSort(int* a, int len)
{
	//从第二个值开始往前做有序插入
	//先暂存待插入值
	//比较前面一位，如果比待插入值大，直接往前覆盖
	//依次类推，一直到前面没有数或者找到比待插入值小的数停止
	//最后把暂存的待插入值放到合适的位置
	//时间复杂度：最理想的情况，判断一次，比较一次：2n;最恶劣的情况，第一次挪一个，第二次挪两个，n^2/2。 O(n^2)
	int temp;
	int j;
	for (int i= 1; i < len; i++)
	{
		temp = a[i];
		j = i - 1; //j从i-1开始
		while (j >= 0 && a[j] > a[i])
		{
			a[j + 1] = a[j]; //往后覆盖
			j--;
		}
		a[j + 1] = temp; //temp覆盖回来
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