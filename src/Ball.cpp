#include "../head/Ball.h"

Ball::Ball(const unsigned x, const unsigned y, const unsigned r, const ALLEGRO_COLOR c):
  GameObj(x, y, c), radius(r){}

void Ball::clear(){color = BLACK;}

unsigned Ball::getRadius()const{return radius;}

type Ball::getType()const{return BALL;}

void Ball::draw()
  {
    //disegna una pallina...
    if(!al_init_primitives_addon())
      cerr << "failed to initialize Ball!\n";
    else
      al_draw_filled_circle(source_x, source_y, radius, color);
  }