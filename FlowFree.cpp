#include "ScreenSettings.h"
#include "Level.h"

int main()
{
  if(!al_init())
  {
   cerr << "failed to initialize allegro!\n";
   return -1;
  }

  if(!al_install_keyboard())
  {
    cerr << "failed to initialize keyboard!\n";
   return -1;
  }

  if(!al_install_mouse())
  {
    cerr << "failed to initialize mouse!\n";
   return -1;
  }
    ScreenSettings s;

    Level myLevel;

    //crea coda eventi...
    //ALLEGRO_TIMER* timer = al_create_timer(10.0);
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

    //registra evento del timer...
    //al_register_event_source(event_queue, al_get_timer_event_source(timer));

    //registra eventi sul display...
    //al_register_event_source(event_queue, al_get_display_event_source(al_get_current_display()));

    //registra eventi del mouse...
    al_register_event_source(event_queue, al_get_mouse_event_source());

    //registra eventi della tastiera...
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    //avvia il timer...
    //al_start_timer(timer);
    bool done = false;

    while(!done)
    {
      //avvia il primo livello...
      myLevel.run();
      //al_rest(2.0); //attendi 2 secondi

      //cattura eventi...
      ALLEGRO_EVENT events;
      al_wait_for_event(event_queue, &events);

      if(events.type == ALLEGRO_EVENT_KEY_DOWN)
      {
        if (events.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        done = true; 
      }
      //evento hover del mouse...
      else if(events.type == ALLEGRO_EVENT_MOUSE_AXES)
      {
      	unsigned x = events.mouse.x,
      	         y = events.mouse.y;
            
        cout << "(" << x << " - " << y << ")" << endl;
      }

      //click del mouse...
      /*else if(events.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    	{
        		if(events.mouse.button& 1)
        	    {
                done = true;
              }
        		else if(events.mouse.button& 2)
        	    {

              }
      }*/
    }

    //al_destroy_timer(timer);
    al_destroy_event_queue(event_queue); 

    return 0;
}
