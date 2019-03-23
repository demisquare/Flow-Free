#include "../head/Path.h"

Path::Path(const unsigned x, const unsigned y, const ALLEGRO_COLOR c):
  GameObj(x, y, c){}
  
type Path::getType()const{return PATH;}

void Path::draw(){return;}