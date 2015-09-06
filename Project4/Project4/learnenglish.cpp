/*学习英语
   测试通过，但是OJ 说答案错误
   我觉得应该都是正确的
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int da[10] = {1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
string st1[10] = {"billion", "hundred", "", "million", "hundred", "", "thousand", "hundred", "", ""};
string st2[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};   //10~19的内容
string gewei[10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; //1~9的内容
string shiwei[8] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};  // 20,30,40...

vector<string> to_eng(unsigned long d)
{
	vector<string> svec;
	int temp;
	int numi = 0;
	for(int i = 0; i <=9; i++)                              //遍历十位数
	{
		if((i+1)%3)                                            //非十位数 千位数 百位数 个位数(千位数相当于个位数),(到了十位数检查个位数)
		{
		   if (temp = d/da[i])
		   {	
			   numi++;
			   d = d % da[i];
			   if(((i+2)%3 == 0)||(i%3 == 0))                                          //百位数 千位数    对个位也不能操作，交给十位来操作,此为千位，百位
		        {
					if((i+2)%3 == 0)                               //numi表示不是第一个出现的数字
				         svec.push_back(gewei[temp]);     //seven
					if((i%3 == 0)&&(numi == 1))
						svec.push_back(gewei[temp]);
				    svec.push_back(st1[i]);                 //hundred,thousand
//					if((st1[i] == "hundred")&&(d%da[i+1] != 0))
//						svec.push_back("and");
			   }
//			   else if(d/da[i-1] != 1)                                            //个位数,并且十位数不等于1
//			   {
//				   svec.push_back(gewei[temp]);     //seven
//				   svec.push_back(st1[i]);                 //hundred,thousand
//			   }
		   }
			else                                                  //temp = 0
				continue;
		 }
		 else                                                    //操作十位数
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
				   svec.push_back(gewei[(d)/da[i+1]]);          //five   操作各位
			   }
		   }
		   else if(numi != 0)                           //十位数=0，但是前面有数字
		   {
			      d = d % da[i];
				  if (d/da[i+1])
				  {
			          svec.push_back("and");
				  
		          svec.push_back(gewei[(d)/da[i+1]]);        //装填个位数
				  }
		   }
		   else                                                           //temp = 0的情况统统让它继续
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