#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <vector>
#include <ctime>
#include <cstdlib>
#include <constants.hpp>
#include <Creature.hpp>
#include <Input.hpp>
#include <SDL2/SDL.h>

class Creature;
class Input;

class Network
{
	private:
 	public:
		SDL_Renderer *renderer;
    		Network();
		void	simulation();
		void	deadCriteria(int type);
		void	nextGen();
		void	analyzeOutput(Creature *cr);
		void	readjustInput(Input *in, Creature *cr);
		void	readjustCreatures();
		void	actionLauncher();

		std::vector<Creature>	creatures;
    		~Network();
};

#endif
