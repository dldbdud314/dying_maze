//Game.cpp

#include "Game.h"

#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<iostream>
#include<cstdlib>
#include <ctime>

#define col GetStdHandle(STD_OUTPUT_HANDLE)     // 콘솔창의 핸들정보를 받아옵니다.
#define WHITE  SetConsoleTextAttribute(col, 0x000f) // 흰색
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define TRUE 1
#define FALSE 0

#define GAWI 0
#define BAWI 1
#define BO 2
#define MY_WIN 0
#define PC_WIN 1
#define DRAW 2
using namespace std;

Game::Game(){
    count = 0;
    wrongAnsNum = 0;
}

void Game::upDown() //업다운 게임 
{
   gotoxy(0, 0);
   int seed=time(NULL);
   srand(seed);
   int number = rand() % 100 + 1;
   int answer, count = 0;
   
   cout << "(기회는 다섯 번 입니다.)" << endl; 
   for(int i = 0; i < 5; i++)
   {
      cout << "예상하는 랜덤수를 쓰시오: ";
      cin >> answer;
      
      if(number > answer)
      {
         cout << "up" << endl;
      }
      else if(number < answer)
      {
         cout << "down" << endl;
      }
      else if(number == answer)
      {
         cout << "correct!" << endl;
         count++;
         Sleep(1000);
       break;
      }
   }
   if(count == 0)
   {
      cout << "정답을 맞추지 못했습니다. 정답은 " << number << "입니다." << endl;
      Sleep(1000);
        wrongAnsNum++; 
   }
}

void Game::gawiBawiBo(){ //가위바위보 게임 
    int player, computer;
    int count = 0;
    int no=0;
    int winner;
    cout << "당신은 가위바위보 세계에 빠졌습니다. 3번의 가위바위보를 통해 승리를 쟁취하십쇼." << endl;
 
    while(count < 3){
   int seed=time(NULL);
      srand(seed);    
    computer = rand()%3;
    
    cout <<"가위: 0, 바위 1: 보:2 >";
    cin >> player;
    
   if(player <= 2){
    if (player == computer) winner = DRAW;
    if ((player == GAWI) && (computer == BAWI)) winner = PC_WIN; 
    if ((player == GAWI) && (computer == BO))  winner = MY_WIN;   
    if ((player == BAWI) && (computer == BO)) winner = PC_WIN;
    if ((player == BAWI) && (computer == GAWI))   winner = MY_WIN;
    if ((player == BO) && (computer == GAWI))  winner = PC_WIN;
    if ((player == BO) && (computer == BAWI))    winner = MY_WIN;  
   
   
     switch (winner){
       case DRAW:       
          cout <<"무승부입니다. 운이 좋군 자네.\n";
          break;
        case PC_WIN:
             cout <<"당신은 졌습니다. 애송이군.\n";
             no++;
             count++;
             break;
       case MY_WIN:
             cout <<"당신이 이겼습니다. 쳇.\n";
              count++;
              break;
          } 
   }
   else if(player > 2) 
      cout << "0, 1, 2 중에 선택하세요.\n";
      
    if(count == 3 && no >= 2){
       wrongAnsNum++; 
       Sleep(1000);
    }
    else if (count == 3 && no < 2){
       Sleep(1000);
   }
 }
}

void Game::numBall(){ //숫자야구 게임 
   int COM[3];
   int USER[3];
   int i,j;
   int num=1;
   int Strike=0;
   int Ball=0;
   
   for(i=0;i<3;i++){
      COM[i]=(rand()%9)+1;
      for(j=0;j<i;j++)
         if(COM[i]==COM[j]&&i!=j)
            i--;
   }
   while(1){
      cout<<num<<" 번째 시도 "<<endl;   
      while(1){
      cout<<"1~9까지의 숫자 3개를 입력하세요: ";
      cin>>USER[0]>>USER[1]>>USER[2];
      if(USER[0]<1||USER[0]>9||USER[1]<1||USER[1]>9||USER[2]<1||USER[2]>9)
      {
         cout<<"범위내에서만 입력하세요.."<<endl;
         continue; 
         }   
       else if(USER[0]==USER[1]||USER[1]==USER[2]||USER[2]==USER[0])
       {
          cout<<"중복해서 입력하지 마세요.."<<endl;
         continue; 
          }   
      break;    
    }
   for(i=0;i<3;i++)
      for(j=0;j<3;j++)
         if(COM[i]==USER[j])
            if(i==j)
               Strike++;
            else
               Ball++;
                  
   if(Strike||Ball)
      cout<<"=> "<<Strike<<" 스트라이크 & "<<Ball<<" 볼"<<endl<<endl;
   else
      cout<<"...... 아웃! "<<endl<<endl;
   if(Strike==3){
      if(num<4){
         cout<<"당신은 찍신입니다"<<endl;
       Sleep(1000); 
      } 
      else if(num==4){
         cout<<"당신은 천재입니다.. 리스펙!"<<endl;
       Sleep(1000); 
      } 
      else if(num<9){
         cout<<"당신은 보통입니다"<<endl;
       Sleep(1000); 
      } 

      Strike=Ball=0;
      num=1;
      break;       
   }
   
   else if(num==9){
         cout<<"이제 그만하세요...ㄸㄹㄹ"<<endl; 
         cout<<"정답은 [ "<<COM[0] << COM[1] << COM[2]<<" ] 입니다" <<endl;
         wrongAnsNum++; 
       Sleep(1000);
        
      Strike=Ball=0;
      num=1;
      break;    
   }
   Strike=Ball=0;       
   ++num;   
  }
      system("cls");
      mazeFrame();   
}

void Game::nonSenseQuiz(){ //넌센스 퀴즈 
   string ans;
   string userAns; 
   int x = rand() % 10;
   switch(x){
         case 0: 
            ans = "와이파이"; 
            cout<<"\n\n\t\t ♤♠---  넌센스 퀴이이즈으으--- ♤♠"<<endl<<endl; 
            cout << "\t\t 이 나라에 아기를 벤 엄마 애플파이가 살았습니다. \n\t 엄마 애플파이는 호기심이 많은 아기 애플파이가 나오길 기도했습니다.";
          cout<<"\n \t\t 며칠이 지나 아기 파이가 태어났습니다.\n\n\t\t 과연 이 아기 파이의 이름은 무엇일까요?"<<endl<<endl;
            cout << "\n\t띄어쓰기 없이 답변을 작성해주세요. 모르면 '?'로 답해주세요!" << endl;
            cout<<"\n\t\t\t답: ";
         cin >> userAns;
            if(ans == userAns)
               cout << "\n\t\t\t ----- 정답입니다!!-----";
            else if(userAns == "?"){
                cout << "궁금하겠지만 답 안 알랴줌^_^";
                wrongAnsNum++;
             }
            else{
               cout << "땡! 틀렸습니다! 답은 '와이파이'입니다!";
            wrongAnsNum++; 
            }
            break; 
         case 1:
            ans = "패스트푸드";
            cout<<"\n\n\t\t ♠♤♠ ---  넌센스 퀴이이즈으으--- ♠♤♠"<<endl<<endl; 
            cout << "\t\t\t|| 식인종에게 우사인볼트는? ||"<<endl<<endl;
           cout << "\n \t띄어쓰기 없이 답변을 작성해주세요. 모르면 '?'로 답해주세요!" << endl;
            cout<<"\n\t\t\t답: ";
       cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----정답입니다!!-----";
            else if(userAns == "?"){
                cout << "궁금하겠지만 답 안 알랴줌^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t 땡! 틀렸습니다! 답은 '패스트푸드'입니다!";
               wrongAnsNum++;
            }
            break;
        case 2:
           ans = "일본사람";
           cout<<"\n\n\t\t ♠♤♠ ---  넌센스 퀴이이즈으으--- ♠♤♠"<<endl<<endl; ; 
            cout << "\t\t || 화장실 에서 방금 나온 사람은?? ||"<<endl<<endl;
             cout << "\n \t띄어쓰기 없이 답변을 작성해주세요. 모르면 '?'로 답해주세요!" << endl;
            cout<<"\n\t\t\t답: ";
       cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----정답입니다!!-----";
            else if(userAns == "?"){
                cout << "궁금하겠지만 답 안 알랴줌^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t땡! 틀렸습니다! 답은 '일본사람'입니다!";
               wrongAnsNum++;
            }
            break;
        case 3:
         ans = "신동엽";
        cout<<"\n\n\t\t ♠♤♠ ---  넌센스 퀴이이즈으으--- ♠♤♠"<<endl<<endl; 
            cout << "\t\t || 슈퍼쥬니어 '신동' 옆에 있는 사람은?? ||"<<endl<<endl;
            cout << "\n \t띄어쓰기 없이 답변을 작성해주세요. 모르면 '?'로 답해주세요!" << endl;
            cout<<"\n\t\t\t답: ";
       cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----정답입니다!!-----";
            else if(userAns == "?"){
                cout << "궁금하겠지만 답 안 알랴줌^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t땡! 틀렸습니다! 답은 '신동엽'입니다!";
               wrongAnsNum++;
         }
            break; 
        case 4:
         ans = "유언비어";
         cout<<"\n\n\t\t ♤♠---  넌센스 퀴이이즈으으--- ♤♠"<<endl<<endl; 
            cout << "\t\t || 맥주가 죽기 전, 한 말은? ||"<<endl<<endl;
             cout << "\n \t띄어쓰기 없이 답변을 작성해주세요. 모르면 '?'로 답해주세요!" << endl;
            cout<<"\n\t\t\t답: ";
       cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----정답입니다!!-----";
            else if(userAns == "?"){
                cout << "궁금하겠지만 답 안 알랴줌^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t땡! 틀렸습니다! 답은 '유언비어'입니다!";
               wrongAnsNum++;
            }
            break;
      case 5:
         ans ="산채비빔밥";
         cout<<"\n\n\t\t ♠♤♠ ---  넌센스 퀴이이즈으으--- ♠♤♠"<<endl<<endl; 
            cout << "\t\t || 세상에서 가장 잔인한 비빔밥은?? ||" <<endl<<endl;
             cout << "\n \t띄어쓰기 없이 답변을 작성해주세요. 모르면 '?'로 답해주세요!" << endl;
            cout<<"\n\t\t\t답: ";
       cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----정답입니다!!-----";
            else if(userAns == "?"){
                cout << "궁금하겠지만 답 안 알랴줌^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t땡! 틀렸습니다! 답은 '산채비빔밥'입니다!";
               wrongAnsNum++;
            }
            break;
      case 6:
         ans ="을지문덕";
         cout<<"\n\n\t\t ♠♤♠ ---  넌센스 퀴이이즈으으--- ♠♤♠"<<endl<<endl; 
            cout << "\t\t\t|| 싸움을 잘하는 오리는?? ||"<<endl<<endl;
             cout << "\n \t띄어쓰기 없이 답변을 작성해주세요. 모르면 '?'로 답해주세요!" << endl;
            cout<<"\n\t\t\t답: ";
          cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----정답입니다!!-----";
            else if(userAns == "?"){
                cout << "궁금하겠지만 답 안 알랴줌^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t땡! 틀렸습니다! 답은 '을지문덕'입니다!";
               wrongAnsNum++;
            }
            break;
      case 7:
         ans ="글로벌";
         cout<<"\n\n\t\t ♠♤♠ ---  넌센스 퀴이이즈으으--- ♠♤♠"<<endl<<endl; 
            cout << "\t\t\t|| 반성문을 영어로 하면? ||"<<endl<<endl;
             cout << "\n \t띄어쓰기 없이 답변을 작성해주세요. 모르면 '?'로 답해주세요!" << endl;
            cout<<"\n\t\t\t답: ";
       cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----정답입니다!!-----";
            else if(userAns == "?"){
                cout << "궁금하겠지만 답 안 알랴줌^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t땡! 틀렸습니다! 답은 '글로벌'입니다!";
               wrongAnsNum++;
            }
            break;
      case 8:
         ans ="부처핸섬";
        cout<<"\n\n\t\t ♠♤♠ ---  넌센스 퀴이이즈으으--- ♠♤♠"<<endl<<endl; 
            cout << "\t\t\t|| 잘생긴 부처님은?? ||"<<endl<<endl;
            cout << "\n \t띄어쓰기 없이 답변을 작성해주세요. 모르면 '?'로 답해주세요!" << endl;
            cout<<"\n\t\t\t답: ";
       cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----정답입니다!!-----";
            else if(userAns == "?"){
                cout << "궁금하겠지만 답 안 알랴줌^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t땡! 틀렸습니다! 답은 '부처핸섬'입니다!";
               wrongAnsNum++;
            }
            break;
      case 9:
         ans ="개강해서";
         cout<<"\n\n\t\t ♠♤♠ ---  넌센스 퀴이이즈으으--- ♠♤♠"<<endl<<endl;  
            cout << "\t\t|| 3월이 되면 대학생이 강한 이유는??||"<<endl<<endl;
            cout << "\n \t띄어쓰기 없이 답변을 작성해주세요. 모르면 '?'로 답해주세요!" << endl;
            cout<<"\n\t\t\t답: ";
          cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----정답입니다!!-----";
            else if(userAns == "?"){
                cout << "궁금하겠지만 답 안 알랴줌^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t땡! 틀렸습니다! 답은 '개강해서'입니다!";
               wrongAnsNum++;
            }
            break;   
       }
      Sleep(1000);
}

bool Game::isEqual(){ //grade()에서 지나온 경로와 최단경로 비교작업을 위한 함수
   int equal = 0;
   for(int i = 0; i < q; i++)
   {
       for(int j = 0; j < p; j++)
       {
          if(his[j].b == stPath[i].b && his[j].a == stPath[i].a)
          {
              equal++;
              //break;
          }
      }
   }
   if(equal < p)
   {
      equal = 0;
      return false;
   }
   else if(equal == p)
   {
      equal = 0;
      return true;
   }
}

void Game::grade(){ //최단경로로 갔는지(기준1)와 틀린 게임 개수(기준2)에 따라 미로 탈출 성적 매기기 
   if(isEqual() == true)
   {
      switch(wrongAnsNum){
          case 0:
              cout<<"당신의 학점은 A+ ! (敗:0 / 加+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
         case 1:
              cout<<"당신의 학점은 A0 ! (敗:1 / 加+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 2:
              cout<<"당신의 학점은 A0 ! (敗:2 / 加+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 3:
              cout<<"당신의 학점은 B+ ! (敗:3 / 加+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 4:
              cout<<"당신의 학점은 B+ ! (敗:4 / 加+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 5:
              cout<<"당신의 학점은 B0 ! (敗:5 / 加+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break; 
          case 6:
              cout<<"당신의 학점은 C+ ! (敗:6 / 加+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 7:
              cout<<"당신의 학점은 C0 ! (敗:7 / 加+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 8:
              cout<<"당신의 학점은 D+ ! (敗:8 / 加+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;   
          default:
               cout<<"Good Bye 다신보지말자 "<<endl; 
              cout<<"당신의 학점은 F ! (敗:9+)"<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
         }
   }
   else if(isEqual() == false)
   {
      switch(wrongAnsNum){
          case 0:
              cout<<"당신의 학점은 A0 ! (敗:0) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
         case 1:
              cout<<"당신의 학점은 A0 ! (敗:1) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 2:
              cout<<"당신의 학점은 A- ! (敗:2) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 3:
              cout<<"당신의 학점은 B0 ! (敗:3) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 4:
              cout<<"당신의 학점은 B0 ! (敗:4) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 5:
              cout<<"당신의 학점은 B- ! (敗:5) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break; 
          case 6:
              cout<<"당신의 학점은 C0 ! (敗:6) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 7:
              cout<<"당신의 학점은 D0 ! (敗:7) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 8:
              cout<<"당신의 학점은 D- ! (敗:8) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;   
          default:
               cout<<"Good Bye 다신보지말자 "<<endl; 
              cout<<"당신의 학점은 F ! (敗:9+)"<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
       }
   }
}

void Game::display(int A){
   int x = 2, y = 0;
    int trapx, trapy = 0;
    
    his[p].a = x; //구조체 배열에 저장 
    his[p].b = y; 
    p++;
    char dir;
   //////////////////////////////////////////
   mazeFrame();
   gotoxy(y, x);
   cout << "☞";
   while (1) {
      dir = _getch(); //방향키 누름 인지 
      if (dir == 72) { //방향키 UP 
        if (map[x - 1][y] != 0 && x >= 0 && y >= 0) {
            gotoxy(y * 2, x);
            printf(" ");
            x = x - 1;
            gotoxy(y * 2, x);
            cout<<"☞";
            
            his[p].a = x; //구조체 배열에 저장 
            his[p].b = y; 
            p++;
        }
      }
      else if (dir == 80) { //방향키 DOWN
        if (map[x + 1][y] != 0 && x >= 0 && y >= 0) {
            gotoxy(y * 2, x);
            printf(" ");
            x = x + 1;
            gotoxy(y * 2, x);
            cout<<"☞";
            
            his[p].a = x;
            his[p].b = y; 
            p++;
        }
      }
      else if (dir == 75) { //방향키 LEFT
        if (map[x][y - 1] != 0 && x >= 0 && y >= 0) {
            gotoxy(y * 2, x);
            printf(" ");
            y = y - 1;
            gotoxy(y * 2, x);
            cout<<"☞";
            
            his[p].a = x;
            his[p].b = y; 
            p++;
        }
      }
      else if (dir == 77) { //방향키 RIGHT
        if (map[x][y + 1] != 0 && x >= 0 && y >= 0) {
            gotoxy(y * 2, x);
            printf(" ");
            y = y + 1;
            gotoxy(y * 2, x);
            cout<<"☞";
            
            his[p].a = x;
            his[p].b = y; 
            p++;
        }
      }
      else if (dir == 'r') {
         gotoxy(y * 2, x);
         cout<<"  ";
         x = 2;
         y = 0;
         gotoxy(y * 2, x);
         cout<<"☞";
         count = 0;
      }
      
      if(A == 1){ //1학년 
      if(map[x][y] == 2) //2번 함정에 빠졌을 때 
      {
         system("cls");
         int a = rand() % 3;
       switch(a) //랜덤으로 게임 선택 
         {
            case 0:
               upDown();
               count++;
               break;
            case 1:
               gawiBawiBo();
               count++;
               break;
         case 2:
            nonSenseQuiz();
            count++;
            break;    
         }
         system("cls");
         mazeFrame();
        if(count%7 == 1 || count%7 == 6 || count%7 == 0){
       y = y + 1;
        his[p].a = x;
         his[p].b = y; 
         p++; 
         }
        else if(count%7 == 2 || count%7 == 3 || count%7 == 5){
           x = x + 1;
            his[p].a = x;
         his[p].b = y; 
         p++; 
    	}
    	else if(count % 7 == 4)
    	{
    		x = x -1;
    		his[p].a = x;
        	his[p].b = y; 
        	p++;
		}
         gotoxy(y * 2, x);
         cout << "☞";
      }
      
   if(map[x][y] == 4) //4번 함정에 빠졌을 때 
   {
      trapx = x;
      trapy = y;
   }
   if(map[x][y] == 3) //3번 함정에 빠졌을 떄 
      { 
        system("cls");
        int a = rand() % 3;
        
       switch(a)
        {
            case 0:
                  upDown();
                  break;
            case 1:
                  gawiBawiBo();
                  break;
            case 2:
               nonSenseQuiz();
               break;
        }
         system("cls");
         mazeFrame();
         y = trapy;
         x = trapx;
         gotoxy(y * 2, x);
         cout << "☞"; 
         his[p].a = x;
         his[p].b = y; 
         p++; 
      }
  }
  else if(A == 2){ //2학년 
     
      if(map[x][y] == 2)
      {
         system("cls");
        int a = rand() % 4;
        
       switch(a)
         {
            case 0:
               upDown();
               count++;
               break;
            case 1:
               gawiBawiBo();
               count++;
               break;
            case 2:
               numBall();
               count++;
               break;
            case 3:
               nonSenseQuiz();
               count++;
               break;    
         }
         system("cls");
         mazeFrame();
        if(count%7 == 1 || count%7 == 6 || count%7 == 0){
       y = y + 1;
        his[p].a = x;
         his[p].b = y; 
         p++; 
         }
        else if(count%7 == 2 || count%7 == 3 || count%7 == 5){
           x = x + 1;
            his[p].a = x;
         	his[p].b = y; 
         	p++; 
    	}
    	else if(count % 7 == 4)
    	{
    		x = x -1;
    		his[p].a = x;
        	his[p].b = y; 
        	p++;
		}
         gotoxy(y * 2, x);
         cout << "☞"; 

      }
   if(map[x][y] == 4)
   {
      trapx = x;
      trapy = y;
   }
   if(map[x][y] == 3)
      { 
         system("cls");
         int a = rand() % 4;
        // int a = 3;
       switch(a)
         {
            case 0:
               upDown();
               break;
            case 1:
               gawiBawiBo();
               break;
            case 2:
               numBall();
               break; 
         case 3:
            nonSenseQuiz();
            break;
         }
         system("cls");
         mazeFrame();
         y = trapy;
         x = trapx;
         gotoxy(y * 2, x);
         cout << "☞"; 
          his[p].a = x;
         his[p].b = y; 
         p++; 
      }
  }
      if (map[x][y] == 9){
        break;
     }
   }
   gotoxy(66, 20);
   cout<<"!!!!!!success!!!!!!"<<endl;
   ////////////////////////////////////

   gotoxy(66, 22);
   cout<<"아무키나 누르면 종료\n";
   _getch();
  }

void Game::mazeFrame(){
     for(int i=0; i < Matrix::m; i++){
            for(int j=0; j < Matrix::n; j++){
       
         if (map[i][j] == 9) {
            cout<<"★";
         }
         else if (map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 5) {
            cout<<"  ";
         }
         else if (map[i][j] == 0) {
            cout<<"■";
         }
        
      }
      printf("\n");
   }
   
   gotoxy(66, 10);
   cout<<"위[↑]";
   gotoxy(66, 11);
   cout<<"아래[↓]";
   gotoxy(66, 12);
   cout<<"왼쪽[←]";
   gotoxy(66, 13);
   cout<<"오른쪽[→]";
   gotoxy(66, 14);
   cout<<"r == 리셋";
  }
