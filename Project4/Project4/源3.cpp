/*
   删除出现次数最少的字符
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string shanChuCishuZuishao(string str)
{
	int iarr[26] = {0};
	int i;
	string::iterator it;                //定义iterator不能写成str.iterator
	for(it = str.begin(); it != str.end(); ++it){
		switch(*it)
		{
		case 'a': ++iarr[0];break;
		case 'b': ++iarr[1];break;
		case 'c': ++iarr[2];break;
		case 'd': ++iarr[3];break;
		case 'e': ++iarr[4];break;
		case 'f': ++iarr[5];break;
		case 'g': ++iarr[6];break;
		case 'h': ++iarr[7];break;
		case 'i': ++iarr[8];break;
		case 'j': ++iarr[9];break;
		case 'k': ++iarr[10];break;
		case 'l': ++iarr[11];break;
		case 'm': ++iarr[12];break;
		case 'n': ++iarr[13];break;
		case 'o': ++iarr[14];break;
		case 'p': ++iarr[15];break;
		case 'q': ++iarr[16];break;
		case 'r': ++iarr[17];break;
		case 's': ++iarr[18];break;
		case 't': ++iarr[19];break;
		case 'u': ++iarr[20];break;
		case 'v': ++iarr[21];break;
		case 'w': ++iarr[22];break;
		case 'x': ++iarr[23];break;
		case 'y': ++iarr[24];break;
		case 'z': ++iarr[25];break;
		}
	}
	int tem2 = 0;
	for(i = 0; i != 26; ++i){
		if(iarr[i] != 0){tem2 = iarr[i];break;}        //break是出for循环的
	}
	for(i = 0; i != 26; ++i){
		if(iarr[i] != 0 && iarr[i] != tem2){break;}
	}
	if(i == 26)
		return str;                                             //判断是否所有出现的字符次数都相等，只需要比较第一个出现字符与后面任意出现字符次数的比较
	int tem = 20;
	vector<char> v;
	for(i = 0; i !=26; ++i){
		if(iarr[i] < tem && iarr[i] != 0){
			tem = iarr[i];
		}
	}                                                             // 统计出现字符最少的次数
	for(i = 0; i !=26; ++i){
		if(iarr[i] == tem){
			v.push_back(static_cast<char>(i)+'a');
		}
	}
	for(it = str.begin(); it != str.end(); ++it){
		for(vector<char>::iterator iter = v.begin(); iter !=v.end(); ++iter){
			if(*it == *iter){
				it = str.erase(it);
				--it;
				break;                                         //用迭代的话方便进行增加或者删除操作
			}
		}
	}
	return str;
}

int mai1n()
{
	string str;
	cin>>str;
	cout<<shanChuCishuZuishao(str)<<endl;
	system("PAUSE");
	return 0;
	
}
