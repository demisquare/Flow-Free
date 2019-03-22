#include "../head/Level.h"

Level::Level(ALLEGRO_BITMAP* b, int x, int y):
timer(NULL), event_queue(NULL), buffer(b), scaleX(x), scaleY(y)
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
    ALLEGRO_BITMAP* prev_target = al_get_target_bitmap();

    al_set_target_bitmap(al_get_backbuffer(al_get_current_display()));

    al_clear_to_color(BLACK);
    myMap.draw(x, y, lvl);

    al_flip_display();
  
    //registra evento del timer...
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    //registra eventi sul display...
    al_register_event_source(event_queue, al_get_display_event_source(al_get_current_display()));
    //registra eventi del mouse...
    al_register_event_source(event_queue, al_get_mouse_event_source());
    //registra eventi della tastiera...
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_set_target_bitmap(buffer);
  
    //avvia il timer...
    al_start_timer(timer);
    
    while(true)
    {
      //cattura eventi...
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);

      int mouseX = ev.mouse.x - scaleX;
      int mouseY = ev.mouse.y - scaleY;

      switch(ev.type)
      {
        //eventi tastiera...
        case ALLEGRO_EVENT_KEY_DOWN:
          if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            exit(1); 
          break;
        //evento hover del mouse...
        case ALLEGRO_EVENT_MOUSE_AXES:
          al_draw_filled_circle(mouseX, mouseY, 3, RED);
          break;
        
        //evento click del mouse...
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
          //tasto sx mouse...
          if(ev.mouse.button& 1)
            break;
          
          //tasto dx mouse...
        	if(ev.mouse.button& 2)
            break;
          
        default:
          break;
          
      }
      al_flush_event_queue(event_queue);
    }
}
Level::~Level()
{
  al_destroy_timer(timer);
  al_destroy_event_queue(event_queue);
}