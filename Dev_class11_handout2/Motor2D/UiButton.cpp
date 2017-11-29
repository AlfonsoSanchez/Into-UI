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
UiButton::UiButton(int x, int y, p2List<SDL_Rect> rect , const SDL_Texture* texture, uint type) : UI(x, y, texture, type)
{
	default_texture_rect=rect[0];
	mouse_on_rect = rect[1];
	clicked_rect = rect[2];
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