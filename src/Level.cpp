#include "../head/Level.h"

Level::Level(int mode):gameMode(mode)
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

void Level::redraw()
{
  //disegna la mappa...
  myMap.draw();

  //disegna una pallina bianca per capire dove siamo col mouse...
  cursor(WHITE);
}

void Level::drawPath()
{
  if(myMap.inMap(mouseX, mouseY) && mouse_down)
  {
    if(myMap.getObj(mouseX, mouseY)->getType()==BALL)
    {
      //chiudi percorso...
      if(start!=nullptr && current != nullptr && next != nullptr)
      {
        end = myMap.getObj(mouseX, mouseY);
        myPaths.add(end->getLogicY(), end->getLogicX(), end->getColor());
      } 
      else
      {
        //valuta prima cella...
        start = myMap.getObj(mouseX, mouseY);
        myPaths.add(start->getLogicY(), start->getLogicX(), start->getColor());
        }
    }

    if(myMap.getObj(mouseX, mouseY)->getType()==EMPTY)
    { 
      //valuta la cella corrente   
      current = myMap.getObj(mouseX, mouseY);
     
      //se incontro celle adiacenti...
      if( (start->getLogicX() ==  current->getLogicX()) || (start->getLogicY() ==  current->getLogicY()) )
      {
        //se non ho segnato il percorso...
        myPaths.add(current->getLogicY(), current->getLogicX(), start->getColor());
        myMap.addPath(current->getLogicY(), current->getLogicX(), start->getColor());      
      }
      //valuta prossima cella...    
      next = myMap.getObj(mouseX, mouseY);
      
      //se incontro celle adiacenti...
      if((current->getLogicX() ==  next->getLogicX()) || (current->getLogicY() ==  next->getLogicY()) )
      {
        //se non ho segnato il percorso...
        myPaths.add(next->getLogicY(), next->getLogicX(), start->getColor());
        myMap.addPath(next->getLogicY(), next->getLogicX(), start->getColor());   
      }
    } //!=BALL
  } //&& mouse_down
}

void Level::cursor(ALLEGRO_COLOR c)
{
  al_draw_filled_circle(mouseX, mouseY, 7, c);
}

void Level::run(const char* lvl)
{
  myMap.load(lvl);
  //registra evento del timer...
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  //registra eventi sul display...
  al_register_event_source(event_queue, al_get_display_event_source(al_get_current_display()));
  //registra eventi del mouse...
  al_register_event_source(event_queue, al_get_mouse_event_source());
  //registra eventi della tastiera...
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  //nascondi il mouse...
  al_hide_mouse_cursor(al_get_current_display());
  //avvia il timer...
  al_start_timer(timer);

  cout << myPaths.victory(myMap) << endl;
  
  while(true)
  {
    //cattura eventi...
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    switch(ev.type)
    {
      case ALLEGRO_EVENT_TIMER:
        has_redraw = true;
        break;

      //eventi tastiera...
      case ALLEGRO_EVENT_KEY_DOWN:
        if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
          exit(1); 
        break;

      //evento hover del mouse...
      case ALLEGRO_EVENT_MOUSE_AXES:
        mouseX = ev.mouse.x;
        mouseY = ev.mouse.y;
        /*if(myMap.inMap(mouseX, mouseY) && mouse_down)
          cout << myMap.get(mouseY) << " - " << myMap.get(mouseX) << endl;*/
        break;
      
      case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
        mouse_down = true;
        break;

      //evento click del mouse...
      case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
        mouse_down = false;
        start = nullptr;
        current = nullptr;
        next = nullptr;           
        break;
        
      default:
        break;  
    }
    al_flush_event_queue(event_queue);
    if(has_redraw && al_is_event_queue_empty(event_queue))
    {
      drawPath();
      has_redraw = false;
      al_set_target_bitmap(al_get_backbuffer(al_get_current_display()));
      al_clear_to_color(BLACK);
      redraw();
      
      al_flip_display();
    }
  }
}
Level::~Level()
{
  al_destroy_timer(timer);
  al_destroy_event_queue(event_queue);
}
