#include "FontManager.h"

using namespace std;


FontManager::FontManager()
{}


FontManager::~FontManager()
{}

Font* FontManager::getActualFont() {
	return actualFont;
}

void FontManager::setActualFont(const char* name) {
	if (name != nullptr) {
		actualFont = listOfFonts[fontTable[name]];
	}
	else printf("Error name is empty\n");
}

void FontManager::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Error in SDL initialization: %s\n", SDL_GetError());
	}
	else {
		appWindow = SDL_CreateWindow("Fonts", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_SCREEN_WIDTH, WINDOW_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (appWindow == nullptr) {
			printf("Error in creating window: %s\n", SDL_GetError());
		}
		else {
			sdlScreenSurface = SDL_GetWindowSurface(appWindow);
			if (sdlScreenSurface != nullptr) {
				SDL_FillRect(sdlScreenSurface, NULL, SDL_MapRGB(sdlScreenSurface->format, 0xFF, 0xFF, 0xFF));
				SDL_UpdateWindowSurface(appWindow);
				start(appWindow);
			}
			else {
				printf("Error in creating window: %s\n", SDL_GetError());
			}
		}
	}
}

bool FontManager::start(SDL_Window *window) {
	if (window != nullptr) {
		appWindow = window;
		renderer = SDL_CreateRenderer(appWindow, -1, NULL);
		if (renderer != nullptr) {
			return true;
		}
		printf("Error creating renderer %s\n", SDL_GetError());
	}
	printf("Error window is null \n");
	return false;
}

bool FontManager::loadFont(string name) {
	if (!name.empty()) {
		SDL_Surface *fontsurface = SDL_LoadBMP((path.append(name)).c_str());
		printf("Path name:  %s\n", (path.c_str()));
		if (fontsurface != nullptr) {
			Font* f = new Font(fontsurface);
			if (f->bmp != nullptr) {
				listOfFonts.push_back(f);
				fontTable[name.c_str()] = listOfFonts.size();
				return true;
			}			
		}
		else printf("Error bitmap couldn't be loaded  %s\n", SDL_GetError());
	}
	else printf("Error name is empty\n");
	return false;
}

void FontManager::end() {
	if (actualFont != nullptr) {
		actualFont->cleanUp();
		delete actualFont;
		actualFont = nullptr;
	}
	SDL_FreeSurface(sdlScreenSurface);
	sdlScreenSurface = nullptr;
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(appWindow);
	appWindow = nullptr;
}

SDL_Renderer* FontManager::getRenderer() {
	return renderer;
}