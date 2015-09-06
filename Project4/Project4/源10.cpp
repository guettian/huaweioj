/*找出字符串中第一个只出现一次的字符 
   OJ通过得了96分
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char FindChar(string pInputString)
{
	int num[26] = {0};
	int pos;
	int p;
	vector<int> ivec;
	for(int i = 0; i < pInputString.size(); i++)
	{
		pos = static_cast<int>(pInputString[i] - 'a');
		if(!num[pos])
		{
			num[pos] += (i*100 + 1);
		}     //百位数的1用来统计
		else
			num[pos]++;
//		ivec.push_back(i);
	}
	for(int j = 0; j < 26; j++)
	{
	    if(num[j]%100 == 1)
			ivec.push_back(num[j]);
	}
	if(ivec.empty())
		return '.';
	int min = *ivec.begin();
	for(vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		if(min > *iter)
			min = *iter;
	}
	p = min/100;
	return pInputString[p];
}

int main10()
{
	string str;
	cin >> str;
	cout << FindChar(str) << endl;
	system("PAUSE");
    return 0;
}