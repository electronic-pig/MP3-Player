#include"common.h"

MOUSEMSG m; /* �����Ϣ */;

/* ������¼� */
void mouse_click()
{
	/* ���õ��Ч�� */
	setrop2(R2_XORPEN);
	for (int i = 0; i <= 10; i++)
	{
		setlinecolor(RGB(25 * i, 25 * i, 25 * i));/* ����Բ��ɫ */
		circle(m.x, m.y, 2 * i);
		Sleep(30);
		circle(m.x, m.y, 2 * i);                  /* Ĩȥ�ոջ���Բ */
	}

	/* play��pause */
	if (m.x > 360 && m.x < 410 && m.y>530 && m.y < 580)
	{
		/* ��ͣ״̬ */
		if (!state)
		{
			putimage(360, 530, &pauseactiveimage);
			state = true;
			/* ���û�п�ʼ���Ϳ�ʼ���� */
			if (!begin)
			{
				play(musics[num]);
				begin = true;
			}
			/* ����Ѿ���ʼ���ͼ������� */
			else
			{ 
				resume(musics[num]);
			}
		}
		/* ����״̬ */
		else
		{
			putimage(360, 530, &playactiveimage);
			state = false;
			pause(musics[num]);
		}
	}
	/* stop */
	else if (m.x > 480 && m.x < 530 && m.y>530 && m.y < 580)
	{
		stop(musics[num]);
		begin = false;
		state = 0;
		putimage(360, 530, &playimage);
	}
	/* upnext */
	else if (m.x > 300 && m.x < 350 && m.y>530 && m.y < 580)
	{
		putimage(20, 10 + (num * 48), &listimage);
		putmusicname(num);
		upnextmode();
		putimage(20, 10 + (num * 48), &curplayimage);
		putmusicname(num);
		state = true;
		putimage(360, 530, &playimage);
	}
	/* downnext */
	else if (m.x > 420 && m.x < 470 && m.y>530 && m.y < 580)
	{
		putimage(20, 10 + (num * 48), &listimage);
		putmusicname(num);
		downnextmode();
		putimage(20, 10 + (num * 48), &curplayimage);
		putmusicname(num);
		state = true;
		putimage(360, 530, &playimage);
	}
	/* volumeUp */
	else if (m.x > 250 && m.x < 275 && m.y>530 && m.y < 555)
	{
		volumeUp(musics[num]);
	}
	/* volumeDown */
	else if (m.x > 250 && m.x < 275 && m.y>560 && m.y < 585)
	{
		volumeDown(musics[num]);
	}
	/* +15s */
	else if (m.x > 550 && m.x < 575 && m.y>530 && m.y < 555)
	{
		plus15(musics[num]);
	}
	/* -15s */
	else if (m.x > 550 && m.x < 575 && m.y>556 && m.y < 581)
	{
		minus15(musics[num]);
	}

	/* �ж��������λ��,�������˸����б����л����� */
	if (list_judge(m.x, m.y) != 0)
	{
		putimage(20, 10 + (num * 48), &listimage);
		putmusicname(num);
		putimage(20, 10 + ((list_judge(m.x, m.y) - 1) * 48), &curplayimage);
		putmusicname(list_judge(m.x, m.y) - 1);
		select(list_judge(m.x, m.y) - 1);/* �л����� */
		state = true;
		putimage(360, 530, &pauseimage);
	}
	FlushMouseMsgBuffer();       /* ��������Ϣ������ */
}

/* ����ƶ��¼�*/
void mouse_move()
{
	/*  ѡ��״̬ */
	/* pause */
	if (m.x > 360 && m.x < 410 && m.y>530 && m.y < 580 && state == false)
	{
		putimage(360, 530, &playactiveimage);
	}
	/* play */
	else if (m.x > 360 && m.x < 410 && m.y>530 && m.y < 580 && state == true)
	{
		putimage(360, 530, &pauseactiveimage);
	}
	/* upnext */
	else if (m.x > 300 && m.x < 350 && m.y>530 && m.y < 580)
	{
		putimage(300, 530, &unextactiveimage);
	}
	/* downnext */
	else if (m.x > 420 && m.x < 470 && m.y>530 && m.y < 580)
	{
		putimage(420, 530, &dnextactiveimage);
	}
	/* stop */
	else if (m.x > 480 && m.x < 530 && m.y>530 && m.y < 580)
	{
		putimage(480, 530, &stopactiveimage);
	}
	/* volumeUp */
	else if (m.x > 250 && m.x < 275 && m.y>530 && m.y < 555)
	{
		putimage(250, 530, &volplusactiveimage);
	}
	/* volumeDown */
	else if (m.x > 250 && m.x < 275 && m.y>560 && m.y < 585)
	{
		putimage(250, 560, &volminusactiveimage);
	}
	/* +15s */
	else if (m.x > 550 && m.x < 575 && m.y>530 && m.y < 555)
	{
		putimage(550, 530, &plus15activeimage);
	}
	/* -15s */
	else if (m.x > 550 && m.x < 575 && m.y>556 && m.y < 581)
	{
		putimage(550, 556, &minus15activeimage);
	}
	/* ��ѡ��״̬ */
	else
	{
		if (state)
		{
			putimage(360, 530, &pauseimage);
		}
		else
		{
			putimage(360, 530, &playimage);
		}
		putimage(300, 530, &unextimage);
		putimage(420, 530, &dnextimage);
		putimage(480, 530, &stopimage);
		putimage(250, 530, &volplusimage);
		putimage(250, 560, &volminusimage);
		putimage(550, 530, &plus15image);
		putimage(550, 556, &minus15image);
	}

	/* ���ָ����ָ��λ�÷����仯 */
	if (list_judge(m.x, m.y) != temp)
	{
		/* ָ���λ�ò����б��� */
		if (list_judge(m.x, m.y) == 0)
		{
			putimage(20, 10 + ((temp - 1) * 48), &listimage);
			putmusicname(temp - 1);
			putimage(20, 10 + (num * 48), &curplayimage);
			putmusicname(num);
		}
		/* ָ���λ�����б��� */
		else
		{
			putimage(20, 10 + ((temp - 1) * 48), &listimage);
			putmusicname(temp - 1);
			putimage(20, 10 + ((list_judge(m.x, m.y) - 1) * 48), &listactiveimage);
			putmusicname(list_judge(m.x, m.y) - 1);
			putimage(20, 10 + (num * 48), &curplayimage);
			putmusicname(num);
		}
		temp = list_judge(m.x, m.y);/* ��¼ָ���λ�� */
	}
}