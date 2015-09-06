#include <iostream>
#include <string>

using namespace std;

#define MAXSIZE 200


int min_pos(int c[])
{
	int len = sizeof(c)/4;
	int tmp;
	for(int i = len-1; i >= 0; i--)
	{
	    if(c[i] == 0)
		{
		     len--;

		}
		if((c[i] != 0)&&(c[i] < c[i+1]))
		 {
			 tmp = c[i];
		     c[i] = c[i+1];
			 c[i+1] = c[i];
		 }
	}
	return 0;
}

int main2()
{
    string s;
	int c[MAXSIZE] = {0};
	getline(cin,s);	
	int n = 0;
	int len = s.length();
	for(int i = 0; i < len; i++)
	{
/*      if(s[i] < 'a' || s[i] > 'z')
	   {
		 for(int j = 0; j < len; j++)
	      {
	           if(s[i] == s[j])
			          c[i]++;
	      }
	    }    */
	    n = s[i];
	    c[n]++;
	}
	for(int j = 0; j <= MAXSIZE; j++)
	{
	    
	}

	cout << len;
	system("PAUSE");
	return 0;
}