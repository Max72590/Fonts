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
		
		int width = bmp->h;
		int  height = bmp->w/ 94;

		for (int i = 0; i < 94; ++i) {
			char c = letters[i];
			charToFontChar[c] = i;
		}
		
		for (int i = 0; i < 94; ++i) {
			SDL_Rect* rect = new SDL_Rect;
			rect->x = width * i;
			rect->y = height;
			rect->w = width;
			rect->h = height;
			bmpChars.push_back(rect);
			printf("Size: %d\n", bmpChars.size());
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
	charToFontChar.clear();
}

void Font::drawText(int posX, int posY, string text, SDL_Surface* screen) {
	
	int relativeX = posX;
	for (int i = 0; i < (int) text.size(); ++i ) {
		if (charToFontChar.count(text[i])) {
			SDL_Rect * charRect = bmpChars[charToFontChar[text[i]]];
			printf("Rect: x: %d , y: %d , w: %d , h: %d \n", charRect->x, charRect->y, charRect->w, charRect->h);
			if (charRect != nullptr) {
				SDL_Rect destRect;
				destRect.x = relativeX;
				destRect.y = posY;
				destRect.w = charRect->w;
				destRect.h = charRect->h;
				printf("DestRect: x: %d , y: %d , w: %d , h: %d \n", destRect.x, destRect.y, destRect.w, destRect.h);
				if (charRect != nullptr) {
					SDL_BlitSurface(bmp, charRect, screen, &destRect);
					relativeX += charRect->w;
				}
			}
			else 	printf("Rect for char %s not found\n", &text[i]);
		}			
	}
}


/*
Spaguetti code for load bmp

for (int cellColLeft = 0; cellColLeft < width; ++cellColLeft) {
for (int cellRowLeft = 0; cellRowLeft < height; ++cellRowLeft) {
int pX = (i * width) + cellColLeft;
int pY = cellRowLeft;
if (pixelToInt32(pX, pY, bmp) != bgColor) {
rect.x = pX;
cellColLeft = width;
cellRowLeft = height;
}
}
}

for (int cellColRigth = 0; cellColRigth < width - 1; --cellColRigth) {
for (int cellRowRight = 0; cellRowRight < height; ++cellRowRight) {
int pX = (i * width) + cellColRigth;
int pY = cellRowRight;
if (pixelToInt32(pX, pY, bmp) != bgColor) {
rect.w = (pX - rect.x) + 1;
cellColRigth = -1;
cellRowRight = height;
}
}
}

++bmpCharIterator;
}
*/