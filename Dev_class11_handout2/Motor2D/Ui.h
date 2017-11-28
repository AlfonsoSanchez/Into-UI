#ifndef _UI_
#define _UI_

#include "SDL/include/SDL.h"
#include "p2Defs.h"
#include "p2Point.h"
#include "j1Textures.h"

class UI
{
public:
	UI(int,int, const SDL_Texture*);
	virtual void Update(float) { };
	virtual void Draw(float);
	virtual ~UI(){ };



public:
	uint width;
	uint height;
	iPoint screen_pos;
	SDL_Rect rectUi;
	const SDL_Texture *texture= nullptr;
};



#endif
