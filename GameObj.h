#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <iostream>
#include <allegro5/allegro_primitives.h>
#include "Color.h"

using namespace std;

enum type { BALL, PATH };
enum direction {HORIZONTAL, VERTICAL};

class GameObj
{
protected:
  unsigned source_x, source_y;
  type t;
  ALLEGRO_COLOR color;
public:
  GameObj(const unsigned &x, const unsigned &y, const ALLEGRO_COLOR &c):
    source_x(x), source_y(y), color(c){}

  virtual ~GameObj();

  void clear(){color = BLACK;}


  unsigned getX()const{return source_x;}
  unsigned getY()const{return source_y;}
  ALLEGRO_COLOR getColor()const{return color;}

  virtual type getType()const = 0;

  virtual void draw() = 0;
};

class Ball:public GameObj
{
private:
  unsigned radius;
public:
  Ball(const unsigned &x, const unsigned &y, const unsigned &r, const ALLEGRO_COLOR &c):
  GameObj(x, y, c), radius(r){t = BALL;}

  void draw()
  {
    //disegna una pallina...
    if(!al_init_primitives_addon())
      cerr << "failed to initialize Ball!\n";
    else
      al_draw_filled_circle(source_x, source_y, radius, color);
  }

  unsigned getRadius()const{return radius;}

  virtual type getType()const {return t;}
};

class Path:public GameObj
{
private:
  direction dir;
public:
  Path(const unsigned &x, const unsigned &y, const ALLEGRO_COLOR &c):GameObj(x, y, c){t = PATH;}

  void draw()
  {
    //disegna un percorso...
    if(!al_init_primitives_addon())
      cerr << "failed to initialize Path!\n";
    else
    {
      //gestisci disegno del percorso...
    }
  }

  type getType()const {return t;}
};

#endif
