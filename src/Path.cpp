#include "../head/Path.h"

Path::Path(unsigned x, unsigned y, ALLEGRO_COLOR c):
  GameObj(x, y, c){}
  
type Path::getType()const{return PATH;}

// disegna la giunzione di un percorso...
void Path::draw(){ al_draw_filled_circle(source_x, source_y, r/8, color);}