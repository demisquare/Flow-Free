#include "../head/Setup.h"

Setup::Setup()
{
  if(!al_init())
  {
    cerr << "failed to initialize allegro!\n";
    exit(-1);
  }
  if(!al_install_keyboard())
  {
    cerr << "failed to initialize keyboard!\n";
    exit(-1);
  }
  if(!al_install_mouse())
  {
    cerr << "failed to initialize mouse!\n";
    exit(-1);
  }
  if(!al_init_image_addon())
  {
    cerr << "failed to initialize menu!\n";
    exit(-1);
  }
  if(!al_init_primitives_addon())
  {
    cerr << "failed to initialize primitives!\n";
    exit(-1);
  }

  init_display();
  init_buffer();

  al_hide_mouse_cursor(display);
}

void Setup::runLevel(int mode)
{
  al_destroy_timer(timer);
  al_destroy_event_queue(event_queue);
  al_destroy_bitmap(buffer);

  Level* level = nullptr;
  bool done = true;
  int i = 1;

  while(i <= nLevels && done)
  {
    level = new Level(mode);
    done = level->run(i);
    delete level;
    i++;
  }

  init_buffer();
  menu();
}

void Setup::menu()
{
  ALLEGRO_BITMAP *menu = al_load_bitmap("../images/background.png");
  if(!menu)
  {
      cout<<"Failed to load menu bitmap!\n";
      exit(-1);
  }

  //primo frame...
  al_set_target_bitmap(buffer);
  al_clear_to_color(BLACK);

  drawMenu(menu, mouseX, mouseY);
  cursor(mouseX, mouseY);

  al_set_target_backbuffer(al_get_current_display());
  al_clear_to_color(BLACK);
  al_draw_scaled_bitmap(buffer, 0, 0, WIDTH, HEIGHT, scaleX, scaleY, scaleW, scaleH, 0);

  al_flip_display();

  init_event_queue();
  init_timer();
  
  al_register_event_source(event_queue, al_get_mouse_event_source());
  al_register_event_source(event_queue, al_get_keyboard_event_source());

  //avvia il timer...
  al_start_timer(timer);

  while(true)
  { 
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    
    switch (ev.type)
    {
      case ALLEGRO_EVENT_TIMER:
          has_redraw = true;
          break;

      case ALLEGRO_EVENT_MOUSE_AXES: //movimento mouse
          mouseX = ev.mouse.x - scaleX;
          mouseY = ev.mouse.y - scaleY;    
          break;
      
      case ALLEGRO_EVENT_MOUSE_BUTTON_UP: //click mouse
      
      //sono su "Play!"
           if(mouseX >= 275 &&
              mouseX <= 370 &&
              mouseY >= 283 &&
              mouseY <= 315)
	           {
                runLevel(0);
                break;
             }
        

      //sono su "Options"
      else if (mouseX >= 260 &&
               mouseX <= 379 &&
               mouseY >= 330 &&
               mouseY <= 363)
        
              {
                al_destroy_event_queue(event_queue);
                options();
              }

      //sono su "Quit"
      else if (mouseX >= 283 &&
               mouseX <= 356 &&
               mouseY >= 421 &&
               mouseX <= 460)
				      exit(1);

      break;

      case ALLEGRO_EVENT_KEY_DOWN:
      if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        exit(1);
      break;

      default:
        break;
    }

    al_flush_event_queue(event_queue);

    if(has_redraw && al_is_event_queue_empty(event_queue))
    {
      al_set_target_bitmap(buffer);
      al_clear_to_color(BLACK);

      drawMenu(menu, mouseX, mouseY);
      cursor(mouseX, mouseY);

      al_set_target_backbuffer(al_get_current_display());
      al_clear_to_color(BLACK);
      al_draw_scaled_bitmap(buffer, 0, 0, WIDTH, HEIGHT, scaleX, scaleY, scaleW, scaleH, 0);

      al_flip_display();
    }
  }
  al_destroy_event_queue(event_queue);
  al_destroy_bitmap(menu);
}

void Setup::options()
{
  ALLEGRO_BITMAP *options = al_load_bitmap("../images/GameMode.png");
  if(!options)
  {
    cout<<"Failed to load the options bitmap!\n";
    exit(-1);
  }

  //primo frame...
  al_set_target_bitmap(buffer);
  al_clear_to_color(BLACK);

  drawOptions(options, mouseX, mouseY);
  cursor(mouseX, mouseY);

  al_set_target_backbuffer(al_get_current_display());
  al_clear_to_color(BLACK);
  al_draw_scaled_bitmap(buffer, 0, 0, WIDTH, HEIGHT, scaleX, scaleY, scaleW, scaleH, 0);

  al_flip_display();

  init_event_queue();
  init_timer();
  
  al_register_event_source(event_queue, al_get_mouse_event_source());
  al_register_event_source(event_queue, al_get_keyboard_event_source());

  //avvia il timer...
  al_start_timer(timer);
  
  bool done = false;

  while(!done)
  {
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
 
    switch (ev.type)
    {
    case ALLEGRO_EVENT_TIMER:
      has_redraw = true;
      break;

    case ALLEGRO_EVENT_MOUSE_AXES: //movimento mouse
      mouseX = ev.mouse.x - scaleX;
      mouseY = ev.mouse.y - scaleY;

      break;

    case ALLEGRO_EVENT_MOUSE_BUTTON_UP: //click mouse
      //sono su "Classic"
           if(mouseX >= 243 &&
              mouseX <= 395 &&
              mouseY >= 132 &&
              mouseY <= 188)
	           {
                runLevel(0);
                done = true;
             }

      //sono su "Moves"
      else if (mouseX >= 243 &&
               mouseX <= 395 &&
               mouseY >= 212 &&
               mouseY <= 268)
        
            {
              runLevel(1);
              done = true;
            }

      //sono su "Timer"
      else if (mouseX >= 259 &&
               mouseX <= 376 &&
               mouseY >= 292 &&
               mouseY <= 340)
            {
              runLevel(2);
              done = true;
            }

      //sono su "Back"
      else if (mouseX >= 278 &&
               mouseX <= 361 &&
               mouseY >= 417 &&
               mouseY <= 450)
				    done = true;

      break;

    case ALLEGRO_EVENT_KEY_DOWN:
        if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
          done = true;
        break;

    default:
        break;
    }

    al_flush_event_queue(event_queue);

    if(has_redraw && al_is_event_queue_empty(event_queue))
    {
      al_set_target_bitmap(buffer);
      al_clear_to_color(BLACK);

      drawOptions(options, mouseX, mouseY);
      cursor(mouseX, mouseY);

      al_set_target_backbuffer(al_get_current_display());
      al_clear_to_color(BLACK);
      al_draw_scaled_bitmap(buffer, 0, 0, WIDTH, HEIGHT, scaleX, scaleY, scaleW, scaleH, 0);

      al_flip_display();
    }
  }
  if(done)
  {
    al_destroy_event_queue(event_queue);
    al_destroy_bitmap(options);
    menu();
  }
}

Setup::~Setup()
{
  al_uninstall_keyboard();
  al_uninstall_mouse();

  al_destroy_timer(timer);
  al_destroy_bitmap(buffer);
  al_destroy_display(display);
}