/* �ַ����ӽ��� (������) */
#include <iostream>
#include <string>

using namespace std;

string Encrypt (string aucPassword);
string unEncrypt (string result);

int main4()
{
	string auc,res;
	cout << "����һ��Ҫ���ܵ�����" << endl;
	getline(cin, auc);
	cout << "����һ���ӹ��ܵ�����" << endl;
	getline(cin,res);
	cout << "������ܺ������" << Encrypt(auc) << endl;
	cout << "������ܺ������" << unEncrypt(res) << endl;
	system("PAUSE");
	return 0;
}

string Encrypt (string aucPassword)
{
	string::iterator iter;
	for(iter = aucPassword.begin(); iter != aucPassword.end(); ++iter)
	{
		if((*iter >= 'a')&&(*iter <'z'))
		{
			*iter -= static_cast<char>(31);
		}
		if(*iter == 'z')
		{
		    *iter = 'A';
		}
		if((*iter >= 'A')&&(*iter <'Z'))
		{
		    *iter += static_cast<char>(33);
		}
		if(*iter == 'Z')
		{
		    *iter = 'a';
		}
		if((*iter >= '0')&&(*iter <='8'))
		{
		    *iter +=  static_cast<char>(1);
		}
		if(*iter=='9')
		{
		    *iter =  '0';
		}
	}
	return aucPassword;
}

string unEncrypt (string result)
{
	string::iterator iter;
	for(iter = result.begin(); iter != result.end(); ++iter)
	{
		if((*iter >= 'A')&&(*iter <='Z'))
		{
			if(*iter == 'A')
		    {
		          *iter = 'z';
		    }
			else
			{
                  *iter += static_cast<char>(31);
			}				
		}
		
		if((*iter >= 'b')&&(*iter <='z'))
		{
		    *iter -= static_cast<char>(33);
		}
		if(*iter == 'a')
		{
		    *iter = 'Z';
		}
		if((*iter >= '1')&&(*iter <='9'))
		{
		    *iter -=  static_cast<char>(1);
		}
		if(*iter=='0')
		{
		    *iter =  '9';
		}
	}
	return result;
}
