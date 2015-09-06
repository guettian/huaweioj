/*
   字符串反转 ，OJ通过100分
*/
#include <iostream>
#include <string>

using namespace std;

char* stringreverse(string str)
{
	int len = str.length();
	char* rev = (char*)malloc(sizeof(char)*len);
//	string::iterator iter, iter1;
//	for(iter == str.begin(), iter1 = rev.end(); iter != str.end())
	for(int i = 0, j = len-1; i <= len-1, j >=0; i++, j--)
	{
		*(rev+j) = str[i];
	}
	*(rev+len) = '\0';
	return rev;
}

int main8(int argc, char *argv[])
{
	string str;
	char* rev;
	getline(cin,str);
	rev = stringreverse(str);
	cout << rev << endl;
	free(rev);
	system("PAUSE");
    return 0;
}