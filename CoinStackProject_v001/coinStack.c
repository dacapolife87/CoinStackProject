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
#include <string.h>
#include <io.h>
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
char selectMenu();
// game start
void startGame();
void stackGame(int);
// game default setting
//int gameLevelSelect();
int gameSetting(int);
void gameBackground();
void gameInfo();
// game Func
void coinMove();
void coinDown();
void coinStack();
int coinBalanceCheck();
void coinClear();
// gameMissionCheck
void gameOver();
void gameClear();
void showNextLevel(int);
// gameRankFileIO
void showRank();
struct rankList returnBestPlayer();
void writeRank(int);
char* inputNameRank();
// program func
void gotoxy(int,int);
//<-------------- Declare Function ProtoType End-------------->

//<-------------- Declare Global Variable Start-------------->
double coinMovingSpeed = 0;
int bestPlayer =0;
//<-------------- Declare Global Variable End-------------->

//<-------------- Declare Struct Start-------------->
struct rankList{
	int rank;
	int level;
	char name[10];
};
//<-------------- Declare Struct End-------------->


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
	system("mode con:lines=30 cols=90");

	return;
}
// main menu
void startMenu()
{
	int menuNum=0;
	char key;
	/*
	\key=getch();
			if(key=='d')*/
	system("cls");
	setWindowSize();
	startImage();

	
	//key=getch();
	//if(key==1)

	
	while(1)
	{
		Sleep(200);
		//key = selectMenu();
		if(kbhit())
		{
			key=getch();
			if(key=='1'||key=='2')
				break;
			//printf("test1111");
			//break;
		}
	}
	if(key=='1')
	{
		startGame();
		return;
	}
	else if (key=='2')
	{
		showRank();
		Sleep(2000);
		startMenu();
		return;
	}
	/*
	// 영문자 입력시 무한루프......왜리럴까.....
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
	if(menuNum == 2)
	{
		showRank();
		Sleep(2000);
		startMenu();
		return;
	}
	*/
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
	printf("                             2. 순위보기   \n");
	printf("                             3. 게임종료   \n");
	printf("                          원하시는 메뉴를 선택하세요.   \n");
	
	return;
}
char selectMenu()
{
	int selectMenuNum = '0';
	char key;
	//scanf("%d", &selectMenuNum);
	//printf("selectNum %d\n",selectMenuNum);
	key=getch();
	return key;
}
// game start
void startGame()
{
	int gameLevel=1;
	stackGame(gameLevel);
	return;
}
void stackGame(int gameLevel)
{
	int x=23;
	int y=1;
	int speed=100;
	system("cls");
	speed=gameSetting(gameLevel);
	gameBackground();
	gameInfo(gameLevel);
	coinMove(x,y,speed,gameLevel);
	return;
}
// game default setting
int gameSetting(int level)
{
	double movingSpeed=BASESLEEPTIME;
	int i;

	for(i=1;i<level;i++)
	{
		movingSpeed = (movingSpeed * 9)/10;
	}

	coinMovingSpeed = movingSpeed;
	
	return coinMovingSpeed;
}
void gameBackground()
{
	int i,j;
	int x,y;
	GOLD;
	
	y=2;

	for(i=0;i<19;i++)
	{
		x=20;
		gotoxy(x,y);
		printf("▦");
		for(j=0;j<20;j++)
			printf("  ");
		printf("▦");
		printf("\n");
		y++;
	}
	x=20;
	gotoxy(x,y);
	printf("▦");
	for(i=0;i<20;i++)
	{
		if(i>7 && i<12)
		{
			GRAY;
			printf("▩");
		}
		else
		{
			GOLD;
			printf("▦");
		}		
	}
	printf("▦");
	printf("\n");
	
	return;
}
void gameInfo(int level)
{
	struct rankList rank1;
     rank1=returnBestPlayer();

	gotoxy(3,10);
	printf("CoinStack");
	gotoxy(3,12);
	printf("Level %d\n",level);

	gotoxy(65,10);
	printf("BestPlayer!!!\n");
	gotoxy(65,12);
	printf("Level : %d\n",rank1.level);
	gotoxy(65,14);
	printf("Name : %s\n",rank1.name);
	bestPlayer=rank1.level;
	if(bestPlayer<level)
	{
		gotoxy(65,12);
		printf("Level : %d\n",level);
		gotoxy(65,14);
		printf("You are the Best!!!\n");
	}

	return;
}

// game Func
void coinMove(int x,int y,int speed,int level)
{
	int rightmove = 1;
	int leftmove = 0;
	int downline = 0;
	int dropheight =20;
	int gameCheck=1;
	double balance=41.5;
	double stackBalance=41.5;
	char key;
	YELLOW;
	while(1){
		if(rightmove==1)
		{
			gotoxy(x,y);
			printf("▥▥▥▥");
			Sleep(speed);
			x++;
			if(x==53)
			{
				rightmove=0;
				leftmove=1;
			}
			
		}
		if(leftmove==1)
		{
			gotoxy(x,y);
			printf("▥▥▥▥");
			Sleep(speed);
			x--;
			if(x==23)
			{
				leftmove=0;
				rightmove=1;
			}
		}
		if(kbhit())	
		{
			key=getch();
			if(key=='d')
			{
				coinClear((x-8),y);
				coinDown(x,dropheight);
		
				leftmove=0;
				rightmove=1;

				// checkBalanceFunc
				gameCheck = coinBalanceCheck(balance,stackBalance,x);
				if(gameCheck!=1)
				{
					gameOver(level);
					return;
				}
				balance=(balance+stackBalance)/2;

				coinStack(x,dropheight);
			
				dropheight--;
				x=23;

			}
		}
		if(dropheight==15)
		{
			gameClear(level);
			return;
		}
	}
}
void coinDown(int x,int dropheight)
{
	int i;
	for(i=1;i<=dropheight;i++)
	{
		coinStack(x,i);
		coinClear(x,i-1);
		Sleep(DROPTIME);
	}
	return;
}
void coinStack(int x,int dropheight)
{
	gotoxy(x,dropheight);
	printf("▥▥▥▥");

	return;
}
int coinBalanceCheck(double balance,double stackBalance,int x)
{

	stackBalance=(float)x+3.5;

	if(balance<stackBalance-3.5)
	{
		return 0;
	}else if(balance>stackBalance+3.5)
	{
		return 0;
	}
	return 1;
}
void coinClear(int x,int y)
{
	gotoxy(x,y);
	printf("       ");

	return;
}
// gameMissionCheck
void gameOver(int level)
{
	//int x,y;
	char name[10];
	system("cls");
	//x=35;
	//y=15;
	gotoxy(35,15);
	printf("GameOver\n");
	Sleep(1000);
	//strcpy(name,"홍길동");
	writeRank(level);
	startMenu();
	return;
}
void gameClear(int level)
{
	int x,y;
	char yes;
	system("cls");
	x=35;
	y=15;
	gotoxy(x,y);
	printf("GameClear\n");
	Sleep(1000);
	level++;
	
	
	showNextLevel(level);

	stackGame(level);
	/*
	do
	{
		printf("다음 레벨로 넘어가시겠습니까? (Y/N)\n");
		scanf("%c",&yes);
		switch (yes)
		{
		case 'Y':case'y':
			stackGame(level);
			return;
		case 'N':case'n':
			startMenu();
			return;
		default:
			break;
		}
		system("cls");
	} while (1);*/
	
	return;
}
void showNextLevel(int level)
{
	system("cls");
	gotoxy(35,15);
	printf("Next Level : %d\n",level);
	Sleep(1000);
	return;
}
// GameRankFileIO
void showRank()
{
	struct rankList rank[10];
	int i;
	FILE *f;
	char *name;
	char *fileName = "./rank.txt";
	system("cls");
	
	// 파일 존재 확인하여 존재하지 않으면 기본값 생성
	if(0!=access(fileName,0))
	{
		
		f=fopen("rank.txt","w");
		for(i=0;i<10;i++)
		{
			rank[i].rank = i+1;
			rank[i].level = 0;
			strcpy(rank[i].name,"noRank");
		}
		for(i=0;i<10;i++)
		{
			fprintf(f, "%d %d %s\n",rank[i].rank,rank[i].level,rank[i].name);
		}
		fclose(f);
	}
	
	// 파일을 열어 순위를 표시
	f=fopen("rank.txt","r");
	for(i=0;i<10;i++){
		fscanf(f,"%d %d %s",&rank[i].rank,&rank[i].level,&rank[i].name);
		printf("%d %d %s\n",rank[i].rank,rank[i].level,rank[i].name);
	}
	fclose(f);
	//name = inputNameRank();
	//printf("%s",name);
	return;
}
struct rankList returnBestPlayer()
{
	struct rankList rank[10];
	//struct rankList rank[10];
	FILE *f;

	f=fopen("rank.txt","r");
	fscanf(f,"%d %d %s",&rank[0].rank,&rank[0].level,&rank[0].name);
	fclose(f);

	return rank[0];
}
void writeRank(int level)
{
	struct rankList rank[10];
	int i,j;
	FILE *f;
	int rankLevel=0;
	int checkNum=0;
	char* name;
	// 기존 랭킹 파일 열기
	f=fopen("rank.txt","r");
	for(i=0;i<10;i++){
		fscanf(f,"%d %d %s",&rank[i].rank,&rank[i].level,&rank[i].name);
		printf("%d %d %s\n",rank[i].rank,rank[i].level,rank[i].name);
		if(checkNum==0)
		{
			if(rank[i].level <level) // 기존레벨보다 현재 위치가 높은지 확인
			{
				//printf("if inside\n"); // 기존레벨보다 높은것이 있으면 그 위치 체크
				rankLevel=i;
				checkNum=1;
			}
		}
	}
	
	printf("------------------ %d %d\n",rankLevel,level);
	// 뒤에서부터 확인된 랭크까지 1단계씩 내림
	for(j=9;j>rankLevel;j--)
	{
		rank[j].level = rank[j-1].level;
		strcpy(rank[j].name,rank[j-1].name);
	} 
	//////////
	// 순위변경된 랭크 출력
	for(i=0;i<10;i++){
		printf("%d %d %s\n",rank[i].rank,rank[i].level,rank[i].name);
	}
	name=inputNameRank();
	rank[rankLevel].level = level;
	strcpy(rank[rankLevel].name , name);
	fclose(f);
	/////////
	for(i=0;i<10;i++){
		printf("%d %d %s\n",rank[i].rank,rank[i].level,rank[i].name);
	}
	
	
	///////////////////// 랭크 재정렬
	f=fopen("rank.txt","w");
	for(i=0;i<10;i++)
	{
		fprintf(f, "%d %d %s\n",rank[i].rank,rank[i].level,rank[i].name);
	}
	
	fclose(f);
 
	//Sleep(100000);
}
char* inputNameRank()
{
	static char name[10];
	//strcpy(name,"test");
	printf("이름을 입력하세요 : \n");
	scanf("%s",name);
	printf("inputNameRank Func  %s\n",name);
	return name;
}
// program func
void gotoxy(int x,int y)
{
	COORD Pos ={x-1,y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);

	return;
}

//<-------------- Program Function End-------------->

