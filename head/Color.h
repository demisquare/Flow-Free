#ifndef COLOR_H
#define COLOR_H

#include <allegro5/allegro.h>

// mappa di alcuni colori utilizzati...

#define RED al_map_rgb(255, 0, 0)
#define GREEN al_map_rgb(0, 255, 0)
#define BLUE al_map_rgb(0, 0, 255)
#define YELLOW al_map_rgb(255, 255, 0)
#define ORANGE 	al_map_rgb(255, 140, 0)
#define PINK al_map_rgb(255, 0, 255)
#define AQUA al_map_rgb(0, 255, 255)
#define BLACK al_map_rgb(0,0,0)
#define WHITE al_map_rgb(255, 255, 255)

//"ridefinizione" operator ==...
static bool operator ==(const ALLEGRO_COLOR &left, const ALLEGRO_COLOR &right)
{
    return left.a == right.a
        && left.r == right.r
        && left.g == right.g
        && left.b == right.b;
}

#endif
