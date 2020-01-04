//lunaticMatrix.h
#ifndef LUNATIC_MATRIX_H
#define LUNATIC_MATRIX_H
class LunaticMatrix{
protected:
   int m, n; //map의 가로 세로 
    int** map; //input 받아오는 미로 matrix 
     
public:      
     LunaticMatrix();
     ~LunaticMatrix();
     void gotoxy(int x, int y);
     void setLunaticMatrix();
     void endingFrame();
     };

#endif
