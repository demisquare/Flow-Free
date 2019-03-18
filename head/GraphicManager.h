#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>


#ifndef GRAPHICMANAGER_H
#define GRAPHICMANAGER_H
class GraphicManager
{
    private:
        int scale_w;      
        int scale_h;
        int scale_x;
        int scale_y;
        ALLEGRO_DISPLAY * display;
        ALLEGRO_BITMAP * buffer;
        //ALLEGRO_FONT * font;
        //string tiles = "classic";
        int drawAssets();

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
