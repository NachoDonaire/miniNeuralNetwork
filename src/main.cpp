#include <Network.hpp>


SDL_Window *initializeWindow()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Junkie slip", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	return window;
}



int main()
{
	int	i;
	bool	quit = false;
	Network net;

	SDL_Event e;
	SDL_Window *window = initializeWindow();
	net.renderer= SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	i = 0;
	net.creatures[0].display();
	i = 0;
	while (i < CREATURES)
	{
		net.creatures[i++].paintCreature(net.renderer);
	}
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}
		net.simulation();
	}
	//net.creatures[0].display();
	return 0;
}

