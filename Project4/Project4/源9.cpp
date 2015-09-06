/*公共子串计算
   OJ答案错误，得分336（450） 
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int getCommonStrLength(string pFirstStr, string pSecondStr)
{
//	 string::iterator iter1, iter2;
	int count = 0, temp;
	int i = 0, j;
	vector<int> ivec;
	transform(pFirstStr.begin(), pFirstStr.end(), pFirstStr.begin(), tolower);
	transform(pSecondStr.begin(), pSecondStr.end(), pSecondStr.begin(), tolower);
	while(i < pFirstStr.size())
	{
		j = 0;
		temp = i;
		while(j < pSecondStr.size())
		{
			if (pFirstStr[i] == pSecondStr[j])
			{
				count++;
				i++;
				j++;
			}
			else
			{
				i = temp;
				count = 0;
				j++;
			}
			ivec.push_back(count);
		}
		i = temp;
        ++i;
	}
	int res = *ivec.begin();
	for(vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		if(res < *iter)
			res = *iter;
	}
	return res;
}

int main9()
{
	string  s1, s2;
	cin >> s1 >> s2;
	cout << getCommonStrLength(s1, s2) << endl;
	system("PAUSE");
    return 0;
}