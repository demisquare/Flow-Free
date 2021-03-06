#include "../head/Level.h"

Level::Level(int mode):gameMode(mode){}
void Level::redraw()
{
  al_set_target_bitmap(buffer);
  al_clear_to_color(BLACK);
  
  //disegna la mappa...
  drawMap(map);
  drawScore(score, gameMode, level, mouseX, mouseY);

  //disegna una pallina bianca per capire dove siamo col mouse...
  cursor(mouseX, mouseY);

  al_set_target_backbuffer(al_get_current_display());
  al_clear_to_color(BLACK);
  al_draw_scaled_bitmap(buffer, 0, 0, WIDTH, HEIGHT, scaleX, scaleY, scaleW, scaleH, 0);
  
  al_flip_display();

}

//traccia percorsi...
void Level::drawPath()
{
  if(map.getLogic().inMap(mouseX, mouseY) && mouse_down)
  {
    if(map.getLogic().getObj(mouseX, mouseY)->getType()==BALL)
    {
      //chiudi percorso...
      if(start != nullptr && current != nullptr)
      {
        end = map.getLogic().getObj(mouseX, mouseY);
        if(end->getColor() == start->getColor())
          if(map.add(end->getLogicY(), end->getLogicX(), end->getColor()))
            moved = true;
        else
          end = nullptr;
      } 
      else
      {
        //valuta prima cella...
        start = map.getLogic().getObj(mouseX, mouseY);
        if(map.getCurrentPath().empty())
          if(map.add(start->getLogicY(), start->getLogicX(), start->getColor()))
            moved = true;
      }
    }

    if(map.getLogic().getObj(mouseX, mouseY)->getType()!=BALL)
      if(start != nullptr)
      { 
        //valuta la cella corrente   
        current = map.getLogic().getObj(mouseX, mouseY); 
        if(map.add(current->getLogicY(), current->getLogicX(), start->getColor()))
          moved = true;
      }
  }
}

//lancia livello...
int Level::run(const int& lvl)
{
  resize(al_get_current_display());

  init_buffer();
  init_font();
  init_timer();
  init_event_queue();

  music.init();
  music.playGame();

  level = lvl;

  map.getLogic().load(lvl);
  score.setRemainingMoves(map.getLogic().getColors());

  al_register_event_source(event_queue, al_get_timer_event_source(timer));

  al_register_event_source(event_queue, al_get_display_event_source(al_get_current_display()));
  al_register_event_source(event_queue, al_get_mouse_event_source());
  al_register_event_source(event_queue, al_get_keyboard_event_source());

  al_hide_mouse_cursor(al_get_current_display());
  
  al_start_timer(timer);
  
  while(!map.victory())
  {
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    switch(ev.type)
    {
      case ALLEGRO_EVENT_TIMER:
     
        drawPath();

        //conteggio del tempo...
        if(gameMode == 2)
        {
          counter++;
          if(counter == FPS)
          {
            score.tick();
            counter = 0;
          }
        }

        //condizioni di sconfitta...
        if((score.timeElapsed() && gameMode == 2) || (score.noMoreMoves() && gameMode == 1))
        {
          al_destroy_event_queue(event_queue);
          return result(0);
        }
        
        has_redraw = true;
        
        break;

      //eventi tastiera...
      case ALLEGRO_EVENT_KEY_DOWN:
        if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
          al_destroy_event_queue(event_queue);
          return 1;
        }

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

        //chiusura e/o rimozione al click...
        if(map.getLogic().inMap(mouseX, mouseY)
        && (map.closePath() || (start != nullptr
        &&  map.remove(start->getLogicY(), start->getLogicX()))))
          moved = true;
        
        //conteggio delle mosse...
        if(moved)
        {
          score.addMoves();
          moved = false;
        }

        mouse_down = false;

        start = nullptr;
        current = nullptr;
        end = nullptr;

        //cancella percorso corrente se incompleto...
        map.removePath(map.getCurrentPath());

        //turn back
        if(mouseX >= 566 &&
           mouseX <= 629 &&
           mouseY >= 380 &&
           mouseY <= 411)
           {
              music.playSelect();
              al_destroy_event_queue(event_queue);
              return 0;
           }

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
  //vittoria del gioco...
  al_destroy_event_queue(event_queue);
  return result(1);
}

//visualizza il risultato della partita...
int Level::result(bool res)
{
  music.playRes(res);

  ALLEGRO_BITMAP *win = al_load_bitmap("../assets/images/you_win.png");
  if(!win)
  {
    cout<<"Failed to load the victory bitmap!\n";
    exit(-1);
  }
  ALLEGRO_BITMAP *lose = al_load_bitmap("../assets/images/you_lose.png");
  if(!win)
  {
    cout<<"Failed to load the lose bitmap!\n";
    exit(-1);
  }

  init_timer();
  init_event_queue();

  al_register_event_source(event_queue, al_get_timer_event_source(timer));

  al_register_event_source(event_queue, al_get_display_event_source(al_get_current_display()));
  al_register_event_source(event_queue, al_get_mouse_event_source());
  al_register_event_source(event_queue, al_get_keyboard_event_source());

  al_hide_mouse_cursor(al_get_current_display());
  
  al_start_timer(timer);

   while(true)
  {
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
        {
          al_destroy_event_queue(event_queue);
          al_destroy_bitmap(win);
          al_destroy_bitmap(lose);
          return 1;
        }

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

        //se sono su "Menu"
        if (mouseX >= 140 &&
            mouseX <= 262 &&
            mouseY >= 317 &&
            mouseY <= 356)
        {
          music.playSelect();
          al_destroy_event_queue(event_queue);
          al_destroy_bitmap(win);
          al_destroy_bitmap(lose);
          return 0;
        }
        
        //se sono su "Next/Retry"
        else if (mouseX >= 380 &&
                 mouseX <= 502 &&
                 mouseY >= 317 &&
                 mouseY <= 356)
               			
		    {
          music.playSelect();
          al_destroy_event_queue(event_queue);
          al_destroy_bitmap(win);
          al_destroy_bitmap(lose);
          if(res)
            return 1;
          return -1;
        }

        break;

      default:
        break;  
    }
    al_flush_event_queue(event_queue);
    if(has_redraw && al_is_event_queue_empty(event_queue))
    {
      has_redraw = false;
      al_set_target_bitmap(buffer);
      al_clear_to_color(BLACK);

      if(res)
        drawResult(win, mouseX, mouseY);
      else
        drawResult(lose, mouseX, mouseY);

      cursor(mouseX, mouseY);

      al_set_target_backbuffer(al_get_current_display());
      al_clear_to_color(BLACK);
      al_draw_scaled_bitmap(buffer, 0, 0, WIDTH, HEIGHT, scaleX, scaleY, scaleW, scaleH, 0);

      al_flip_display();
    }
  }
}

Level::~Level()
{
  al_destroy_font(font);
  al_destroy_timer(timer);
  al_destroy_bitmap(buffer);
}
