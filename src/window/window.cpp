#include <SDL2/SDL.h>
#include <Creature.hpp>

void	paintCreature(Creature cr)
{
	int	evPoint[2];

	float	distance = 0;
	float x = cr.pos[0];
	float	y = cr.pos[1];

	evPoint[0] = 0;
	evPoint[1] = 0;
	while (evPoint[0] < WIDTH)
	{
		while (evPoint[1] < HEIGHT)
		{
			distance = sqrt(pow(x - evPoint[0], 2) + pow(y - evPoint[1], 2));
			if (distance <= radius)
			{
				SDL_SetRenderDrawColor(renderer, in.rgba[0], in.rgba[1], in.rgba[2], 255);
				SDL_RenderDrawPoint(renderer, evPoint[0], evPoint[1]);
			}
			evPoint[1]++;
		}
		evPoint[1] = 0;
		evPoint[0]++;
	}
}
