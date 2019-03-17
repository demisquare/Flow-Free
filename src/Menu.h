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

        //disegna il menu...
        menu = al_load_bitmap("images/background.png");
        al_draw_bitmap(menu, 200, 0, 0);
        al_flip_display(); //aggiorna display

    //creo una coda di eventi per gestire le scelte del menu
    /*ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    if(!queue)
    {
      cerr << "failed to create event queue!\n";
    }
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    ALLEGRO_BITMAP *btp = al_create_bitmap(140, 40);
    while(true)
    {
      ALLEGRO_EVENT ev;
      al_wait_for_event(queue, &ev);
      switch (ev.type)
        {
        case ALLEGRO_EVENT_MOUSE_AXES: //movimento mouse
        //se mi trovo su "Play !" faccio apparire una pallina alla sua sinistra
            if (ev.mouse.x >= && ev.mouse.x<= && ev.mouse.y >= && ev.mouse.y <= )
            {
                
            }
        //se mi trovo su "Options" faccio apparire una pallina alla sua sinistra
            else if (ev.mouse.x >= && ev.mouse.x <= && ev.mouse.y >= && ev.mouse.y <= )
            {
                
            }
        //se mi trovo su "Quit" faccio apparire una pallina alla sua sinistra
            else if (ev.mouse.x >= && ev.mouse.x <= && ev.mouse.y >= && ev.mouse.y <= )
            {
                
            }
        case ALLEGRO_EVENT_MOUSE_BUTTON_UP: //se faccio click

        //se premo su "Play !" avvio il primo livello
            if (ev.mouse.x >= && ev.mouse.x <= && ev.mouse.y >= && ev.mouse.y <=)
            {
                //first level
            }

        //se premo su "Options" carico ad esempio una funzione runOptions
            else if (ev.mouse.x >= && ev.mouse.x <= && ev.mouse.y >= && ev.mouse.y <= )
             //options

        //se premo su "Quit" esco dal gioco
            else if (ev.mouse.x >=  && ev.mouse.x <=  && ev.mouse.y >=  && ev.mouse.y <= )
                //quit
            break;

        default:
            break;
        }
      /*
      al_flip_display();
      btp = 0;
      al_flush_event_queue(queue);*/
      // al_destroy_event_queue(queue);
    }
   
  

  ~Menu(){al_destroy_bitmap(menu);}
};
#endif