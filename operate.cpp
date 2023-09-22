#define _CRT_SECURE_NO_WARNINGS
#include"common.h"

/* �����ļ��У���ȡ������������ */
int search(char* lpPath)
{
	char szFind[100], szFile[100];
	WIN32_FIND_DATA FindFileData; /* ��FindFirstFile����Ŀ¼ */
	HANDLE hFind;/* �����ļ��ľ�� */
	strcpy(szFind, lpPath);
	strcat(szFind, "\\*.mp3");
	hFind = FindFirstFile(szFind, &FindFileData);
	if (INVALID_HANDLE_VALUE == hFind)
	{
		return total;
	}
	while (TRUE)
	{
		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if (FindFileData.cFileName[0] != '.')
			{
				strcpy(szFile, lpPath);
				strcat(szFile, "\\");
				strcat(szFile, FindFileData.cFileName);
				search(szFile);
			}
		}
		else
		{
			strcpy(musics[total], FindFileData.cFileName);/* FindFileData.cFileName���ļ��� */
			total++;
		}
		if (!FindNextFile(hFind, &FindFileData))
		{
			break;
		}
	}
	return total;
}

/* �������� */
void play(const char name[])
{
	char pathname[100] = "music\\";/* ����·���� */
	char opencmd[100] = "open ";
	char playcmd[100] = "play ";
	char repeat[10] = " repeat";
	strcat(pathname, name);
	GetShortPathName(pathname, pathname, 100);/* �˵��ļ�·���Ŀո� */
	strcat(opencmd, pathname);
	strcat(playcmd, pathname);
	strcat(playcmd, repeat);
	mciSendString(opencmd, NULL, 0, NULL);
	mciSendString(playcmd, NULL, 0, NULL);
	displaycurmusic(num);
}

/* ��ͣ���� */
void pause(const char name[])
{
	char pathname[100] = "music\\";/* ����·���� */
	char pausecmd[100] = "pause ";
	strcat(pathname, name);
	GetShortPathName(pathname, pathname, 100);/* �˵��ļ�·���Ŀո� */
	strcat(pausecmd, pathname);
	mciSendString(pausecmd, NULL, 0, NULL);
}

/* �������� */
void resume(const char name[])
{
	char pathname[100] = "music\\";/* ����·���� */
	char resumecmd[100] = "resume ";
	strcat(pathname, name);
	GetShortPathName(pathname, pathname, 100);/* �˵��ļ�·���Ŀո� */
	strcat(resumecmd, pathname);
	mciSendString(resumecmd, NULL, 0, NULL);
}

/* ֹͣ���� */
void stop(const char name[])
{
	char pathname[100] = "music\\";/* ����·���� */
	char stopcmd[100] = "stop ";
	char closecmd[100] = "close ";
	strcat(pathname, name);
	GetShortPathName(pathname, pathname, 100);/* �˵��ļ�·���Ŀո� */
	strcat(stopcmd, pathname);
	strcat(closecmd, pathname);
	mciSendString(stopcmd, NULL, 0, NULL);
	mciSendString(closecmd, NULL, 0, NULL);
}

/* ��һ�� */
void upnextmode()
{
	/* �����ǵ�һ��*/
	if (0 == num)
	{
	stop(musics[num]);
	num = total - 1;/* �ص����һ�� */
	play(musics[num]);
	displaycurmusic(num);
	}
	/* �������ǵ�һ�� */
	else
	{
		stop(musics[num]);
		num--;/* �ص���һ�� */
		play(musics[num]);
		displaycurmusic(num);
	}
}

/* ��һ�� */
void downnextmode() 
{
	/* ���������һ��*/
	if (total - 1 == num)
	{
		stop(musics[num]);
		num = 0;/* �ص���һ�� */
		play(musics[num]);
		displaycurmusic(num);
	}
	/* �����������һ��*/
	else
	{
		stop(musics[num]);
		num++;/* ��һ�� */
		play(musics[num]);
		displaycurmusic(num);
	}
}

/* ���15�� */
void plus15(const char name[])
{
	int position;
	char pathname[100] = "music\\";/* ����·���� */
	char st[100];
	char text[100];
	char cmd1[100] = "status ";
	char text1[20] = " position";
	char cmd2[100] = "seek ";
	char text2[20] = " to ";
	char cmd3[100] = "play ";
	char repeat[10] = " repeat";

	strcat(pathname, name);
	GetShortPathName(pathname, pathname, 100);/* �˵��ļ�·���Ŀո� */
	strcat(cmd1, pathname);
	strcat(cmd1, text1);
	mciSendString(cmd1, st, 100, 0);
	position = atoi(st);
	position += 15000;
	_itoa(position, text, 10);
	strcat(cmd2, pathname);
	strcat(cmd2, text2);
	strcat(cmd2, text);
	mciSendString(cmd2, NULL, 0, NULL);
	strcat(cmd3, pathname);
	strcat(cmd3, repeat);
	mciSendString(cmd3, NULL, 0, NULL);
}

/* ����15�� */
void minus15(const char name[])
{
	int position;
	char pathname[100] = "music\\";/* ����·���� */
	char st[100];
	char text[100];
	char cmd1[100] = "status ";
	char text1[20] = " position";
	char cmd2[100] = "seek ";
	char text2[20] = " to ";
	char cmd3[100] = "play ";
	char repeat[10] = " repeat";

	strcat(pathname, name);
	GetShortPathName(pathname, pathname, 100);/* �˵��ļ�·���Ŀո� */
	strcat(cmd1, pathname);
	strcat(cmd1, text1);
	mciSendString(cmd1, st, 100, 0);
	position =  atoi(st);
	position -= 15000;
	_itoa(position, text, 10);
	strcat(cmd2, pathname);
	strcat(cmd2, text2);
	strcat(cmd2, text);
	mciSendString(cmd2, NULL, 0, NULL);
	strcat(cmd3, pathname);
	strcat(cmd3, repeat);
	mciSendString(cmd3, NULL, 0, NULL);
}

/* �������� */
void volumeUp(const char name[])
{
	int volume = 0;
	char pathname[100] = "music\\";/* ����·���� */
	char vo[20];
	char res[260];
	char cmd1[100] = "status ";
	char text1[20] = " volume";
	char cmd2[100] = "setaudio ";
	char text2[20] = " volume to ";

	strcat(pathname, name);
	GetShortPathName(pathname, pathname, 100);/* �˵��ļ�·���Ŀո� */
	strcat(cmd1, pathname);
	strcat(cmd1, text1);
	mciSendString(cmd1, res, 260, NULL);
	volume = atoi(res);
	volume += 100;
	_itoa(volume, vo, 10);
	strcat(cmd2, pathname);
	strcat(cmd2, text2);
	strcat(cmd2, vo);
	mciSendString(cmd2, NULL, 0, NULL);
}

/* ������С */
void volumeDown(const char name[]) {
	int volume = 0;
	char pathname[100] = "music\\";/* ����·���� */
	char vo[20];
	char res[260];
	char cmd1[100] = "status ";
	char text1[20] = " volume";
	char cmd2[100] = "setaudio ";
	char text2[20] = " volume to ";

	strcat(pathname, name);
	GetShortPathName(pathname, pathname, 100);/* �˵��ļ�·���Ŀո� */
	strcat(cmd1, pathname);
	strcat(cmd1, text1);
	mciSendString(cmd1, res, 260, NULL);
	volume = atoi(res);
	volume -= 100;
	_itoa(volume, vo, 10);
	strcat(cmd2, pathname);
	strcat(cmd2, text2);
	strcat(cmd2, vo);
	mciSendString(cmd2, NULL, 0, NULL);
}

/* ѡ�񲥷� */
void select(int choose)
{
	stop(musics[num]);
	num = choose;
	play(musics[num]);
	displaycurmusic(num);
}

/* �ж�����ƶ����б��λ�� */
int list_judge(unsigned int x, unsigned int y)
{
	for (unsigned int i = 0; i < total; i++)
	{
		if (x > 20 && x<780 && y>(10 + i * 48) && y < (10 + (i + 1) * 48)) {
			return i + 1;
		}
	}

	return 0;
}