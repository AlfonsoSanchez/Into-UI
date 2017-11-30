#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1PathFinding.h"
#include "j1Gui.h"
#include "j1Scene.h"

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	if(App->map->Load("iso_walk.tmx") == true)
	{
		int w, h;
		uchar* data = NULL;
		if(App->map->CreateWalkabilityMap(w, h, &data))
			App->pathfinding->SetMap(w, h, data);

		RELEASE_ARRAY(data);
	}

	debug_tex = App->tex->Load("maps/path2.png");

	// TODO 3: Create the banner (rect {485, 829, 328, 103}) and the text "Hello World"
	/*uint width, height;
	App->win->GetWindowSize(width, height);
	uint scale = App->win->GetScale();
	App->gui->CreateImage({ ((int)(width*scale) / 2) - (300 / 2), 50 * (int)scale }, { 485, 829, 328, 103 },App->gui->GetAtlas());
	_TTF_Font* font = App->font->Load("fonts/open_sans/OpenSans-Bold.ttf", 20);
	App->gui->CreateLabel(50,200, "Hello world", {100,100,100,100},font);*/
	
	_TTF_Font* font = App->font->Load("ingame/fonts/ARIALN.ttf", 12);
	//login_background2.jpg
	//ingame/reference.jpg
	const SDL_Texture *tex = App->tex->Load("ingame/login_background2.jpg");
	App->gui->CreateImage({ 0,0 }, { 0,0,1024,768 },tex);
	
	const SDL_Texture *tex2 = App->tex->Load("ingame/UI-DialogBox-Button-Up.png");
	//Manage Acount
	App->gui->CreateImage({ 19,577 }, { 0,0,130,35 }, tex2);
	App->gui->CreateLabel(29, 581, "Manage Acount", { 226,186,31,255 }, font);
	//Community site
	App->gui->CreateImage({ 19,616 }, { 0,0,130,35 }, tex2);
	App->gui->CreateLabel(29, 620, "Community Site", { 226,186,31,255 }, font);
	//Login
	App->gui->CreateImage({ 445,525 }, { 0,0,150,39 }, tex2);
	App->gui->CreateLabel(503, 530, "Login", { 226,186,31,255 }, font);
	//Cinematics
	App->gui->CreateImage({ 878,516 }, { 0,0,134,35 }, tex2);
	App->gui->CreateLabel(888, 521, "Cinematics", { 226,186,31,255 }, font);
	//Credits
	App->gui->CreateImage({ 878,552 }, { 0,0,134,35 }, tex2);
	App->gui->CreateLabel(888, 557, "Credits", { 226,186,31,255 }, font);
	//Term of use
	App->gui->CreateImage({ 878,588 }, { 0,0,134,35 }, tex2);
	App->gui->CreateLabel(888, 593, "Terms of Use", { 226,186,31,255 }, font);
	//Quit
	App->gui->CreateImage({ 878,707 }, { 0,0,134,35 }, tex2);
	App->gui->CreateLabel(888, 711, "Quit", { 226,186,31,255 }, font);
	//LOGO BIG
	const SDL_Texture *tex3 = App->tex->Load("ingame/Glues-WoW-Logo.png");
	App->gui->CreateImage({ 0,10 }, { 0,0,350,139}, tex3);
	//BlizzardLogo
	const SDL_Texture *tex4 = App->tex->Load("ingame/Glues-BlizzardLogo.png");
	App->gui->CreateImage({ 460,640}, { 0,0,128,128 }, tex4);
	//xperience in game
	const SDL_Texture *tex5 = App->tex->Load("ingame/Glues-ESRBRating.png");
	App->gui->CreateImage({ 20,595 }, { 0,0,128,128 }, tex5);
	//input
	const SDL_Texture *tex6 = App->tex->Load("ingame/UI-DialogBox-Button-Disabled.png");
	//name
	App->gui->CreateImage({ 445,389 }, { 0,0,153,38 }, tex6);
	App->gui->CreateLabel(463, 370, "Account Name", { 226,186,31,255 }, font);
	//password
	App->gui->CreateImage({ 445,463 }, { 0,0,153,38 }, tex6);
	App->gui->CreateLabel(463, 444, "Account Password", { 226,186,31,255 }, font);
	//Remember Account Name
	const SDL_Texture *tex7 = App->tex->Load("ingame/Glues-CheckBox-Background.png"); 
	App->gui->CreateLabel(42,655, "Remember Account Name", { 226,186,31,255 }, font);
	App->gui->CreateImage({ 22, 655 }, {0,0,16,16}, tex7);
	//Version 2.0.12(6546)(Release)
	App->gui->CreateLabel(2, 732, "Version 2.0.12(6546)(Release)", { 226,186,31,255}, font);
	//All righst reserved
	App->gui->CreateLabel(350, 750, "Copyright 2004-2007 Blizzard Entertainment. All Rights Reserved", { 226,186,31,255 }, font);
	//WoWps.org TBC
	App->gui->CreateLabel(888, 613, "WoWps.org TBC", { 102, 102, 102,255 }, font);

	App->gui->CreateButton({ 200,0 },{0, 113, 229, 69},{411, 169, 229, 69},{642, 169, 229, 69},App->gui->GetAtlas());
	App->gui->CreateButton({ 200,200 }, { 0, 113, 229, 69 }, { 411, 169, 229, 69 }, { 642, 169, 229, 69 }, App->gui->GetAtlas());
	App->gui->CreateButton({ 200,400 }, { 0, 113, 229, 69 }, { 411, 169, 229, 69 }, { 642, 169, 229, 69 }, App->gui->GetAtlas());
	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{

	// debug pathfing ------------------
	static iPoint origin;
	static bool origin_selected = false;

	int x, y;
	App->input->GetMousePosition(x, y);
	iPoint p = App->render->ScreenToWorld(x, y);
	p = App->map->WorldToMap(p.x, p.y);

	if(App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_DOWN)
	{
		if(origin_selected == true)
		{
			App->pathfinding->CreatePath(origin, p);
			origin_selected = false;
		}
		else
		{
			origin = p;
			origin_selected = true;
		}
	}

	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	// Gui ---
	
	// -------
	if(App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
		App->LoadGame("save_game.xml");

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
		App->SaveGame("save_game.xml");

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		App->render->camera.y += floor(200.0f * dt);

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		App->render->camera.y -= floor(200.0f * dt);

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		App->render->camera.x += floor(200.0f * dt);

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		App->render->camera.x -= floor(200.0f * dt);

	//App->map->Draw();

	int x, y;
	App->input->GetMousePosition(x, y);
	iPoint map_coordinates = App->map->WorldToMap(x - App->render->camera.x, y - App->render->camera.y);
	p2SString title("Map:%dx%d Tiles:%dx%d Tilesets:%d Tile:%d,%d",
					App->map->data.width, App->map->data.height,
					App->map->data.tile_width, App->map->data.tile_height,
					App->map->data.tilesets.count(),
					map_coordinates.x, map_coordinates.y);

	//App->win->SetTitle(title.GetString());

	// Debug pathfinding ------------------------------
	//int x, y;
	App->input->GetMousePosition(x, y);
	iPoint p = App->render->ScreenToWorld(x, y);
	p = App->map->WorldToMap(p.x, p.y);
	p = App->map->MapToWorld(p.x, p.y);

	App->render->Blit(debug_tex, p.x, p.y);

	const p2DynArray<iPoint>* path = App->pathfinding->GetLastPath();

	for(uint i = 0; i < path->Count(); ++i)
	{
		iPoint pos = App->map->MapToWorld(path->At(i)->x, path->At(i)->y);
		App->render->Blit(debug_tex, pos.x, pos.y);
	}
	//colision buttons
	
	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;

	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}
