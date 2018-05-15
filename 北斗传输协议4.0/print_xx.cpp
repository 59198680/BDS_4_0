/***********************Project Version1.0*************************
@��Ŀ��:��������4.0(C++)
@File:BD_Protocol_4_0.cpp
@File_Version:1.0a
@Author:lys
@QQ:591986780
@UpdateTime:2018��5��16��02:39:46

@˵��:��ӡLOG

���������C++�ı����̱��Ĵ������
��VS2017������ͨ��

Viual Studio 2017 Version:V141
Windows SDK Version:10.0.16299.0
******************************************************************/

#include "BD_Protocol_4_0.h"

void print_dwxx()
{

}

void print_txxx()
{
	myprint("ͨѶ��Ϣ:��Ϣ���:%0x,���ŷ���ַ:%0x,%0x,%0x,����ʱ��:%d:%d,���ĳ���:%dλ,CRC��־%d\n",
		bdxx.txxx.xxlb, bdxx.txxx.fxfdz[0], bdxx.txxx.fxfdz[1], bdxx.txxx.fxfdz[2],
		bdxx.txxx.fxsj_h, bdxx.txxx.fxsj_m, bdxx.txxx.dwcd, bdxx.txxx.crc);
	myprint("��������:");
	for (UINT i = 0; i < bdxx.txxx.dwcd / 8; ++i)
	{
		myprint("%0x ", bdxx.txxx.dwnr[i]);
	}
	myprint("\n");
}

void print_icxx()
{
	printf("ic��Ϣ:�û���ַ:%d,֡��:%d,ͨ��ID:%d,�û�����:%d,����Ƶ��:%d,ͨ�ŵȼ�:%d,���ܱ�־:%d,�����û���:%d\n",
		((UINT)bdxx.icxx.yhdz[0])*(1 << 16) + ((UINT)bdxx.icxx.yhdz[1])*(1 << 8) + (UINT)bdxx.icxx.yhdz[2], bdxx.icxx.zh,
		bdxx.icxx.tbid, bdxx.icxx.yhtz, bdxx.icxx.fwpd, bdxx.icxx.txdj, bdxx.icxx.jmbz, bdxx.icxx.xsyhzs);
}

void print_zjxx()
{
	myprint("ϵͳ�Լ�:IC��%d,Ӳ��״̬%d,��ص���%d,��վ״̬%s,%s\n", bdxx.zjxx.iczt, bdxx.zjxx.yjzt, bdxx.zjxx.dcdl, bdxx.zjxx.rzzt & 0x01 ? "����" : "������", bdxx.zjxx.rzzt & 0x02 ? "�Ǿ�Ĭ" : "��Ĭ");
	myprint("����1:%d,����2:%d,����3:%d������4:%d������5:%d������6:%d\n", bdxx.zjxx.bsgl[0], bdxx.zjxx.bsgl[1], bdxx.zjxx.bsgl[2], bdxx.zjxx.bsgl[3], bdxx.zjxx.bsgl[4], bdxx.zjxx.bsgl[5]);
}

void print_sjxx()
{
	myprint("ʱ����Ϣ:%d��%d��%d��%dʱ%d��%d��\n", bdxx.sjxx.year, bdxx.sjxx.month, bdxx.sjxx.day, bdxx.sjxx.hour, bdxx.sjxx.minute, bdxx.sjxx.second);
}

void print_fkxx()
{
	myprint("������Ϣ:");
	if (bdxx.fkxx.flbz == 0)
	{
		myprint("�ɹ�,ָ��:%c%c%c%c\n", bdxx.fkxx.fjxx[0], bdxx.fkxx.fjxx[1], bdxx.fkxx.fjxx[2], bdxx.fkxx.fjxx[3]);
		if (bdxx.fkxx.fjxx[0] == 'T'&&bdxx.fkxx.fjxx[1] == 'X'&&bdxx.fkxx.fjxx[2] == 'S'&&bdxx.fkxx.fjxx[3] == 'Q')
		{
			myprint("���ͳɹ�\n");
		}
	}
	else if (bdxx.fkxx.flbz == 1)
		myprint("ʧ��,ָ��:%c%c%c%c\n", bdxx.fkxx.fjxx[0], bdxx.fkxx.fjxx[1], bdxx.fkxx.fjxx[2], bdxx.fkxx.fjxx[3]);
	else if (bdxx.fkxx.flbz == 2)
		myprint("�ź�δ����\n");
	else if (bdxx.fkxx.flbz == 3)
		myprint("��������\n");
	else if (bdxx.fkxx.flbz == 4)
		myprint("����Ƶ��δ��,ʱ��:%d��\n", bdxx.fkxx.fjxx[3]);
	else if (bdxx.fkxx.flbz == 5)
		myprint("�ӽ��ܴ���\n");
	else if (bdxx.fkxx.flbz == 6)
		myprint("CRC����,ָ��:%c%c%c%c\n", bdxx.fkxx.fjxx[0], bdxx.fkxx.fjxx[1], bdxx.fkxx.fjxx[2], bdxx.fkxx.fjxx[3]);
	else if (bdxx.fkxx.flbz == 7)
		myprint("�û���������\n");
	else if (bdxx.fkxx.flbz == 8)
		myprint("���ƽ��\n");
}


void print_gntx()
{
	myprint("GNTX:ʱ��:%d,%d��%d��%d��%dʱ%d��%d��\n", bdxx.gntx.sqlx, bdxx.gntx.year + 2000, bdxx.gntx.month, bdxx.gntx.day, bdxx.gntx.hour, bdxx.gntx.minute, bdxx.gntx.second);
}

void print_gnpx()
{
	myprint("GNPX:���ȷ�Χ:%c,����%d,����%d,����%d,��С��%d,γ�ȷ�Χ%c,γ��%d,γ��%d,γ��%d,γС��%d,�߶�:%d\
,�ٶ�%d,����%d,������%d,״̬%d,����ϵ��%d,�������:%d\n", bdxx.gnpx.jdfw, bdxx.gnpx.jd, bdxx.gnpx.jf, bdxx.gnpx.jm, bdxx.gnpx.jxm,
bdxx.gnpx.wdfw, bdxx.gnpx.wd, bdxx.gnpx.wf, bdxx.gnpx.wm, bdxx.gnpx.wxm, bdxx.gnpx.gd, bdxx.gnpx.sd, bdxx.gnpx.fx, bdxx.gnpx.wxs,
bdxx.gnpx.zt, bdxx.gnpx.jdxs, bdxx.gnpx.gjwc);
}
void print_gnvx()
{
	myprint("GNVX:�������:%s,���Ǹ���:%d\n", bdxx.gnvx.wxlb == 1 ? "GPS����" : "BDS����", bdxx.gnvx.wxgs);
}

