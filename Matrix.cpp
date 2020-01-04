//Matrix.cpp 
#include "Matrix.h"

#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define col GetStdHandle(STD_OUTPUT_HANDLE)     // 콘솔창의 핸들정보를 받아옵니다.
#define WHITE  SetConsoleTextAttribute(col, 0x000f) // 흰색

Matrix::Matrix(){ //동적 배열 생성 
   p = 0;
   m = 20;
   n = 30;
    map = new int* [m];
      
    for(int i=0; i<m; i++){
        map[i]=new int[n];
    }
}

Matrix::~Matrix(){
    for(int i=0; i<m; i++){
       delete[]map[i];
    }
    delete[]map;
}

void Matrix::setMatrix(){
   ifstream input;
    input.open("Maze.txt"); //파일로 입력 가능 
       
   if(input.fail()){
       cout<<"파일생성 후 다시실행"<<endl;
       return;
    }
     
   for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
           if(!input.eof())
              input>>map[i][j];
           else{
              cout<<"실패"<<endl;
              return;
           }
       }
   } 
   input.close();
}
  
void Matrix::gotoxy(int x, int y) //커서 이동 함수 
{
   COORD A = { x, y };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), A);
}

void Matrix::introFrame() //처음 시작화면에 출력 될 틀을 짜는 함수이다.
{
   int i;
   gotoxy(0, 0);
    cout<<"┏-----------------------------------------------------------┓"<<endl;
    for (i = 0; i<18; i++){
       gotoxy(0, i + 1);
       cout<<"┃                                                           ┃"<<endl;
    }
    gotoxy(0, i + 1);
   cout<<"└-----------------------------------------------------------┘"<<endl;
    gotoxy(0, 0);
    gotoxy(12, 4);
    cout<<"┌------------------------------------┐"<<endl;
    gotoxy(12, 5);
    cout<<"│         D Y I N G   M A Z E        │"<<endl;
    gotoxy(12, 6);
    cout<<"└------------------------------------┘"<<endl;
    gotoxy(12, 20);
}

void Matrix::endingFrame(){//각각의 기본 게임틀을 완성시켜주는 함수로 뼈대를 그리고 있다.
   int i;
   gotoxy(0, 0);
   cout<<"┏-----------------------------------------------------------┓"<<endl;
   for (i = 0; i<18; i++){
      gotoxy(0, i + 1);
      cout<<"┃                                                           ┃"<<endl;
   }
    gotoxy(0, i + 1);
    cout<<"└-----------------------------------------------------------┘"<<endl;
    gotoxy(0, 0);
}

void Matrix::index()
{
   gotoxy(24,3);
   cout<<"1) 1학년반"<<endl;
   
   gotoxy(24,5);
   cout<<"2) 2학년반"<<endl;
   
   gotoxy(24,7);
   cout<<"3) 3학년반"<<endl;
   
   gotoxy(24,9);
   cout<<"4) 4학년반"<<endl;
   
   gotoxy(24,11);
   cout<<"5) 5학년반"<<endl;
   
   gotoxy(24,13);
   cout<<"6) 6학년반"<<endl;
   
   gotoxy(24,15);
   cout<<"7) 루나틱"<<endl;
   
   gotoxy(20, 17);
   cout<<"입력>> ";
}

void Matrix::explain()
{
   gotoxy(25, 5);
    cout << "게임 설명" << endl;
    gotoxy(22, 8);
   cout << "1. 넌센스 퀴즈"<<endl;
   gotoxy(22, 10);
   cout << "2. 가위바위보"<<endl;
   gotoxy(22, 12);
   cout << "3. 랜덤숫자 맞추기"<<endl;
   gotoxy(22, 14);
   cout << "4. 숫자야구"<<endl;
      
}

void Matrix::title() //이 부분 또한 시작할 때 맵을 나타내기 위한 시작 프레임이다.
{
   gotoxy(24, 8);
   cout<<"1. 게임 시작";
   gotoxy(24, 10);
   cout<<"2. 미로 설명";
   gotoxy(24, 12);
   cout<<"3. 게임 설명";
   gotoxy(24, 14);
   cout<<"4. 게임 종료";
   gotoxy(20, 16);
   cout<<"입력>> ";
}
