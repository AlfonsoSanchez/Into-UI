#include "Ui.h"
#include "j1Render.h"
#include "j1App.h"
#include "j1Gui.h"

UI::UI(int x, int y)
{
	rectUi.x = x;
	rectUi.y = y;
}

void UI::Draw(float dt)
{
	App->render->Blit(App->gui->GetAtlas(), 0, 0, &rectUi);

}