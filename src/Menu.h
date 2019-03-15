#ifndef MENU_H
#define MENU_H

#include "Level.h"

class Menu
{
private:
    ALLEGRO_BITMAP* menu;

public:
    Menu():menu(NULL){}

    void run()
  {
    al_clear_to_color(BLACK);

        //disegna la mappa...
        menu = al_load_bitmap("images/background.png"); //grid...
        al_draw_bitmap(menu, 0, 0, 0);                                 

        
        al_flip_display(); //aggiorna display
  }

  ~Menu(){al_destroy_bitmap(menu);}
};
#endif