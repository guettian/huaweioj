/*多线程
   OJ没有通过
*/

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

static int pos = 0;
void init();  //初始化函数
void Release(); //资源释放函数
DWORD __stdcall ThreadFun1(PVOID pM); //线程函数1，传入一个int类型的指针[取值范围：1 – 250，测试用例保证]，用于初始化输出A次数，资源需要线程释放
DWORD __stdcall ThreadFun2(PVOID pM);//线程函数2，无参数传入
DWORD __stdcall ThreadFun3(PVOID pM);//线程函数3，无参数传入
DWORD __stdcall ThreadFun4(PVOID pM);//线程函数4，无参数传入
char  g_write[1032] = ""; //线程1,2,3,4按顺序向该数组赋值。不用考虑数组是否越界，测试用例保证

CRITICAL_SECTION g_cs;

HANDLE hThread1;
HANDLE hThread2;
HANDLE hThread3;
HANDLE hThread4;

int N = 0; //用户输入的重复次数


void init()
{
	InitializeCriticalSection(&g_cs);
	cin >> N;
	hThread1 = CreateThread(NULL, 0, ThreadFun1, &N, CREATE_SUSPENDED, NULL);
	hThread2 = CreateThread(NULL, 0, ThreadFun2, NULL, CREATE_SUSPENDED, NULL);
	hThread3 = CreateThread(NULL, 0, ThreadFun3, NULL, CREATE_SUSPENDED, NULL);
	hThread4 = CreateThread(NULL, 0, ThreadFun4, NULL, CREATE_SUSPENDED, NULL);
	ResumeThread(hThread1);
}

void Release()
{
	DeleteCriticalSection(&g_cs);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	CloseHandle(hThread3);
	CloseHandle(hThread4);
}

int mainthread()
{
	init();
	while(pos < 4*N)
		Sleep(2);
	cout << g_write <<endl;
	Release();
	system("PAUSE");
    return 0;
}

DWORD __stdcall ThreadFun1(PVOID pM)  
{
	int *p = (int *)pM;
	while(pos < *p*4)
	{
		EnterCriticalSection(&g_cs);
		g_write[pos++] = 'A';
		LeaveCriticalSection(&g_cs);
		ResumeThread(hThread2);
		SuspendThread(hThread1);
		Sleep(2);
	}
	return 0;
}

DWORD __stdcall ThreadFun2(LPVOID pM) 
{
	while(1)
	{
		EnterCriticalSection(&g_cs);
		g_write[pos++] = 'B';
		LeaveCriticalSection(&g_cs);
		ResumeThread(hThread3);
		SuspendThread(hThread2);
		Sleep(2);
	}
	return 0;
}

DWORD __stdcall ThreadFun3(PVOID pM) 
{
	while(1)
	{
		EnterCriticalSection(&g_cs);
		g_write[pos++] = 'C';
		LeaveCriticalSection(&g_cs);
		ResumeThread(hThread4);
		SuspendThread(hThread3);
		Sleep(2);
	}
	return 0;
}

DWORD __stdcall ThreadFun4(PVOID pM)
{
	while(1)
	{
		EnterCriticalSection(&g_cs);
		g_write[pos++] = 'D';
		LeaveCriticalSection(&g_cs);
		Sleep(2);
		ResumeThread(hThread1);
		SuspendThread(hThread4);
	}
	return 0;
}