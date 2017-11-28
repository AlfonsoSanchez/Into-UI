
#include "j1Render.h"
#include "j1App.h"
#include "j1Gui.h"

UI::UI(int x, int y, const SDL_Texture* texture)
{

	screen_pos.x = x;
	screen_pos.y = y;
	this->texture = texture;
}

void UI::Draw(float dt)
{
	App->render->Blit(texture, screen_pos.x, screen_pos.y, &rectUi);
}