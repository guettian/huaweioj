/*
   名字的漂亮度
   测试通过，未能通过OJ
*/
#include <iostream>
#include <string>

using namespace std;

//#define LEN (26);

int calcbeauty(string s)                //寻找字符串出现次数最多的字符
{
	int len = s.length(); 
	int num[26] = {0};
	int index,temp;
	int result = 0;
	string::iterator iter;
	for(iter = s.begin(); iter !=s.end(); ++iter)
	{
	     if((*iter >= 'a')&&(*iter <= 'z'))
		 {
			 index = static_cast<int>(*iter - 'a');
			 num[index]++;
		 }
		 if((*iter >= 'A')&&(*iter <= 'Z'))
		{
			 index = static_cast<int>(*iter - 'A');
			 num[index]++;
		 }
	}
    for(int i = 0; i < 26; i++)
	{
		for(int j = 25; j > i; j--)
		{
			if(num[j-1] < num[j])
			{
				temp = num[j];
				num[j] = num[j-1];
				num[j-1] = temp;
			}
		}
	}
	int shu = 26;
	for(int k = 0; k <= 25; k++)
	{
	    if(num[k] != 0)
		{
			result += num[k]*shu;
			shu --;
		}
	}
	return result;
}

int main6()
{
	string name[3];
	int beauty[3];
//	cin >> name[0] >> name[1] >> name[2];
	getline(cin, name[0]);
	getline(cin, name[1]);
	getline(cin, name[2]);
	for(int i = 0; i <= 2; i++)
	{
	     beauty[i] = calcbeauty(name[i]);
		 if(beauty[i] != 0)
	          cout << beauty[i] << '\n';
	}  
	cout << endl;
	system("PAUSE");
	return 0;
}