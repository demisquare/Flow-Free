#ifndef PATH_H
#define PATH_H

#include "GameObj.h"

class Path:public GameObj
{
public:
  Path(const unsigned x, const unsigned y, const ALLEGRO_COLOR c);

  //sono ereditati
  /*unsigned getX()const{return source_x;}
  unsigned getY()const{return source_y;}
  ALLEGRO_COLOR getColor()const{return color;}*/

  type getType()const;

   //implementare il metodo draw() in base agli eventi del mouse e alla direzione
   void draw();

  //forse andrebbe aggiunto un metodo clear()

};

#endif