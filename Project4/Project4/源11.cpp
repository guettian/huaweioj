/*判断两个IP是否属于同一子网*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
int checkNetSegment(string mask, string ip1, string ip2)
{
	int pos;
	int temp;
	vector<int> vmask, vip1, vip2;
	vector<int>::iterator iter, iter1, iter2;
	for(pos = 0; pos < mask.size(); ++pos)
	{
		if(mask[pos] = '.')
		{
			temp = static_cast<int>(mask[pos] - '0');
			vmask.push_back(temp);
		}
	}
	for(pos = 0; pos < ip1.size(); ++pos)
	{
		if((ip1[pos] >= '0')&&(ip1[pos] <='9'))
		{
			temp = static_cast<int>(ip1[pos] - '0');
			vip1.push_back(temp);
		}
	}
	for(pos = 0; pos < ip2.size(); ++pos)
	{
		if((ip2[pos] >= '0')&&(ip2[pos] <='9'))
		{
			temp = static_cast<int>(ip2[pos] - '0');
			vip2.push_back(temp);
		}
	}
	for(iter = vmask.begin(), iter1 = vip1.begin(), iter2 = vip2.begin(); iter != vmask.end(), iter1 != vip1.end(), iter2 != vip2.end(); ++iter, ++iter1, ++iter2)
	{
	     
	}
} */

int maindna()
{
	int ip[3] = {0};
	int a[3][4];
	string mask, ip1, ip2;
	for(int i = 0; i < 3; ++i)
	    scanf("%d.%d.%d.%d",&a[i][0], &a[i][1], &a[i][2], &a[i][3]);
	for(int i = 0; i < 3; ++i)
	{
	     for(int j = 0; j < 4; ++j)
		{
		     if(a[i][j] > 255)
			 {
			     cout << 1 << endl;
			     return 0;
			 }				 
		}
	}

    for(int i = 0; i < 3; ++i)
		ip[i] = ((a[i][0] >> 24) | (a[i][1] >> 16) | (a[i][2] >> 8) | a[i][3]);

	if((ip[0] & ip[1]) == (ip[0] & ip[2]))
		cout << '0';
	else
		cout << '2';
	cout << endl;

	system("PAUSE");
    return 0;
}

