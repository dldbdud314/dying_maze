//LunaticGame.cpp
#include "LunaticGame.h"

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

LunaticGame::LunaticGame(){
   
}

void LunaticGame::upDown() //업다운 게임 
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
       }
}

void LunaticGame::gawiBawiBo(){ //가위바위보 게임 
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
       Sleep(1000);
    }
    else if (count == 3 && no < 2){
       Sleep(1000);
   }

 }

}

void LunaticGame::numBall(){ //숫자야구 게임 
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
       Sleep(1000);
        
      Strike=Ball=0;
      num=1;
      break;    
   }
   Strike=Ball=0;       
   ++num;   
  }
      system("cls");
      lunaticMazeFrame();   
}

void LunaticGame::nonSenseQuiz(){ //넌센스 퀴즈 
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
             }
            else{
               cout << "땡! 틀렸습니다! 답은 '와이파이'입니다!"; 
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
                
             }
            else{
               cout << "\n\t\t\t 땡! 틀렸습니다! 답은 '패스트푸드'입니다!";
               
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
                
             }
            else{
               cout << "\n\t\t\t땡! 틀렸습니다! 답은 '일본사람'입니다!";
               
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
                
             }
            else{
               cout << "\n\t\t\t땡! 틀렸습니다! 답은 '신동엽'입니다!";
               
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
                
             }
            else{
               cout << "\n\t\t\t땡! 틀렸습니다! 답은 '유언비어'입니다!";
               
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
                
             }
            else{
               cout << "\n\t\t\t땡! 틀렸습니다! 답은 '산채비빔밥'입니다!";
               
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
                
             }
            else{
               cout << "\n\t\t\t땡! 틀렸습니다! 답은 '을지문덕'입니다!";
               
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
                
             }
            else{
               cout << "\n\t\t\t땡! 틀렸습니다! 답은 '글로벌'입니다!";
               
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
                
             }
            else{
               cout << "\n\t\t\t땡! 틀렸습니다! 답은 '부처핸섬'입니다!";
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
             }
            else{
               cout << "\n\t\t\t땡! 틀렸습니다! 답은 '개강해서'입니다!";
            }
            break;   
       }
      Sleep(1000);
}

void LunaticGame::display(int A){
   int x = 2, y = 0;
    char dir;
   //////////////////////////////////////////
   lunaticMazeFrame();
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
        }
      }
      else if (dir == 80) { //방향키 DOWN
        if (map[x + 1][y] != 0 && x >= 0 && y >= 0) {
            gotoxy(y * 2, x);
            printf(" ");
            x = x + 1;
            gotoxy(y * 2, x);
            cout<<"☞";
        }
      }
      else if (dir == 75) { //방향키 LEFT
        if (map[x][y - 1] != 0 && x >= 0 && y >= 0) {
            gotoxy(y * 2, x);
            printf(" ");
            y = y - 1;
            gotoxy(y * 2, x);
            cout<<"☞";
        }
      }
      else if (dir == 77) { //방향키 RIGHT
        if (map[x][y + 1] != 0 && x >= 0 && y >= 0) {
            gotoxy(y * 2, x);
            printf(" ");
            y = y + 1;
            gotoxy(y * 2, x);
            cout<<"☞";
        }
      }
      else if (dir == 'r') {
         gotoxy(y * 2, x);
         cout<<"  ";
         x = 2;
         y = 0;
         gotoxy(y * 2, x);
         cout<<"☞";
      }
      
      if(A == 7){ //1학년 
      if(map[x][y] == 2) //2번 함정에 빠졌을 때 
      {
         system("cls");
         int a = rand() % 4;
       switch(a) //랜덤으로 게임 선택 
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
           case 3:
              numBall();
              break;
         }
         system("cls");
         lunaticMazeFrame();
    
         gotoxy(y * 2, x);
         cout << "☞";
      }
    else if (map[x][y] == 7){
    gotoxy(66, 20);
   cout<<"!!!!!!success!!!!!!"<<endl;
   gotoxy(66, 22);
   cout<<"아무키나 누르면 종료\n";
   _getch();
    system("cls");
    endingFrame();
    gotoxy(23,6);
    cout << "GAME OVER ^ㅁ^";
    gotoxy(20,14);
    cout<<"  1.한번 더  2.그만";
    gotoxy(18,12);
    cout<<"한번 더 도전하시겠습니까?"<<endl;
        break;
     }
   else if (map[x][y] == 8){
        system("cls");
        endingFrame();
        key();
        system("cls");
        endingFrame();
		gotoxy(23, 6);
		cout << "!!!!!!success!!!!!!" << endl;
		gotoxy(20, 14);
		cout<<"  1.한번 더  2.그만";
    	gotoxy(18,12);
    	cout<<"한번 더 도전하시겠습니까?"<<endl;
        break;
     }
    else if (map[x][y] == 9){
        gotoxy(66, 20);
      cout<<"!!!!!!success!!!!!!"<<endl;
      gotoxy(66, 22);
      cout<<"아무키나 누르면 종료\n";
      _getch();
       system("cls");
       endingFrame();
       gotoxy(23,6);
       cout << "I'll be Back...ㅋ";
       gotoxy(20,14);
       cout<<"  1.한번 더  2.그만";
       gotoxy(18,12);
       cout<<"한번 더 도전하시겠습니까?"<<endl;
        break;
     }
      }
   }
}

int LunaticGame::key()//세번째 방으로부터 힌트를 얻어 최종적으로 탈출 할 수 있게 하는 함수이다.
{
int input[4];
int room;
   gotoxy(10, 10);
   cout<<" [Secret Room] 에 입장하였습니다.";
   Sleep(1000);
position:
   system("cls");
   endingFrame();
   keyFrame();
    
   gotoxy(48, 4);
   cout<<"1th Room : ";
   cin>>room;
   gotoxy(60, 4);
   cout << " ";
   secretRoom(room);
   gotoxy(18, 7);
   cout<<"완료"; 
   gotoxy(48, 4);
   cout<<"2nd Room : ";
   cin>>room;
   secretRoom(room);
   gotoxy(18, 7);
   cout<<"완료    완료";
   gotoxy(48, 4);
   cout<<"3rd Room : ";
   cin>>room;
   secretRoom(room);
   gotoxy(18, 7);
   cout<<"완료    완료    완료";
   gotoxy(48, 4);
   cout<<"4th Room : ";
   cin>>room;
   secretRoom(room);
   gotoxy(18, 7);
   cout<<"완료    완료    완료    완료";
    
   gotoxy(9, 10);
   printf("탈출 비밀 번호 4자리를 입력 (모르면 0을 입력)");
   gotoxy(20, 12);
   cout<<"┌───┐ ┌───┐ ┌───┐ ┌───┐\n";
   gotoxy(20, 14);
   cout<<"└───┘ └───┘ └───┘ └───┘\n";
   gotoxy(14, 16);
   cout<<"1번째 자리 : ";
   cin>>input[0];
   gotoxy(20, 13);
   cout<<"  "<<input[0]<<"    "; 
   gotoxy(35, 16);
   cout<<"2번째 자리 : ";
   cin>>input[1];
   gotoxy(20, 13);
   cout<<"  "<<input[0]<<"     "<<input[1];
   gotoxy(14, 17);
   cout<<"3번째 자리 : ";
   cin>>input[2];
   gotoxy(20, 13);
   cout<<"  "<<input[0]<<"     "<<input[1]<<"     "<<input[2];
   gotoxy(35, 17);
   printf("4번째 자리 : ");
   cin>>input[3];
   gotoxy(20, 13);
   cout<<"  "<<input[0]<<"     "<<input[1]<<"     "<<input[2]<<"     "<<input[3];
   if(input[0]==0&&input[1]==8&&input[2]==2&&input[3]==9){
      gotoxy(20, 18);
      cout<<" --- correct --- ";
      fflush(stdin);
      getchar();
      return 3;
   }
   else if(input[0]==0&&input[1]==0&&input[2]==0&&input[3]==0)
      return 0;
   else{
      gotoxy(12, 20);
      cout<<"비밀번호가 틀렸습니다. 다시 입력하시오.";
   	  system("cls");
	  display(7);
	}
}

void LunaticGame::keyFrame(){
   gotoxy(5, 2);
   cout<<" 방 순번에 맞는 숫자를 입력해 방을 들어가야합니다";
   gotoxy(3, 4);
   cout<<" 방에서 얻은 keyword를 조합하여 탈출하세요";
   gotoxy(16, 5);
   cout << "┌─────┐ ┌─────┐ ┌─────┐ ┌─────┐\n";
   gotoxy(18,6);
   cout<<"#1. \t  #2. \t  #3. \t  #4. ";
   gotoxy(16, 8);
   cout << "└─────┘ └─────┘ └─────┘ └─────┘\n";
}

void LunaticGame::secretRoom(int k){
	string ans;
	string userAns;
	switch(k){
		case 1:
			system("cls");
			cout << "Q. 향지는 독특한 암호가 적힌 단어장을 발견했다. \n단어장에는 단어를 해석하는 뜻과 숫자만이 적혀 있었다." << endl;
			gotoxy(12, 4);
    		cout<<"┌--------------------------------------------------------------------┐"<<endl;
    		gotoxy(12, 5);
    		cout<<"│         33-1-20-20-3 = ? : 목소리로만 연기하는 배우                │"<<endl;
    		gotoxy(12, 6);
    		cout<<"│         32-4-20-13-3 = ? : 경상북도에 있는 신라 천년의 고도        │"<<endl;
    		gotoxy(12, 7);
    		cout<<"│         33-1-54-45-9-20 = ? : 부러워하여 바라는 것                 │"<<endl;
    		gotoxy(12, 8);
    		cout<<"└--------------------------------------------------------------------┘"<<endl;
    		gotoxy(12, 11);
    		cout << "다음 규칙을 따랐을 때, 이 암호가 나타내는 단어는 무엇일까?" << endl;
			gotoxy(12, 12);
			cout << "20-3-13-3-33-1-54 ";
			
			ans = "우주선";
			cout << "입력>> "; 
			cin >> userAns;
			
			if(userAns == ans){
				gotoxy(12, 16);
				cout << "축하합니다! 1번 방의 key는 '1'입니다.";
				Sleep(1000);
				system("cls");
				endingFrame();
				keyFrame();
			}
			else{
				system("cls");
				display(7);
               }
            break;
            
        case 2:
        	system("cls");
			cout << "Q. What word am I thinking of?"<< endl;
			cout << endl;
			cout << "1. I am thinking of a seven letter word which we read almost daily." << endl;
			cout << "2. Letters 5, 6 and 7 increase every year." << endl;
			cout << "3. Letters 3 and 4 are the same." << endl;
			cout << "4. Letters 3, 2 and 5 cover about 70 percent of the world." << endl;
						
			ans = "message";
			cout << endl << endl;
			cout << "입력>> ";
			cin >> userAns;
			
			if(userAns == ans){
				cout << "축하합니다! 2번 방의 key는 '1'입니다.";
				Sleep(1000);
				system("cls");
				endingFrame();
				keyFrame();
			}
			else{
				system("cls");
				display(7);
			}
			break;
		
		case 3:
			system("cls");
			cout << "테러리스트 채연이가 한국에 잠입하여 소경아파트에 폭탄을 설치했다. \n아파트 관리소 컴퓨터에는 폭탄을 제거할 수 있는 암호가 남겨져 있었다.\n 암호는 무엇인가?" <<endl;
			gotoxy(12, 4);
    		cout<<"┌----------------------------------------------------------------------------------┐"<<endl;
    		gotoxy(12, 5);
    		cout<<"│   ■■■■■ ■■■■■ ■■■■■ ■         ■■■■■ ■■■■■ ■■■■■   │"<<endl;
    		gotoxy(12, 6);
    		cout<<"│   ■         ■      ■         ■ ■         ■                 ■ ■      ■   │"<<endl;
    		gotoxy(12, 7);
    		cout<<"│   ■         ■      ■         ■ ■         ■                 ■ ■      ■   │"<<endl;
    		gotoxy(12, 8);
    		cout<<"│   ■         ■      ■         ■ ■         ■                 ■ ■      ■   │"<<endl;
    		gotoxy(12, 9);
			cout<<"│   ■■■■■ ■■■■■         ■ ■■■■■ ■■■■■         ■ ■■■■■   │"<<endl;
    		gotoxy(12, 10);
    		cout<<"└----------------------------------------------------------------------------------┘"<<endl;
    		
    		ans = "6573675";
    		gotoxy(12, 12);
			cout << "입력>> ";
			cin >> userAns;
			
			if(userAns == ans){
				gotoxy(12, 15);
				cout << "축하합니다! 3번 방의 key는 '1'입니다.";
				Sleep(1000);
				system("cls");
				endingFrame();
				keyFrame();
			}
			else{
				system("cls");
				display(7);
			}
			break;
			
		case 4:
			system("cls");
			cout << "Q. 수민이는 낡은 서람장에서 오래된 편지 한 통을 발견했다. \n편지 쓴 주인공은 누구일까?";
			gotoxy(12, 4);
    		cout<<"┌---------------------------------------┐"<<endl;
    		gotoxy(12, 5);
    		cout<<"│   난 T를 만나면 늘 밀당을 하게 되     │"<<endl;
    		gotoxy(12, 6);
    		cout<<"│   난 D를 만나면 자꾸 계산을 하게 되   │"<<endl;
    		gotoxy(12, 7);
    		cout<<"│   난 E를 만나면 도움을 주고 싶어져    │"<<endl;
    		gotoxy(12, 8);
			cout<<"│   나를 기억하겠니?                    │"<<endl;
    		gotoxy(12, 9);
    		cout<<"└---------------------------------------┘"<<endl;
    
			ans = "car";
			gotoxy(12, 11); 
			cout << "입력>> ";
			cin >> userAns;
			
			if(userAns == ans){
				gotoxy(12, 15);
				cout << "축하합니다! 4번 방의 key는 '1'입니다.";
				Sleep(1000);
				system("cls");
				endingFrame();
				keyFrame();
			}
			else{
				system("cls");
				display(7);
			}
			break;
	}	
}

void LunaticGame::lunaticMazeFrame(){
     for(int i=0; i < LunaticMatrix::m; i++){
            for(int j=0; j < LunaticMatrix::n; j++){
       
         if (map[i][j] == 9 || map[i][j] == 8 || map[i][j] == 7) {
            cout<<"★";
         }
         else if (map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 5) {
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
