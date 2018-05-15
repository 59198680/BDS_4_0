/***********************Project Version1.0*************************
@��Ŀ��:��������4.0(C++)
@File:main.cpp
@File_Version:1.0a
@Author:lys
@QQ:591986780
@UpdateTime:2018��5��16��02:39:46

@˵��:���ºÿ�ͷ

���������C++�ı����̱��Ĵ������
��VS2017������ͨ��

Viual Studio 2017 Version:V141
Windows SDK Version:10.0.16299.0
******************************************************************/

#include "SerialPort.h"  
#include  <iostream>
#include "BD_Protocol_4_0.h" 

DWORD WINAPI myfun1(LPVOID lpParameter);                   //�����̺߳��� 
DWORD WINAPI myfun2(LPVOID lpParameter);
DWORD myfun1(LPVOID lpParameter)
{
	while (1)
	{
		Receive_Protocol();
		Sleep(1);
	}

	return 0;
}
DWORD myfun2(LPVOID lpParameter)
{
	while (1)
	{
		check_status();
		if (SEND_BLOCKTIME)
			--SEND_BLOCKTIME;
		Sleep(1000);
	}

	return 0;
}
int main()
{
	HANDLE h1, h2;                                         //����������  
	init();
	if (!mySerialPort.InitPort(2))
	{
		std::cout << "initPort fail !" << std::endl;
	}
	else
	{
		std::cout << "initPort success !" << std::endl;
	}

	if (!mySerialPort.OpenListenThread())
	{
		std::cout << "OpenListenThread fail !" << std::endl;
	}
	else
	{
		std::cout << "OpenListenThread success !" << std::endl;
	}
	h1 = ::CreateThread(NULL, 0, myfun1, NULL, 0, NULL);   //�����߳�  
	h2 = ::CreateThread(NULL, 0, myfun2, NULL, 0, NULL);
	while (1)
	{
		//myprint("1\n");
	}

	return 0;
}
