#include<graphics.h>//绘图头文件
#include<mmsystem.h>//多媒体设备接口

#pragma comment(lib,"winmm.lib")//多媒体设备接口库文件

#define _WND_WDITH 1300//窗口宽 不可修改
#define _WND_HEIGHT 700//窗口高 不可修改
#define HERO_WIDTH 45//英雄宽
#define HERO_HEIGHT 45//英雄高
#define Speed 10//英雄移动速度

VOID InitGame();//初始化游戏
VOID MouseMessage();//鼠标消息
VOID Paint();//绘图
VOID Judge();//判断胜利

IMAGE Background;//背景图片
IMAGE Hero;//英雄图片
IMAGE Herotie;//英雄贴图
LPCTSTR start = L"开始";
LPCTSTR end = L"结束";
MOUSEMSG msg = { 0 };//鼠标消息
int X = 110, Y = 240;//英雄位置坐标

int main()
{
	InitGame();

	while (1)
	{
		MouseMessage();
		Judge();
	}
	return 0;
}

VOID InitGame()
{
	initgraph(_WND_WDITH, _WND_HEIGHT);
	PlaySound(L"MyNewClothes.wav", NULL, SND_LOOP | SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
	loadimage(&Background, L"bkimage.jpg", _WND_WDITH-100, _WND_HEIGHT);
	loadimage(&Hero, L"Hero.jpeg", HERO_WIDTH, HERO_HEIGHT);
	loadimage(&Herotie, L"Hero.jpeg", 180, 180);
	putimage(0, 0, &Background);
	putimage(X, Y, &Hero);
	putimage(_WND_WDITH-180, _WND_HEIGHT-180, &Herotie);

	setbkmode(0);
	settextcolor(RED);
	settextstyle(50, 50, L"宋体");
	outtextxy(1200, 350, L"迷");
	outtextxy(1200, 430, L"宫");

	settextcolor(GREEN);
	settextstyle(15, 15, L"宋体");
	outtextxy(50, 240, start);
	outtextxy(1120, 150, end);

	//画上下左右键
	setlinecolor(RGB(255, 255, 0));
	setfillcolor(BLUE);
	fillrectangle(1220, 50, 1280, 110);
	fillrectangle(1220, 120, 1280, 180);
	fillrectangle(1220, 190, 1280, 250);
	fillrectangle(1220, 260, 1280, 320);
	setfillcolor(RED);
	int ptsUp[] = { 1230,97,1270,97,1250,63 };
	fillpolygon((POINT*)ptsUp, 3);
	int ptsDown[] = { 1230,133,1270,133,1250,167 };
	fillpolygon((POINT*)ptsDown, 3);
	int ptsLeft[] = { 1233,220,1267,200,1267,240 };
	fillpolygon((POINT*)ptsLeft, 3);
	int ptsRight[] = { 1233,270,1233,310,1267,290 };
	fillpolygon((POINT*)ptsRight, 3);
}
 
VOID MouseMessage()
{
	msg = GetMouseMsg();
	switch (msg.uMsg)
	{
	case WM_LBUTTONUP:
		if (msg.x>1220&&msg.x<1280)
		{
			if (msg.y > 50 && msg.y < 110)
			{
				if (Y > 70)
				{
					if ((X >= 210 && X < 300 && Y == 120) ||
						(X >= 110 && X <= 150 && Y == 300) ||
						(X >= 160 && X <= 200 && Y == 530) ||
						(X >= 260 && X <= 300 && Y == 420) ||
						(X >= 310 && X < 810 && Y == 180)||
						(X >= 360 && X <= 400 && Y == 300)||
						(X >= 810 && X <= 900 && Y == 120)||
						(X >= 660 && X <= 750 && Y == 120)||
						(X >= 460 && X <= 600 && Y == 120)||
						(X >= 960 && X <= 1000 && Y == 480)||
						(X >= 910 && X <= 950 && Y == 180)||
						(X >= 910 && X <= 1000 && Y == 530)||
						(X >= 110 && X <= 1000 && Y == 590)||
						(X >= 410 && X <= 850 && Y == 240)||
						(X >= 360 && X <= 800 && Y == 530)||
						(X >= 310 && X <= 700 && Y == 480)||
						(X >= 510 && X <= 750 && Y == 300)||
						(X >= 460 && X <= 600 && Y == 420)||
						(X >= 410 && X <= 500 && Y == 360)
						)
					{
						Y = Y;
					}else
					Y-= Speed;
				}
			}else if (msg.y > 120 && msg.y < 180)
			{
				if (Y < _WND_HEIGHT-110)
				{
					if ((X >= 150 && X < 300 && Y == 70) ||
						(X > 250 && X <= 350 && Y == 120) ||
						(X >= 110 && X <= 150 && Y == 240) ||
						(X >= 110 && X <= 1000 && Y == 530) ||
						(X > 250 && X <= 650 && Y == 420)||
						(X >= 360 && X <= 400 && Y == 300)||
						(X > 350 && X <= 850 && Y == 180)||
						(X >= 860 && X <= 950 && Y == 120)||
						(X >= 960 && X <= 1000 && Y == 70)||
						(X >= 660 && X <= 900 && Y == 70)||
						(X >= 410 && X <= 750 && Y == 120)||
						(X >= 460 && X <= 550 && Y == 70)||
						(X >= 910 && X <= 1000 && Y == 480)||
						(X >= 410 && X <= 450 && Y == 300)||
						(X >= 460 && X <= 800 && Y == 240)||
						(X >= 360 && X <= 750 && Y == 480)||
						(X >= 660 && X <= 700 && Y == 300)||
						(X >= 460 && X <= 550 && Y == 360)
						)
					{
						Y = Y;
					}
					else
					Y+= Speed;
				}
			}else if (msg.y > 190 && msg.y < 250)
			{
				if (X > 110)
				{
					if ((Y >= 120 && Y < 530 && X == 210) ||
						(Y >= 80 && Y <= 110 && X == 300) ||
						(Y >= 180 && Y < 420 && X == 310)||
						(Y >= 120 && Y <= 170 && X == 810)||
						(Y >= 70 && Y <= 110 && X == 610)||
						(Y >= 70 && Y <= 120 && X == 410)||
						(Y >= 80 && Y <= 110 && X == 910)||
						(Y >= 80 && Y <= 470 && X == 1010)||
						(Y >= 180 && Y <= 530 && X == 910)||
						(Y >= 490 && Y <= 520 && X == 1010)||
						(Y >= 540 && Y <= 580 && X == 1010)||
						(Y >= 240 && Y <= 290 && X == 410)||
						(Y >= 250 && Y <= 520 && X == 810)||
						(Y >= 480 && Y <= 530 && X == 310)||
						(Y >= 310 && Y <= 470 && X == 710)||
						(Y >= 310 && Y <= 410 && X == 710)||
						(Y >= 300 && Y <= 410 && X == 610)||
						(Y >= 360 && Y <= 420 && X == 410)||
						(Y >= 300 && Y <= 350 && X == 510)
						)
					{
						X = X;
					}else
					X-= Speed;
				}
			}else if (msg.y > 260 && msg.y < 320)
			{
				if (X < _WND_WDITH - 250)
				{
					if ((Y > 70 && Y <= 240 && X == 150) ||
						(Y >= 70 && Y <= 120 && X == 350) ||
						(Y >= 300 && Y <= 520 && X == 150) ||
						(Y >= 130 && Y < 420 && X == 250) ||
						(Y > 420 && Y <= 530 && X == 250) ||
						(Y >= 310 && Y <= 420 && X == 350) ||
						(Y >= 190 && Y <= 290 && X == 350) ||
						(Y > 120 && Y <= 180 && X == 850) ||
						(Y > 70 && Y <= 120 && X == 950) ||
						(Y >= 80 && Y <= 110 && X == 650) ||
						(Y == 120 && X == 750)||
						(Y == 70 && X == 550)||
						(Y >= 80 && Y <= 110 && X == 450)||
						(Y >= 180 && Y <= 470 && X == 950)||
						(Y >= 250 && Y <= 300 && X == 450)||
						(Y >= 240 && Y <= 530 && X == 850)||
						(Y >= 490 && Y <= 520 && X == 350)||
						(Y >= 300 && Y <= 480 && X == 750)||
						(Y >= 310 && Y <= 420 && X == 650)||
						(Y >= 300 && Y <= 360 && X == 550)||
						(Y >= 370 && Y <= 410 && X == 450)
						)
					{
						X = X;
					}else
					X+= Speed;
				}
			}
			Paint();
		}
	}
}

VOID Paint()
{
	putimage(0, 0, &Background);
	putimage(X, Y, &Hero);
	putimage(_WND_WDITH - 180, _WND_HEIGHT - 180, &Herotie);
	outtextxy(50, 240, start);
	outtextxy(1120, 150, end);
}

VOID Judge()
{
	if (X >= 1040 && Y >= 110 && Y <= 150)
	{
		HWND hwnd;
		hwnd = GetHWnd();
		MessageBox(hwnd, L"恭喜您！胜利！", L"游戏结束！", MB_OK);
		closegraph();
	}
}