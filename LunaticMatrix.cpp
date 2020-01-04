//LunaticMatrix.cpp
#include "LunaticMatrix.h"

#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define col GetStdHandle(STD_OUTPUT_HANDLE)     // 콘솔창의 핸들정보를 받아옵니다.
#define WHITE  SetConsoleTextAttribute(col, 0x000f) // 흰색

LunaticMatrix::LunaticMatrix(){ //동적 배열 생성 
   m = 20;
   n = 30;
      map = new int* [m];
      
      for(int i=0; i<m; i++){
         map[i]=new int[n];
     }
}

LunaticMatrix::~LunaticMatrix(){
    for(int i=0; i<m; i++){
        delete[]map[i];
     }
    delete[]map;
}

void LunaticMatrix::setLunaticMatrix(){
    ifstream input;
    input.open("LunaticMaze.txt"); //파일로 입력 가능 
       
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
  
void LunaticMatrix::gotoxy(int x, int y) //커서 이동 함수 
{
   COORD A = { x, y };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), A);
}

void LunaticMatrix::endingFrame(){//각각의 기본 게임틀을 완성시켜주는 함수로 뼈대를 그리고 있다.
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
