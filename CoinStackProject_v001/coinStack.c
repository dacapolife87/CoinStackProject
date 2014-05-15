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
#define BASESLEEPTIME 100
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

	printf("��ȣ�Է� : \n");
	menuNum = selectMenu();
	
	// ������ �Է½� ���ѷ���......
	while ( !((menuNum==1)|| (menuNum==2)) )
	{
		printf("���Է� : \n");
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
	printf("                             1. ���ӽ���    \n");
	printf("                             2. ��������   \n");
	printf("                          ���Ͻô� �޴��� �����ϼ���.   \n");
	
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
		printf("������ ���� �ƴ� �⺻�� 1 �� ���� : %d \n",selectLevel);
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

