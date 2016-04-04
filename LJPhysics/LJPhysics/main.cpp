#include <iostream>
#include <SDL\SDL.h>
#undef main

int main(int argc, char** argv)
{
	SDL_Window* window;
	unsigned screenWidth = 600;
	unsigned screenHeigth = 600;

	window = SDL_CreateWindow("LJPhysics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeigth, SDL_WINDOW_OPENGL);

	int y = 0;
	int x = 0;
	float mass = 10.0;
	float g = 9.81;
	float velocity = mass * g;
	while (window)
	std::cout << "laatikko tippuu y: " << --y << std::endl;
	

	return 0;
}