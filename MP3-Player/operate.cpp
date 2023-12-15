#define _CRT_SECURE_NO_WARNINGS
#include"common.h"

/* 遍历文件夹，获取音乐名到数组 */
int search(char* lpPath)
{
	char szFind[100], szFile[100];
	WIN32_FIND_DATA FindFileData; /* 用FindFirstFile遍历目录 */
	HANDLE hFind;/* 查找文件的句柄 */
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
			strcpy(musics[total], FindFileData.cFileName);/* FindFileData.cFileName是文件名 */
			total++;
		}
		if (!FindNextFile(hFind, &FindFileData))
		{
			break;
		}
	}
	return total;
}

/* 播放音乐 */
void play(const char name[])
{
	char pathname[100] = "music\\";/* 歌曲路径名 */
	char opencmd[100] = "open ";
	char playcmd[100] = "play ";
	char repeat[10] = " repeat";
	strcat(pathname, name);
	GetShortPathName(pathname, pathname, 100);/* 滤掉文件路径的空格 */
	strcat(opencmd, pathname);
	strcat(playcmd, pathname);
	strcat(playcmd, repeat);
	mciSendString(opencmd, NULL, 0, NULL);
	mciSendString(playcmd, NULL, 0, NULL);
	displaycurmusic(num);
}

/* 暂停播放 */
void pause(const char name[])
{
	char pathname[100] = "music\\";/* 歌曲路径名 */
	char pausecmd[100] = "pause ";
	strcat(pathname, name);
	GetShortPathName(pathname, pathname, 100);/* 滤掉文件路径的空格 */
	strcat(pausecmd, pathname);
	mciSendString(pausecmd, NULL, 0, NULL);
}

/* 继续播放 */
void resume(const char name[])
{
	char pathname[100] = "music\\";/* 歌曲路径名 */
	char resumecmd[100] = "resume ";
	strcat(pathname, name);
	GetShortPathName(pathname, pathname, 100);/* 滤掉文件路径的空格 */
	strcat(resumecmd, pathname);
	mciSendString(resumecmd, NULL, 0, NULL);
}

/* 停止播放 */
void stop(const char name[])
{
	char pathname[100] = "music\\";/* 歌曲路径名 */
	char stopcmd[100] = "stop ";
	char closecmd[100] = "close ";
	strcat(pathname, name);
	GetShortPathName(pathname, pathname, 100);/* 滤掉文件路径的空格 */
	strcat(stopcmd, pathname);
	strcat(closecmd, pathname);
	mciSendString(stopcmd, NULL, 0, NULL);
	mciSendString(closecmd, NULL, 0, NULL);
}

/* 上一曲 */
void upnextmode()
{
	/* 歌曲是第一首*/
	if (0 == num)
	{
	stop(musics[num]);
	num = total - 1;/* 回到最后一首 */
	play(musics[num]);
	displaycurmusic(num);
	}
	/* 歌曲不是第一首 */
	else
	{
		stop(musics[num]);
		num--;/* 回到上一首 */
		play(musics[num]);
		displaycurmusic(num);
	}
}

/* 下一曲 */
void downnextmode() 
{
	/* 歌曲是最后一首*/
	if (total - 1 == num)
	{
		stop(musics[num]);
		num = 0;/* 回到第一首 */
		play(musics[num]);
		displaycurmusic(num);
	}
	/* 歌曲不是最后一首*/
	else
	{
		stop(musics[num]);
		num++;/* 下一首 */
		play(musics[num]);
		displaycurmusic(num);
	}
}

/* 快进15秒 */
void plus15(const char name[])
{
	int position;
	char pathname[100] = "music\\";/* 歌曲路径名 */
	char st[100];
	char text[100];
	char cmd1[100] = "status ";
	char text1[20] = " position";
	char cmd2[100] = "seek ";
	char text2[20] = " to ";
	char cmd3[100] = "play ";
	char repeat[10] = " repeat";

	strcat(pathname, name);
	GetShortPathName(pathname, pathname, 100);/* 滤掉文件路径的空格 */
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

/* 快退15秒 */
void minus15(const char name[])
{
	int position;
	char pathname[100] = "music\\";/* 歌曲路径名 */
	char st[100];
	char text[100];
	char cmd1[100] = "status ";
	char text1[20] = " position";
	char cmd2[100] = "seek ";
	char text2[20] = " to ";
	char cmd3[100] = "play ";
	char repeat[10] = " repeat";

	strcat(pathname, name);
	GetShortPathName(pathname, pathname, 100);/* 滤掉文件路径的空格 */
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

/* 音量增大 */
void volumeUp(const char name[])
{
	int volume = 0;
	char pathname[100] = "music\\";/* 歌曲路径名 */
	char vo[20];
	char res[260];
	char cmd1[100] = "status ";
	char text1[20] = " volume";
	char cmd2[100] = "setaudio ";
	char text2[20] = " volume to ";

	strcat(pathname, name);
	GetShortPathName(pathname, pathname, 100);/* 滤掉文件路径的空格 */
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

/* 音量减小 */
void volumeDown(const char name[]) {
	int volume = 0;
	char pathname[100] = "music\\";/* 歌曲路径名 */
	char vo[20];
	char res[260];
	char cmd1[100] = "status ";
	char text1[20] = " volume";
	char cmd2[100] = "setaudio ";
	char text2[20] = " volume to ";

	strcat(pathname, name);
	GetShortPathName(pathname, pathname, 100);/* 滤掉文件路径的空格 */
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

/* 选择播放 */
void select(int choose)
{
	stop(musics[num]);
	num = choose;
	play(musics[num]);
	displaycurmusic(num);
}

/* 判断鼠标移动到列表的位置 */
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