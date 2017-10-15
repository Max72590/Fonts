#pragma once
#include "SDL.h"
#include <map>
#include <string>
#include <vector>




class Font
{
public:
	
	Font();
	Font(SDL_Surface *surface);
	~Font();

	void cleanUp();
	Uint32 pixelToInt32(int x, int y,const SDL_Surface* surface);
	void drawText(int posX, int posY, std::string text, SDL_Surface* screen);

public:

	SDL_Surface* bmp;
	std::vector<SDL_Rect*> bmpChars;
	Uint32 bgColor;
	int coordX, width, spacing;
	std::map<char, int> charToFontChar;
	char letters[94] = { '!','"','#','$','%','&','·','(',')','*','+','-','.',
		'/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@',
		'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R',
		'S','T','U','V','W','X','Y','Z','[','\\',']','^','_','´','a','b','c','d',
		'e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
		'w','x','y','z','{','|','}','~',' ' };

};

