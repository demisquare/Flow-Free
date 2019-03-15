#ifndef SETUP_H
#define SETUP_H

#define WIDTH 640
#define HEIGHT 480
#define FPS 30

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>

using namespace std;

class Setup
{
private:
    ALLEGRO_DISPLAY* display;
    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* event_queue;

    void init_display()
    {
        float windowWidth = WIDTH, windowHeight = HEIGHT;
        al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
        display = al_create_display(windowWidth, windowHeight);
  
        if(!display)
           {
               cerr << "failed to initialize allegro!\n";
               al_destroy_timer(timer);
           }
  
        else
        {
            //operazione di resize...
            windowWidth = al_get_display_width(display);
            windowHeight = al_get_display_height(display);

            int screenWidth = WIDTH, screenHeight = HEIGHT;

            float sx = windowWidth/(float)screenWidth;
            float sy = windowHeight/(float)screenHeight;

            ALLEGRO_TRANSFORM trans;
            al_identity_transform(&trans);
            al_scale_transform(&trans, sx, sy);
            al_use_transform(&trans);
        }
    }

    void init_timer()
    {
        timer = al_create_timer(1.0/FPS);
        if(!timer)
            cerr << "failed to create timer!\n";
    }

    void init_event_queue()
    {
        event_queue = al_create_event_queue();
        if(!event_queue)
        {
          cerr << "failed to create event queue!\n";
          al_destroy_display(display);
          al_destroy_timer(timer);
        }
    }

    void register_events()
    {
        //registra evento del timer...
        al_register_event_source(event_queue, al_get_timer_event_source(timer));

        //registra eventi sul display...
        al_register_event_source(event_queue, al_get_display_event_source(display));

        //registra eventi del mouse...
        al_register_event_source(event_queue, al_get_mouse_event_source());

        //registra eventi della tastiera...
        al_register_event_source(event_queue, al_get_keyboard_event_source());
    }

public:
    Setup():display(NULL), timer(NULL), event_queue(NULL)
    {
        if(!al_init())
         cerr << "failed to initialize allegro!\n";
        
        if(!al_install_keyboard())
          cerr << "failed to initialize keyboard!\n";
        
        if(!al_install_mouse())
          cerr << "failed to initialize mouse!\n";

        if(!al_init_image_addon())
        cerr << "failed to initialize menu!\n";
        
        init_timer();
        init_display();
        init_event_queue();

        register_events();
    }

    void gameLoop()
    {
        //avvia il timer...
        al_start_timer(timer);

        bool done = false;

        while(!done)
        {
          //cattura eventi...
          ALLEGRO_EVENT events;
          al_wait_for_event(event_queue, &events);

          switch(events.type)
          {
            //eventi tastiera...
            case ALLEGRO_EVENT_KEY_DOWN:
              if(events.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                done = true; 
              break;

            //evento hover del mouse...
            case ALLEGRO_EVENT_MOUSE_AXES:
          	  unsigned x = events.mouse.x,
          	           y = events.mouse.y;

              cout << "(" << x << " - " << y << ")" << endl;
              break;
            
            //evento click del mouse...
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
              //tasto sx mouse...
              if(events.mouse.button& 1)
            	{
              }
              //tasto dx mouse...
            	else if(events.mouse.button& 2)
            	{
              }
              break;
          }
        }
    }

    ALLEGRO_TIMER* getTimer(){return timer;}
    ALLEGRO_DISPLAY* getDisplay(){return display;}
    ALLEGRO_EVENT_QUEUE* getEventQueue(){return event_queue;}


    ~Setup()
    {
        al_destroy_timer(timer);
        al_destroy_display(display);
        al_destroy_event_queue(event_queue);
    }
};

#endif