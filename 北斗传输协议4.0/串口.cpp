// chuankou1.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include<iostream>  
#include<windows.h>  

using namespace std;

int main123()
{
	//�����Ǵ򿪴���ͨ��
	HANDLE hCom=NULL;  //ȫ�ֱ��������ھ��
	/*hCom = CreateFile("\\\\.\\COM11",  //COM11��
		GENERIC_READ | GENERIC_WRITE, //�������д
		0,  //��ռ��ʽ
		NULL,
		OPEN_EXISTING,  //�򿪶����Ǵ���
		0, //�첽  1Ϊͬ��
		NULL);*/
	if (hCom == (HANDLE)-1)
	{
		cout << "�򿪴���ʧ��" << endl;
		return -1;
	}
	else {
		cout << "�򿪴��ڳɹ�" << endl;
	}
	SetupComm(hCom, 1024, 1024);
	//��ʱ
	// ����ͨ�ų�ʱʱ�� SET THE COMM TIMEOUTS.
	COMMTIMEOUTS timeouts;
	timeouts.ReadIntervalTimeout = 0;
	timeouts.ReadTotalTimeoutMultiplier = 1;
	timeouts.ReadTotalTimeoutConstant = 1;
	timeouts.WriteTotalTimeoutMultiplier = 1;
	timeouts.WriteTotalTimeoutConstant = 1;
	if (!SetCommTimeouts(hCom, &timeouts)) {
		cout << "��ʱ����ʧ��" << endl;
	}
	else {
		cout << "��ʱ���óɹ�" << endl;
	}
	//ͨ������
	DCB dcb;
	GetCommState(hCom, &dcb);
	dcb.BaudRate = 115200;
	dcb.ByteSize = 8;
	dcb.Parity = 0;
	dcb.StopBits = 1;
	if (SetCommState(hCom, &dcb)) {
		cout << "���ô��ڳɹ�" << endl;
	}

	//���Ͷ�ȡ����
	char data[1];
	memcpy(data, "A", 1);
	DWORD dwWrittenLen = 0;
	char buffer[1];
	DWORD dwReadLen = 0;
	for (int i = 0; i < 10; ++i) {
		if (!WriteFile(hCom, data, 1, &dwWrittenLen, NULL)) {
			cout << "���ʹ�������ʧ��" << endl;
		}
		else {
			cout << "�������ݳɹ���" << data[0] << endl;
		}
		
		if (!ReadFile(hCom, buffer, sizeof(buffer), &dwReadLen, NULL)) {
		cout << "���մ�������ʧ��" << endl;
		}
		else {
		cout << "�������ݣ�"<<hex<<buffer[0] << endl;
		cout << dec;
		}
	}
	//�رմ���
	if (!CloseHandle(hCom)) {
		cout << "�޷��رմ���" << endl;
	}
	else {
		cout << "�رմ��ڳɹ�" << endl;
	}
	while (1);
	return 0;
}