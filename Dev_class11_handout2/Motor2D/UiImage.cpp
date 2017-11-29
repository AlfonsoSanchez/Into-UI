#include "UiImage.h"
#include "j1App.h"
#include "j1Gui.h"
#include "j1Render.h"

UiImage::UiImage (int x, int y,SDL_Rect rect, const SDL_Texture* texture, uint type) : UI(x,y,texture,type)
{
	this->rectUi = rect;
}

