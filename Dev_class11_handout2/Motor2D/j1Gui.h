#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include "Ui.h"
#include "p2List.h"
#include "UiLabel.h"
#include "UiImage.h"
#include "UiButton.h"
#define CURSOR_WIDTH 2


enum Ui_type {
	UI_IMAGE=0,
	UI_BUTTON,
	UI_LABEL
};
// TODO 1: Create your structure of classes

// ---------------------------------------------------
class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// TODO 2: Create the factory methods
	// Gui creation functions
	bool Update(float);
	UiImage* CreateImage(iPoint,SDL_Rect, const SDL_Texture*);
	UiLabel* CreateLabel(int, int, char*, SDL_Color, _TTF_Font*);
	UiButton* CreateButton(iPoint, SDL_Rect, SDL_Rect, SDL_Rect, const SDL_Texture*);
	const SDL_Texture* GetAtlas() const;

private:

	SDL_Texture* atlas;
	p2SString atlas_file_name;
	p2List<UI*> UiElement;
};

#endif // __j1GUI_H__