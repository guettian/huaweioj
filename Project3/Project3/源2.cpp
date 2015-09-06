#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void foo(char *a)
{
      cout << strlen(a) << endl;
}

void main()
{
	char ia[10]="aA";
//	char ia[];
//	char * p = ia;
	cout << sizeof(ia) << endl;
//	ia = "hello";
//	cout << ia[3] <<endl;
	foo(ia);
	system("PAUSE");
}

