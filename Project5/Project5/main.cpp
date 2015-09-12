#include <iostream>
#include <string>

using namespace std;

int calc(int n, int t, int c, int *p)
{
     int num = 0;
	 int temp;
	 if(n < c)
		 return NULL;
	 for(int i = 0; i <= (n-c); i++)
	 {
		 temp = 0;
	     for(int j = i; j < i+c; j++)
		 {
			 temp += *(p+j);
//		     cout << *(p+j) << ' ';
		 }
//		     cout << endl;
			 if(temp <= t)
			 num++;
	 }
	 return num;
}

int main()
{
	int n, t, c;
	int temp;
	cin>>n>>t>>c;
	int *p = (int *)malloc(sizeof(int)*n);	
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&temp); 
	    *(p+i) = temp;
	}
	cout << calc(n, t, c, p) << endl;
	system("pause");
    return 0;
}