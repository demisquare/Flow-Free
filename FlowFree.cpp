#include "src/Setup.h"
#include "src/Menu.h"


int main()
{
  Setup mySetup;

  Menu myMenu;
  myMenu.run();

  //Level myLevel;
  //myLevel.run("level1.txt");

  mySetup.gameLoop();
  
  return 0;
}
