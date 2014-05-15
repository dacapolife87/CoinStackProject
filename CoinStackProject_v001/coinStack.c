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
#define BASESLEEPTIME 100
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
int selectMenu();
// game start
void startGame();
// game default setting
int gameLevelSelect();
void gameSetting(int);
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

//<-------------- Declare Global Variable Start-------------->
double coinMovingSpeed = 0;
//<-------------- Declare Global Variable End-------------->



//////////////////////////////////////////////////////////////////////////////////////////////////
//<-------------- Program Function Start-------------->
// program main
void main(void)
{
	startMenu();

	return;
}
// program setting
void setWindowSize()
{
	system("mode con:lines=30 cols=100");

	return;
}
// main menu
void startMenu()
{
	int menuNum=0;
	//startImage();

	printf("번호입력 : \n");
	menuNum = selectMenu();
	
	// 영문자 입력시 무한루프......
	while ( !((menuNum==1)|| (menuNum==2)) )
	{
		printf("재입력 : \n");
		menuNum = selectMenu();
	}
	
	printf("input selectNum : %d\n",menuNum);
	////////////////////////////////////
	if(menuNum == 1)
	{
		startGame();
		return;
	}
	
	return;
}
void startImage()
{
	ORIGINAL;
	printf("   ###      ####     #####    #     #\n");
	printf("  #   #    #    #      #      ##    #\n");
	printf("  #        #    #      #      # ### #\n");
	printf("  #   #    #    #      #      #    ##\n");
	printf("   ###	    ####     #####    #     #\n");
	printf("\n");
	printf("                                 ####   #######    #       ###    #   #\n");
	printf("                                 #         #      #  #    #   #   #  #\n");
	printf("                                 ####      #     ######   #       ###\n");
	printf("                                    #      #     #    #   #   #   #  #\n");
	printf("                                 ####      #     #    #    ###    #   #\n");
	printf("\n");
	printf("                             1. 게임시작    \n");
	printf("                             2. 게임종료   \n");
	printf("                          원하시는 메뉴를 선택하세요.   \n");
	
	return;
}
int selectMenu()
{
	int selectMenuNum = '0';

	scanf("%d", &selectMenuNum);
	printf("selectNum %d\n",selectMenuNum);

	return selectMenuNum;
}
// game start
void startGame()
{
	int gameLevel=0;
	system("cls");
	printf("startGameFunc gamelevel : %d\n",gameLevel);
	gameLevel = gameLevelSelect();
	printf("after gamelevel select : %d",gameLevel);
	gameSetting(gameLevel);
	
}
// game default setting
int gameLevelSelect()
{
	int selectLevel=1;
	//system("cls");
	printf("1. Level 1\n");
	printf("2. Level 2\n");
	printf("3. Level 3\n");
	printf("4. Level 4\n");
	printf("5. Level 5\n");
	
	scanf("%d",&selectLevel);

	switch (selectLevel)
	{
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		return 3;
	case 4:
		return 4;
	case 5:
		return 5;
	default:
		selectLevel =1;
		printf("범위내 숫자 아님 기본값 1 로 지정 : %d \n",selectLevel);
		break;
	}
	
	return selectLevel;
}
void gameSetting(int level)
{
	double movingSpeed=BASESLEEPTIME;
	int i;

	for(i=1;i<level;i++)
	{
		movingSpeed = (movingSpeed * 9)/10;
	}

	coinMovingSpeed = movingSpeed;
	
	return;
}
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

