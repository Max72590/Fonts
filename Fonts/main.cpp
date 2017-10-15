#include <SDL.h>
#include <stdio.h>
#include "FontManager.h"
#include "time.h"
#include <string>
using namespace std;

int x, y;
int xInc, yInc;
string message = "ABCD\0";
FontManager* fm;

void Update() {
	if (x > WINDOW_SCREEN_WIDTH - (int)(message.size() * 17)) xInc = -1;
	if (x < (int)((message.size() / 2) * 17)) xInc = 1;
	if (y > WINDOW_SCREEN_HEIGHT) yInc = -1;
	if (y < 9) yInc = 1;
	x += xInc;
	y += yInc;
	SDL_FillRect(fm->sdlScreenSurface, NULL, SDL_MapRGB(fm->sdlScreenSurface->format, 0x00, 0x00, 0x00));
	fm->drawFont(x, y, message, fm->sdlScreenSurface);
	SDL_UpdateWindowSurface(fm->appWindow);
}

int main(int argc, char* args[]) {
	fm = new FontManager();
	x = y = 0;
	xInc = yInc = 0;
	fm->init();
	fm->setActualFont(fm->getFont("lemred.bmp"));
	if (fm->getActualFont() != nullptr) {
		bool loop = true;
		SDL_UpdateWindowSurface(fm->appWindow);
		SDL_RenderPresent(fm->getRenderer());
		while (loop)
		{
			Update();
		}
	}
	fm->end();
	delete fm;
	fm = nullptr;	
	return 0;
}