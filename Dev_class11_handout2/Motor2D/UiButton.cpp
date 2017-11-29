#include "UiButton.h"
#include "j1App.h"
#include "j1Gui.h"
#include "j1Render.h"


/*
Rect UI list:
0=Button default
1=Mouse on Button
2=Button clicked
*/
UiButton::UiButton(int x, int y, SDL_Rect default, SDL_Rect mouse_on, SDL_Rect clicked, const SDL_Texture* texture, uint type) : UI(x, y, texture, type)
{
	default_texture_rect=default;
	mouse_on_rect = mouse_on;
	clicked_rect = clicked;
}

void UiButton::Draw(float dt) {
	
	if (mouse_on) {
		if (mouse_click){
			rectUi = clicked_rect;
		}
		else {
			rectUi = mouse_on_rect;
		}
	}
	else {
		rectUi = default_texture_rect;
	}
	
	App->render->Blit(texture, screen_pos.x, screen_pos.y, &rectUi);
}