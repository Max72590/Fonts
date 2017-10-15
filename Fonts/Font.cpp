#include "Font.h"


using namespace std;

// 94 piezas, 9 de ancho, X,Y: 32*9->init + 4*9->end  

Font::Font() {
	bmp = nullptr;
	spacing = 0;
}

Font::~Font()
{

}

Font::Font(SDL_Surface* surface)
{
	bmp = nullptr;
	if (surface != nullptr) {
		bmp = surface;
		bgColor = SDL_MapRGB( bmp->format, 0x00, 0x00, 0x00);		
		int height = bmp->h;
		int width  = bmp->w/ 94;
		for (int i = 0; i < 94; ++i) {
			char c = letters[i];
			charToFontChar[c] = i+1;
		}		
		for (int i = 0; i < 94; ++i) {
			SDL_Rect* rect = new SDL_Rect;
			rect->x = width * i;
			rect->y = 1;
			rect->w = width+1;
			rect->h = height+1;
			bmpChars.push_back(rect);
		}
	}
	else 	printf("Surface is null\n");
}

Uint32 Font::pixelToInt32(int x, int y,const SDL_Surface* surface) {
	Uint32 *pixels = (Uint32 *)surface->pixels;
	return pixels[y*surface->w + x];
}

void Font::cleanUp() {
	SDL_FreeSurface(bmp);
	bmp = nullptr;
	bmpChars.clear();
	charToFontChar.clear();
}

void Font::drawText(int posX, int posY, string text, SDL_Surface* screen) {	
	int relativeX = posX;
	for (int i = 0; i < (int) text.size(); ++i ) {
		if (charToFontChar.count(text[i])) {
			SDL_Rect * charRect = bmpChars[charToFontChar[text[i]]];
			if (charRect != nullptr) {
				SDL_Rect destRect;
				destRect.x = relativeX;
				destRect.y = posY;
				destRect.w = charRect->w;
				destRect.h = charRect->h;
				if (charRect != nullptr) {
					SDL_BlitSurface(bmp, charRect, screen, &destRect);
					relativeX += charRect->w;
				}
			}
			else 	printf("Rect for char %s not found\n", &text[i]);
		}			
	}
}

