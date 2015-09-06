/*汽水瓶*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int qishui(int n)    //n代表的是空瓶子的数目
{
	int sha = n/3;
    int res = n%3;
	int ret = 0;
	if(!sha)
		return 0;
	if(sha == 1)
	{
	    ret = sha;		
	    if(res)
		  ret++;
		return ret;
	}
		
	while((sha != 1)&&(sha))
	{
	    ret += sha;
		sha = sha/3;
	}	
	if(res)
		ret += 2;
	else
	    ret++;
	return ret;	
}

int main()
{
	vector<int> ivec;
	int i=0;
	int d;

	while(scanf("%d",&d))
	{
		if(d)
	       cout << qishui(d) << ' ';
		else
			break;
	}
	cout << endl;	

	system("pause");
    return 0;
}