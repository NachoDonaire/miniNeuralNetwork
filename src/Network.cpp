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

void	Network::analyzeOutput(Creature *cr)
{
	int	i = 1;
	int	val = 0;
	float	pos = cr->getOut()[0].getActivation();
	while (i < OUTPUT_NEURONS)
	{
		if (pos < cr->getOut()[i].getActivation())
		{
			pos = cr->getOut()[i].getActivation();
			val = i;
		}
		i++;
	}
	if (cr->getOut()[val].getId() == MOVE_EAST)
		cr->move_east();
	else if (cr->getOut()[val].getId() == MOVE_WEST)
		cr->move_west();
	else if (cr->getOut()[val].getId() == MOVE_NORTH)
		cr->move_north();
	else if (cr->getOut()[val].getId() == MOVE_SOUTH)
		cr->move_south();
	else if (cr->getOut()[val].getId() == MOVE_RANDOM)
		cr->move_random();
	else if (cr->getOut()[val].getId() == MOVE_CENTER)
		cr->move_center();
	else if (cr->getOut()[val].getId() == STAY)
		cr->stay();
}

void	Network::deadCriteria(int type)
{
	int	i = 0;

	if (type == 0)
	{
		while (i < CREATURES)
		{
			if (creatures[i].closeWall())
				creatures[i].setLive(0);
			i++;
		}
	}
}

void	Network::nextGen()
{
	int	i = 0;
	int	f = 0;
	int	m = 0;
	std::vector<Creature> neocr;
	std::vector<Creature>::iterator cri = creatures.begin();

	deadCriteria(0);
	while (i < CREATURES)
	{
		if (!creatures[i].getLive())
		{
			creatures.erase(cri);
		}
		cri++;
		i++;
	}
	i = 0;
	while (i < CREATURES - creatures.size())
	{
		f = rand() % creatures.size();
		m = rand() % creatures.size();
		Creature s(creatures[f], creatures[m]);
		neocr.push_back(s);
		i++;
	}
	i = 0;
	while (i < neocr.size())
	{
		creatures.push_back(neocr[i++]);
	}
}



void	Network::readjustInput(Input *in, Creature *cr)
{
	if (in->getId() == PX)
		in->setInput(sigmoid(cr->getX()) + abs(randisimoFloat(0, 4)));
	else if (in->getId() == PY)
		in->setInput(sigmoid(cr->getY()) + abs(randisimoFloat(0, 4)));
	else if (in->getId() == MADNESS)
	{
		if (cr->closeWall())
		{
			in->setInput(in->getInput() - 5);
		}
	}
	else if (in->getId() == SURVIVAL)
		in->setInput(in->getInput() + 5);
}

void	Network::readjustCreatures()
{
	int	i = 0;
	int	y = 0;

	while (i < CREATURES)
	{
		while (y < INPUT_NEURONS)
		{
			readjustInput(&this->creatures[i].getIn()[y++], &creatures[i]);
		}
		y = 0;
		i++;
	}
}
		


void	Network::actionLauncher()
{
	int	i = 0;
	while (i < CREATURES)
	{
		analyzeOutput(&creatures[i++]);
	}
}


void	Network::simulation()
{
	int	i = 0;
	int	y = 0;

	while (i < SIMSTEPS)
	{

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		while (y < CREATURES)
		{
			creatures[y++].connections();
		}
		actionLauncher();
		y = 0;
		while (y < CREATURES)
		{
			creatures[y++].paintCreature(renderer);
		}
		SDL_RenderPresent(renderer);
		readjustCreatures();
		i++;
	}
	nextGen();
}
