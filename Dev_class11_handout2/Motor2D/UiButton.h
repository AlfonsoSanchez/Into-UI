#ifndef _UIBUTTON_
#define _UIBUTTON_


#include "Ui.h"
#include "SDL/include/SDL.h"
#include "p2Defs.h"
#include "p2Point.h"

class UiButton : public UI
{
public:

	UiButton(int, int, p2List<SDL_Rect>, const SDL_Texture*, uint);
	void Draw(float);

private:
	SDL_Rect default_texture_rect;
	SDL_Rect mouse_on_rect;
	SDL_Rect clicked_rect;
public:
	bool mouse_on = false;
	bool mouse_click = false;
};


#endif
