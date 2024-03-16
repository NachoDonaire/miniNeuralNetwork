#ifndef ACREATURE_HPP
#define ACREATURE_HPP

#include <Network.hpp>
#include <Neuron.hpp>
#include <OutNeuron.hpp>
#include <Input.hpp>
#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>

class Input;

class Creature
{
	private:
		std::vector<Input>		in;
		OutNeuron			*out;
		bool				live;
		unsigned			age;
		std::string			name;
		float				pos[2];
		float				rgba[4];
 	public:
    		Creature();
    		Creature(Creature &f, Creature &m);
    		Creature(int uid);
    		//Creature(std::string n, float p[2], float rgba[4]);
		std::string	genName();
		std::string	getName();
		OutNeuron	*getOut(){return this->out;};
		std::vector<Input> getIn();
		void		setLive(bool l) { live = l;};
		bool		getLive() { return live;};
		void		paintCreature(SDL_Renderer *renderer);
		void		connections();
		void		display();
		void		happyBirhtday();
		void		output();
		bool		checkOutput(OutNeuron *o);
		void		move_east();
		void		move_west();
		void		move_north();
		void		move_south();
		void		move_random();
		void		move_center();
		bool		closeWall()  ;
		void		stay();
		float		getX();
		float		getY();
		float		getRGBA(int n) { return rgba[n];};
		unsigned	getAge();
		~Creature();
};

#endif
