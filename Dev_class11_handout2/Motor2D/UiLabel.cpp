#include "UiLabel.h"
#include "Ui.h"
#include "j1App.h"
#include "j1Gui.h"
#include "j1Render.h"

UiLabel::UiLabel(int x, int y, SDL_Rect rect,const SDL_Texture *texture) : UI(x, y,texture)
{
	this->rectUi = rect;
	screen_pos.x = x;
	screen_pos.y = y;
}

void UiLabel::Draw(float dt)
{
	App->render->Blit(texture, screen_pos.x, screen_pos.y, &rectUi);
}