#ifndef GRAPHICMANAGER_H
#define GRAPHICMANAGER_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

#include "Color.h"

#define WINDOW_W 640
#define WINDOW_H 480

using namespace std;

class GraphicManager
{
    private:
        int scale_w;      
        int scale_h;
        int scale_x;
        int scale_y;

        ALLEGRO_DISPLAY* display;
        ALLEGRO_BITMAP* buffer;

    public:
        GraphicManager();
        GraphicManager(const int&, const int& ,const int&, const int&, ALLEGRO_BITMAP *, ALLEGRO_DISPLAY *);
        ~GraphicManager();

        int drawMenu(); //restituisce 1 se premo su play, 2 se esco con esc e 3 se premo su options
        int drawOptions(); //restituisce la modalità di gioco
       
        //void setLevel(const int&);
        //int getLevel();
};
#endif
