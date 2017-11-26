#ifndef _UILABEL_
#define _UILABEL_

#include "Ui.h"
#include "SDL/include/SDL.h"
#include "p2Defs.h"
#include "p2Point.h"
#include "j1Fonts.h"

class UiLabel : public UI
{
public:

	UiLabel(int x, int y, char* text, SDL_Color color, _TTF_Font* font);

	void Update(float dt) { };
	void Draw();

public:
	char* text = nullptr;
	SDL_Color color;
	_TTF_Font* font;
};




#endif
