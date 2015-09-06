/*求最小公倍数 
通过 100分*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max(int a, int b)
{
	return((a > b) ?a:b);
}

int main120()
{
	int a, b;
	int res;
	scanf("%d %d",&a,&b);
	for(int k = max(a,b); k <= a*b; k++)
	{
	    if((!(k%a))&&(!(k%b)))
		{
		    res = k;
			break;
		}			
	}
	cout << res << endl;
	system("PAUSE");
    return 0;
}