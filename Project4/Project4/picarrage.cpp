/*Í¼Æ¬ÕûÀí*/
#include <iostream>
#include <cstring>

using namespace std;

/*string sort(string str)
{
	string str1, str2, str3;
	for(int i = 0; i < str.size(); i++)
	{
	    if(str[i] >= '0')&&(str[i] <= '9')
		{
		    
		}
	    if(str[i] >= 'A')&&(str[i] <= 'Z')
		if(str[i] >= 'a')&&(str[i] <= 'z')
	}
}*/
/*
int main()
{
	char s[256];
	memset(s, 0, sizeof(s));
	char c;
	while((c=getchar()) && (c!=EOF))
	{		
	        s[c]++;
	}
	for(int i = 0; i < 256; i++)
	{
		while(s[i]--)
			 cout << static_cast<char>(i);
	}
	system("pause");
	
   return 0;
} */

int cmp(const void* p1, const void* p2)
{return *(char*)p1 - *(char*)p2;}
/*
int main()
{
    char s[1024];
    gets(s);
    qsort(s, strlen(s), sizeof(char), cmp);
    puts(s);
    return 0;
} */