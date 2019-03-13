#include "Level.h"
#include "ScreenSettings.h"

int main()
{
  if(!al_init())
  {
   cerr << "failed to initialize allegro!\n";
   return -1;
  }
    ScreenSettings s;
    Level myLevel;

    al_rest(2.0); //attendi 2 secondi

    return 0;
}
