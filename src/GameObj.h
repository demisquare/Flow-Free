#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <iostream>
#include <allegro5/allegro_primitives.h>
#include "Color.h"

using namespace std;

enum type { BALL, PATH };

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
  ALLEGRO_COLOR getColor()const{return color;}

  virtual type getType()const = 0;

  virtual void draw() = 0;

};

class Ball:public GameObj
{
protected:
  unsigned radius;
public:
  Ball(const unsigned x, const unsigned y, const unsigned r, const ALLEGRO_COLOR c):
  GameObj(x, y, c), radius(r){}

  void clear(){color = BLACK;}

  unsigned getX()const{return source_x;}
  unsigned getY()const{return source_y;}
  ALLEGRO_COLOR getColor()const{return color;}

  unsigned getRadius()const{return radius;}

  type getType()const{return BALL;}

  void draw()
  {
    //disegna una pallina...
    if(!al_init_primitives_addon())
      cerr << "failed to initialize Ball!\n";
    else
      al_draw_filled_circle(source_x, source_y, radius, color);
  }

};

class Path:public GameObj
{
public:
  Path(const unsigned x, const unsigned y, const ALLEGRO_COLOR c):
  GameObj(x, y, c){}

  unsigned getX()const{return source_x;}
  unsigned getY()const{return source_y;}
  ALLEGRO_COLOR getColor()const{return color;}

  type getType()const{return PATH;}

};

#endif
