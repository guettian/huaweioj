/*DNA序列
   OJ测试通过 100分
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string DNAsequence(string str, int n)
{
	int count;
	vector<int> ivec;
	vector<string> svec;
	if(n > str.size())
		return NULL;
	for(int i = 0; i < (str.size()-n); i++)
	 {
		  count = 0;
		  for(int j = i; j < i+n; j++)
		  {
			  if((str[j] == 'G') || (str[j] == 'C'))
				  count++;
		  }
		  ivec.push_back(count);
		  svec.push_back(str.substr(i, n));
	 }
	int max = *ivec.begin();
	string res = *svec.begin();
	vector<int>::iterator iter;
	vector<string>::iterator it;
	if(!ivec.empty())
	{
		for(iter = ivec.begin(), it = svec.begin(); iter != ivec.end(), it!= svec.end(); ++iter, ++it)
	    {
	        if(max < *iter)
			{
			   max = *iter;
			   res = *it;
			}
	    }
	}
	return res;
}

int main0()
{
	string str;
	int n;
	cin >> str >> n;
	cout << DNAsequence(str, n) << endl;
	system("PAUSE");
    return 0;
}