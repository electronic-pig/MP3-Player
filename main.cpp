#define _CRT_SECURE_NO_WARNINGS
#include"common.h"

/* ȫ�ֱ������� */
char musics[10][100];/* �ַ������飬���ڴ洢�������ƣ������Դ洢10�׸� */
unsigned int num = 0;/* ������ǰλ�ã��������±� */
unsigned int total = 0;/* ����Ŀ */
unsigned int liststate = 0;/* ��ֵ�������ָ���ĸ��������, 0�������û��λ���б� */
unsigned int temp = 0;/* ��Ϊ�ж��б����λ�õ��м���� */
bool state = false;/* ����״̬��fauseΪ��ͣ��trueΪ���� */
bool begin = false;/* �Ƿ��Ѿ���ʼ���� */
char path[] = ".\\music";

int main() 
{
	/* �����ļ��У���ȡ�������Ƶ��ַ�����,û�ж�ȡ���ļ��ͷ�����ʾ��Ϣ������ */
	if (search(path) == 0)
	{
		printf("music�ļ�����û�ж�ȡ��mp3�ļ�\n");
		system("pause");
		return 0;
	}
	initgraph(800, 600);
	setbkmode(TRANSPARENT);/* ���ñ���Ϊ͸�� */
	load_image();/* ���ؽ���ͼƬ */

	/* ѭ��������״̬,��ȡ�¼���Ϣ */
	while (true)
	{
		m = GetMouseMsg(); /* ��ȡһ�������Ϣ */
		if (m.uMsg == WM_LBUTTONDOWN)/* ��������� */
		{
			mouse_click();
		}
		if (m.uMsg == WM_MOUSEMOVE)/* ����ƶ� */
		{
			mouse_move();
		}
	}

	return 0;
}