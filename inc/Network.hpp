#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <vector>
#include <ctime>
#include <cstdlib>
#include <constants.hpp>
#include <Creature.hpp>

class Creature;

class Network
{
	private:
 	public:
    		Network();
		std::vector<Creature>	creatures;
    		~Network();
};

#endif
