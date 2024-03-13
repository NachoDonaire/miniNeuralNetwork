#include <Network.hpp>
#include <constants.hpp>

Network::Network()
{
	unsigned i = 0;

	while (i < CREATURES)
	{
		creatures.push_back(Creature(i++));
	}
}


Network::~Network()
{
}

