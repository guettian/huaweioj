/*蛇形矩阵*/
#include <iostream>
#include <string>

using namespace std;

void GetResult(int Num, char* pResult)
{
	*pResult = '1';
	for(int i = 1; i <= Num; i++)           //遍历行
	{
		for(int j = 1; j <= (Num-i+1); i++)     //遍历列
	          ;
	}
}

int main5()
{
	char* p[] = {"stinn","sada",};
	char **q = p;
	string s = "sasada";
	cout << **p << endl;
	cout << &s;
//	p[] = {"strang","sdaf",};
	cout << p << *q << endl;
	system("PAUSE");
     return 0;
}