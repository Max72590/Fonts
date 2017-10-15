#pragma once
#include <vector>
#include <map>
#include <string>
#include "SDL.h"
#include "Font.h"

const int WINDOW_SCREEN_WIDTH = 640;
const int WINDOW_SCREEN_HEIGHT = 480;




class FontManager
{
public:
	FontManager();
	~FontManager();
	void init();
	Font* getActualFont();
	Font* getFont(std::string name);
	void setActualFont(Font* font);
	bool start(SDL_Window *window);
	bool loadFont(std::string name);
	void drawFont(int x, int y, std::string text, SDL_Surface* surface);
	void end();
	SDL_Renderer* getRenderer();
	SDL_Renderer *renderer;
	SDL_Window *appWindow;


public:
	SDL_Surface* sdlScreenSurface = nullptr;
	std::string path = "C:\\Users\\Usuario\\Documents\\Max\\Master\\EjerFonts\\";

private:
	Font* actualFont;
	std::vector<Font*> listOfFonts;
	std::map <std::string, int> fontTable;

};

