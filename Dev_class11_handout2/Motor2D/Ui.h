#ifndef _UI_
#define _UI_

#include "SDL/include/SDL.h"
#include "p2Defs.h"
#include "p2Point.h"
#include "j1Textures.h"

class UI
{
public:
	UI(int,int, const SDL_Texture*,uint);
	virtual void Update(float) { };
	virtual void Draw(float);
	virtual ~UI(){ };



public:
	uint type;
	uint width;
	uint height;
	iPoint screen_pos;
	SDL_Rect rectUi;
	bool mouse_on = false;
	bool mouse_click = false;
	const SDL_Texture *texture= nullptr;
};



#endif
