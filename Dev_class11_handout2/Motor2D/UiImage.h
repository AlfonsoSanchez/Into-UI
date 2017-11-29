#ifndef _UIIMAGE_
#define _UIIMAGE_


#include "Ui.h"
#include "SDL/include/SDL.h"
#include "p2Defs.h"
#include "p2Point.h"

class UiImage : public UI
{
public:

	UiImage(int,int,SDL_Rect, const SDL_Texture*,uint);

};


#endif

