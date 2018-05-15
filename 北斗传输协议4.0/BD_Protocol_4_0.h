/***********************Project Version1.0*************************
@��Ŀ��:��������4.0(C++)
@File:BD_Protocol_4_0.h
@File_Version:1.0a
@Author:lys
@QQ:591986780
@UpdateTime:2018��5��16��02:39:46

@˵��:��Ŀͷ�ļ�

���������C++�ı����̱��Ĵ������
��VS2017������ͨ��

Viual Studio 2017 Version:V141
Windows SDK Version:10.0.16299.0
******************************************************************/
#pragma once
#ifndef __BD_PROTOCOL_4_0_H
#define __BD_PROTOCOL_4_0_H
#include "malloc.h"
#include <string.h>
#include "SerialPort.h"  

#define DATA_FIRM_LENTH 6
#define BD_PRINT_TIME_SEQ 8
#define BD_PRINT_GNPX_SEQ 5
#define BD_PRINT_GNTX_ZONE 5
#define BD_PRINT_GNTX_SEQ 5
#define BD_PRINT_GNVX_SEQ 5
const int RE_BUFFER_SIZE = 4095;
typedef unsigned int  UINT;
typedef unsigned char  UCHR;
extern int(*myprint)(_In_z_ _Printf_format_string_ char const* const, ...);
extern UCHR SEND_BLOCKTIME;

//�ڰ�λΪ�ظ�λ������λΪȷ��λ,����λԤ��,1-5λ����
#define STEP_NONE 0
#define STEP_ICJC 1
#define STEP_XJZJ 2
#define STEP_SJSC 0X0F
#define STEP_GNPS 3
#define STEP_GNVS 4
#define STEP_GNTS 5
#define STEP_READY 10
#define STATUS_BIT_STEP 0x1f

#define STATUS_BIT_ANSWER (1<<7)
#define STATUS_BIT_NO_ANSWER (0<<7)
#define STATUS_BIT_CONFIRM (1<<6)
#define STATUS_BIT_NO_CONFIRM (0<<6)
struct RE_BUFFER
{
	UINT wp;
	UINT rp;
	UCHR buffer[RE_BUFFER_SIZE + 1];
};
extern RE_BUFFER rebuff;

extern UCHR status;
#define GNTX_LENTH 0x12
struct BD_GNTX
{
	char sqlx;//ʱ������
	UCHR year;
	UCHR month;
	UCHR day;
	UCHR hour;
	UCHR minute;
	UCHR second;
};
#define GNPX_LENTH 0x20

struct BD_GNPX //BDS&GPS��λ��Ϣ
{
	UCHR jdfw;//���ȷ�Χ
	UCHR jd;//����
	UCHR jf;//����
	UCHR jm;//����
	UCHR jxm;//��С��
	UCHR wdfw;//γ�ȷ�Χ
	UCHR wd;//γ��
	UCHR wf;//γ��
	UCHR wm;//γ��
	UCHR wxm;//γС��
	int gd;//�߶�
	UINT sd;//�ٶ�
	UINT fx; //����
	UCHR wxs;//������
	UCHR zt;//״̬
	UCHR jdxs;//����ϵ��
	UINT gjwc;//�������
};
//#define GNVX_LENTH 
struct WXXX
{
	UCHR wxbh;//���Ǳ��
	UCHR wxyj;//��������
	UINT fwj;//��λ��
	UCHR xzb;//�����
};
struct BD_GNVX
{
	UCHR wxlb;//�������
	UCHR wxgs;//���Ǹ���
	WXXX wxxx[64];//������Ϣ
};
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
	struct BD_SJSC sjsc;
	struct BD_SJXX sjxx;
	struct BD_TXSQ txsq;
	struct BD_TXXX txxx;
	struct BD_XTZJ xtzj;
	struct BD_ZJXX zjxx;
	struct BD_GNTX gntx;
	struct BD_GNPX gnpx;
	struct BD_GNVX gnvx;
};
extern BDXX bdxx;
void init();
void check_status();
void icjc_send();
void xtzj_send();
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
void Extract_GNTX(UCHR *buf, UINT i);
void print_gntx();
void Extract_GNPX(UCHR *buf, UINT i);
void print_gnpx();
void Extract_GNVX(UCHR *buf, UINT i);
void print_gnvx();
void Receive_Protocol();
bool check_overflow(RE_BUFFER *buff, UINT value);
void Analysis_data(const UCHR *fxfdz, const UCHR h, const UCHR m, const UCHR *buffer, const UINT package_length);
void DATA_Handler(const UCHR *fxfdz, const UCHR h, const UCHR m, const UCHR *data, const UINT lenth);
UINT UCHRtoUINT(UCHR a, UCHR b);
char* data_encapsulation(char *send_buffer, const char *data, const UINT length_data);
void bd_send(const char *buffer, UINT len, UCHR *dis);
void Handle_FXXX();
void Handle_ZJXX();
INT UCHRtoINT(UCHR a, UCHR b);
void gnps_send();
void gnts_send();
void gnvs_send();
#endif __BD_PROTOCOL_4_0_H