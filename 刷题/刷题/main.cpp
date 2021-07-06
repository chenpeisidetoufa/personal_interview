#include <iostream>
#include "Solution.h"
#include "MKAverage.h"

using namespace std;

int main()
{
	Solution sol;
	MKAverage obj = MKAverage(3, 1);
	obj.addElement(3);        // ��ǰԪ��Ϊ [3]
	obj.addElement(1);        // ��ǰԪ��Ϊ [3,1]
	cout << obj.calulateMAAverage() << endl; // ���� -1 ����Ϊ m = 3 ������������ֻ�� 2 ��Ԫ��
	obj.addElement(10);       // ��ǰԪ��Ϊ [3,1,10]
	cout << obj.calulateMAAverage() << endl; // ��� 3 ��Ԫ��Ϊ [3,1,10]
							  // ɾ����С�Լ����� 1 ��Ԫ�غ�����Ϊ [3]
							  // [3] ��ƽ��ֵ���� 3/1 = 3 ���ʷ��� 3
	obj.addElement(5);        // ��ǰԪ��Ϊ [3,1,10,5]
	obj.addElement(5);        // ��ǰԪ��Ϊ [3,1,10,5,5]
	obj.addElement(5);        // ��ǰԪ��Ϊ [3,1,10,5,5,5]
	cout << obj.calulateMAAverage() << endl;; // ��� 3 ��Ԫ��Ϊ [5,5,5]
							  // ɾ����С�Լ����� 1 ��Ԫ�غ�����Ϊ [5]
							  // [5] ��ƽ��ֵ���� 5/1 = 5 ���ʷ��� 5
	return 0;
}