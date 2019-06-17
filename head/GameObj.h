#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <iostream>
#include <allegro5/allegro_primitives.h>
#include "Color.h"

static const unsigned pos = 90;
static const unsigned offset = 140;
static const unsigned r = 65;
static const unsigned gap = 20;

using namespace std;

enum type { BALL, PATH, EMPTY };
//classe astratta; implementare i metodi getType() e draw() nelle classi figlie
class GameObj
{
protected:
  unsigned source_x, source_y;
  ALLEGRO_COLOR color;
public:
  GameObj(const unsigned x, const unsigned y, const ALLEGRO_COLOR c):
    source_x(x), source_y(y), color(c){}

  unsigned getX()const{return source_x;}
  unsigned getY()const{return source_y;}
  
  unsigned getLogicX()const{return (int(source_x-gap)/offset);} 
  unsigned getLogicY()const{return (int(source_y-gap)/offset);}

  ALLEGRO_COLOR getColor()const{return color;}

  virtual type getType()const = 0;

  virtual void draw() = 0;

  //forse andrebbe aggiunto il metodo clear() come in Ball.h

};
#endif
