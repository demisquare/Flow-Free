#include "src/Setup.h"
#include "src/Level.h"


int main()
{
  Setup mySetup;

  Level myLevel;
  myLevel.run("level1.txt");

  mySetup.gameLoop();
  
  return 0;
}
