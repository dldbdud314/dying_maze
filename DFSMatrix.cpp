//DFSMatrix.cpp

#include "DFSMatrix.h"

#include<stdio.h>
#include<Windows.h>
#include<iostream>
#include<fstream>
using namespace std;

#define col GetStdHandle(STD_OUTPUT_HANDLE)     // 콘솔창의 핸들정보를 받아옵니다.
#define WHITE  SetConsoleTextAttribute(col, 0x000f) // 흰색

DFSMatrix::DFSMatrix(){
   q = 0; 
   m = 20;
   n = 30; 
   dfs_map = new int* [m];
    
    for(int i=0; i<m; i++){
       dfs_map[i] = new int[n];
    }
}

DFSMatrix::~DFSMatrix(){
   for(int i=0; i<m; i++){
       delete[]dfs_map[i];
    }
    delete[]dfs_map;
}

void DFSMatrix::setDFSMatrix(){
   ifstream input;
    input.open("dfsMaze.txt");//파일로 입력 가능 
    
   if(input.fail()){
       cout<<"파일생성 후 다시실행"<<endl;
       return;
   }
    
   for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           if(!input.eof())
               input>>dfs_map[i][j];
            else{
               cout<<"실패"<<endl;
               return;
           }
        }
    }
   dfs(2, 0, 1); 
   input.close();
}

void DFSMatrix::dfs(int tr, int tc, int d){
   int min = 600;
   dfs_map[tr][tc] = 0; // 지나온 곳은 0로 표시
   if(tr == 13 && tc == 29){
      if(min > d)
           min=d;
        
       stPath[q].a = tr;
        stPath[q].b = tc;
        q++;
        
      return;
    }
    else if(dfs_map[tr][tc+1]!=0 && tc+1<30){//일단 3시 방향이 0인지 검사 합니다.//현재위치가 맨 오른쪽이 아니면 실행
           stPath[q].a = tr;
            stPath[q].b = tc;
            q++;
            
           dfs(tr, tc+1, d + 1);            
       }
        else if(dfs_map[tr+1][tc]!=0 && tr+1<20){
         
            stPath[q].a = tr;
            stPath[q].b = tc;
            q++;
                    
          dfs(tr+1, tc, d + 1);
       }
       else if(dfs_map[tr-1][tc]!=0 && tr-1>=0){

            stPath[q].a = tr;
            stPath[q].b = tc;
            q++;
            
          dfs(tr-1, tc, d + 1); 
       }
       else if(dfs_map[tr][tc-1]!=0 && tc-1>=0){

            stPath[q].a = tr;
            stPath[q].b = tc;
            q++;
            
          dfs(tr, tc-1, d + 1);     
       }
   dfs_map[tr][tc] = 1; // 되돌아가므로 1으로 표시. 수정된 부분입니다.     
}
