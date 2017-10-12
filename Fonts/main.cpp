#include <SDL.h>
#include <stdio.h>
#include "FontManager.h"






void PrintFont(FontManager* fm, int x, int y, const char* c) {
	Font *f = fm->getFont();
	SDL_Rect srect;
	srect.x = fm->actualFont->coordX;
	srect.y = 0;
	srect.w = f->width;
	srect.h = 9;
	SDL_Rect drect;
	drect.x = x;
	drect.y = y;
	drect.w = f->width;
	drect.h = 9;
	SDL_RenderCopy(fm->renderer, fm->getFont()->texture, &srect, &drect);
}

void End() {

}

int main(int argc, char* args[]) {
	
	FontManager* fm = new FontManager();
	bool gameLoop = true;
	fm->Init();
	//PrintFont(fm, 240, 320, "ABCD");
	/*while (gameLoop) {
	PrintFont(fm, 240, 320, "ABCD");
	}*/


	SDL_Delay(5000);

	fm->End();
	delete fm;
	fm = nullptr;
	
	return 0;
}