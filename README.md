# Flow-Free
**Flow Free** for OOP University Project, written in C++ using ALLEGRO 5 by **Team Photoshop**.

## Requires:
 - g++/gcc/MinGW compiler
 - Allegro 5

## Run Game:
Navigate into src folder, then open terminal and type:
```bash
g++ *.cpp -lallegro -lallegro_image -lallegro_primitives -g
./a.out
```
Quit game with **Escape** key.

## History:
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

## Next changes:
- Adding Score, Path, Menu, Game music.
- Mouse events.
- Timed Level mode.

## Authors:

* **demisquare** - (https://github.com/demisquare)
* **MartinaCanonPh** - (https://github.com/MartinaCanonPh)
