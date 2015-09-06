#include <iostream>
#include <string>

using namespace std;

int man()
{
    string inputString;
	//cin >> inputString;
	getline(cin, inputString);
	for(string::size_type i = inputString.size(); i>0; i--)
	{
		cout << inputString[i-1];
	}
	cout <<endl;
	return 0;
}