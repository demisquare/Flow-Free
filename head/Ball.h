#include "GameObj.h"

class Ball:public GameObj
{
protected:
  unsigned radius;
public:
  Ball(const unsigned x, const unsigned y, const unsigned r, const ALLEGRO_COLOR c);

  void clear(); //fa diventare la palline nera come lo sfondo

  //sono ereditati
  /*unsigned getX()const{return source_x;}
  unsigned getY()const{return source_y;}
  ALLEGRO_COLOR getColor()const{return color;}*/

  unsigned getRadius()const;
  type getType()const;
  void draw();

};