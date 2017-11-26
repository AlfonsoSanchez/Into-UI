#include "UiImage.h"
#include "j1App.h"
#include "j1Gui.h"
#include "j1Render.h"

UiImage::UiImage(int x, int y, SDL_Rect rect): UI(x,y)
{
	this->rectUi = rect;
}

void UiImage::Draw(float dt)
{

	App->render->Blit(App->gui->GetAtlas(), screen_pos.x, screen_pos.y, &rectUi);

}