#define _CRT_SECURE_NO_WARNINGS
#include"common.h"

/* 全局变量定义 */
char musics[10][100];/* 字符串数组，用于存储歌曲名称，最大可以存储10首歌 */
unsigned int num = 0;/* 歌曲当前位置，即数组下标 */
unsigned int total = 0;/* 总曲目 */
unsigned int liststate = 0;/* 其值代表鼠标指到的歌曲的序号, 0代表鼠标没有位于列表处 */
unsigned int temp = 0;/* 作为判断列表鼠标位置的中间变量 */
bool state = false;/* 播放状态，fause为暂停，true为播放 */
bool begin = false;/* 是否已经开始播放 */
char path[] = ".\\music";

int main() 
{
	/* 遍历文件夹，获取歌曲名称到字符数组,没有读取到文件就发出提示信息并返回 */
	if (search(path) == 0)
	{
		printf("music文件夹内没有读取到mp3文件\n");
		system("pause");
		return 0;
	}
	initgraph(800, 600);
	setbkmode(TRANSPARENT);/* 设置背景为透明 */
	load_image();/* 加载界面图片 */

	/* 循环检测鼠标状态,获取事件信息 */
	while (true)
	{
		m = GetMouseMsg(); /* 获取一条鼠标信息 */
		if (m.uMsg == WM_LBUTTONDOWN)/* 鼠标左键点击 */
		{
			mouse_click();
		}
		if (m.uMsg == WM_MOUSEMOVE)/* 鼠标移动 */
		{
			mouse_move();
		}
	}

	return 0;
}