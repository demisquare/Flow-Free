#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

#define WIDTH 640
#define HEIGHT 480
#define FPS 30

using namespace std;

//classe astratta di metodi comuni alle classi con materiale grafico
class GameEngine
{
    protected:
    ALLEGRO_DISPLAY* display;
    ALLEGRO_BITMAP * buffer;
    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* event_queue;

    bool has_redraw = true;
    int mouseX, mouseY;

    public:
    GameEngine():display(NULL), buffer(NULL), timer(NULL), event_queue(NULL){};

    ~GameEngine()
    {
        al_destroy_bitmap(buffer);
        al_uninstall_keyboard();
        al_uninstall_mouse();
        al_destroy_display(display);
    }
    
};
#endif