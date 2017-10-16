#pragma once
#include <vector>
#include <map>
#include <string>
#include "SDL.h"
#include "Font.h"

const int WINDOW_SCREEN_WIDTH = 640;
const int WINDOW_SCREEN_HEIGHT = 480;

#define MY_SOLUTIONDIR2 = $(SolutionDir)


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
	void end();
	SDL_Renderer* getRenderer();

public:
	SDL_Surface* sdlScreenSurface = nullptr;
	SDL_Window *appWindow;

private:
	Font* actualFont;
	std::vector<Font*> listOfFonts;
	std::map <std::string, int> fontTable;
	SDL_Renderer *renderer;

	// Fix this to relative path
	std::string path = "C:\\Users\\maximinopm\\Documents\\GitHub\\Fonts\\FontsRes\\"; //"C:\\Users\\Usuario\\Documents\\Max\\Master\\EjerFonts\\";

};

