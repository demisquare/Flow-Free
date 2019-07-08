#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "PathMap.h"
#include "Score.h"

#define WIDTH 640
#define HEIGHT 480
#define FPS 60

using namespace std;

//classe astratta di metodi comuni alle classi con materiale grafico
class GameEngine
{
    private:
    void drawPath(vector<pair<int,int> >, const GameMap&);
    
    protected:
    ALLEGRO_DISPLAY* display;
    ALLEGRO_BITMAP* buffer;
    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* event_queue;

    ALLEGRO_FONT* font;

    float windowWidth = WIDTH, windowHeight = HEIGHT;
    float sx, sy;

    int scale;

    int scaleW, scaleH;
    int scaleX, scaleY;

    bool has_redraw = true;
    int mouseX, mouseY;

    public:
    GameEngine():display(NULL), buffer(NULL), timer(NULL), event_queue(NULL){};

    void init_display();
    void init_buffer();
    void init_font();
    void init_timer();
    void init_event_queue();

    void resize(ALLEGRO_DISPLAY*);

    void cursor(int, int);
    
    void drawMenu(ALLEGRO_BITMAP*, int, int);
    void drawOptions(ALLEGRO_BITMAP*, int, int);
    void drawWin(ALLEGRO_BITMAP*, int, int);
    void drawLose(ALLEGRO_BITMAP*, int, int);
    void drawScore(Score&, const unsigned&, const unsigned&, int, int);
    void drawMap(PathMap&);

    ~GameEngine()
    {
        /* al_destroy_bitmap(buffer);
        al_destroy_display(display); */
        //al_destroy_font(font);
    }
    
};
#endif