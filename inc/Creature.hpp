#ifndef ACREATURE_HPP
#define ACREATURE_HPP

#include <Network.hpp>
#include <Neuron.hpp>
#include <OutNeuron.hpp>
#include <Input.hpp>
#include <iostream>

class Creature
{
	private:
		std::vector<Input>		in;
		bool				live;
		std::string			name;
		float				pos[2];
		float				rgba[4];
 	public:
    		Creature();
    		Creature(int uid);
    		//Creature(std::string n, float p[2], float rgba[4]);
		std::string	genName();
		std::string	getName();
		std::vector<Input> getIn();
		void		display();
		~Creature();
};

#endif
