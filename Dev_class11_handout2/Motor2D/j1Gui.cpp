#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"

j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.GetString());


	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	return true;
}
bool j1Gui::Update(float dt)
{

	p2List_item<UI*> *Ui_item = UiElement.start;

	while (Ui_item != nullptr)
	{
		Ui_item->data->Draw(dt);
		Ui_item = Ui_item->next;
	}
	
	
	iPoint mouse;
	App->input->GetMousePosition(mouse.x, mouse.y);
	Ui_item = UiElement.start;

	while (Ui_item != nullptr)
	{
		if (Ui_item->data->type == UI_BUTTON) {
			if (mouse.x < Ui_item->data->screen_pos.x + Ui_item->data->rectUi.w && mouse.x > Ui_item->data->screen_pos.x && mouse.y < Ui_item->data->screen_pos.y + Ui_item->data->rectUi.h && mouse.y > Ui_item->data->screen_pos.y) {
				Ui_item->data->mouse_on = true;
			}
			else {
				Ui_item->data->mouse_on = false;
			}

			if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT)) {
				Ui_item->data->mouse_click = true;
			}

			else {
				Ui_item->data->mouse_click = false;
			}
		}
		Ui_item = Ui_item->next;
	}
	return true;

}
// Called after all Updates
bool j1Gui::PostUpdate()
{
	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");
	
	UiElement.clear();

	return true;
}

// const getter for atlas
const SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

UiImage* j1Gui::CreateImage(iPoint position, SDL_Rect rect, const SDL_Texture* texture)
{
	UiImage* newImage = new UiImage(position.x,position.y, rect,texture,UI_IMAGE);
	UiElement.add((UI*)newImage);
	return newImage;
}

UiLabel* j1Gui::CreateLabel(int x, int y, char* text, SDL_Color color, _TTF_Font* font)
{
	const SDL_Texture* tex = App->font->Print(text,color,font);

	
	UiLabel* newLabel = new UiLabel(x,y,tex,UI_LABEL);
	UiElement.add((UI*)newLabel);
	
	return newLabel;
}

UiButton* j1Gui::CreateButton(iPoint position, SDL_Rect default, SDL_Rect mouse_on, SDL_Rect clicked, const SDL_Texture* texture)
{
	/*
	Rect UI list:
	0=Button default
	1=Mouse on Button
	2=Button clicked
	*/

	UiButton* newButton = new UiButton(position.x, position.y, default, mouse_on, clicked, texture, UI_BUTTON);
	UiElement.add((UI*)newButton);
	return newButton;
}

// class Gui ---------------------------------------------------
