#pragma once
#ifndef __BD_PROTOCOL_4_0_H
#define __BD_PROTOCOL_4_0_H
#include "malloc.h"
#include <string.h>
#include "SerialPort.h"  

const int RE_BUFFER_SIZE = 2047;
typedef unsigned int  UINT;
typedef unsigned char  UCHR; 
extern int(*myprint)(_In_z_ _Printf_format_string_ char const* const, ...);
#define GNTX_LENTH 0x12
#define GNPX_LENTH 0x20
//#define GNVX_LENTH 
struct RE_BUFFER
{
	UINT wp;
	UINT rp;
	UCHR buffer[RE_BUFFER_SIZE];
};
extern RE_BUFFER rebuff;


struct BD_DWSQ  //��λ����
{
	const static UINT lenth = 22;
	UCHR xxlb;//��Ϣ���
	UINT gcsstxg;//�߳����ݺ����߸�
	UINT qyss;//��ѹ����
	UINT rzpd;//��վƵ��
};

struct BD_TXSQ //ͨ������
{
	const static UINT lenth = 18;//��������������
	UCHR xxlb;//��Ϣ���
	UCHR yhdz[3];//�û���ַ
	UINT dwcd;//���ĳ���
	UCHR sfyd;//�Ƿ�Ӧ��
					   //UCHR dwnr[1680];//��������
};

struct BD_CKSC //�������
{
	const static UINT lenth = 12;
	UCHR cssl;//��������
};

struct BD_ICJC //ic���
{
	const UINT lenth = 12;
	UCHR zh;//֡��
};

struct BD_XTZJ //ϵͳ�Լ�
{
	const UINT lenth = 13;
	UINT zjpd;//�Լ�Ƶ��
};

struct BD_SJSC //ʱ�����
{
	const UINT lenth = 13;
	UINT scpd;//���Ƶ��
};

struct BD_BBDQ
{
	const UINT lenth = 11;
};
#define DWXX_LENTH (11+1+3+4+4+4+2+2)
struct BD_DWXX
{
	UCHR xxlb;//��Ϣ���
	UCHR cxdz[3];//��ѯ��ַ
	UINT T;//��λʱ��
	UINT L;//�û�λ�õĴ�ؾ�������
	unsigned  int B;//�û�λ�õĴ��γ������
	UINT H;//�û�λ�õĴ�ظ߳�����
	UINT S;//�û�λ�õĸ߳��쳣ֵ
};


struct BD_TXXX
{
	UCHR xxlb;//��Ϣ���
	UCHR fxfdz[3];//���ŷ���ַ
	UCHR fxsj_h;//����ʱ�䣨Сʱ��
	UCHR fxsj_m;//����ʱ�䣨���ӣ�
	UINT  dwcd;//���ĳ���
	UCHR dwnr[210];//��������
	UCHR crc;//CRC��־
};

#define ICXX_LENTH (11+1+3+1+2+1+1+2)
struct BD_ICXX
{
	UCHR yhdz[3];//�û���ַ
	UCHR zh;//֡��
	UINT tbid;//ͨ��ID
	UCHR yhtz;//�û�����
	UINT fwpd;//����Ƶ��
	UCHR txdj;//ͨ�ŵȼ�
	UCHR jmbz;//���ܱ�־
	UINT xsyhzs;//�����û�����
};

#define ZJXX_LENTH (11+1+1+1+1+6)
struct BD_ZJXX //�Լ���Ϣ
{
	UCHR iczt;//IC��״̬
	UCHR yjzt;//Ӳ��״̬
	UCHR dcdl;//��ص���
	UCHR rzzt;//��վ״̬
	UCHR bsgl[6];//��������1-6
};

#define SJXX_LENTH (11+2+1+1+1+1+1)
struct BD_SJXX //ʱ����Ϣ
{
	UINT year;
	UCHR month;
	UCHR day;
	UCHR hour;
	UCHR minute;
	UCHR second;
};

struct BD_BBXX // �汾��Ϣ
{

};

#define FKXX_LENTH (11+1+4)

struct BD_FKXX //������Ϣ
{
	UCHR flbz;//������־
	UCHR fjxx[4];//������Ϣ
};

struct BDXX
{
	struct BD_BBDQ bbdq;
	struct BD_BBXX bbxx;
	struct BD_CKSC cksc;
	struct BD_DWSQ dwsq;
	struct BD_DWXX dwxx;
	struct BD_FKXX fkxx;
	struct BD_ICJC icjc;
	struct BD_ICXX icxx;
	struct BD_SJSC sjsc ;
	struct BD_SJXX sjxx;
	struct BD_TXSQ txsq;
	struct BD_TXXX txxx;
	struct BD_XTZJ xtzj;
	struct BD_ZJXX zjxx;
};

void init();
void check_status();
void icjc_send();
void xyzj_send();
void sjsc_send();
void dwsq_send();
void txsq_send(const char *buffer, UINT len, UCHR *dis);
UCHR xor_checksum(UCHR *buf, UINT location, UINT len);
UCHR xor_checksum2(UCHR *buf, UINT len);
void Extract_DWXX(UCHR *buf, UINT i);
void print_dwxx();
void Extract_TXXX(UCHR *buf, UINT i);
void print_txxx();
void Extract_ICXX(UCHR *buf, UINT i);
void print_icxx();
void Extract_ZJXX(UCHR *buf, UINT i);
void print_zjxx();
void Extract_SJXX(UCHR *buf, UINT i);
void print_sjxx();
void Extract_FKXX(UCHR *buf, UINT i);
void print_fkxx();
void Receive_Protocol();
bool check_overflow(RE_BUFFER *buff, UINT value);
void Analysis_data(const UCHR *fxfdz, const UCHR h, const UCHR m, const UCHR *buffer, const UINT package_length);
void DATA_Handler(const UCHR *fxfdz, const UCHR h, const UCHR m, const UCHR *data, const UINT lenth);

#endif


