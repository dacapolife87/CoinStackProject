////////////////////////////////////////////////////////////////////////////////////////////////// 
/* 줄 바꿈 길이 */

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
#define COL			GetStdHandle(STD_OUTPUT_HANDLE)			// 콘솔창의 핸들정보 받기
#define BLACK       SetConsoleTextAttribute(COL, 0x0000);   // 검정색
#define DARK_BLUE   SetConsoleTextAttribute(COL, 0x0001);   // 파란색
#define GREEN       SetConsoleTextAttribute(COL, 0x0002);   // 녹색
#define BLUE_GREEN  SetConsoleTextAttribute(COL, 0x0003);   // 청녹색
#define BLOOD       SetConsoleTextAttribute(COL, 0x0004);   // 검붉은색
#define PURPLE      SetConsoleTextAttribute(COL, 0x0005);   // 보라색
#define GOLD        SetConsoleTextAttribute(COL, 0x0006);   // 금색
#define ORIGINAL    SetConsoleTextAttribute(COL, 0x0007);   // 밝은 회색 (ORIGINAL CONSOLE COLOR)
#define GRAY        SetConsoleTextAttribute(COL, 0x0008);   // 회색
#define BLUE        SetConsoleTextAttribute(COL, 0x0009);   // 파란색
#define HIGH_GREEN  SetConsoleTextAttribute(COL, 0x000a);   // 연두색
#define SKY_BLUE    SetConsoleTextAttribute(COL, 0x000b);   // 하늘색
#define RED         SetConsoleTextAttribute(COL, 0x000c);   // 빨간색
#define PLUM        SetConsoleTextAttribute(COL, 0x000d);   // 자주색
#define YELLOW      SetConsoleTextAttribute(COL, 0x000e);   // 노란색
#define WHITE       SetConsoleTextAttribute(COL, 0x000f);   // 흰색
 
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

