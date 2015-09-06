/* 计算字符个数 
    OJ通过得了60分*/
#include <iostream>
#include <string>

using namespace std;

int calcnum(string str, char s)
{
	int count = 0;
	string::iterator iter;
	for(iter = str.begin(); iter != str.end(); ++iter)
	{
		if((s == *iter) || (s == *iter -32) || (s == *iter +32))
			count++;
	}
	return count;
}

int main7()
{
	string str;
	char s;
	getline(cin,str);
	cin >> s;
	cout << calcnum(str, s) << endl;
	system("PAUSE");
    return 0;
}