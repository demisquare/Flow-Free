#include "../head/Level.h"

Level::Level(int mode):gameMode(mode)
{

  init_display();

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
  al_set_target_bitmap(buffer);
  al_clear_to_color(BLACK);
  
  //disegna la mappa...
  drawMap(map);
  drawScore();

  //disegna una pallina bianca per capire dove siamo col mouse...
  cursor(mouseX, mouseY);

  al_set_target_backbuffer(display);
  al_clear_to_color(BLACK);
  al_draw_scaled_bitmap(buffer, 0, 0, WIDTH, HEIGHT, scaleX, scaleY, scaleW, scaleH, 0);
  
  al_flip_display();

}
void Level::drawPath()
{
  if(map.getLogic().inMap(mouseX, mouseY) && mouse_down)
  {
    if(map.getLogic().getObj(mouseX, mouseY)->getType()==BALL)
    {
      //chiudi percorso...
      if(start != nullptr && current != nullptr && next != nullptr)
      {
        end = map.getLogic().getObj(mouseX, mouseY);
        map.add(end->getLogicY(), end->getLogicX(), end->getColor());
      } 
      else
      {
        //valuta prima cella...
        start = map.getLogic().getObj(mouseX, mouseY);
        map.add(start->getLogicY(), start->getLogicX(), start->getColor());
      }
    }

    if(map.getLogic().getObj(mouseX, mouseY)->getType()==EMPTY && start!=nullptr)
    { 
      //valuta la cella corrente   
      current = map.getLogic().getObj(mouseX, mouseY);
     
      //se incontro celle adiacenti...
      /* if((current->getLogicX() == start->getLogicX()) && (current->getLogicY() != start->getLogicY())
      || (current->getLogicX() != start->getLogicX()) && (current->getLogicY() == start->getLogicY()))
      { */
        //se non ho segnato il percorso...
        cout << "current: " << current->getLogicY() << " - " << current->getLogicX() << endl;
        map.add(current->getLogicY(), current->getLogicX(), start->getColor());
        map.getLogic().addPath(current->getLogicY(), current->getLogicX(), start->getColor());      
      //}
      //valuta prossima cella...    
      next = map.getLogic().getObj(mouseX, mouseY);
      
      //se incontro celle adiacenti...
      if(((current->getLogicX() == next->getLogicX()) && (current->getLogicY() != next->getLogicY())
      ||  (current->getLogicX() != next->getLogicX()) && (current->getLogicY() == next->getLogicY())))
      {
        //se non ho segnato il percorso...
        cout << "next: " << next->getLogicY() << " - " << next->getLogicX() << endl;
        map.add(next->getLogicY(), next->getLogicX(), start->getColor());
        map.getLogic().addPath(next->getLogicY(), next->getLogicX(), start->getColor());   
      }
    } //!=BALL
  } //&& mouse_down
}
void Level::run(const int& lvl)
{
  map.getLogic().load(lvl);
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
  
  while(!map.victory())
  {
    //cattura eventi...
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    switch(ev.type)
    {
      case ALLEGRO_EVENT_TIMER:
        drawPath();
        
        has_redraw = true;
        break;

      //eventi tastiera...
      case ALLEGRO_EVENT_KEY_DOWN:
        if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
          exit(1); 
        break;

      //evento hover del mouse...
      case ALLEGRO_EVENT_MOUSE_AXES:
        mouseX = ev.mouse.x - scaleX;
        mouseY = ev.mouse.y - scaleY;
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
      has_redraw = false;
      redraw();
    }
  }
  cout << "you win!" << endl;

  al_destroy_event_queue(event_queue);
  al_destroy_timer(timer);
  al_destroy_bitmap(buffer);
  al_destroy_display(display);
}
Level::~Level()
{
  al_destroy_event_queue(event_queue);
  al_destroy_timer(timer);
  al_destroy_bitmap(buffer);
  al_destroy_display(display);
}
