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
	long sum;  //总和

	//multiset是有序可重复的
	multiset<int> lower; //储存最小的k个值
	multiset<int> middle;  //储存其他值
	multiset<int> upper; //储存最大的k个值

	queue<int> nums; //所有数据队列
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

	if (lower.size() && *lower.rbegin() >= num)  //如果lower不等于空，而且num小于等于lower里面的最大值
	{
		lower.insert(num);
	}
	else if (upper.size() && *upper.begin() <= num) //如果upper不等于空，而且num大于等于upper里面的最小值
	{
		upper.insert(num);
	}
	else   //注意前m个数直接插入middle
	{
		middle.insert(num);
		sum += num;
	}


	//可能出现lower或者upper的数量大于k的情况，都先移动到middle，并且重新计算sum
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

	if (nums.size() > m) //如果nums的数量超过m个
	{
		//为了保持数据最多只有m个，并且只取流中的最后m个元素，也就是保留后插入的
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

	if (nums.size() >= m) //如果数量达到m
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
