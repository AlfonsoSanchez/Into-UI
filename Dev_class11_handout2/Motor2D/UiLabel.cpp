#include "UiLabel.h"
#include "Ui.h"
#include "j1App.h"
#include "j1Gui.h"
#include "j1Render.h"

UiLabel::UiLabel(int x, int y, char* text, SDL_Color color, _TTF_Font* font, SDL_Rect rect) : UI(x, y)
{
	this->text = text;
	this->color = color;
	this->font = font;
	this->rectUi = rect;
	screen_pos.x = x;
	screen_pos.y = y;
}

void UiLabel::Draw(float dt)
{
	//const SDL_Texture* tex = App->font->Print(text, color, font);
	App->font->CalcSize(text, rectUi.w, rectUi.h, font);
	App->render->Blit(App->font->Print(text, color, font), screen_pos.x, screen_pos.y, &rectUi);

}