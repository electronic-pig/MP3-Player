#include"common.h"
/* ȫ�ֱ��� */
IMAGE namecoverimage;
IMAGE background;
IMAGE playimage, playactiveimage;
IMAGE dnextimage, dnextactiveimage;
IMAGE unextimage, unextactiveimage;
IMAGE pauseimage, pauseactiveimage;
IMAGE stopimage, stopactiveimage;
IMAGE listimage, listactiveimage;
IMAGE volplusimage, volplusactiveimage;
IMAGE volminusimage, volminusactiveimage;
IMAGE volsignimage;
IMAGE curplayimage;
IMAGE plus15image, plus15activeimage;
IMAGE minus15image, minus15activeimage;

/* ����ͼƬ */
void load_image() 
{
	loadimage(&background, "image\\background.jpg", 800, 600);
	loadimage(&volsignimage, "image\\volsign.jpg", 25, 25);
	loadimage(&namecoverimage, "image\\namecover.jpg", 180, 50);
	loadimage(&playimage, "image\\play.jpg", 50, 50);
	loadimage(&dnextimage, "image\\downnext.jpg", 50, 50);
	loadimage(&unextimage, "image\\upnext.jpg", 50, 50);
	loadimage(&pauseimage, "image\\pause.jpg", 50, 50);
	loadimage(&stopimage, "image\\stop.jpg", 50, 50);
	loadimage(&listimage, "image\\list.jpg", 760, 48);
	loadimage(&curplayimage, "image\\currentplay.jpg", 760, 48);
	loadimage(&playactiveimage, "image\\play-active.jpg", 50, 50);
	loadimage(&dnextactiveimage, "image\\downnext-active.jpg", 50, 50);
	loadimage(&unextactiveimage, "image\\upnext-active.jpg", 50, 50);
	loadimage(&pauseactiveimage, "image\\pause-active.jpg", 50, 50);
	loadimage(&stopactiveimage, "image\\stop-active.jpg", 50, 50);
	loadimage(&listactiveimage, "image\\list-active.jpg", 760, 48);
	loadimage(&volplusimage, "image\\volumeplus.jpg", 25, 25);
	loadimage(&volplusactiveimage, "image\\volumeplus-active.jpg", 25, 25);
	loadimage(&volminusimage, "image\\volumeminus.jpg", 25, 25);
	loadimage(&volminusactiveimage, "image\\volumeminus-active.jpg", 25, 25);
	loadimage(&plus15image, "image\\plus15.jpg", 25, 25);
	loadimage(&plus15activeimage, "image\\plus15-active.jpg", 25, 25);
	loadimage(&minus15image, "image\\minus15.jpg", 25, 25);
	loadimage(&minus15activeimage, "image\\minus15-active.jpg", 25, 25);

	putimage(0, 0, &background);
	putimage(360, 530, &playimage);
	putimage(300, 530, &unextimage);
	putimage(420, 530, &dnextimage);
	putimage(480, 530, &stopimage);
	putimage(250, 530, &volplusimage);
	putimage(250, 560, &volminusimage);
	putimage(215, 543, &volsignimage);
	putimage(550, 530, &plus15image);
	putimage(550, 556, &minus15image);

	/*��ʼ���б�*/
	for (unsigned int i = 0; i < total; i++)
	{
		putimage(20, 10 + (i * 48), &listimage);/* ���ú���ͼƬ */
		putmusicname(i);/* ���ø��������б� */
	}

	putimage(20, 10 + (num * 48), &curplayimage);/* ���õ�ǰ����ͼƬ */
	putmusicname(num);/* ���ø����� */
}

/*��ʾ��ǰ���ڲ��ŵĸ�������*/
void displaycurmusic(int num) 
{
	putimage(20, 530, &namecoverimage);/* ����ͼƬ */
	RECT R1 = { 20,530 ,200 ,580 }; 
	LOGFONT f;                                    /* ������ʽָ�� */
	gettextstyle(&f);                             /* ��ȡ������ʽ */
	_tcscpy_s(f.lfFaceName, _T("����"));          /* ��������Ϊ���� */
	settextstyle(&f);                             /* ���������ʽ */
	settextcolor(WHITE);						  /* ����������ɫ */
	drawtext(musics[num], &R1, DT_LEFT | DT_VCENTER | DT_SINGLELINE);/* ����룬��ֱ���У�������ʾ */
}

/* �Ѹ����������б� */
void putmusicname(int i) 
{
	RECT R1 = { 50,10 + (i * 48) ,780 , 10 + ((i + 1) * 48) };
	LOGFONT f;                                    /* ������ʽָ�� */
	gettextstyle(&f);                             /* ��ȡ������ʽ */
	_tcscpy_s(f.lfFaceName, _T("����"));          /* ��������Ϊ���� */
	settextstyle(&f);                             /* ���������ʽ */
	settextcolor(BLACK);						  /* ����������ɫ */
	drawtext(musics[i], &R1, DT_LEFT | DT_VCENTER | DT_SINGLELINE);/* ����룬��ֱ���У�������ʾ */
	return;
}