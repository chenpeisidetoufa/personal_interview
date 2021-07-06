#pragma once
#include <iostream>
#include <set>
#include <queue>


using namespace std;


class MKAverage
{
public:
	MKAverage(int m, int k);
	~MKAverage();
	void shiftLeft(multiset<int> & l, multiset<int> & r);

	void shiftRight(multiset<int> & l, multiset<int> & r);

	void addElement(int num);

	int calulateMAAverage();

private:
	long m;  //m m>2*k
	long k;  //k
	long sum;  //�ܺ�

	//multiset��������ظ���
	multiset<int> lower; //������С��k��ֵ
	multiset<int> middle;  //��������ֵ
	multiset<int> upper; //��������k��ֵ

	queue<int> nums; //�������ݶ���
};

MKAverage::MKAverage(int m, int k)
{
	this->m = m;
	this->k = k;
	sum = 0;
}

MKAverage::~MKAverage()
{
}

void MKAverage::shiftLeft(multiset<int> & l, multiset<int> & r)
{
	l.insert(*r.begin());
	r.erase(r.begin());
}

void MKAverage::shiftRight(multiset<int> & l, multiset<int> & r)
{
	r.insert(*l.rbegin());
	l.erase(--l.end());
}

void MKAverage::addElement(int num)
{
	nums.push(num);

	if (lower.size() && *lower.rbegin() >= num)  //���lower�����ڿգ�����numС�ڵ���lower��������ֵ
	{
		lower.insert(num);
	}
	else if (upper.size() && *upper.begin() <= num) //���upper�����ڿգ�����num���ڵ���upper�������Сֵ
	{
		upper.insert(num);
	}
	else   //ע��ǰm����ֱ�Ӳ���middle
	{
		middle.insert(num);
		sum += num;
	}


	//���ܳ���lower����upper����������k������������ƶ���middle���������¼���sum
	while (lower.size() > k)
	{
		sum += *lower.rbegin();
		shiftRight(lower, middle);
	}
	while (upper.size() > k)
	{
		sum += *upper.begin();
		shiftLeft(middle, upper);
	}

	if (nums.size() > m) //���nums����������m��
	{
		//Ϊ�˱����������ֻ��m��������ֻȡ���е����m��Ԫ�أ�Ҳ���Ǳ���������
		int d = nums.front();
		nums.pop();
		if (lower.find(d) != lower.end())
		{
			lower.erase(lower.find(d));
		}
		else if (middle.find(d) != middle.end())
		{
			middle.erase(middle.find(d));
			sum -= d;
		}
		else
		{
			upper.erase(upper.find(d));
		}
	}

	if (nums.size() >= m) //��������ﵽm
	{
		while (lower.size() < k)
		{
			sum -= *middle.begin();
			shiftLeft(lower, middle);
		}
		while (upper.size() < k)
		{
			sum -= *middle.rbegin();
			shiftRight(middle, upper);
		}
	}
}

int MKAverage::calulateMAAverage()
{
	if (nums.size() < m)
	{
		return -1;
	}
	else
	{
		return sum / (m - 2*k);
	}
}
