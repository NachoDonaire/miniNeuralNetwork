#include <Network.hpp>

int main()
{
	int	i;
	int	y = 0;
	int	z = 0;
	Network net;

	i = 0;
	while (i < CREATURES)
	{
		while (y < INPUT_NEURONS)
		{
			std::cout << "IIIINNNPPPUUUUTTT" << std::endl;
			while (z < NEURONS)
			{
				//net.creatures[i].getIn()[y].getOut()[z++].display();
				net.creatures[i].getIn()[y].getNeurons()[z++].display();
				//net.creatures[i].getIn()[y];//.getOut()[z++].display();
				z++;
			}
			y++;
			z = 0;
		}
		i++;
		y = 0;
	}
	return 0;
}

