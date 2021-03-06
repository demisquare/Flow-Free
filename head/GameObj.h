#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <iostream>
#include <allegro5/allegro_primitives.h>
#include "Color.h"

//valori grafici per costruire la mappa...
const int pos = 45;
const int offset = 70;
const int r = 32;
const int gap = 64;

using namespace std;

enum type { BALL, PATH, EMPTY };

class GameObj
{
protected:
  unsigned source_x, source_y;
  ALLEGRO_COLOR color;
public:
  GameObj(const unsigned x, const unsigned y, const ALLEGRO_COLOR c):
    source_x(x), source_y(y), color(c){}

  // coordinate in pixel...
  unsigned getX()const{return source_x;}
  unsigned getY()const{return source_y;}
  
  // coordinate rispetto alla mappa logica...
  unsigned getLogicX()const{return (int(source_x-gap)/offset);} 
  unsigned getLogicY()const{return (int(source_y-gap)/offset);}

  ALLEGRO_COLOR getColor()const{return color;}

  virtual type getType()const = 0;

  virtual void draw() = 0;

  bool operator==(GameObj* g)const
  {
    return (this->getLogicX() == g->getLogicX() &&
            this->getLogicY() == g->getLogicY() &&
            this->getColor() == g->getColor());
            
  }
};
#endif
