#include <Network.hpp>

int main()
{
	int	i;
	Network net;

	i = 0;
	while (i < CREATURES)
		std::cout << net.creatures[i++].getName() << std::endl;
	return 0;
}

