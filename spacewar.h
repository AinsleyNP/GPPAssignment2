
#ifndef _SPACEWAR_H             // Prevent multiple definitions if this 
#define _SPACEWAR_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN
//  Module:             Gameplay Programming
//  Assignment1:        Galactic Escape
//  Student Name:       Lim Wei Fu
//  Student Number:     S10189687

//  Module:             Gameplay Programming
//  Assignment1:        Galactic Escape
//  Student Name:       Brannon Chua
//  Student Number:     S10187075

//  Module:             Gameplay Programming
//  Assignment1:        Galactic Escape
//  Student Name:       Ainsley Malcolm Pereira
//  Student Number:     S10186606

//  Module:             Gameplay Programming
//  Assignment1:        Galactic Escape
//  Student Name:		Dinesh KP
//  Student Number:     S10185976

#include "game.h"
#include "textureManager.h"
#include "image.h"
//#include "planet.h"
#include "ship.h"
#include "enemy.h"
#include "laser.h"
#include "bullet.h"

namespace spaceWarNS
{
	const int TEXTURE_SIZE = 128;
	const int TEXTURE_COLS = 4;
	const int MAP_HEIGHT = 15;
	const int MAP_WIDTH = 5;
	const float SCROLL_RATE = 10;
	const int __ = -1;                  // empty tile

	const int tileMap[MAP_HEIGHT][MAP_WIDTH] = { // TILEMAP
		3,__,__,1,__,		//Starting row
		__,__,3,__,__,
		__,__,__,__,__,
		__,0,__,__,__,
		__,__,__,__,__,	//Row 5
		__,__,2,__,__,
		__,__,1,__,2,
		__,__,__,__,__,
		__,0,__,__,__,
		__,__,__,__,__,	//Row 10
		__,__,__,1,__,
		__,__,__,__,__,
		__,__,2,__,__,
		__,1,__,__,__,
		0,__,__,__,3		//Row 15
	};
}


//=============================================================================
// This class is the core of the game
//=============================================================================
class Spacewar : public Game
{
private:
    // game items
    TextureManager backgroundTexture;   // nebula texture
    TextureManager gameTextures;    // game texture
	TextureManager tileTextures;
	TextureManager mainMenuTexture;		// main menu texture
	TextureManager gameOverTexture;
	Image mainMenu;						// main menu image
	Image tile;
	Ship    ship1;    // spaceships (https://www.pnglot.com/downpng/hTxmTim_first-version-of-my-sprite-sheet-i-have/)
	Enemy enemy1; //enemy spaceships
	Laser laser;
	Bullet bullet;
	float mapX;
	float mapY;
	Image Gameover;
    Image   background;         // backdrop image

	bool menu = true;
	bool over = false;
public:
    // Constructor
    Spacewar();

    // Destructor
    virtual ~Spacewar();

    // Initialize the game
    void initialize(HWND hwnd);
    void update();      // must override pure virtual from Game
    void ai();          // "
    void collisions();  // "
    void render();      // "
    void releaseAll();
    void resetAll();
};

#endif
