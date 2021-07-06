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

void ShellSort(int* a, int len)
{
	//核心思想，优化插入排序中的不必要的后挪
	//引用步长，按照步长分组，组内做插入排序
	//步长每次折半
	int step = len / 2;
	int temp;
	int j;
	while (step)
	{
		//内部使用插入排序(交错执行)
		for (int i = step; i < len; i++) //从步长开始，每组都要
		{
			temp = a[i];
			j = i - step; //*在组内
			while (j >= 0 && a[j] > a[i])
			{
				a[j + step] = a[j]; //往后覆盖
				j -= step;
			}
			a[j + step] = temp; //temp覆盖回来
		}
		step = step / 2;
	}
}

int main(int argc, char *args[])
{
	int arr[11] = { 1,9,66,0,33,5,2,88,666,233, 77 };
	Print(arr, 11);
	ShellSort(arr, 11);
	Print(arr, 11, false);

	//int arr[10] = { 1,9,66,0,33,5,2,88,666,233 };
	//Print(arr, 10);
	//ShellSort(arr, 10);
	//Print(arr, 10, false);
	return 0;
}