#include "UiLabel.h"
#include "Ui.h"
#include "j1App.h"
#include "j1Gui.h"
#include "j1Render.h"

UiLabel::UiLabel(int x, int y,const SDL_Texture *texture) : UI(x, y,texture)
{
	screen_pos.x = x;
	screen_pos.y = y;
}

