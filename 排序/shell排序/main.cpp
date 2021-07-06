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

void ShellSort(int* a, int len)
{
	//����˼�룬�Ż����������еĲ���Ҫ�ĺ�Ų
	//���ò��������ղ������飬��������������
	//����ÿ���۰�
	int step = len / 2;
	int temp;
	int j;
	while (step)
	{
		//�ڲ�ʹ�ò�������(����ִ��)
		for (int i = step; i < len; i++) //�Ӳ�����ʼ��ÿ�鶼Ҫ
		{
			temp = a[i];
			j = i - step; //*������
			while (j >= 0 && a[j] > a[i])
			{
				a[j + step] = a[j]; //���󸲸�
				j -= step;
			}
			a[j + step] = temp; //temp���ǻ���
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