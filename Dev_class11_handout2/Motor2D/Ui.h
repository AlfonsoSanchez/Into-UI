#ifndef _UI_
#define _UI_

#include "SDL/include/SDL.h"
#include "p2Defs.h"
#include "p2Point.h"

class UI
{
public:
	UI(int,int);
	virtual void Update(float) { };
	virtual void Draw(float);
	virtual ~UI(){ };



public:
	iPoint screen_pos;
	SDL_Rect rectUi;

};



#endif
