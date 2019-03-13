//eventi del mouse

ALLEGRO_TIMER *timer=al_create_timer(2.0/FPS);
ALLEGRO_EVENT_QUEUE *event_queue= al_create_event_queue();
al_register_event_source(event_queue, al_get_timer_event_source(timer));
al_register_event_source(event_queue, al_get_display_event_source(display));
al_register_event_source(event_queue, al_get_mouse_event_source());

//eventualmente nascondere il cursore
al_hide_mouse_cursor(display);

al_start_time_timer(timer);
bool done=false;

while(!done)
{
	ALLEGRO_EVENT events;
	al_wait_for_event(event_queue, &events);
	
	if(events.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
		done=true;
	else if(events.type==ALLEGRO_EVENT_MOUSE_AXES)
	{
		x=events.mouse.x;
		y=events.mouse.y;
	}
	else if(events.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		if(events.mouse.button & 1)
			//qualcosa
		else if(events.mouse.botton & 2)
			//qualcosa
	}
}

/*	altre funzioni del mouse
ALLEGRO_EVENT_MOUSE_AXES
ALLEGRO_EVENT_MOUSE_BUTTON_DOWN
ALLEGRO_EVENT_MOUSE_BUTTON_UP
ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY
ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY
ALLEGRO_EVENT_MOUSE_WARPED
*/
