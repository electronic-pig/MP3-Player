/* 对外提供的接口 */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<graphics.h>/* 图形库头文件 */
#include<mmsystem.h>/* mci库头文件 */
#pragma comment(lib,"winmm.lib")/* 链接/指定MCI库，mciSendString函数的定义在winmm.lib中 */

/* 全局变量声明 */
extern char musics[10][100];/* 字符串数组，用于存储歌曲名称，最大可以存储10首歌 */
extern unsigned int num;/* 歌曲当前位置，，即数组下标 */
extern unsigned int total;/* 总曲目 */
extern unsigned int liststate;/* 其值代表鼠标指到的歌曲的序号, 0代表鼠标没有位于列表处 */
extern bool state;/* 播放状态，0为暂停，1为播放 */
extern bool begin;/* 是否已经开始播放 */
extern unsigned int temp;/* 作为判断列表鼠标位置的中间变量 */

extern MOUSEMSG m;/* 鼠标信息 */

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

/* 方法声明 */
/* operate.c */
extern int search(char* lpPath);            /* 遍历文件夹，获取音乐名到数组 */
extern void play(const char name[]);         /* 播放音乐 */
extern void pause(const char name[]);		 /* 暂停播放 */
extern void resume(const char name[]);       /* 继续播放 */
extern void stop(const char name[]);         /* 停止播放 */
extern void upnextmode();                    /* 上一曲 */
extern void downnextmode();                  /* 下一曲 */
extern void plus15(const char name[]);		 /* 快进15秒 */
extern void minus15(const char name[]);      /* 快退15秒 */
extern void volumeUp(const char name[]);     /* 音量增大 */
extern void volumeDown(const char name[]);   /* 音量减小 */
extern void select(int choose);              /* 选择播放 */
extern int list_judge(unsigned int x, unsigned int y);		 /* 判断鼠标移动到列表的位置 */

/* gui.c */
extern void load_image();                    /* 加载图片 */
extern void displaycurmusic(int num);        /* 显示当前正在播放的歌曲名字 */
extern void putmusicname(int i);             /* 把歌曲名放入列表 */

/* mouse_event.c */
extern void mouse_click();                   /* 鼠标点击事件 */
extern void mouse_move();				     /* 鼠标移动事件 */