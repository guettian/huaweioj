#include <iostream>
#include <string>

using namespace std;

int calc(int m, int n, int **p)
{
    int num = 0;
	for()

}

int main()
{
	int m, n;
	int temp;
	cin>>m>>n;
	int **p = (int **)malloc(sizeof(int)*(m*n));
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
		  scanf("%d",&temp); 
	      *(*(p+i)+j) = temp;
		}
	}
	cout << calc(n, t, c, p) << endl;
	system("pause");
    return 0;
}