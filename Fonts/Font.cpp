#include "Font.h"


using namespace std;

// 94 piezas, 9 de ancho, X,Y: 32*9->init + 4*9->end  

Font::Font() {
	bmp = nullptr;
	spacing = newlines = 0;

}

Font::Font(SDL_Surface* surface/*const char* BMPname, const char* message, SDL_Renderer *renderer*/)
{
	if (surface != nullptr) {
		bmp = surface;
		bgColor = SDL_MapRGB( bmp->format, 0x00, 0x00, 0x00);
		int width = bmp->w / 94;
		int height = bmp->h;
		int bmpCharIterator = 0;
		for (int i = 0; i < 94; ++i) {
			SDL_Rect *rect = bmpChars[bmpCharIterator];
			rect->x = width * i;
			rect->y = height;
			rect->w = width;
			rect->h = height;
			
			for (int cellCol = 0; cellCol < width; ++cellCol) {
				for (int cellRow = 0; cellRow < height; ++cellRow) {
					int pX = (i * width ) + cellCol;
					int pY = cellRow;
					if (pixelToInt32(pX,pY, bmp) != bgColor) {
						rect->x = pX;
						cellCol = width;
						cellRow = height;
					}
				}			
			}

			//for ()
			++bmpCharIterator;
		}
	
	}

	/*const char* filename = "C:\\Users\\Usuario\\Documents\\Visual Studio 2015\\Projects\\Fonts\\FontsRes\\+BMPname+.bmp";
	SDL_Surface* surface = SDL_LoadBMP(filename);
	if (surface != nullptr) {
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		SetCoords();
		SDL_FreeSurface(surface);
	}*/
}

Font::~Font()
{

}

Uint32 Font::pixelToInt32(int x, int y, SDL_Surface* surface) {
	Uint32 *pixels = (Uint32 *)surface->pixels;

	return pixels[y*surface->w + x];
}











void Font::SetCoords() {
	coordX = 32 * 9;
	width = 36;
}

void Font::CleanUp() {
	SDL_DestroyTexture(texture);
	texture = nullptr;
}