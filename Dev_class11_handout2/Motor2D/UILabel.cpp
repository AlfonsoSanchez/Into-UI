
#include "UiLabel.h"
#include "j1App.h"
#include "j1Gui.h"
#include "j1Render.h"

UiLabel::UiLabel(int x, int y, char* text, SDL_Color color, _TTF_Font* font) : UI(x, y)
{
	this->text = text;
	this->color = color;
	this->font = font;
}

void UiLabel::Draw()
{
	SDL_Texture* tex = App->font->Print(text, color, font);
	App->font->CalcSize(text, rectUi.w, rectUi.h, font);
	App->render->Blit(tex, screen_pos.x, screen_pos.y, &rectUi);

}