////////////////////////////////////////////////////////////////////////////////////////////////// 
/* �� �ٲ� ���� */

/*************************************
* Coin Stack
* VisualStudio 2012
* 2014.04.16~
*************************************/
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
//////////////////////////////////////////////////////////////////////////////////////////////////
//<--------------------- Define Start--------------------->
// Define SleepTime 
#define SLEEPTIME 100
#define DROPTIME 50
#define ENDINGTIME 2000
// Define ColorSetting
#define COL			GetStdHandle(STD_OUTPUT_HANDLE)			// �ܼ�â�� �ڵ����� �ޱ�
#define BLACK       SetConsoleTextAttribute(COL, 0x0000);   // ������
#define DARK_BLUE   SetConsoleTextAttribute(COL, 0x0001);   // �Ķ���
#define GREEN       SetConsoleTextAttribute(COL, 0x0002);   // ���
#define BLUE_GREEN  SetConsoleTextAttribute(COL, 0x0003);   // û���
#define BLOOD       SetConsoleTextAttribute(COL, 0x0004);   // �˺�����
#define PURPLE      SetConsoleTextAttribute(COL, 0x0005);   // �����
#define GOLD        SetConsoleTextAttribute(COL, 0x0006);   // �ݻ�
#define ORIGINAL    SetConsoleTextAttribute(COL, 0x0007);   // ���� ȸ�� (ORIGINAL CONSOLE COLOR)
#define GRAY        SetConsoleTextAttribute(COL, 0x0008);   // ȸ��
#define BLUE        SetConsoleTextAttribute(COL, 0x0009);   // �Ķ���
#define HIGH_GREEN  SetConsoleTextAttribute(COL, 0x000a);   // ���λ�
#define SKY_BLUE    SetConsoleTextAttribute(COL, 0x000b);   // �ϴû�
#define RED         SetConsoleTextAttribute(COL, 0x000c);   // ������
#define PLUM        SetConsoleTextAttribute(COL, 0x000d);   // ���ֻ�
#define YELLOW      SetConsoleTextAttribute(COL, 0x000e);   // �����
#define WHITE       SetConsoleTextAttribute(COL, 0x000f);   // ���
 
//<--------------------- Define End--------------------->



//<-------------- Declare Function ProtoType Start-------------->

// program setting
void setWindowSize();
// main menu
void startMenu();
void startImage();
void selectMenu();
// game start
void startGame();
// game default setting
void gameLevelSelect();
void gameSetting();
void gameBackground();
void gameInfo();
// game Func
void coinMove();
void coinDown();
void coinStack();
void coinBalanceCheck();
void coinClear();
// gameMissionCheck
void gameOver();
void gameClear();
// program func
void gotoxy(int,int);
//<-------------- Declare Function ProtoType End-------------->




//////////////////////////////////////////////////////////////////////////////////////////////////
//<-------------- Program Function Start-------------->
// program main
void main(){}
// program setting
void setWindowSize()
{
	system("mode con:lines=30 cols=100");

	return;
}
// main menu
void startMenu(){}
void startImage(){}
void selectMenu(){}
// game start
void startGame(){}
// game default setting
void gameLevelSelect(){}
void gameSetting(){}
void gameBackground(){}
void gameInfo(){}
// game Func
void coinMove(){}
void coinDown(){}
void coinStack(){}
void coinBalanceCheck(){}
void coinClear(){}
// gameMissionCheck
void gameOver(){}
void gameClear(){}
// program func
void gotoxy(int x,int y)
{
	COORD Pos ={x-1,y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);

	return;
}

//<-------------- Program Function End-------------->

