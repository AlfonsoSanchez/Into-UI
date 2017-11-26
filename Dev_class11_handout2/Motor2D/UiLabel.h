#ifndef _UILABEL_
#define _UILABEL_

#include "Ui.h"
#include "SDL/include/SDL.h"
#include "p2Defs.h"
#include "p2Point.h"

class UiLabel : public UI
{
public:

	UiLabel();

	void Update(float dt) { };
	void Draw() { };






public:
	SDL_Rect position;
};




#endif
