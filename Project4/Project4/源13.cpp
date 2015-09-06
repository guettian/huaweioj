/*���߳�
   OJû��ͨ��
*/

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

static int pos = 0;
void init();  //��ʼ������
void Release(); //��Դ�ͷź���
DWORD __stdcall ThreadFun1(PVOID pM); //�̺߳���1������һ��int���͵�ָ��[ȡֵ��Χ��1 �C 250������������֤]�����ڳ�ʼ�����A��������Դ��Ҫ�߳��ͷ�
DWORD __stdcall ThreadFun2(PVOID pM);//�̺߳���2���޲�������
DWORD __stdcall ThreadFun3(PVOID pM);//�̺߳���3���޲�������
DWORD __stdcall ThreadFun4(PVOID pM);//�̺߳���4���޲�������
char  g_write[1032] = ""; //�߳�1,2,3,4��˳��������鸳ֵ�����ÿ��������Ƿ�Խ�磬����������֤

CRITICAL_SECTION g_cs;

HANDLE hThread1;
HANDLE hThread2;
HANDLE hThread3;
HANDLE hThread4;

int N = 0; //�û�������ظ�����


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