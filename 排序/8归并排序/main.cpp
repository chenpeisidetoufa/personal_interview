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

void merge(int* a, int L, int M, int R) 
{
	//拆成两个数组[L, M], [M + 1, R]
	int LEFT_SIZE = M - L + 1;
	int RIGHT_SIZE = R - M;
	int* left = new int[LEFT_SIZE];
	int* right = new int[RIGHT_SIZE];
	int i, j, k;
	for (i = L; i <= M; i++)
	{
		left[i - L] = a[i];
	}
	for (i = M + 1; i <= R; i++)
	{
		right[i - (M + 1)] = a[i];
	}

	//合并过程
	i = 0; //left的第一个
	j = 0; //right的第一个
	k = L; //数组的第一个

	while (i < LEFT_SIZE && j < RIGHT_SIZE)
	{
		if (left[i] < right[j])
		{
			a[k] = left[i];
			i++;
		}
		else   //>=
		{
			a[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < LEFT_SIZE)  //当j先走到头
	{
		a[k] = left[i];
		i++;
		k++;
	}
	while (j < RIGHT_SIZE)  //当i先走到头
	{
		a[k] = right[j];
		j++;
		k++;
	}

	delete[] left;
	delete[] right;
}


void MergeSort(int* a, int L, int R)
{
	if (L == R) //停止条件，只有一个元素
	{
		return;
	}
	int M = (L + R) / 2;
	MergeSort(a, L, M);
	MergeSort(a, M + 1, R);
	merge(a, L, M, R);
}

int main(int argc, char *args[])
{
	//int arr[11] = { 1,9,66,0,33,5,2,88,666,233,77 };
	//Print(arr, 11);
	//MergeSort(arr, 0, 10);
	//Print(arr, 11, false);
	int arr[6] = { 1,9,66,0,33,5};
	Print(arr, 6);
	MergeSort(arr, 0, 5);
	Print(arr, 6, false);
	return 0;
}