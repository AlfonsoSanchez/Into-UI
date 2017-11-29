#ifndef _UIBUTTON_
#define _UIBUTTON_


#include "Ui.h"
#include "SDL/include/SDL.h"
#include "p2Defs.h"
#include "p2Point.h"

class UiButton : public UI
{
public:

	UiButton(int, int, SDL_Rect, SDL_Rect, SDL_Rect, const SDL_Texture*, uint);
	void Draw(float);

private:
	SDL_Rect default_texture_rect;
	SDL_Rect mouse_on_rect;
	SDL_Rect clicked_rect;

};


#endif
