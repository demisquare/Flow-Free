#include "../head/Level.h"

Level::Level():timer(NULL), event_queue(NULL)
{
    timer = al_create_timer(1.0/FPS);
    if(!timer)
      {
        cerr << "failed to create timer!\n";
        exit(-1);
      }


    event_queue = al_create_event_queue();
    if(!event_queue)
    {
      cerr << "failed to create event queue!\n";
      exit(-1);
    }
}
void Level::run(const char* lvl)
{
    //registra evento del timer...
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    //registra eventi sul display...
    al_register_event_source(event_queue, al_get_display_event_source(al_get_current_display()));
    //registra eventi del mouse...
    al_register_event_source(event_queue, al_get_mouse_event_source());
    //registra eventi della tastiera...
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_clear_to_color(BLACK);                              
    myMap.draw(x, y, lvl);
    al_flip_display();//aggiorna display
  
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
          cout << "(" << events.mouse.x << " - " << events.mouse.y << ")" << endl;
          break;
        
        //evento click del mouse...
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
          //tasto sx mouse...
          if(events.mouse.button& 1)
        	{
                break;
            }
          
          //tasto dx mouse...
        	if(events.mouse.button& 2)
        	{
                break;
            }
        default:
          break;
          
      }
      al_flush_event_queue(event_queue);
    }
}
Level::~Level()
{
    al_clear_to_color(BLACK);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
}