/*ѧϰӢ��
   ����ͨ��������OJ ˵�𰸴���
   �Ҿ���Ӧ�ö�����ȷ��
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int da[10] = {1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
string st1[10] = {"billion", "hundred", "", "million", "hundred", "", "thousand", "hundred", "", ""};
string st2[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};   //10~19������
string gewei[10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; //1~9������
string shiwei[8] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};  // 20,30,40...

vector<string> to_eng(unsigned long d)
{
	vector<string> svec;
	int temp;
	int numi = 0;
	for(int i = 0; i <=9; i++)                              //����ʮλ��
	{
		if((i+1)%3)                                            //��ʮλ�� ǧλ�� ��λ�� ��λ��(ǧλ���൱�ڸ�λ��),(����ʮλ������λ��)
		{
		   if (temp = d/da[i])
		   {	
			   numi++;
			   d = d % da[i];
			   if(((i+2)%3 == 0)||(i%3 == 0))                                          //��λ�� ǧλ��    �Ը�λҲ���ܲ���������ʮλ������,��Ϊǧλ����λ
		        {
					if((i+2)%3 == 0)                               //numi��ʾ���ǵ�һ�����ֵ�����
				         svec.push_back(gewei[temp]);     //seven
					if((i%3 == 0)&&(numi == 1))
						svec.push_back(gewei[temp]);
				    svec.push_back(st1[i]);                 //hundred,thousand
//					if((st1[i] == "hundred")&&(d%da[i+1] != 0))
//						svec.push_back("and");
			   }
//			   else if(d/da[i-1] != 1)                                            //��λ��,����ʮλ��������1
//			   {
//				   svec.push_back(gewei[temp]);     //seven
//				   svec.push_back(st1[i]);                 //hundred,thousand
//			   }
		   }
			else                                                  //temp = 0
				continue;
		 }
		 else                                                    //����ʮλ��
		{
		   if (temp = d/da[i])
		   {
			   numi++;
			   d = d % da[i];
			   if(temp == 1)
			   {	
				   if(d/da[i+1])
				         svec.push_back("and");
				   svec.push_back(st2[(d)/da[i+1]]);		//thirteen   
			   }
			   else
			   {
				   if(d/da[i+1])
				         svec.push_back("and");
				   svec.push_back(shiwei[temp-2]);               //fourty 
				   svec.push_back(gewei[(d)/da[i+1]]);          //five   ������λ
			   }
		   }
		   else if(numi != 0)                           //ʮλ��=0������ǰ��������
		   {
			      d = d % da[i];
				  if (d/da[i+1])
				  {
			          svec.push_back("and");
				  
		          svec.push_back(gewei[(d)/da[i+1]]);        //װ���λ��
				  }
		   }
		   else                                                           //temp = 0�����ͳͳ��������
			   continue;
		}	   
	}
	return svec;
}

int main520()
{
	unsigned long d;	
	vector<string> svec;
	vector<string>::iterator iter;
	scanf("%d",&d);
	svec = to_eng(d);
	for(iter = svec.begin(); iter != svec.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;
	system("pause");
    return 0;
}