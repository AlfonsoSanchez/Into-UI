#ifndef _UILABEL_
#define _UILABEL_

#include "SDL/include/SDL.h"
#include "p2Defs.h"
#include "p2Point.h"
#include "j1Fonts.h"
#include "Ui.h"

class UiLabel : public UI
{
public:

	UiLabel(int x, int y, SDL_Rect rect, const SDL_Texture *texture);

	void Update(float dt) { };
	void Draw(float dt);

public:
	SDL_Rect position;
	char* text = nullptr;
	SDL_Color color;
	_TTF_Font* font;
};

#endif