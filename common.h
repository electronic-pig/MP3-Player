/* �����ṩ�Ľӿ� */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<graphics.h>/* ͼ�ο�ͷ�ļ� */
#include<mmsystem.h>/* mci��ͷ�ļ� */
#pragma comment(lib,"winmm.lib")/* ����/ָ��MCI�⣬mciSendString�����Ķ�����winmm.lib�� */

/* ȫ�ֱ������� */
extern char musics[10][100];/* �ַ������飬���ڴ洢�������ƣ������Դ洢10�׸� */
extern unsigned int num;/* ������ǰλ�ã����������±� */
extern unsigned int total;/* ����Ŀ */
extern unsigned int liststate;/* ��ֵ�������ָ���ĸ��������, 0�������û��λ���б� */
extern bool state;/* ����״̬��0Ϊ��ͣ��1Ϊ���� */
extern bool begin;/* �Ƿ��Ѿ���ʼ���� */
extern unsigned int temp;/* ��Ϊ�ж��б����λ�õ��м���� */

extern MOUSEMSG m;/* �����Ϣ */

extern IMAGE namecoverimage;
extern IMAGE background;
extern IMAGE playimage, playactiveimage;
extern IMAGE dnextimage, dnextactiveimage;
extern IMAGE unextimage, unextactiveimage;
extern IMAGE pauseimage, pauseactiveimage;
extern IMAGE stopimage, stopactiveimage;
extern IMAGE listimage, listactiveimage;
extern IMAGE volplusimage, volplusactiveimage;
extern IMAGE volminusimage, volminusactiveimage;
extern IMAGE volsignimage;
extern IMAGE curplayimage;
extern IMAGE plus15image, plus15activeimage;
extern IMAGE minus15image, minus15activeimage;

/* �������� */
/* operate.c */
extern int search(char* lpPath);            /* �����ļ��У���ȡ������������ */
extern void play(const char name[]);         /* �������� */
extern void pause(const char name[]);		 /* ��ͣ���� */
extern void resume(const char name[]);       /* �������� */
extern void stop(const char name[]);         /* ֹͣ���� */
extern void upnextmode();                    /* ��һ�� */
extern void downnextmode();                  /* ��һ�� */
extern void plus15(const char name[]);		 /* ���15�� */
extern void minus15(const char name[]);      /* ����15�� */
extern void volumeUp(const char name[]);     /* �������� */
extern void volumeDown(const char name[]);   /* ������С */
extern void select(int choose);              /* ѡ�񲥷� */
extern int list_judge(unsigned int x, unsigned int y);		 /* �ж�����ƶ����б��λ�� */

/* gui.c */
extern void load_image();                    /* ����ͼƬ */
extern void displaycurmusic(int num);        /* ��ʾ��ǰ���ڲ��ŵĸ������� */
extern void putmusicname(int i);             /* �Ѹ����������б� */

/* mouse_event.c */
extern void mouse_click();                   /* ������¼� */
extern void mouse_move();				     /* ����ƶ��¼� */