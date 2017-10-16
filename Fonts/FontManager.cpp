#include "FontManager.h"

using namespace std;


FontManager::FontManager()
{}


FontManager::~FontManager()
{}

Font* FontManager::getActualFont() {
	return actualFont;
}

Font* FontManager::getFont(string name) {
	int index = -1;
	index = fontTable[name];
	if (index > -1 && index < (int) listOfFonts.size()) {
		return listOfFonts[index];
	}
	return nullptr;
}

void FontManager::setActualFont(Font* font) {
	if (font != nullptr) {
		actualFont = font;
	}
	else printf("Error font parameter is empty\n");
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
				SDL_FillRect(sdlScreenSurface, NULL, SDL_MapRGB(sdlScreenSurface->format, 0x00, 0x00, 0x00));
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
			if (loadFont("lemgreen.bmp")) printf("Load successful \n");
			if (loadFont("lemred.bmp")) printf("Load successful \n");
			if (loadFont("lemyellow.bmp")) printf("Load successful \n");
			return true;

		}
		printf("Error creating renderer %s\n", SDL_GetError());
	}
	printf("Error window is null \n");
	return false;
}

bool FontManager::loadFont(string name) {
	if (!name.empty()) {
		string relativepath = path;
		SDL_Surface *fontsurface = SDL_LoadBMP((relativepath.append(name)).c_str());
		if (fontsurface != nullptr) {
			Font* f = new Font(fontsurface);
			if (f->bmp != nullptr) {
				fontTable[name] = (int)listOfFonts.size();
				listOfFonts.push_back(f);
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
	if (listOfFonts.size() > 0) {
		for (int i = 0; i < (int)listOfFonts.size(); ++i) {
			listOfFonts[i]->cleanUp();
		}
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