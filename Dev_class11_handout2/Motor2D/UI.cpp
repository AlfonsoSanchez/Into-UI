
#include "j1Render.h"
#include "j1App.h"
#include "j1Gui.h"

UI::UI(int x, int y)
{

	screen_pos.x = x;
	screen_pos.y = y;
}

void UI::Draw(float dt)
{
	App->render->Blit(App->gui->GetAtlas(), screen_pos.x, screen_pos.y, &rectUi);
}