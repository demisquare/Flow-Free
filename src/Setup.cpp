#include "../head/Setup.h"

void Setup::init_display()
{
  al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);

  display = al_create_display(WIDTH, HEIGHT);
  if(!display)
  {
   cerr << "Fatal error, unable to create a display\n";
   exit(-1);
  }
  
  buffer = al_create_bitmap(WIDTH, HEIGHT);
  if(!buffer)
  {
    cout << "Fatal error, unable to create a buffer\n";
    exit(-1);
  }
  
  //operazione di resize...
   windowHeight = al_get_display_height(display);
   windowWidth = al_get_display_width(display);

   sx = windowWidth / float(WIDTH);
   sy = windowHeight / float(HEIGHT);

   scale = std::min(sx, sy);

   scaleW = WIDTH * scale;
   scaleH = HEIGHT * scale;

   scaleX = (windowWidth - scaleW) / 2;
   scaleY = (windowHeight - scaleH) / 2;

  al_set_target_bitmap(buffer);
  al_clear_to_color(BLACK);
}

Setup::Setup():display(NULL), buffer(NULL)
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
  
  init_display();
}

void Setup::drawMenu()
{
  if(!buffer)
  {
    cout<<"Failed to load buffer!\n";
    exit(-1);
  }
  al_set_target_bitmap(buffer);

  ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

  if(!event_queue)
  {
      cout<<"Failed to load event queue!\n";
      exit(-1);
  }

  ALLEGRO_BITMAP *menu = al_load_bitmap("../images/background.png");
  if(!menu)
  {
      cout<<"Failed to load menu bitmap!\n";
      exit(-1);
  }

  al_clear_to_color(BLACK);
  al_draw_bitmap(menu, 0, 0, 0);

  al_set_target_bitmap(al_get_backbuffer(display));

  al_clear_to_color(BLACK);
  al_draw_scaled_bitmap(buffer, 0, 0, WIDTH, HEIGHT, scaleX, scaleY, scaleW, scaleH, 0);
  al_flip_display();

  al_register_event_source(event_queue, al_get_mouse_event_source());
  al_register_event_source(event_queue, al_get_keyboard_event_source());

  al_set_target_bitmap(buffer);


  while(true)
  {
    menu = al_load_bitmap("../images/background.png");

    if(!menu)
      exit(-1);

    al_clear_to_color(BLACK);
    al_draw_bitmap(menu, 0, 0, 0);

    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);

    int mouseX = ev.mouse.x - scaleX;
    int mouseY = ev.mouse.y - scaleY;

    switch (ev.type)
    {
      case ALLEGRO_EVENT_MOUSE_AXES: //movimento mouse
      //al_draw_filled_circle(ev.mouse.x, ev.mouse.y, 7, WHITE); //coordinate effettive
      //al_draw_filled_circle(mouseX, mouseY, 3, RED); //coordinate traslate

            //sono su "Play!"
            if(mouseX >= 275 &&
               mouseX <= 370 &&
               mouseY >= 283 &&
               mouseY <= 315)
      
	      al_draw_filled_circle(252, 300, 7, PINK);

      //sono su "Options"
      else if (mouseX >= 260 &&
               mouseX <= 379 &&
               mouseY >= 330 &&
               mouseY <= 363)
      
        al_draw_filled_circle(252, 350, 7, GREEN);
      
      
      //sono su "Quit"
      else if (mouseX >= 283 &&
               mouseX <= 356 &&
               mouseY >= 421 &&
               mouseX <= 460)
      
				al_draw_filled_circle(267, 444, 7, RED);
          
          
      else
        al_set_target_bitmap(buffer);
            
      break;
      
      case ALLEGRO_EVENT_MOUSE_BUTTON_UP: //click mouse
      
      //sono su "Play!"
           if(mouseX >= 275 &&
              mouseX <= 370 &&
              mouseY >= 283 &&
              mouseY <= 315)
	           {
              al_destroy_event_queue(event_queue);
               
              Level myLevel(buffer, scaleX, scaleY,0);
              myLevel.run("../levels/level1.txt");
             }
        

      //sono su "Options"
      else if (mouseX >= 260 &&
               mouseX <= 379 &&
               mouseY >= 330 &&
               mouseY <= 363)
        
          {
            al_destroy_event_queue(event_queue);
            drawOptions();
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
    
    al_set_target_bitmap(al_get_backbuffer(display));
    al_clear_to_color(BLACK);

    al_draw_scaled_bitmap(buffer, 0, 0, WIDTH, HEIGHT, scaleX, scaleY, scaleW, scaleH, 0);
    al_flip_display();

    al_set_target_bitmap(buffer);
    al_clear_to_color(BLACK);
    
    al_flush_event_queue(event_queue);
  }
  al_destroy_event_queue(event_queue);
}

void Setup::drawOptions()
{
  if(!buffer)
  {
    cout<<"Failed to load buffer!\n";
    exit(-1);
  }
  al_set_target_bitmap(buffer);

  ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

  if(!event_queue)
  {
    cout<<"Failed to create the event queue!\n";
    exit(-1);
  }

  ALLEGRO_BITMAP *options = al_load_bitmap("../images/GameMode.png");
  if(!options){
    cout<<"Failed to load the options bitmap!\n";
    exit(-1);
  }
  al_clear_to_color(BLACK);
  al_draw_bitmap(options, 0, 0, 0);

  al_set_target_bitmap(al_get_backbuffer(display));

  al_clear_to_color(BLACK);
  al_draw_scaled_bitmap(buffer, 0, 0, WIDTH, HEIGHT, scaleX, scaleY, scaleW, scaleH, 0);
  al_flip_display();  

  al_register_event_source(event_queue, al_get_mouse_event_source());
  al_register_event_source(event_queue, al_get_keyboard_event_source());

  al_set_target_bitmap(buffer);

  bool done = false;
  
  while (!done)
  {
    options = al_load_bitmap("../images/GameMode.png");

    if(!options)
      exit(-1);
    al_clear_to_color(BLACK);
    al_draw_bitmap(options, 0, 0, 0);

    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);

    int mouseX = ev.mouse.x - scaleX;
    int mouseY = ev.mouse.y - scaleY;
    
    switch (ev.type)
    {
    case ALLEGRO_EVENT_MOUSE_AXES: //movimento mouse
    
    //se sono su "Classic"
        if (mouseX >= 243 &&
            mouseX <= 395 &&
            mouseY >= 132 &&
            mouseY <= 188)
                      
		      al_draw_filled_circle(227, 164, 8, ORANGE);
        
        
     //se sono su "Moves"
        else if (mouseX >= 243 &&
                 mouseX <= 395 &&
                 mouseY >= 212 &&
                 mouseY <= 268)
               			
		        al_draw_filled_circle(227, 244, 8, YELLOW);
        
        
      //se sono su "Timer"
        else if (mouseX >= 259 &&
                 mouseX <= 376 &&
                 mouseY >= 292 &&
                 mouseY <= 348)
                    	
		 	      al_draw_filled_circle(243, 316, 8, AQUA);

        //sono su "Back"
        else if (mouseX >= 278 &&
                 mouseX <= 361 &&
                 mouseY >= 417 &&
                 mouseY <= 450)

            al_draw_filled_circle(267, 435, 7, RED);

      else
            al_set_target_bitmap(buffer);
        
        break;

    case ALLEGRO_EVENT_MOUSE_BUTTON_UP: //click mouse
      
      //sono su "Classic"
           if(mouseX >= 243 &&
              mouseX <= 395 &&
              mouseY >= 132 &&
              mouseY <= 188)
	           {
              al_destroy_event_queue(event_queue);
               
              Level myLevel(buffer, scaleX, scaleY,0);
              myLevel.run("../levels/level1.txt");
             }
        

      //sono su "Moves"
      else if (mouseX >= 243 &&
               mouseX <= 395 &&
               mouseY >= 212 &&
               mouseY <= 268)
        
          {
            al_destroy_event_queue(event_queue);
               
              Level myLevel(buffer, scaleX, scaleY,1);
              myLevel.run("../levels/level1.txt");
          }

      //sono su "Timer"
      else if (mouseX >= 259 &&
               mouseX <= 376 &&
               mouseY >= 292 &&
               mouseY <= 340)
            {
            al_destroy_event_queue(event_queue);
               
              Level myLevel(buffer, scaleX, scaleY,2);
              myLevel.run("../levels/level1.txt");
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
    al_set_target_bitmap(al_get_backbuffer(display));
    al_clear_to_color(BLACK);

    al_draw_scaled_bitmap(buffer, 0, 0, WIDTH, HEIGHT, scaleX, scaleY, scaleW, scaleH, 0);
    al_flip_display();

    al_set_target_bitmap(buffer);
    al_clear_to_color(BLACK);
    
    al_flush_event_queue(event_queue);
  }
  if(done)
  {
    al_destroy_event_queue(event_queue);
    drawMenu();
  }
}
Setup::~Setup()
{
  al_destroy_bitmap(buffer);
  al_uninstall_keyboard();
  al_uninstall_mouse();
  al_destroy_display(display);
}