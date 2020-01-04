//Matrix.h

#ifndef MATRIX_H
#define MATRIX_H
#define MAX_STACK_SIZE 100

class Matrix{
protected:
   int m, n; //map의 가로 세로 
    int** map; //input 받아오는 미로 matrix 
    struct XY{
       int a;
       int b;
    }; //지나온 경로 (a, b) 저장하는 구조체
    struct XY his[MAX_STACK_SIZE]; //지나온 경로 (a, b) 저장용 구조체(historyXY)의 배열(his)
   int p; //지나온 경로 (a, b) 저장용 구조체(historyXY) 배열(his) index
    
public:      
    Matrix();
    ~Matrix();
    void gotoxy(int x, int y);
    void setMatrix();
    void introFrame();
    void endingFrame();
    void index();
    void explain(); 
    void title();  
};

#endif
