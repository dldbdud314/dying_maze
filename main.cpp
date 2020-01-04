//main.cpp
#include "Game.h"
#include "lunaticGame.h"

#include<stdio.h> 
#include<Windows.h>
#include<conio.h>
#include<iostream>
#include<cstdlib>

#define col GetStdHandle(STD_OUTPUT_HANDLE)        // col는 enum 매개 변수 STD_OUTPUT_HANDLE로 호출하여 모든 표준 출력이 (콘솔) 인 창 핸들을 리턴합니다
#define WHITE  SetConsoleTextAttribute(col, 0x000f) // 흰색

#define MAX_STACK_SIZE 100 

using namespace std;

int main() {
   Game g;
   LunaticGame l;

   int a ,A,end1;
   int num, point = 0; // a는title()에서 입력될 변수 ,A는 index()에서 입력될 변수 endl은 한번 더할껀지에 관한 변수 
  
   HWND console = GetConsoleWindow(); //  HWND은 윈도우 디스크립터이다. 창에 대한 포인터로 볼 수 있습니다. 
   RECT r; // 게임들이 출력될 영역지정 윈도우 디스크립터 
   GetWindowRect(console, &r);
   MoveWindow(console, r.left, r.top, 900, 900, TRUE); // 800 width, 100 height
   
   system("cls");
   g.introFrame(); //시작화면 출력 
   g.title();   // 게임시작, 게임설명, 게임과정,종료 내용 
   cin >> a;
   while(1){
       if(a == 29){ //게임설명창에서 esc를 입력할경우  
           system("cls");
           g.introFrame();
           g.title();
           cin >> a;
      }
       if (a == 1){// 게임시작 선택경우  
           g.endingFrame();  //기본프레임 
           g.index();
           g.gotoxy(39, 18);
           cout << "되돌아가려면 29번" << endl;
           g.gotoxy(27, 17);
           cin >> A;
           system("cls");
           while (1) {
              if(A == 29){ //게임설명창에서 esc를 입력할경우  
                 system("cls");
                 g.introFrame();
                 g.title();
                 cin >> a;
                 break;
            }
              else if(A == 1){ //1학년 선책한 경우 
                  g.gotoxy(0,0); // 미로가 출력될 시작점 
                  g.setMatrix(); // 2차원배열로 만들어진 미로출력을 위해 이중포인터로 힙메모리에 성정 
                  g.setDFSMatrix(); // 미로안의 최단거리를 구함 (재귀 함수 이용)
                  g.display(A); // 게임밑 미로의 모양출력 
                  system("cls");// 게임이 끝나면 현 화면을 운영 체제에서 허용하는 경우 clear 시킨다. (stdlib.h)
                  g.endingFrame();
                  g.gotoxy(19, 6);// grade()를 출력할 시작점  
                  g.grade();// 최단거리, 게임의 승률 에따른 학점부여 
                  g.gotoxy(20,14);
                  cout <<"  1.한번 더  2.그만";
                  g.gotoxy(18,12);
                  cout << "한번 더 도전하시겠습니까?" << endl;
                  g.gotoxy(24,16);
                  cin >> end1;
                  system("cls");
                  if(end1==2) // endl이 1일때는 종료가 아니므로 while이 께속 1인 true로 유지 하므로 또다시 미로가 실행된다. 
                      return 0;
              }
               else if (A == 2){//2학년일때 
                  g.gotoxy(0,0);
                  g.setMatrix();
                  g.setDFSMatrix(); 
                  g.display(A);
                  system("cls");
                  g.endingFrame();
                  g.gotoxy(19, 6);
                  g.grade();
                  g.gotoxy(20,14);
                  cout <<"  1.한번 더  2.그만";
                  g.gotoxy(18,12);
                  cout << "한번 더 도전하시겠습니까?" << endl;
                  g.gotoxy(24,16);
                  cin >> end1;
                  system("cls");
                  if(end1==2)
                      return 0;
               }
               else if(A == 7){ //루나틱일때 
                  l.gotoxy(0,0);//새로운 객체를 생성하여 루나틱메트릭스 따로 호출 
                  l.setLunaticMatrix();  
                  l.display(A);
                  l.gotoxy(24,16);
                  cin >> end1;
                  system("cls");
                  if(end1==2)
                      return 0;
              }
           }
       }
       else if (a == 2){//미로 설명 
           system("cls");
           g.endingFrame();
           g.gotoxy(2, 7);
           cout << "당신은 호구아트 학생 Walld H Ro.\n┃ 트라위저드 토너먼트의 참가자를 결정하는 물의 잔 속에서\n┃ 당신의 이름이 뽑혔습니다.\n┃ 최강자의 타이틀을 얻기위해 마지막 관문을 통과해야합니다.\n┃ 마지막 관문은 DYING MAZE.\n┃ 함정에서 살아남아 학점을 쟁취하세요.";
           g.gotoxy(39, 18);
           cout << "되돌아가려면 29번" << endl;
           g.gotoxy(52, 18);
           cin >> a;// window.h에있는 esc의 16진수 코드가 입력될 경우를 따진다. 
       } 
       else if (a == 3){//게임 설명 
           system("cls");
           g.endingFrame();
           g.explain();
           g.gotoxy(39, 18);
           cout << "되돌아가려면 29번" << endl;
           g.gotoxy(20, 16);
         cout<<"입력>> ";
           cin >> num;
           if(num == 29)
           {
              point++;
         } 
          while(1)
           {
              switch(num){
                 case 1 :
                     system("cls");
                     g.endingFrame();
                     g.gotoxy(25, 4);
                     cout << "넌센스 퀴즈" << endl;
                     g.gotoxy(17, 10);
                     cout <<"말 그대로 넌센스 퀴즈입니다." << endl;
                     g.gotoxy(39, 18);
                     cout << "되돌아가려면 29번" << endl;
                     g.gotoxy(52, 18);
                     cin >> num;// window.h에있는 esc의 16진수 코드가 입력될 경우를 따진다.
                     point += 2;
                     break;
               case 2 :
                     system("cls");
                     g.endingFrame();
                     g.gotoxy(23, 4);
                     cout << "가위바위보"<<endl;
                     g.gotoxy(6, 10);
                     cout << "0:가위 1:바위 2:보로 컴퓨터와 진검승부를 펼치세요!" << endl;
                     g.gotoxy(39, 18);
                     cout << "되돌아가려면 29번" << endl;
                     g.gotoxy(52, 18);
                     cin >> num;// window.h에있는 esc의 16진수 코드가 입력될 경우를 따진다.
                     point += 2;
                     break;
                 case 3 :
                     system("cls");
                     g.endingFrame();
                     g.gotoxy(22, 4);
                     cout << "랜덤숫자 맞추기"<<endl;
                     g.gotoxy(2, 9);
                     cout<<"1~100사이 랜덤숫자를 정해서 그 숫자를 맞추는 게임입니다. \n┃ 랜덤수보다 낮을시 up, 높으면 down 이라고 알려줍니다. \n┃ 5번의 기회 안에 맞추시길 바랍니다.\n┃ (소주뚜껑 숫자맞추기 많이 하셨죠ㅎㅎ)"<<endl;
                     g.gotoxy(39, 18);
                     cout << "되돌아가려면 29번" << endl;
                     g.gotoxy(52, 18);
                     cin >> num;// window.h에있는 esc의 16진수 코드가 입력될 경우를 따진다.
                     point += 2;
                    break;
                 case 4 :
                     system("cls");
                     g.endingFrame();
                     g.gotoxy(24, 4);
                     cout << "숫자야구게임"<<endl;
                     g.gotoxy(2, 8);
                     cout<<"0부터 9까지의 숫자 3중 [3개의 숫자]를 정확히 맞추면 된다.\n┃ 3자리 수에서 포함된 수가 플레이어가 말한 수와 자릿수는\n┃ 틀리고 수는 맞을 시 맞는 갯수에따라 최대 3[볼]이 가능하다.\n┃ 더하여 수가 맞고 자릿수까지 같으면 최대 3[스트라이크]로 \n┃ 게임이 종료된다."<<endl;
                     g.gotoxy(39, 18);
                     cout << "되돌아가려면 29번" << endl;
                     g.gotoxy(52, 18);
                     cin >> num;// window.h에있는 esc의 16진수 코드가 입력될 경우를 따진다.
                  point += 2; 
                     break;
              }
              if(num == 29 && point % 2 == 0)
              {
                 system("cls");
                 g.endingFrame();
                 g.explain();
                 g.gotoxy(39, 18);
                 cout << "되돌아가려면 29번" << endl;
                 g.gotoxy(20, 16);
               cout << "입력>> ";
                 //num = _getch();
                 point = 0;
                 cin >> num;
                 if(num == 29)
                 {
                    point++;
               }
            }
            else if(num == 29 && point % 2 == 1)
            {
               a = num;
               num = 0;
               point = 0;
               break;
            }
         }
       }
       else if (a == 4){//첫 화면세서 종료할 때
           system("cls");
           g.endingFrame();
           g.gotoxy(26, 6);
           cout<<"The End";
           g.gotoxy(21, 12);
           cout<<"게임을 종료 합니다.";
           g.gotoxy(26, 30);
           cout<<"";
           return 0;                  
       }
   }    
   return 0;
}
