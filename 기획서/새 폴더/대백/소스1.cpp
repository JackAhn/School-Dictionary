#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#pragma comment (lib, "SDL2")
#pragma comment (lib, "SDL2main")

void gotoxy(short x, short y) {
	COORD Pos = { Pos.X = x, Pos.Y = y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
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
void eventphoto();
void mainscreen();
void Using();
void end();

int main(int argc, char ** argv) {
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
void first() {
	while (1) {
		srand(time(NULL));
		int a = rand() % 7 + 9;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
		printf("                                                                                                                                                  \n");
		printf("                                                                                                                                                  \n");
		printf("                                                                                                                                                  \n");
		printf("                                                                                                                                                  \n");
		printf("                                                                                                                                                  \n");
		printf("                                                                                                                                                  \n");
		printf("                                                                                                                                                  \n");
		printf("                                                                                                                                                  \n");
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
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
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
				screen :
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
				printf("   │                학교에 대하여               │                 학교 소식                  │                     일정                   │               꿀팁 게시판                │     \n");
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
				POINT mouse;
				GetCursorPos(&mouse);
				printf("x : %d, y : %d \n", mouse.x, mouse.y);
				while ((mouse.x >= 34 && mouse.y >= 94) && (mouse.x <= 390 && mouse.y <= 287)) {
					system("cls");
					while (1) {
						gotoxy(75, 15);
						printf("정말로 '학교에 대하여' 카테고리로 이동하시겠습니까?\n");
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
					printf("                                                                                  학교에 대하여로 이동 중입니다.");
					for (i = 0; i < 4; i++) {
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
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                                  학교 소식으로 이동 중입니다.");
					for (i = 0; i < 4; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					category2();
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
					for (i = 0; i < 4; i++) {
						printf(".");
						Sleep(1000);
					}
					system("cls");
					break;
				}
				while ((mouse.x >= 1402 && mouse.y >= 56) && (mouse.x <= 1498 && mouse.y <= 58)) {
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
					for (i = 0; i < 4; i++) {
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
		POINT mouse;
		GetCursorPos(&mouse);
		if ((mouse.x >= 1281 && mouse.y >= 40) && (mouse.x <= 1438 && mouse.y <= 100)) {
			system("cls");
			first();
		}
		gotoxy(0, 0);
	}
}
void category1(){
	while (1) {
		int i;
		screen :
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
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '학교에 대하여'로 돌아가는 중입니다.");
					for (i = 0; i < 4; i++) {
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
			printf("                                                                             '대구 소프트웨어 고등학교란' 정보로 이동 중입니다.");
			for (i = 0; i < 4; i++) {
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
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '학교에 대하여'로 돌아가는 중입니다.");
					for (i = 0; i < 4; i++) {
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
			printf("                                                                                  '교가' 정보로 이동 중입니다.");
			for (i = 0; i < 4; i++) {
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
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '학교에 대하여'로 돌아가는 중입니다.");
					for (i = 0; i < 4; i++) {
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
			printf("                                                                                  '교가' 정보로 이동 중입니다.");
			for (i = 0; i < 4; i++) {
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
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '학교에 대하여'로 돌아가는 중입니다.");
					for (i = 0; i < 4; i++) {
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
			printf("                                                                                  '전공과목 소개' 정보로 이동 중입니다.");
			for (i = 0; i < 4; i++) {
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
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '학교에 대하여'로 돌아가는 중입니다.");
					for (i = 0; i < 4; i++) {
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
			printf("                                                                                  '학교구조 소개' 정보로 이동 중입니다.");
			for (i = 0; i < 4; i++) {
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
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("                                                                             '학교에 대하여'로 돌아가는 중입니다.");
					for (i = 0; i < 4; i++) {
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
			printf("                                                                                  학교에 대하여로 이동 중입니다.");
			for (i = 0; i < 4; i++) {
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
			for (i = 0; i < 4; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			mainscreen();
		}
		printf("%d %d\n", mouse.x, mouse.y);
		gotoxy(0, 0);
	}
}
void DB1() {
	while (1) {

	}
}
void DB2() {
	while (1) {

	}
}
void DB3() {
	while (1) {

	}
}
void DB4() {
	while (1) {

	}
}
void DB5() {
	while (1) {

	}
}
void DB6() {
	while (1) {

	}
}
void category2() {
	while (1) {
		int i;
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
		printf("			│                                              │                  (새창 열림)                 │                                            │     \n");
		printf("			│                                              │                                              │                                            │     \n");
		printf("			│                                              │                                              │                                            │     \n");
		printf("			│                                              │                                              │                                            │     \n");
		printf("			│          각종 중요한 정보를 한 곳에!         │       매번 학교에서 펼쳐지는 행사 사진을     │          가장 중요한 급식 정보를           │     \n");
		printf("			│                                              │               확인할 수 있는 곳!             │         한  눈으로 볼 수 있는 곳!          │     \n");
		printf("			│                                              │                                              │                                            │     \n");
		printf("			│                                              │                                              │                                            │     \n");
		printf("			└───────────────────────┴───────────────────────┴──────────────────────┘     \n");
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
		while ((mouse.x >= 590 && mouse.y >= 320) && (mouse.x <= 957 && mouse.y <= 510)) {
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("                                                                                   행사 사진으로 이동합니다.");
			for (i = 0; i < 4; i++) {
				printf(".");
				Sleep(1000);
			}
			system("cls");
			eventphoto();
		}
		printf("%d %d\n", mouse.x, mouse.y);
		gotoxy(0, 0);
	}
}
void eventphoto() {
	int argc; 
	char **argv;
		while (1) {
			first :
			bool quit = false;
			SDL_Window *pWindow = SDL_CreateWindow("abc", 100, 100, 500, 400, SDL_WINDOW_SHOWN); //윈도우 생성
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
			SDL_Surface *pHelloBMP = SDL_LoadBMP("abc.bmp");
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
			SDL_Delay(1000);
			printf("계속 보고 싶으시면 1번, 아니면 2번을 눌러주세요.\n");
			if (getch() == '1') {
				SDL_DestroyTexture(pTexture);
				SDL_DestroyRenderer(pRenderer);
				SDL_DestroyWindow(pWindow);
				SDL_Quit();
				system("cls");
				goto first;
			}
			else if (getch() == '2') {
				SDL_DestroyTexture(pTexture);
				SDL_DestroyRenderer(pRenderer);
				SDL_DestroyWindow(pWindow);
				SDL_Quit();
				system("cls");
				category2();
				break;
			}
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