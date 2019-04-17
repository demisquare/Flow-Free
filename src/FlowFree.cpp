#include "../head/Setup.h"

int main()
{
  Setup* mySetup = new Setup();
  mySetup->menu();

  delete mySetup;
  
  return 0;
}
