#include "../head/Path.h"

Path::Path(unsigned x, unsigned y, ALLEGRO_COLOR c):
  GameObj(x, y, c){}
  
type Path::getType()const{return PATH;}

void Path::draw(){ al_draw_filled_circle(source_x, source_y, 10, color);}