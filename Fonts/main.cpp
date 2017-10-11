#include <SDL.h>
#include <stdio.h>

const int WINDOW_SCREEN_WIDTH = 640;
const int WINDOW_SCREEN_HEIGHT = 480;

void Init() {
	


}
void Update() {

}
void Render() {

}
void End() {

}

int main(int argc, char* args[]) {

	SDL_Window* sdlWindow = nullptr;
	SDL_Surface* sdlScreenSurface = nullptr;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Error in SDL initialization: %s\n", SDL_GetError());
	}
	else {
		sdlWindow = SDL_CreateWindow("Fonts", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, WINDOW_SCREEN_WIDTH, WINDOW_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (sdlWindow = NULL) {
			printf("Error in creating window: %s\n", SDL_GetError());
		}
		else {
			sdlScreenSurface = SDL_GetWindowSurface(sdlWindow);
			SDL_FillRect(sdlScreenSurface, NULL, SDL_MapRGB(sdlScreenSurface->format, 0xFF,0xFF, 0xFF));
			SDL_UpdateWindowSurface(sdlWindow);
			SDL_Delay(2000);
			SDL_DestroyWindow(sdlWindow);
			SDL_Quit();
		}
	}

	return 0;
}