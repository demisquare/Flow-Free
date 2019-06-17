#include "../head/Path.h"

Path::Path(unsigned x, unsigned y, ALLEGRO_COLOR c):
  GameObj(x, y, c){}
  
type Path::getType()const{return PATH;}

void Path::draw(){return;}