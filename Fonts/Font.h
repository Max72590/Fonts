#pragma once
#include "SDL.h"

class Font
{
public:
	
	Font();
	Font(SDL_Surface *surface);
	//Font(const char* BMPname, const char* message, SDL_Renderer *renderer);
	~Font();
	void CleanUp();
	Uint32 pixelToInt32(int x, int y, SDL_Surface* surface);
	void makeFont();

public:

	SDL_Surface* bmp;
	SDL_Rect *bmpChars[256];
	Uint32 bgColor;
	int spacing;
	
	int newlines;

	SDL_Texture *texture;
	int coordX, width;

private:

	void SetCoords();

};

