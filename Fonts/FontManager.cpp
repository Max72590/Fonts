#include "FontManager.h"



FontManager::FontManager()
{

}


void FontManager::Init() {
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
				Start(appWindow);
			}
			else {
				printf("Error in creating window: %s\n", SDL_GetError());
			}
			//SDL_DestroyWindow(appWindow);

		}
	}
}

Font* FontManager::getFont() {
	return actualFont;
}

bool FontManager::Start(SDL_Window *window) {
	if (window != nullptr) {
		appWindow = window;
		renderer = SDL_CreateRenderer(appWindow, -1, NULL);
		if (renderer != nullptr) {
			return true;
		}
	}
	return false;
}

FontManager::~FontManager()
{
}


bool FontManager::LoadFont(int index, const char* message,SDL_Renderer *renderer) {
	Font* f = new Font( sdlScreenSurface);
	if (f->texture != nullptr) {
		actualFont = f;
		return true;
	}
	return false;
}

void FontManager::End() {


	if (actualFont != nullptr) {
		actualFont->CleanUp();
		delete actualFont;
		actualFont = nullptr;
	}

	SDL_FreeSurface(sdlScreenSurface);
	sdlScreenSurface = nullptr;
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(appWindow);
	appWindow = nullptr;
	/*for (const char* it : listOfFonts) {
		
	}*/
		//listOfFonts;
}