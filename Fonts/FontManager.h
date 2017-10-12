#pragma once
#include <vector>
#include "SDL.h"
#include "Font.h"

enum FontNames
{
	FONT1,
	FONT2,
	FONT3
};

const int WINDOW_SCREEN_WIDTH = 640;
const int WINDOW_SCREEN_HEIGHT = 480;

class FontManager
{
public:
	FontManager();
	~FontManager();
	
	void Init();

	bool Start(SDL_Window *window);

	bool LoadFont(int index, const char* message, SDL_Renderer *renderer);

	void End();

	Font* getFont();

public:

	SDL_Renderer *renderer;
	SDL_Window *appWindow;
	SDL_Surface* sdlScreenSurface = nullptr;
	Font* actualFont;
	std::vector<const char*> listOfFonts;


};

