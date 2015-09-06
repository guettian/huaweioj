#include <iostream>
#include <string>

using namespace std;

int CalcCapital(string str)
{
	int count = 0;
//  string* p = &str;
	for(int i = 0;i != str.size(); i++)
	{
		if(i > str.size())
			return errno;
	    if((str[i]>='A') && (str[i]<='Z'))
			count++;		
	}
	return count;
}

int main1()
{
    int count;
	string s;
//	while(1)
//	{
	getline(cin,s);
	count = CalcCapital(s);
	cout << count <<endl;
//	}	
	system("PAUSE");
	return 0;
}