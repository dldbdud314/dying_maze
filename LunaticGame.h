//LunaticGame.h
#ifndef LUNATIC_GAME_H
#define LUNATIC_GAME_H

#include "LunaticMatrix.h"

class LunaticGame:public LunaticMatrix{
public:      
  LunaticGame();
  void lunaticMazeFrame();
  void upDown();
  void gawiBawiBo();
  void numBall();
  void nonSenseQuiz();
  void display(int A);
  int key();
  void keyFrame();
  void secretRoom(int k);  
};

#endif
