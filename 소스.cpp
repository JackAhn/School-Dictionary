#include <WinSock2.h>
#include <turboc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <mysql.h>
#include <process.h>
#include <SDL.h>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <math.h>

#define MYSQLIP "192.168.0.75"
#define MYSQLUSER "user"
#define MYSQLPASSWORD ""
#define MAX_CLNT 256
#define BUF_SIZE 100
#define CLS system("cls");

SOCKET clntSock[MAX_CLNT];
HANDLE hMutex;
WSADATA wsaData; //소켓 프로그래밍 변수들 
SOCKET serv_sock, clnt_sock;  //소켓
SOCKADDR_IN servAddr, clntAddr; //주소
HANDLE hthread;  //쓰레드
MYSQL *conn = mysql_init(NULL);  // mysql 변수들
MYSQL_RES *sql_result;   //  명령어를 저장함 *mysql
MYSQL_ROW sql_row;    //  출력에 나온 결과값을 저장함 *mysql
char table[255];
char query[255];
char name[12][20] = {
	"쥐","소","호랑이","토끼","용","뱀","말","양","원숭이","닭","개","돼지"
};

#pragma comment(lib,"libmysql.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment (lib, "SDL2")
#pragma comment (lib, "SDL2main")
//unsigned WINAPI HandleClnt(void * arg);

void gotoxy(short x, short y)      //화면의 원하는 x, y좌표로 보냄
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}	 
void DBstart() {
	if (conn == NULL) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	if (mysql_real_connect(conn, MYSQLIP, MYSQLUSER, MYSQLPASSWORD, NULL, 0, NULL, 0) == NULL) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		mysql_close(conn);
		exit(1);
	}
	mysql_set_character_set(conn, "euckr");
	if (mysql_query(conn, "use infor")) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		mysql_close(conn);
		exit(1);
	}
}
void first();
void category1();
void category2();
void category3();
void DB1();
void DB2();
void DB3();
void DB4();
void DB5();
void DB6();
void important();
void eating();
void calender1();
void calender2();
void ggultip_1();
void ggultip_2();
void ggultip_3();
void ggultip_4();
void timetable_1();
void timetable_2();
void timetable_3();
void timetable_4();
void timetable_5();
void timetable_6();
void fir();
void sec();
void thi();
void fou();
void fif();
void eventphoto();
void mainscreen();
void Using();
void end();

int main(int argc, char *argv[]) { 
	system("title 대소고 백과사전");
	DBstart();
	first();
	bool quit = false;
	SDL_Window *pWindow = SDL_CreateWindow("abc", 100, 100, 500, 400, SDL_WINDOW_SHOWN); //윈도우 생성
	if (pWindow == nullptr) {
		std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl; //예외 처리
		SDL_Quit();
		return 0;
	}
	SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (pRenderer == nullptr) {
		SDL_DestroyWindow(pWindow);
		std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 0;
	}
	SDL_Surface *pHelloBMP = SDL_LoadBMP("abc.bmp");
	if (pHelloBMP == nullptr) {
		SDL_DestroyRenderer(pRenderer);
		SDL_DestroyWindow(pWindow);
		std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 0;
	}
	SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, pHelloBMP);
	SDL_FreeSurface(pHelloBMP);
	if (pTexture == nullptr) {
		SDL_DestroyRenderer(pRenderer);
		SDL_DestroyWindow(pWindow);
		std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 0;
	}
	SDL_Rect Src;
	Src.x = 0;
	Src.y = 0;
	SDL_QueryTexture(pTexture, NULL, NULL, &Src.w, &Src.h);
	SDL_Rect Dst;
	Dst.x = 0;
	Dst.y = 0;
	Dst.w = 500;
	Dst.h = 400;
	SDL_RenderClear(pRenderer);
	SDL_RenderCopy(pRenderer, pTexture, &Src, &Dst);
	SDL_RenderPresent(pRenderer);
	SDL_Delay(1000);
	SDL_DestroyTexture(pTexture);
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();
	return 0;
}
/*unsigned WINAPI HandleClnt(void * arg) {  //쓰레드 전용 main함수
	SOCKET hClntSock = *((SOCKET*)arg);
}*/
void first() {
	while (1) {
		srand(time(NULL));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("\n\n\n\n\n\n\n\n");
		gotoxy(48, 7);
		printf("┌──────────────────────────────────────────────┐  \n");
		printf("                                                │                   대구소프트웨어고등학교에 대한 모든 것들이 담겨져 있다!                   │  \n");
		printf("                                                │                                                                                            │  \n");
		printf("                                                │                                                                                            │  \n");
		printf("                                                │                                                                                            │  \n");
		printf("                                                │                          ■      ■                                   ■    ■             │  \n");
		printf("                                                │                          ■      ■                   ■        ■    ■    ■             │  \n");
		printf("                                                │           ■■■■■■■ ■      ■                   ■        ■    ■    ■             │  \n");
		printf("                                                │           ■             ■      ■                   ■        ■    ■    ■             │  \n");
		printf("                                                │           ■             ■      ■                   ■■■■■■    ■■■■             │  \n");
		printf("                                                │           ■             ■      ■                   ■        ■    ■    ■             │  \n");
		printf("                                                │           ■             ■■■■■                   ■        ■    ■    ■             │  \n");
		printf("                                                │           ■             ■      ■                   ■■■■■■    ■    ■             │  \n");
		printf("                                                │           ■             ■      ■                                   ■    ■             │  \n");
		printf("                                                │           ■■■■■■■ ■      ■                                                        │  \n");
		printf("                                                │                          ■      ■                             ■■■■■■■             │  \n");
		printf("                                                │                          ■      ■                                         ■             │  \n");
		printf("                                                │                          ■      ■                                         ■             │  \n");
		printf("                                                │                                                                                            │  \n");
		printf("                                                │                                                                                            │  \n");
		printf("                                                │                                                                                            │  \n");
		printf("                                                │                                           Ver. 1.0                                         │  \n");
		printf("                                                │                                 (전체 화면으로 사용해주세요!)                              │  \n");
		printf("                                                │                                                                                            │  \n");
		printf("                                                │                                          종료=SPACE                                        │  \n");
		printf("                                                │                                                                                            │  \n");
		printf("                                                │                                         사용법=숫자키                                      │  \n");
		printf("                                                │                                                                                            │  \n");
		printf("                                                │                                        대백 실행=ENTER                                     │  \n");
		printf("                                                │                                                                                            │  \n");
		printf("                                                │                                                                                            │  \n");
		printf("                                                │                             키보드 입력이 안 되시면 세게 눌러주세요!                       │  \n");
		printf("                                                │                                                                                            │  \n");
		printf("                                                │                                                                         Designded by 안도현│  \n");
		printf("                                                │                                                                                            │  \n");
		printf("                                                │                                                                                            │  \n");
		printf("                                                │                                                                                            │  \n");
		printf("                                                │                              Made by 박훈, 김현동, 한승헌, 안도현                          │  \n");
		printf("                                                └──────────────────────────────────────────────┘  \n");
		if (getch() == 13) {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			mainscreen();
			break;
		}
		else if (getch() >= 48 && getch() <= 57) {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			Using();
			break;
		}
		else if (getch() == 32) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			system("cls");
			end();
			break;
		}
	}
}
void mainscreen() {
	int x, y;
	mysql_query(conn, "use infor");
	while (1) {
		char h1[100] = "모든 정보가 모여있는 곳, 대백!";
		char h2[100] = "꿈과 희망이 넘치는 고등학교, 대구소프트웨어고등학교!";
		char h3[100] = "※주의※ : 마우스 왼쪽 키를 누르게 되면 프로그램 오류 발생!(추후 수정 예정)";
		srand(time(NULL));
		char arr1[50] = "대백에";
		char arr2[50] = "오신 것을";
		char arr3[50] = "환영합니다!";
		while (1) {
			CONSOLE_CURSOR_INFO cursorInfo = { 0, };
			cursorInfo.dwSize = 1;
			cursorInfo.bVisible = FALSE;
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
			int i, count = 0, ct = 0;
			printf("\n\n\n");
			while (1) {
				while (count < 3) {
					if (count == 0) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
						printf("                                                                                    %s ", arr1);
						count++;
						Sleep(1000);
					}
					if (count == 1) {
						printf("%s ", arr2);
						count++;
						Sleep(1000);
					}
					if (count == 2) {
						printf("%s \n", arr3);
						count++;
						Sleep(1000);
						system("cls");
					}
				}
			screen:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				printf("\n\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				printf("                                                                                              메인 메뉴");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				printf("                                                                        처음 화면으로 \n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				printf("\n");
				gotoxy(0, 5);
				printf("   ┌──────────────────────┬──────────────────────┬──────────────────────┬─────────────────────┐     \n");
				printf("   │                                            │                                            │                                            │                                          │     \n");
				printf("   │                                            │                                            │                                            │                                          │     \n");
				printf("   │                학교에 대하여               │                 학교 소식                  │                     일정                   │         재학생들이 알려주는 꿀팁         │     \n");
				printf("   │                                            │                                            │                                            │                                          │     \n");
				printf("   │                                            │                                            │                                            │                                          │     \n");
				printf("   │                                            │                                            │                                            │                                          │     \n");
				printf("   │                                            │                                            │                                            │                                          │     \n");
				printf("   │                                            │                                            │                                            │                                          │     \n");
				printf("   │     (학교 소개, 학교 사진, 학과 소개 등)   │        (공지사항, 행사 사진, 급식표)       │              (학사 일정, 시간표)           │    (재학생들의 조언이 담겨 있는 게시판)  │     \n");
				printf("   │                                            │                                            │                                            │                                          │     \n");
				printf("   │                                            │                                            │                                            │                                          │     \n");
				printf("   │                                            │                                            │                                            │                                          │     \n");
				printf("   └──────────────────────┴──────────────────────┴──────────────────────┴─────────────────────┘     \n");
				Sleep(2000);
				POINT mouse;
				GetCursorPos(&mouse);                // 마우스 좌표를 구한다. 
				//printf("x : %d, y : %d \n", mouse.x, mouse.y);
				//while ((mouse.x >= 34 && mouse.y >= 94) && (mouse.x <= 390 && mouse.y <= 287))
				while ((mouse.x >= 34 && mouse.y >= 94) && (mouse.x <= 390 && mouse.y <= 287)) {
					system("cls");
					while (1) {
						POINT mouse;
						GetCursorPos(&mouse);
						//printf("%d %d\n", mouse.x, mouse.y);
						gotoxy(75, 15);
						printf("정말로 '학교에 대하여' 카테고리로 이동하시겠습니까?\n");
						gotoxy(75, 20);
						printf("예                                        아니요");
						if ((mouse.x >= 602 && mouse.y >= 344) && (mouse.x <= 609 && mouse.y <= 346)) {
							system("cls");
							break;
						}
						else if ((mouse.x >= 937 && mouse.y >= 343) && (mouse.x <= 976 && mouse.y <= 346)) {
							system("cls");
							goto screen;
						}
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                                  학교에 대하여로 이동 중입니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					category1();
					break;
				}
				while ((mouse.x >= 403 && mouse.y >= 95) && (mouse.x <= 758 && mouse.y <= 286)) {
					system("cls");
					while (1) {
						gotoxy(75, 15);
						printf("정말로 '학교 소식' 카테고리로 이동하시겠습니까?\n");
						gotoxy(75, 20);
						printf("예                                        아니요");
						POINT mouse;
						GetCursorPos(&mouse);
						if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
							system("cls");
							break;
						}
						else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
							system("cls");
							goto screen;
						}
						//printf("%d %d\n", mouse.x, mouse.y);
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                                  학교 소식으로 이동 중입니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					category2();
					break;
				}
				while ((mouse.x >= 774 && mouse.y >= 112) && (mouse.x <= 1124 && mouse.y <= 302)) {
					system("cls");
					while (1) {
						gotoxy(75, 13);
						printf("정말로 '일정' 카테고리로 이동하시겠습니까?\n");
						gotoxy(75, 20);
						printf("예                                        아니요");
						POINT mouse;
						GetCursorPos(&mouse);
						if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
							system("cls");
							break;
						}
						else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
							system("cls");
							goto screen;
						}
						//printf("%d %d\n", mouse.x, mouse.y);
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '일정' 카테고리로 이동 중입니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					category3();
					break;
				}
				while ((mouse.x >= 1140 && mouse.y >= 112) && (mouse.x <= 1476 && mouse.y <= 302)) {
					system("cls");
					while (1) {
						gotoxy(75, 13);
						printf("정말로 '재학생들이 알려주는 꿀팁' 카테고리로 이동하시겠습니까?\n");
						gotoxy(75, 20);
						printf("예                                        아니요");
						POINT mouse;
						GetCursorPos(&mouse);
						if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
							system("cls");
							break;
						}
						else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							system("cls");
							goto screen;
						}
						//printf("%d %d\n", mouse.x, mouse.y);
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '재학생들이 알려주는 꿀팁' 카테고리로 이동 중입니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					ggultip_1();
					break;
				}
				while ((mouse.x >= 754 && mouse.y >= 57) && (mouse.x <= 821 && mouse.y <= 70)) {
					system("cls");
					Sleep(1000);
					printf("\n\n\n\n\n\n\n\n\n\n\n");
					int b = rand() % 4 + 1;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				Back:
					if (b == 1) {
						printf("                                                                                %s", h1);
						Sleep(1500);
					}
					else if (b == 2) {
						printf("                                                                       %s", h2);
						Sleep(1500);
					}
					else if (b == 3) {
						printf("                                                           %s", h3);
						Sleep(1500);
					}
					else {
						b = rand() % 4 + 1;
						goto Back;
					}
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					printf("                                                                                   메인 화면으로 이동합니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					break;
				}
				while ((mouse.x >= 1400 && mouse.y >= 54) && (mouse.x <= 1498 && mouse.y <= 58)) {
					system("cls");
					Sleep(1000);
					printf("\n\n\n\n\n\n\n\n\n\n\n");
					int b = rand() % 4 + 1;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				Back2:
					if (b == 1) {
						printf("                                                                                %s", h1);
						Sleep(1500);
					}
					else if (b == 2) {
						printf("                                                                       %s", h2);
						Sleep(1500);
					}
					else if (b == 3) {
						printf("                                                           %s", h3);
						Sleep(1500);
					}
					else {
						b = rand() % 4 + 1;
						goto Back2;
					}
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					printf("                                                                                   처음 화면으로 이동합니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					first();
					break;
				}
				gotoxy(0, 0);
			}
		}
	}
}
void Using() {
	while (1) {
		srand(time(NULL));
		int a = rand() % 7 + 9;
		CONSOLE_CURSOR_INFO cursorInfo = { 0, };
		cursorInfo.dwSize = 1;
		cursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
		printf("																																												처음 화면으로");
		printf("															   사용법\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("									이용하실 때에는 반드시 전체화면으로 이용 해 주시기 바랍니다.\n");
		printf("\n\n\n\n\n\n");
		printf("					    원하는 카테고리나 메인화면으로 이동하고 싶은 경우에는 마우스 커서를 몇 초간 올려 놓으면 자동으로 이동이 됩니다.\n");
		printf("\n\n\n\n\n\n");
		printf("							       마우스 왼쪽 키는 눌러 주시지 말아 주시길 바랍니다.(추후 오류 수정 예정)\n");
		printf("\n\n\n\n\n\n");
		printf("							   만약 다른 버그가 생긴다면, fkaus0907@ dgsw.hs.kr 로 메일을 보내 주시기 바랍니다.\n");
		Sleep(2000);
		POINT mouse;
		GetCursorPos(&mouse);
		if ((mouse.x >= 1281 && mouse.y >= 40) && (mouse.x <= 1438 && mouse.y <= 100)) {
			system("cls");
			first();
		}
		gotoxy(0, 0);
	}
}
void category1() {
	while (1) {
		int i;
	screen:
		CONSOLE_CURSOR_INFO cursorInfo = { 0, };
		cursorInfo.dwSize = 1;
		cursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
		srand(time(NULL));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("											  학교에 대하여");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		printf("                                                                        메인 화면으로 \n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("\n\n\n\n\n");
		printf("			      ┌──────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ \n");
		printf("			                            │                  │                  │                  │                  │                     \n");
		printf("			                            │                  │                  │                  │                  │                     \n");
		printf("			                            │                  │                  │                  │                  │                     \n");
		printf("			                            │                  │                  │                  │                  │                     \n");
		printf("			                            │                  │                  │                  │                  │                     \n");
		printf("			           대구 소프트웨어  │       교가       │       교훈       │      전공과목    │    학교  구조    │       현재          \n");
		printf("			             고등학교란     │                  │                  │        소개      │       소개       │     재적 인원       \n");
		printf("			                            │                  │                  │                  │                  │                     \n");
		printf("			                            │                  │                  │                  │                  │                     \n");
		printf("			                            │                  │                  │                  │                  │                     \n");
		printf("			                            │                  │                  │                  │                  │                     \n");
		printf("			                            │                  │                  │                  │                  │                     \n");
		printf("			      └──────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ \n");
		Sleep(2000);
		POINT mouse;
		GetCursorPos(&mouse);
		while ((mouse.x >= 256 && mouse.y >= 322) && (mouse.x <= 409 && mouse.y <= 507)) {
			system("cls");
			while (1) {
				gotoxy(75, 13);
				printf("정말로 '대구 소프트웨어 고등학교란' 정보로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '학교에 대하여'로 돌아가는 중입니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                             '대구 소프트웨어 고등학교란' 정보로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			DB1();
			break;
		}
		while ((mouse.x >= 430 && mouse.y >= 322) && (mouse.x <= 571 && mouse.y <= 510)) {
			system("cls");
			while (1) {
				gotoxy(75, 15);
				printf("정말로 '교가' 정보로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '학교에 대하여'로 돌아가는 중입니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  '교가' 정보로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			DB2();
			break;
		}
		while ((mouse.x >= 589 && mouse.y >= 322) && (mouse.x <= 732 && mouse.y <= 510)) {
			system("cls");
			while (1) {
				gotoxy(75, 15);
				printf("정말로 '교훈' 정보로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '학교에 대하여'로 돌아가는 중입니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  '교훈' 정보로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			DB3();
			break;
		}
		while ((mouse.x >= 746 && mouse.y >= 321) && (mouse.x <= 888 && mouse.y <= 502)) {
			system("cls");
			while (1) {
				gotoxy(75, 15);
				printf("정말로 '전공과목 소개' 카테고리로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '학교에 대하여'로 돌아가는 중입니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  '전공과목 소개' 정보로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			DB4();
			break;
		}
		while ((mouse.x >= 910 && mouse.y >= 318) && (mouse.x <= 1053 && mouse.y <= 508)) {
			system("cls");
			while (1) {
				gotoxy(75, 15);
				printf("정말로 '학교구조 소개' 카테고리로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '학교에 대하여'로 돌아가는 중입니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  '학교구조 소개' 정보로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			DB5();
			break;
		}
		while ((mouse.x >= 1069 && mouse.y >= 320) && (mouse.x <= 1213 && mouse.y <= 508)) {
			system("cls");
			while (1) {
				gotoxy(75, 15);
				printf("정말로 '현재 재적인원' 카테고리로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '학교에 대하여'로 돌아가는 중입니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  학교에 대하여로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			DB6();
			break;
		}
		while ((mouse.x >= 1402 && mouse.y >= 214) && (mouse.x <= 1498 && mouse.y <= 219)) {
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("                                                                                   메인 화면으로 이동합니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			mainscreen();
		}
		//printf("%d %d\n", mouse.x, mouse.y);
		gotoxy(0, 0);
	}
}
void DB1() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
screen:
	while (1) {
		int i;
		POINT mouse;
		GetCursorPos(&mouse);
		mysql_query(conn, "select * from 학교에대하여 where num=1");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(75, 0);
			printf("	%s\n", sql_row[1]);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("	%s\n", sql_row[2]);
		}
		printf("																					이전 화면으로 \n");
		printf("%d %d\n", mouse.x, mouse.y);
		while ((mouse.x >= 1345 && mouse.y >= 455) && (mouse.x <= 1441 && mouse.y <= 458)) {
			system("cls");
			while (1) {
				gotoxy(75, 15);
				printf("정말로 이전 화면으로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  이전 화면으로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			category1();
			break;
		}
	}
}
void DB2() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
screen:
	while (1) {
		int i, count = 1;
		POINT mouse;
		GetCursorPos(&mouse);
		//printf("%d %d\n", mouse.x, mouse.y);
		mysql_query(conn, "select * from 학교에대하여 where num=2");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(80, 0);
			printf("	%s\n", sql_row[1]);
			printf("	%s\n", sql_row[2]);
		}
		printf("																					이전 화면으로 \n");
		//printf("%d %d\n", mouse.x, mouse.y);
		int argc;
		char **argv;
	first:
		bool quit = false;
		SDL_Window *pWindow = SDL_CreateWindow("abc", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 700, SDL_WINDOW_BORDERLESS); //윈도우 생성
		if (pWindow == nullptr) {
			std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl; //예외 처리
			SDL_Quit();
			exit(0);
		}
		SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow,
			-1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (pRenderer == nullptr) {
			SDL_DestroyWindow(pWindow);
			std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(0);
		}
		SDL_Surface *pHelloBMP = SDL_LoadBMP("abcd.bmp");
		if (pHelloBMP == nullptr) {
			SDL_DestroyRenderer(pRenderer);
			SDL_DestroyWindow(pWindow);
			std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(0);
		}
		SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, pHelloBMP);
		SDL_FreeSurface(pHelloBMP);
		if (pTexture == nullptr) {
			SDL_DestroyRenderer(pRenderer);
			SDL_DestroyWindow(pWindow);
			std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(0);
		}
		SDL_Rect Src;
		Src.x = 0;
		Src.y = 0;
		SDL_QueryTexture(pTexture, NULL, NULL, &Src.w, &Src.h);
		SDL_Rect Dst;
		Dst.x = 0;
		Dst.y = 0;
		Dst.w = 500;
		Dst.h = 700;
		if (count == 1) {
			SDL_RenderClear(pRenderer);
			SDL_RenderCopy(pRenderer, pTexture, &Src, &Dst);
			SDL_RenderPresent(pRenderer);
			count++;
			goto first;
		}
		SDL_DestroyTexture(pTexture);
		SDL_DestroyRenderer(pRenderer);
		SDL_DestroyWindow(pWindow);
		SDL_Quit();
		if ((mouse.x >= 1345 && mouse.y >= 151) && (mouse.x <= 1443 && mouse.y <= 154)) {
			system("cls");
			SDL_DestroyTexture(pTexture);
			SDL_DestroyRenderer(pRenderer);
			SDL_DestroyWindow(pWindow);
			SDL_Quit();
			SDL_Init(SDL_INIT_EVERYTHING);
			while (1) {
				gotoxy(75, 15);
				printf("정말로 이전 화면으로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  이전 화면으로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			category1();
			break;
		}
	}
}
void DB3() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
screen:
	while (1) {
		int i, count = 1;
		POINT mouse;
		GetCursorPos(&mouse);
		//printf("%d %d\n", mouse.x, mouse.y);
		mysql_query(conn, "select * from 학교에대하여 where num=3");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(80, 0);
			printf("	%s\n", sql_row[1]);
			printf("	%s\n", sql_row[2]);
		}
		printf("\n\n\n\n\n\n");
		printf("																					이전 화면으로 \n");
	first:
		bool quit = false;
		SDL_Window *pWindow = SDL_CreateWindow("abc", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 200, SDL_WINDOW_BORDERLESS); //윈도우 생성
		if (pWindow == nullptr) {
			std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl; //예외 처리
			SDL_Quit();
			exit(0);
		}
		SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow,
			-1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (pRenderer == nullptr) {
			SDL_DestroyWindow(pWindow);
			std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(0);
		}
		SDL_Surface *pHelloBMP = SDL_LoadBMP("abcde.bmp");
		if (pHelloBMP == nullptr) {
			SDL_DestroyRenderer(pRenderer);
			SDL_DestroyWindow(pWindow);
			std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(0);
		}
		SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, pHelloBMP);
		SDL_FreeSurface(pHelloBMP);
		if (pTexture == nullptr) {
			SDL_DestroyRenderer(pRenderer);
			SDL_DestroyWindow(pWindow);
			std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(0);
		}
		SDL_Rect Src;
		Src.x = 0;
		Src.y = 0;
		SDL_QueryTexture(pTexture, NULL, NULL, &Src.w, &Src.h);
		SDL_Rect Dst;
		Dst.x = 0;
		Dst.y = 0;
		Dst.w = 500;
		Dst.h = 200;
		if (count == 1) {
			SDL_RenderClear(pRenderer);
			SDL_RenderCopy(pRenderer, pTexture, &Src, &Dst);
			SDL_RenderPresent(pRenderer);
			count++;
			goto first;
		}
		SDL_DestroyTexture(pTexture);
		SDL_DestroyRenderer(pRenderer);
		SDL_DestroyWindow(pWindow);
		SDL_Quit();
		if ((mouse.x >= 1345 && mouse.y >= 151) && (mouse.x <= 1443 && mouse.y <= 154)) {
			system("cls");
			SDL_DestroyTexture(pTexture);
			SDL_DestroyRenderer(pRenderer);
			SDL_DestroyWindow(pWindow);
			SDL_Quit();
			SDL_Init(SDL_INIT_EVERYTHING);
			while (1) {
				gotoxy(75, 15);
				printf("정말로 이전 화면으로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  이전 화면으로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			category1();
			break;
		}
	}
}
void sec() {

}
void thi() {

}//사진 필요
void fou() {

}//사진 필요
void fif() {

}//사진 필요
void DB4() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	screen:
	while (1) {
		int i;
		POINT mouse;
		GetCursorPos(&mouse);
		//printf("%d %d\n", mouse.x, mouse.y);
		mysql_query(conn, "select * from 학교에대하여 where num=4");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(75, 0);
			printf("%s\n", sql_row[1]);
			printf("%s\n", sql_row[2]);
		}
		printf("\n\n\n\n\n");
		printf("																					이전 화면으로 \n");
		while ((mouse.x >= 1345 && mouse.y >= 326) && (mouse.x <= 1443 && mouse.y <= 329)) {
			system("cls");
				while (1) {
					gotoxy(75, 15);
					printf("정말로 이전 화면으로 이동하시겠습니까?\n");
					gotoxy(75, 20);
					printf("예                                        아니요");
					POINT mouse;
					GetCursorPos(&mouse);
					if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
						system("cls");
						break;
					}
					else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
						system("cls");
						goto screen;
					}
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf("                                                                                  이전 화면으로 이동 중입니다.");
				for (i = 0; i < 2; i++) {
					printf(".");
					Sleep(1000);
				}
				system("cls");
				category1();
				break;
			}
	}
}
void DB5() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (1) {
	mysql_query(conn, "select * from 학교에대하여 where num=5");
	sql_result = mysql_store_result(conn);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		printf("%s\n", sql_row[1]);
		printf("%s\n", sql_row[2]);
		}
	gotoxy(0, 0);
	}
}
void DB6() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
screen:
	while (1) {
		int i;
		POINT mouse;
		GetCursorPos(&mouse);
		mysql_query(conn, "select * from 학교에대하여 where num=6");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(75, 0);
			printf("%s\n", sql_row[1]);
			printf("%s\n", sql_row[2]);
		}
		printf("\n\n\n\n\n");
		printf("																					이전 화면으로 \n");
		while ((mouse.x >= 1345 && mouse.y >= 151) && (mouse.x <= 1443 && mouse.y <= 154)) {
			system("cls");
			while (1) {
				while (1) {
					gotoxy(75, 15);
					printf("정말로 이전 화면으로 이동하시겠습니까?\n");
					gotoxy(75, 20);
					printf("예                                        아니요");
					POINT mouse;
					GetCursorPos(&mouse);
					if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
						system("cls");
						break;
					}
					else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
						system("cls");
						goto screen;
					}
					//printf("%d %d\n", mouse.x, mouse.y);
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf("                                                                                  이전 화면으로 이동 중입니다.");
				for (i = 0; i < 2; i++) {
					printf(".");
					Sleep(1000);
				}
				system("cls");
				category1();
				break;
			}
		}
	}
}
void category2() {
	int i;
	screen :
	while (1) {
		CONSOLE_CURSOR_INFO cursorInfo = { 0, };
		cursorInfo.dwSize = 1;
		cursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
		srand(time(NULL));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("											  학교 소식");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		printf("                                                                        메인 화면으로 \n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("\n\n\n\n\n");
		printf("			┌───────────────────────┬───────────────────────┬──────────────────────┐     \n");
		printf("			│                                              │                                              │                                            │     \n");
		printf("			│                                              │                                              │                                            │     \n");
		printf("			│                                              │                                              │                                            │     \n");
		printf("			│                  공지 사항                   │                   행사 사진                  │                  급식표                    │     \n");
		printf("			│                                              │                                              │              (오류로 사용 X)               │     \n");
		printf("			│                                              │                                              │                                            │     \n");
		printf("			│                                              │                                              │                                            │     \n");
		printf("			│                                              │                                              │                                            │     \n");
		printf("			│          각종 중요한 정보를 한 곳에!         │       매번 학교에서 펼쳐지는 행사 사진을     │          가장 중요한 급식 정보를           │     \n");
		printf("			│                                              │               확인할 수 있는 곳!             │         한  눈으로 볼 수 있는 곳!          │     \n");
		printf("			│                                              │                                              │                                            │     \n");
		printf("			│                                              │                                              │                                            │     \n");
		printf("			└───────────────────────┴───────────────────────┴──────────────────────┘     \n");
		Sleep(2500);
		POINT mouse;
		GetCursorPos(&mouse);
		//printf("%d %d\n", mouse.x, mouse.y);
		while ((mouse.x >= 1369 && mouse.y >= 214) && (mouse.x <= 1469 && mouse.y <= 219)) {
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("                                                                                   메인 화면으로 이동합니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			mainscreen();
		}
		while ((mouse.x >= 972 && mouse.y >= 320) && (mouse.x <= 1329 && mouse.y <= 504)) {
			system("cls");
			while (1) {
				gotoxy(75, 13);
				printf("정말로 '급식표' 정보로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '학교 정보'로 돌아가는 중입니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                             '급식표' 정보로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			eating();
			break;
		}
		while ((mouse.x >= 202 && mouse.y >= 320) && (mouse.x <= 572 && mouse.y <= 510)) {
			system("cls");
			while (1) {
				gotoxy(75, 13);
				printf("정말로 '공지사항' 정보로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '학교 정보'로 돌아가는 중입니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                             '공지사항' 정보로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			important();
			break;
		}
		while ((mouse.x >= 590 && mouse.y >= 320) && (mouse.x <= 957 && mouse.y <= 510)) {
			system("cls");
			while (1) {
				gotoxy(75, 13);
				printf("정말로 '행사 사진' 정보로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '학교 정보'로 돌아가는 중입니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                             '행사 사진' 정보로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			eventphoto();
			break;
		}
		//printf("%d %d\n", mouse.x, mouse.y);
		gotoxy(0, 0);
	}
}
void eventphoto() {
screen:
	Sleep(1500);
	int argc;
	char **argv;
	int a = 0;
	while (1) {
		int i;
		POINT mouse;
		GetCursorPos(&mouse);
		//printf("%d %d\n", mouse.x, mouse.y);
		bool quit = false;
		SDL_Window *pWindow = SDL_CreateWindow("abc", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 400, SDL_WINDOW_BORDERLESS); //윈도우 생성
		if (pWindow == nullptr) {
			std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl; //예외 처리
			SDL_Quit();
			exit(0);
		}
		SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow,
			-1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (pRenderer == nullptr) {
			SDL_DestroyWindow(pWindow);
			std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(0);
		}
		SDL_Surface *pHelloBMP = SDL_LoadBMP("abcdef.bmp");
		if (pHelloBMP == nullptr) {
			SDL_DestroyRenderer(pRenderer);
			SDL_DestroyWindow(pWindow);
			std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(0);
		}
		SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, pHelloBMP);
		SDL_FreeSurface(pHelloBMP);
		if (pTexture == nullptr) {
			SDL_DestroyRenderer(pRenderer);
			SDL_DestroyWindow(pWindow);
			std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(0);
		}
		SDL_Rect Src;
		Src.x = 0;
		Src.y = 0;
		SDL_QueryTexture(pTexture, NULL, NULL, &Src.w, &Src.h);
		SDL_Rect Dst;
		Dst.x = 0;
		Dst.y = 0;
		Dst.w = 500;
		Dst.h = 400;
		SDL_RenderClear(pRenderer);
		SDL_RenderCopy(pRenderer, pTexture, &Src, &Dst);
		SDL_RenderPresent(pRenderer);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		gotoxy(75, 0);
		printf("\n\n\n\n\n");	
		printf("																다음 사진으로");
		printf("\n\n\n");
		printf("																					이전 화면으로 \n");
		while ((mouse.x >= 1026 && mouse.y >= 104) && (mouse.x <= 1124 && mouse.y <= 106)) {
			SDL_DestroyTexture(pTexture);
			SDL_DestroyRenderer(pRenderer);
			SDL_DestroyWindow(pWindow);
			SDL_Init(SDL_INIT_EVERYTHING);
			SDL_Quit();
			system("cls");
			fir();
		}
		while ((mouse.x >= 1345 && mouse.y >= 151) && (mouse.x <= 1443 && mouse.y <= 154)) {
			system("cls");
			SDL_DestroyTexture(pTexture);
			SDL_DestroyRenderer(pRenderer);
			SDL_DestroyWindow(pWindow);
			SDL_Init(SDL_INIT_EVERYTHING);
			SDL_Quit();
			while (1) {
				gotoxy(75, 15);
				printf("정말로 이전 화면으로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  이전 화면으로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			category2();
			break;
		}
	}
}
void fir() {
	Sleep(1500);
	int argc;
	char **argv;
	int a = 1;
	while (1) {
		int i;
		POINT mouse;
		GetCursorPos(&mouse);
		//printf("%d %d\n", mouse.x, mouse.y);
		bool quit = false;
		SDL_Window *pWindow = SDL_CreateWindow("abc", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 400, SDL_WINDOW_BORDERLESS); //윈도우 생성
		if (pWindow == nullptr) {
			std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl; //예외 처리
			SDL_Quit();
			exit(0);
		}
		SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow,
			-1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (pRenderer == nullptr) {
			SDL_DestroyWindow(pWindow);
			std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(0);
		}
		SDL_Surface *pHelloBMP = SDL_LoadBMP("abcdefg.bmp");
		if (pHelloBMP == nullptr) {
			SDL_DestroyRenderer(pRenderer);
			SDL_DestroyWindow(pWindow);
			std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(0);
		}
		SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, pHelloBMP);
		SDL_FreeSurface(pHelloBMP);
		if (pTexture == nullptr) {
			SDL_DestroyRenderer(pRenderer);
			SDL_DestroyWindow(pWindow);
			std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(0);
		}
		SDL_Rect Src;
		Src.x = 0;
		Src.y = 0;
		SDL_QueryTexture(pTexture, NULL, NULL, &Src.w, &Src.h);
		SDL_Rect Dst;
		Dst.x = 0;
		Dst.y = 0;
		Dst.w = 500;
		Dst.h = 400;
		SDL_RenderClear(pRenderer);
		SDL_RenderCopy(pRenderer, pTexture, &Src, &Dst);
		SDL_RenderPresent(pRenderer);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		gotoxy(75, 0);
		printf("\n\n\n\n\n");														
		printf("									이전 사진으로						다음 사진으로");
		printf("\n\n\n");
		printf("																					이전 화면으로 \n");
		while ((mouse.x >= 575 && mouse.y >= 104) && (mouse.x <= 674 && mouse.y <= 106)) {
			SDL_DestroyTexture(pTexture);
			SDL_DestroyRenderer(pRenderer);
			SDL_DestroyWindow(pWindow);
			SDL_Init(SDL_INIT_EVERYTHING);
			SDL_Quit();
			system("cls");
			eventphoto();
		}
		while ((mouse.x >= 1026 && mouse.y >= 104) && (mouse.x <= 1124 && mouse.y <= 106)) {
			SDL_DestroyTexture(pTexture);
			SDL_DestroyRenderer(pRenderer);
			SDL_DestroyWindow(pWindow);
			SDL_Init(SDL_INIT_EVERYTHING);
			SDL_Quit();
			system("cls");
			sec();
			
		}
	}
}
void important() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	screen :
	while (1) {
		POINT mouse;
		GetCursorPos(&mouse);
		int i;
		mysql_query(conn, "select * from 학교소식 where num=3");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(75, 0);
			printf("%s\n", sql_row[1]);
			printf("%s\n", sql_row[2]);
		}
		printf("\n\n\n\n\n");
		printf("																					이전 화면으로 \n");
		while ((mouse.x >= 1345 && mouse.y >= 151) && (mouse.x <= 1443 && mouse.y <= 154)) {
			system("cls");
			while (1) {
				gotoxy(75, 15);
				printf("정말로 이전 화면으로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  이전 화면으로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			category2();
			break;
		}
		gotoxy(0, 0);
	}
}
void eating() {
	screen:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (1) {
		POINT mouse;
		GetCursorPos(&mouse);
		int i;
		mysql_query(conn, "select * from 학교소식 where num=3");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(75, 0);
			printf("%s\n", sql_row[1]);
			printf("%s\n", sql_row[2]);
		}
		printf("\n\n\n\n\n");
		printf("																					이전 화면으로 \n");
		while ((mouse.x >= 1345 && mouse.y >= 151) && (mouse.x <= 1443 && mouse.y <= 154)) {
			system("cls");
			while (1) {
				gotoxy(75, 15);
				printf("정말로 이전 화면으로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  이전 화면으로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			category2();
			break;
		}
		gotoxy(0, 0);
	}
}
void category3() {
	int i;
screen:
	while (1) {
		CONSOLE_CURSOR_INFO cursorInfo = { 0, };
		cursorInfo.dwSize = 1;
		cursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
		srand(time(NULL));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("												일정");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		printf("                                                                        메인 화면으로 \n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("\n\n\n\n\n");
		printf("						┌───────────────────────┬───────────────────────┐     \n");
		printf("						│                                              │                                              │     \n");
		printf("						│                                              │                                              │     \n");
		printf("						│                                              │                                              │     \n");
		printf("						│                  학사 일정                   │                   시간표                     │     \n");
		printf("						│                                              │                                              │     \n");
		printf("						│                                              │                                              │     \n");
		printf("						│                                              │                                              │     \n");
		printf("						│                                              │                                              │     \n");
		printf("						│        1년을 중심으로 한 일정을 한 곳에!     │     학생들의 하루 일과를 확인할 수 있는 곳!  │     \n");
		printf("						│                                              │                                              │     \n");
		printf("						│                                              │                                              │     \n");
		printf("						│                                              │                                              │     \n");
		printf("						└───────────────────────┴───────────────────────┘     \n");
		Sleep(2500);
		POINT mouse;
		GetCursorPos(&mouse);
		while ((mouse.x >= 1369 && mouse.y >= 214) && (mouse.x <= 1469 && mouse.y <= 219)) {
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("                                                                                   메인 화면으로 이동합니다.");
			for (i = 0; i < 4; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			mainscreen();
		}
		while ((mouse.x >= 396 && mouse.y >= 320) && (mouse.x <= 766 && mouse.y <= 510)) {
			system("cls");
			while (1) {
				gotoxy(75, 13);
				printf("정말로 '학사 일정' 정보로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '일정' 으로 돌아가는 중입니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                             '학사 일정' 정보로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			calender1();
			break;
		}
		while ((mouse.x >= 780 && mouse.y >= 320) && (mouse.x <= 1149 && mouse.y <= 510)) {
			system("cls");
			while (1) {
				gotoxy(75, 13);
				printf("정말로 '시간표' 정보로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '일정' 으로 돌아가는 중입니다.");
					for (i = 0; i < 2; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                             '시간표' 정보로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			timetable_1();
			break;
		}
		printf("%d %d\n", mouse.x, mouse.y);
		gotoxy(0, 0);
	}
}
void calender1() {
	screen :
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (1) {
		int i;
		mysql_query(conn, "select * from 학교소식 where num=1");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(75, 0);
			printf("%s\n", sql_row[1]);
			printf("%s\n", sql_row[2]);
		}
		printf("\n\n\n");
		printf("																					이전 화면으로 \n");
		printf("\n\n\n");
		printf("																					다음 달로 \n");
		POINT mouse;
		GetCursorPos(&mouse);
		printf("				    7월\n");
		printf("			일  월  화  수  목  금  토\n");
		printf("						1\n");
		printf("			2   3   4   ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("5   6   7	");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("8\n");
		printf("			9   10  11  12  13  14  15\n");
		printf("			16  17  18  19	");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("20  21	");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("22\n");
		printf("			23  ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("24  25  26  ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("27  28  29\n");
		printf("			30  31");
		gotoxy(0, 0);
		printf("%d %d\n", mouse.x, mouse.y);
		while ((mouse.x >= 1344 && mouse.y >= 168) && (mouse.x <= 1442 && mouse.y <= 168)) {
			system("cls");
			while (1) {
				gotoxy(75, 15);
				printf("정말로 이전 화면으로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  이전 화면으로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			category3();
			break;
		}
		while ((mouse.x >= 1344 && mouse.y >= 232) && (mouse.x <= 1410 && mouse.y <= 234)) {
			system("cls");
			Sleep(2000);
			calender2();
		}
		gotoxy(0, 0);
	}
}
void calender2() {
screen:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (1) {
		int i;
		mysql_query(conn, "select * from 학교소식 where num=2");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(75, 0);
			printf("%s\n", sql_row[1]);
			printf("%s\n", sql_row[2]);
		}
		printf("\n\n\n");
		printf("																					이전 화면으로 \n");
		printf("\n\n\n");
		printf("																					이전 달로 \n");
		POINT mouse;
		GetCursorPos(&mouse);
		printf("				    8월\n");
		printf("			일  월  화  수  목  금  토\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("				1   ");
		printf("2   3   4   ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("5\n");
		printf("			6   7   8   9  10  11  12\n");
		printf("			13   14	");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("15  16  ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("17  18  19\n");
		printf("			20  21	22  23  24  25  26\n");
		printf("			27  28  29  30  31\n");
		gotoxy(0, 0);
		printf("%d %d\n", mouse.x, mouse.y);
		while ((mouse.x >= 1344 && mouse.y >= 168) && (mouse.x <= 1442 && mouse.y <= 168)) {
			system("cls");
			while (1) {
				gotoxy(75, 15);
				printf("정말로 이전 화면으로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  이전 화면으로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			category3();
			break;
		}
		while ((mouse.x >= 1344 && mouse.y >= 232) && (mouse.x <= 1410 && mouse.y <= 234)) {
			system("cls");
			calender1();
			Sleep(1000);
		}
		gotoxy(0, 0);
	}
}
void timetable_1() {
	screen :
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (1) {
		int i;
		mysql_query(conn, "select * from 일정 where num=1");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(75, 0);
			printf("%s\n", sql_row[1]);
			printf("%s\n", sql_row[2]);
		}
		printf("\n\n\n\n\n");
		printf("																					다음 시간표로");
		printf("\n\n\n");
		printf("																					이전 화면으로 \n");
		POINT mouse;
		GetCursorPos(&mouse);
		//printf("%d %d\n", mouse.x, mouse.y);
		while ((mouse.x >= 1345 && mouse.y >= 422) && (mouse.x <= 1442 && mouse.y <= 426)) {
			system("cls");
			Sleep(1000);
			timetable_2();
		}
		while ((mouse.x >= 1346 && mouse.y >= 471) && (mouse.x <= 1443 && mouse.y <= 474)) {
			system("cls");
			while (1) {
				gotoxy(75, 15);
				printf("정말로 이전 화면으로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  이전 화면으로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			category3();
			break;
		}
		gotoxy(0, 0);
	}
}
void timetable_2() {
	screen :
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (1) {
		int i;
		mysql_query(conn, "select * from 일정 where num=2");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(75, 0);
			printf("%s\n", sql_row[1]);
			printf("%s\n", sql_row[2]);
		}
		printf("																					이전 시간표로");
		printf("\n\n\n\n\n");
		printf("																					다음 시간표로");
		printf("\n\n\n");
		printf("																					이전 화면으로 \n");
		POINT mouse;
		GetCursorPos(&mouse);
		//printf("%d %d\n", mouse.x, mouse.y);
		while ((mouse.x >= 1345 && mouse.y >= 342) && (mouse.x <= 1443 && mouse.y <= 346)) {
			system("cls");
			Sleep(1000);
			timetable_1();
		}
		while ((mouse.x >= 1345 && mouse.y >= 422) && (mouse.x <= 1442 && mouse.y <= 426)) {
			system("cls");
			Sleep(1000);
			timetable_3();
		}
		while ((mouse.x >= 1346 && mouse.y >= 471) && (mouse.x <= 1443 && mouse.y <= 474)) {
			system("cls");
			while (1) {
				gotoxy(75, 15);
				printf("정말로 이전 화면으로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  이전 화면으로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			category3();
			break;
		}
		gotoxy(0, 0);
	}
}
void timetable_3() {
screen:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (1) {
		int i;
		mysql_query(conn, "select * from 일정 where num=3");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(75, 0);
			printf("%s\n", sql_row[1]);
			printf("%s\n", sql_row[2]);
		}
		printf("																					이전 시간표로");
		printf("\n\n\n\n\n");
		printf("																					다음 시간표로");
		printf("\n\n\n");
		printf("																					이전 화면으로 \n");
		POINT mouse;
		GetCursorPos(&mouse);
		//printf("%d %d\n", mouse.x, mouse.y);
		while ((mouse.x >= 1345 && mouse.y >= 342) && (mouse.x <= 1443 && mouse.y <= 346)) {
			system("cls");
			Sleep(1000);
			timetable_2();
		}
		printf("%d %d\n", mouse.x, mouse.y);
		while ((mouse.x >= 1345 && mouse.y >= 422) && (mouse.x <= 1442 && mouse.y <= 426)) {
			system("cls");
			Sleep(1000);
			timetable_4();
		}
		while ((mouse.x >= 1346 && mouse.y >= 471) && (mouse.x <= 1443 && mouse.y <= 474)) {
			system("cls");
			while (1) {
				gotoxy(75, 15);
				printf("정말로 이전 화면으로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  이전 화면으로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			category3();
			break;
		}
		gotoxy(0, 0);
	}
}
void timetable_4() {
screen:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (1) {
		int i;
		mysql_query(conn, "select * from 일정 where num=4");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(75, 0);
			printf("%s\n", sql_row[1]);
			printf("%s\n", sql_row[2]);
		}
		printf("\n\n\n\n");
		printf("																					이전 시간표로");
		printf("\n\n\n\n\n");
		printf("																					다음 시간표로");
		printf("\n\n\n");
		printf("																					이전 화면으로 \n");
		POINT mouse;
		GetCursorPos(&mouse);
		//printf("%d %d\n", mouse.x, mouse.y);
		while ((mouse.x >= 1345 && mouse.y >= 342) && (mouse.x <= 1443 && mouse.y <= 346)) {
			system("cls");
			Sleep(1000);
			timetable_3();
		}
		while ((mouse.x >= 1345 && mouse.y >= 422) && (mouse.x <= 1442 && mouse.y <= 426)) {
			system("cls");
			Sleep(1000);
			timetable_5();
		}
		while ((mouse.x >= 1346 && mouse.y >= 471) && (mouse.x <= 1443 && mouse.y <= 474)) {
			system("cls");
			while (1) {
				gotoxy(75, 15);
				printf("정말로 이전 화면으로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  이전 화면으로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			category3();
			break;
		}
		gotoxy(0, 0);
	}
}
void timetable_5() {
screen:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (1) {
		int i;
		mysql_query(conn, "select * from 일정 where num=5");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(75, 0);
			printf("%s\n", sql_row[1]);
			printf("%s\n", sql_row[2]);
		}
		printf("\n\n\n\n");
		printf("																					이전 시간표로");
		printf("\n\n\n\n\n");
		printf("																					다음 시간표로");
		printf("\n\n\n");
		printf("																					이전 화면으로 \n");
		POINT mouse;
		GetCursorPos(&mouse);
		//printf("%d %d\n", mouse.x, mouse.y);
		while ((mouse.x >= 1345 && mouse.y >= 342) && (mouse.x <= 1443 && mouse.y <= 346)) {
			system("cls");
			Sleep(1000);
			timetable_4();
		}
		while ((mouse.x >= 1345 && mouse.y >= 422) && (mouse.x <= 1442 && mouse.y <= 426)) {
			system("cls");
			Sleep(1000);
			timetable_6();
		}
		while ((mouse.x >= 1346 && mouse.y >= 471) && (mouse.x <= 1443 && mouse.y <= 474)) {
			system("cls");
			while (1) {
				gotoxy(75, 15);
				printf("정말로 이전 화면으로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  이전 화면으로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			category3();
			break;
		}
		gotoxy(0, 0);
	}
}
void timetable_6() {
screen:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (1) {
		int i;
		mysql_query(conn, "select * from 일정 where num=6");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(75, 0);
			printf("%s\n", sql_row[1]);
			printf("%s\n", sql_row[2]);
		}
		printf("\n\n\n\n");
		printf("\n\n\n\n\n");
		printf("																					이전 시간표로");
		printf("\n\n\n");
		printf("																					이전 화면으로 \n");
		POINT mouse;
		GetCursorPos(&mouse);
		//printf("%d %d\n", mouse.x, mouse.y);
		while ((mouse.x >= 1345 && mouse.y >= 422) && (mouse.x <= 1442 && mouse.y <= 426)) {
			system("cls");
			Sleep(1000);
			timetable_5();
		}
		while ((mouse.x >= 1346 && mouse.y >= 471) && (mouse.x <= 1443 && mouse.y <= 474)) {
			system("cls");
			while (1) {
				gotoxy(75, 15);
				printf("정말로 이전 화면으로 이동하시겠습니까?\n");
				gotoxy(75, 20);
				printf("예                                        아니요");
				POINT mouse;
				GetCursorPos(&mouse);
				if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
					system("cls");
					break;
				}
				else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
					system("cls");
					goto screen;
				}
				//printf("%d %d\n", mouse.x, mouse.y);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                                                                  이전 화면으로 이동 중입니다.");
			for (i = 0; i < 2; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			category3();
			break;
		}
		gotoxy(0, 0);
	}
}
void ggultip_1() {
	screen :
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (1) {
		int i;
		mysql_query(conn, "select * from 꿀팁게시판 where num=1");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(25, 0);
			printf("%s  ", sql_row[1]);
			printf("%s\n", sql_row[2]);
		}
			printf("\n\n\n\n\n");
			printf("																					다음 팁으로");
			printf("\n\n\n");
			printf("																					이전 화면으로 \n");
			POINT mouse;
			GetCursorPos(&mouse);
			//printf("%d %d\n", mouse.x, mouse.y);
			while ((mouse.x >= 1344 && mouse.y >= 118) && (mouse.x <= 1427 && mouse.y <= 122)) {
				system("cls");
				Sleep(1000);
				ggultip_2();
			}
			while ((mouse.x >= 1346 && mouse.y >= 167) && (mouse.x <= 1444 && mouse.y <= 170)) {
				system("cls");
				while (1) {
					gotoxy(75, 15);
					printf("정말로 이전 화면으로 이동하시겠습니까?\n");
					gotoxy(75, 20);
					printf("예                                        아니요");
					POINT mouse;
					GetCursorPos(&mouse);
					if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
						system("cls");
						break;
					}
					else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
						system("cls");
						goto screen;
					}
					//printf("%d %d\n", mouse.x, mouse.y);
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf("                                                                                  이전 화면으로 이동 중입니다.");
				for (i = 0; i < 2; i++) {
					printf(".");
					Sleep(1000);
				}
				system("cls");
				mainscreen();
				break;
			}
			gotoxy(0, 0);
		}
	}
void ggultip_2() {
screen:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (1) {
		int i;
		mysql_query(conn, "select * from 꿀팁게시판 where num=2");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(25, 0);
			printf("%s  ", sql_row[1]);
			printf("%s\n", sql_row[2]);
		}
		printf("\n");
			printf("																					이전 팁으로");
			printf("\n\n\n\n");
			printf("																					다음 팁으로");
			printf("\n\n\n");
			printf("																					이전 화면으로 \n");
			POINT mouse;
			GetCursorPos(&mouse);
			printf("%d %d\n", mouse.x, mouse.y);
			while ((mouse.x >= 1345 && mouse.y >= 560) && (mouse.x <= 1425 && mouse.y <= 560)) {
				system("cls");
				Sleep(1000);
				ggultip_1();
			}
			while ((mouse.x >= 1344 && mouse.y >= 118) && (mouse.x <= 1427 && mouse.y <= 122)) {
				system("cls");
				Sleep(1000);
				ggultip_3();
			}
			while ((mouse.x >= 1346 && mouse.y >= 167) && (mouse.x <= 1444 && mouse.y <= 170)) {
				system("cls");
				while (1) {
					gotoxy(75, 15);
					printf("정말로 이전 화면으로 이동하시겠습니까?\n");
					gotoxy(75, 20);
					printf("예                                        아니요");
					POINT mouse;
					GetCursorPos(&mouse);
					if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
						system("cls");
						break;
					}
					else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
						system("cls");
						goto screen;
					}
					//printf("%d %d\n", mouse.x, mouse.y);
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf("                                                                                  이전 화면으로 이동 중입니다.");
				for (i = 0; i < 2; i++) {
					printf(".");
					Sleep(1000);
				}
				system("cls");
				mainscreen();
				break;
			}
			gotoxy(0, 0);
		}
	}
void ggultip_3() {
screen:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (1) {
		int i;
		mysql_query(conn, "select * from 꿀팁게시판 where num=3");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(25, 0);
			printf("%s  ", sql_row[1]);
			printf("%s\n", sql_row[2]);
		}
			printf("\n");
			printf("																					이전 팁으로");
			printf("\n\n\n\n");
			printf("																					다음 팁으로");
			printf("\n\n\n");
			printf("																					이전 화면으로 \n");
			POINT mouse;
			GetCursorPos(&mouse);
			printf("%d %d\n", mouse.x, mouse.y);
			while ((mouse.x >= 1345 && mouse.y >= 54) && (mouse.x <= 1428 && mouse.y <= 58)) {
				system("cls");
				Sleep(1000);
				ggultip_2();
			}
			while ((mouse.x >= 1344 && mouse.y >= 118) && (mouse.x <= 1427 && mouse.y <= 122)) {
				system("cls");
				Sleep(1000);
				ggultip_4();
			}
			while ((mouse.x >= 1346 && mouse.y >= 167) && (mouse.x <= 1444 && mouse.y <= 170)) {
				system("cls");
				while (1) {
					gotoxy(75, 15);
					printf("정말로 이전 화면으로 이동하시겠습니까?\n");
					gotoxy(75, 20);
					printf("예                                        아니요");
					POINT mouse;
					GetCursorPos(&mouse);
					if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
						system("cls");
						break;
					}
					else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
						system("cls");
						goto screen;
					}
					//printf("%d %d\n", mouse.x, mouse.y);
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf("                                                                                  이전 화면으로 이동 중입니다.");
				for (i = 0; i < 2; i++) {
					printf(".");
					Sleep(1000);
				}
				system("cls");
				mainscreen();
				break;
			}
			gotoxy(0, 0);
		}
	}
void ggultip_4() {
screen:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (1) {
		int i;
		mysql_query(conn, "select * from 꿀팁게시판 where num=4");
		sql_result = mysql_store_result(conn);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			gotoxy(25, 0);
			printf("%s  ", sql_row[1]);
			printf("%s\n", sql_row[2]);
		}
			printf("\n\n");
			printf("																					이전 팁으로");
			printf("\n\n\n");
			printf("																					이전 화면으로 \n");
			POINT mouse;
			GetCursorPos(&mouse);
			printf("%d %d\n", mouse.x, mouse.y);
			while ((mouse.x >= 1344 && mouse.y >= 118) && (mouse.x <= 1427 && mouse.y <= 122)) {
				system("cls");
				Sleep(1000);
				ggultip_3();
			}
			while ((mouse.x >= 1346 && mouse.y >= 167) && (mouse.x <= 1444 && mouse.y <= 170)) {
				system("cls");
				while (1) {
					gotoxy(75, 15);
					printf("정말로 이전 화면으로 이동하시겠습니까?\n");
					gotoxy(75, 20);
					printf("예                                        아니요");
					POINT mouse;
					GetCursorPos(&mouse);
					if ((mouse.x >= 602 && mouse.y >= 343) && (mouse.x <= 609 && mouse.y <= 346)) {
						system("cls");
						break;
					}
					else if ((mouse.x >= 937 && mouse.y >= 345) && (mouse.x <= 975 && mouse.y <= 346)) {
						system("cls");
						goto screen;
					}
					//printf("%d %d\n", mouse.x, mouse.y);
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf("                                                                                  이전 화면으로 이동 중입니다.");
				for (i = 0; i < 2; i++) {
					printf(".");
					Sleep(1000);
				}
				system("cls");
				mainscreen();
				break;
			}
			gotoxy(0, 0);
		}
	}
void end() {
	srand(time(NULL));
	int a = rand() % 7 + 9;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	while (1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
		printf("									프로그램을 종료합니다. 이용해 주셔서 감사합니다.\n");
		Sleep(3000);
		exit(0);
	}
}