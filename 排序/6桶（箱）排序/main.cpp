#include <iostream>
using namespace std;

#define AREA 1000 //(0~999)

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

//area-数据范围
void BucketSort(int* a, int len, int area)
{
	//从思想：数据分为几个桶，桶内用其他排序算法排序
	//这里使用10进制位数思想
	int idx;
	int k;
	for (int i = 1; i <= area; i*=10)
	{
		//1.创建10个箱子，并且初始化为-1
		int *pTemp = new int[10 * len];
		for (int j = 0; j < 10 * len; j++)
			pTemp[j] = -1;
		//2.把待排数组中的数据，按规律放到箱子里去
		for (int j = 0; j < len; j++)
		{
			idx = a[j] / i % 10;  //个位、十位、百位...上的数值
			*(pTemp + (idx * 10) + j) = a[j];//二维数组表示pTemp[idx][j]
		}
		//3.按照先后次序把箱子里的数据放到待排数组中去
		k = 0;
		for (int j = 0; j < 10 * len; j++)
		{
			if (-1 != pTemp[j])
			{
				a[k++] = pTemp[j];

			}
		}
		//4.释放内存
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