#ifndef _UI_
#define _UI_

#include "SDL/include/SDL.h"
#include "p2Defs.h"
#include "p2Point.h"
#include "j1Textures.h"

enum UI_COLLISION {
	NO_COLLISION = 0,
	MOUSE_ON,
	CLICKED
};

class UI
{
public:
	UI(int,int, const SDL_Texture*,uint);
	virtual void Update(float) { };
	virtual void Draw();
	virtual ~UI(){ };
	uint state;
public:
	uint type;
	uint width;
	uint height;
	iPoint screen_pos;
	SDL_Rect rectUi;
	const SDL_Texture *texture= nullptr;
};



#endif
