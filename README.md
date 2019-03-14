# Flow-Free
**Flow Free** for OOP University Project, written in C++ using ALLEGRO 5 by **Team Photoshop**.

## Requires:
 - g++/gcc/MinGW compiler
 - Allegro 5

## Run Game:
```bash
g++ FlowFree.cpp -lallegro -lallegro_image -lallegro_primitives -g
./a.out
```
Stop with **Escape** key.

## History:
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
- Adding Score, Path, Menu, Music.
- Mouse events.
- Game music.
- Timed Level mode.

## Authors:

* **demisquare** - (https://github.com/demisquare)
* **MartinaCanonPh** - (https://github.com/MartinaCanonPh)
