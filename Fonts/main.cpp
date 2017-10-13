#include <SDL.h>
#include <stdio.h>
#include "FontManager.h"
#include <string>
using namespace std;


FontManager* fm = new FontManager();


void PrintFont(int x, int y, string text, SDL_Surface* surface) {
	(fm->getActualFont())->drawText(x,y,text, surface);
}

int main(int argc, char* args[]) {
	

	bool gameLoop = true;
	fm->init();
	if (fm->loadFont("lemgreen.bmp")) printf("Load successful \n");
	fm->setActualFont("lemgreen.bmp");
	string message = "ABCD\0";
	PrintFont(200,300,message,fm->sdlScreenSurface);
	//fm->loadFont("lemred.bmp");
	//fm->loadFont("lemyellow.bmp");
	
	while (1)
	{
		SDL_RenderPresent(fm->getRenderer());
	}
	//SDL_Delay(60000);
	//fm->end();
	delete fm;
	fm = nullptr;
	
	return 0;
}