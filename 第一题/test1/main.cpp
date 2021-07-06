#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() 
{
	//存放各个舆情以及总例数
	map<string, int>m1;
	string s;
	while (cin >> s)
	{
		string key;
		int value;
		int pos;
		for (int i = s.length() - 1; i >= 0; i--)
		{
			if (s[i] == ',')
			{
				pos = i;
				break;
			}
		}
		key = s.substr(0, pos);
		value = atoi(s.substr(pos + 1, s.length()).c_str());
		if (m1.find(key) != m1.end())
		{
			m1[key] += value;
		}
		else
		{
			m1[key] = value;
		}
	}
	int count = 0;
	map<string, int>::iterator iter;
	for (iter = m1.begin(); iter != m1.end(); iter++)
	{
		if (iter->second >= 10)
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}