#include "UiLabel.h"
#include "Ui.h"
#include "j1App.h"
#include "j1Gui.h"
#include "j1Render.h"

UiLabel::UiLabel (int x, int y, const SDL_Texture* texture, uint type) : UI(x, y,texture, type)
{
	screen_pos.x = x;
	screen_pos.y = y;
	App->tex->GetSize(texture, width, height);
	rectUi = { 0,0,(int)width,(int)height };
}

