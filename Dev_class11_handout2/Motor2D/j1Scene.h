#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "j1Module.h"

struct SDL_Texture;
class UIImage;
class GuiText;
class UIElement;
class UIButton;
enum EventElement;
enum ElementType;

class j1Scene : public j1Module
{
public:

	j1Scene();

	// Destructor
	virtual ~j1Scene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	void onUiTriggered(UIElement*, EventElement);

private:
	SDL_Texture* debug_tex = nullptr;
	UIImage* banner = nullptr;
	GuiText* text = nullptr;
	p2List<UIButton*> buttons;
};

#endif // __j1SCENE_H__