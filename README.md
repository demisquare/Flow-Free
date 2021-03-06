# Flow-Free
**Flow Free** for OOP University Project, written in C++ using ALLEGRO 5 by **Team Photoshop**.

## Requires:
 - g++/gcc/MinGW compiler
 - Allegro 5

## Run Game:
Navigate into src folder, then open terminal and type:
```bash
make && ./FlowFree
```
Quit game with **Escape** key.

## History:
#### 13-07-19:
- Adj bugfix and fixed game music volume.

#### 12-07-19:
- Now you can delete paths by clicking on balls.
- Now current path delete other paths if overlaps them.
- Music bugfix.

#### 10-07-19:
- Now is possible to delete paths leaving mouse.
- Now is possible to shrink current path if overlaps itself.
- Added a lock on balls when you create a path.
- Improved path closure.

#### 09-07-19:
- Added Music class.
- Re-organized assets in folders.
- Victory and Lose now use the same methods.

#### 08-07-19:
- Improved moves count.
- Added victory and lose screens.

#### 07-07-19:
- PathMap now checks more logic constraints.
- Added moves count.

#### 06-07-19:
- Buffer and level fixes.

#### 05-07-19:
- Added turn back button in Score tab.
- Added multiple level handling.
- Fixed Buffer issues.

#### 04-07-19:
- Added Score class.
- Added font Aberus.
- Timer mode works.

#### 24-06-19:
- Added GameEngine.cpp.
- Added display and buffer in level class.
- Fixed map drawing methods.
- Updating path conditions.

#### 23-06-19:
- More levels.
- Added readLevel() in Setup class.
- Now is possible to go back to menu after victory.
- Now is possible to load a level simply using its number.

#### 22-06-19:
- GameMap is now included in PathMap.
- Now the game is (almost) playable.

#### 21-06-19:
- **PATHS! FINALLY!**
- Added antialiasing.
- Minor bugfixes.

#### 20-06-19:
- Added PathMap class.
- Added victory conditions.
- Fixed colors list update.
- Now paths should close correctly.

#### 19-06-19:
- Added AddPath method in GameMap class.
- Added operator== for GameObj objects.
- Path creation improvements.

#### 17-06-19:
- Changed GameObj*** to vector<vector<GameObj*> >.
- Path creation improvements.

#### 08-05-19:
- Added Empty (extends GameObj) Class.
- Added Color operator==.
- Added GameMap.add() and GameMap.remove().
- Minor bugfixes.

#### 10-04-19:
- Added Makefile.

#### 01-04-19:
- Added get method for mouse coordinates.

#### 26-03-19:
- Fixed GameMap.draw() and added GameMap.load().
- Fixed mouse coordinates in game.

#### 24-03-19:
- Fixed Back button in drawOptions().

#### 23-03-19:
- Fixed GameMode.png with _Back_ new label.
- Added a _Back_ button in drawOptions().
- Added an integer gameMode field in Level.
    - - 0 for Classic mode;
    - - 1 for Moves mode;
    - - 2 for Timer mode.
- Fixed abstract class GameObj
- Added class Ball and Path cpp and header files.

#### 22-03-19:
- GraphicManager is now Setup.
- Removed Menu class.
- Fixed _Play!_ button.

#### 18-03-19:
- Separated headers from implementations.
- Menu class fixes.
- Added GraphicManager class.
- Removed Setup and Victory classes.

#### 15-03-19:
- Fixed Ball positions.
- Fixed dynamic resolution on fullscreen.
- Grid map is now a primitive.
- Added Path class.
- Added a Switch case in Event Queue.

#### 14-03-19:
- Reduced code lines in main().
- Moved all headers in src folder.
- Added gameLoop.
- Renamed GameSettings.h to Setup.h.
- Added Mouse and Keyboard Events.
- Added Level.run() method.
- Removed MouseEvents Class.
- Minor bugfixes.

#### 13-03-19:
- Added Yellow color.
- Added ScreenSettings class.
- Added MouseEvents Class.
- Minor bugfixes.

#### 12-03-19:
- Fixed Core Dump errors.
- Minor bugfixes.

#### 10-03-19:
- Fixed ball position.
- Renamed Menu.h in Level.h.
- Moved grid bitmap to Level.h file.
- Minor bugfixes.

#### 09-03-19:
- First release.
- Added text file input to generate the levelmap.

## Authors:
* **demisquare** - (https://github.com/demisquare)
* **MartinaCanonPh** - (https://github.com/MartinaCanonPh)
