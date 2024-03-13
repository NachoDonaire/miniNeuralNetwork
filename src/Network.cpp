#include <Network.hpp>
#include <constants.hpp>

Network::Network()
{
	srand(std::time(0));
	unsigned i = 0;

	while (i < CREATURES)
	{
		creatures.push_back(Creature(i++));
	}
}


Network::~Network()
{
}

