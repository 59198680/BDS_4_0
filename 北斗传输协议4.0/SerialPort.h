/***********************Project Version1.0*************************
@��Ŀ��:��������4.0(C++)
@File:SerialPort.h
@File_Version:1.0a
@Author:lys
@QQ:591986780
@UpdateTime:2018��5��16��02:39:46

@˵��:����ͷ�ļ�

���������C++�ı����̱��Ĵ������
��VS2017������ͨ��

Viual Studio 2017 Version:V141
Windows SDK Version:10.0.16299.0
******************************************************************/

#ifndef SERIALPORT_H_  
#define SERIALPORT_H_   
#include <windows.h>  
#include "stdio.h"
#include <process.h>
#include <iostream>

class CSerialPort
{
public:
	CSerialPort(void);
	~CSerialPort(void);

public:


	bool InitPort(UINT  portNo = 1, UINT  baud = CBR_9600, char  parity = 'N', UINT  databits = 8, UINT  stopsbits = 1, DWORD dwCommEvents = EV_RXCHAR);


	bool InitPort(UINT  portNo, const LPDCB& plDCB);


	bool OpenListenThread();


	bool CloseListenTread();


	bool WriteData(unsigned char* pData, unsigned int length);


	UINT GetBytesInCOM();


	bool ReadChar(char &cRecved);

private:


	bool openPort(UINT  portNo);


	void ClosePort();


	static UINT WINAPI ListenThread(void* pParam);

private:


	HANDLE  m_hComm;


	static bool s_bExit;


	volatile HANDLE    m_hListenThread;


	CRITICAL_SECTION   m_csCommunicationSync;       //!< �����������  

};
extern CSerialPort mySerialPort;
#endif //SERIALPORT_H_ #pragma once
