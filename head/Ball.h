#ifndef BALL_H
#define BALL_H

#include "GameObj.h"

// Palline...
class Ball:public GameObj
{
protected:
  unsigned radius;
public:
  Ball(const unsigned x, const unsigned y, const unsigned r, const ALLEGRO_COLOR c);

  unsigned getRadius()const;
  type getType()const;
  void draw();

};

 #endif