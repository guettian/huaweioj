/*�ҳ��ַ����е�һ��ֻ����һ�ε��ַ� 
   OJͨ������96��
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
		}     //��λ����1����ͳ��
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