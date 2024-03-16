#include <Creature.hpp>

Creature::Creature(){}

bool Creature::closeWall()
{
	if (pos[0] <= 10 || pos[0] >= WIDTH - 10)
		return 1;
	if (pos[1] <= 10 || pos[1] >= HEIGHT - 10)
		return 1;
	return 0;
}


Creature::Creature(int uid)
{
	(void)uid;
	//Initialize creature properties
	int i = 0;
	name = genName();
	live = 1;
	age = 0;

	//Initialize position
	pos[0] = randomFloat(0, WIDTH);
	if (pos[0] < 0)
		pos[0] *= -1.0;
	pos[1] = randomFloat(0, HEIGHT) * -1.0;
	if (pos[1] < 0)
		pos[1] *= -1.0;
	for (int i = 0; i < 4 ; i++)
		rgba[i] = rand() % 256;
	//Initialize its inputs and neurons (weights, bias) and output in a random way
	OutNeuron *out = new OutNeuron[OUTPUT_NEURONS];
	Neuron	*n = new Neuron[NEURONS];
	i = 0;	
	while (i < OUTPUT_NEURONS)
	{
		out[i] = OutNeuron(i);
		i++;
	}
	i = 0;
	this->out = out;
	while (i < NEURONS)
	{
		n[i] = Neuron(i);
		n[i].setOut(out);
		i++;
	}
	i = 0;
	while (i < INPUT_NEURONS)
	{
		Input why(i, this);
		why.setNeuron(n);
		why.setOut(out);
		in.push_back(why);
		i++;
	}


}

Creature::Creature(Creature &f, Creature &m)
{
	//Initialize creature properties
	int i = 0;
	bool	prio = rand() % 2;
	name = genName();
	live = 1;
	age = 0;

	//Initialize position
	pos[0] = prio ? f.getX() + MOVEMENT_UNIT : m.getX() + MOVEMENT_UNIT;
	pos[1] = prio ? f.getY() + MOVEMENT_UNIT : m.getY() + MOVEMENT_UNIT;
	for (int i = 0; i < 4 ; i++)
	{
		if (i % 2)
			rgba[i] = prio ? f.getRGBA(i) : m.getRGBA(i);
		rgba[i] = prio ? m.getRGBA(i) : f.getRGBA(i);
		i++;
	}
	i = 0;
	while (i < INPUT_NEURONS)
	{
		if (i % 2)
			this->in[i] = prio ? Input(f.getIn()[i]) : Input(m.getIn()[i]);
		else
			this->in[i] = prio ? Input(m.getIn()[i]) : Input(f.getIn()[i]);
		i++;
	}
}


std::vector<Input> Creature::getIn()
{
	return this->in;
}

std::string	Creature::genName()
{
	std::vector<std::string> names = {"Johannes", "Jovedia", "Pontificio", "Esmeraldo", "Enrica", "Dominga", "Koala", "Pedrita", "Hermes", "Claudio", "Tobbie"};
	std::vector<std::string> surnames = {"Bolkinson", "Wilkinson", "Yerbato", "Geremido", "Opañel", "Bolivar", "Lumpur", "Garcia", "Gildo", "El Grande", "Tratamedo"};

	int	name = rand() % names.size();
	int	surname = rand() % surnames.size();

	return (names[name] + " " + names[surname]);
}

std::string Creature::getName()
{
	return this->name;
}

void	Creature::display()
{
	int	i = 0;
	std::cout << "----CREATURE----" << std::endl;
	std::string islive = live ? "Yes" : "No";
	std::cout << "Live :" <<  islive << std::endl;
	std::cout << "Name : " << this->getName() << std::endl;
	std::cout << "x : " << pos[0] << std::endl;
	std::cout << "y : " << pos[1] << std::endl;
	std::cout << "rgba : " << rgba[0] << " " << rgba[1] << " " << rgba[2] << " " << rgba[3] << std::endl;

	std::cout << std::endl;
	i = 0;
	while (i < INPUT_NEURONS)
	{	std::cout << "INNER" << std::endl;
		this->in[i++].display();
	}
}




Creature::~Creature()
{
}

void	Creature::paintCreature(SDL_Renderer *renderer)
{
	int	evPoint[2];

	float	distance = 0;
	float x = pos[0];
	float	y = pos[1];

	evPoint[0] = 0;
	evPoint[1] = 0;
	while (evPoint[0] < WIDTH)
	{
		while (evPoint[1] < HEIGHT)
		{
			distance = sqrt(pow(x - evPoint[0], 2) + pow(y - evPoint[1], 2));
			if (distance <= RADIUS)
			{
				SDL_SetRenderDrawColor(renderer, rgba[0], rgba[1], rgba[2], 255);
				SDL_RenderDrawPoint(renderer, evPoint[0], evPoint[1]);
			}
			evPoint[1]++;
		}
		evPoint[1] = 0;
		evPoint[0]++;
	}
}

void	Creature::connections()
{
	int	i = 0;
	int	n = 0;
	float	sum = 0;
	while (n < NEURONS)
	{
		while (i < INPUT_NEURONS)
		{
			sum += in[i].getWeights(n) * in[i].getInput();
			i++;
		}
		i = 0;
		sum += in[i].getNeurons()[n].getBias();
		in[i].getNeurons()[n].setSum(sum);
		in[i].getNeurons()[n].setActivation(sigmoid(sum));
		sum = 0;
		n++;
	}
	n = 0;
	sum = 0;
	while (n < OUTPUT_NEURONS)
	{
		/*
		while (i < INPUT_NEURONS)
		{
			sum += in[i].getOutWeights(n) * in[i].getInput();
			i++;
		}*/
		i = 0;
		while (i < NEURONS)
		{
			sum += in[0].getNeurons()[i].getActivation() * in[0].getNeurons()[i].getWeights(n);
			i++;
		}
		i = 0;
		sum += in[i].getOut()[n].getBias();
		in[i].getOut()[n].setSum(sum);
		in[i].getOut()[n].setActivation(sigmoid(sum));

		sum = 0;
		n++;
	}
}

bool Creature::checkOutput(OutNeuron *o)
{
	if (o->getActivation() > 0.5)
		return 1;
	return 0;
}

void	Creature::output()
{
	int	i = 0;
	while (i < OUTPUT_NEURONS)
	{
		if (this->in[0].getOut()[i].getId() == MOVE_EAST)
		{
			if (checkOutput(&this->in[0].getOut()[i]))
				move_east();
		}
		else if (this->in[0].getOut()[i].getId() == MOVE_WEST)
		{
			if (checkOutput(&this->in[0].getOut()[i]))
				move_west();
		}
		else if (this->in[0].getOut()[i].getId() == MOVE_NORTH)
		{
			if (checkOutput(&this->in[0].getOut()[i]))
				move_north();
		}
		else if (this->in[0].getOut()[i].getId() == MOVE_SOUTH)
		{
			if (checkOutput(&this->in[0].getOut()[i]))
				move_south();
		}
		i++;
	}
}

void	Creature::move_east()
{
	if (pos[0] >= WIDTH - CLOSE_WALL)
		return;
	this->pos[0] += MOVEMENT_UNIT;
}

void	Creature::move_west()
{
	if (pos[0] <= CLOSE_WALL)
		return;
	this->pos[0] -= MOVEMENT_UNIT;
}

void	Creature::move_north()
{
	if (pos[1] <= CLOSE_WALL)
		return;
	this->pos[1] -= MOVEMENT_UNIT;
}
	
void	Creature::move_south()
{
	if (pos[1] >= HEIGHT - CLOSE_WALL)
		return;
	this->pos[1] += MOVEMENT_UNIT;
}


void	Creature::move_center()
{
	if (pos[0] > WIDTH / 2)
		move_west();
	else
		move_east();
	if (pos[1] > HEIGHT / 2)
		move_north();
	else
		move_south();
}

void	Creature::move_random()
{
	int f = rand() % 5;
	if (f == 0)
		move_east();
	else if (f == 1)
		move_west();
	else if (f == 2)
		move_north();
	else if (f == 3)
		move_south();
	else if (f == 4)
		move_center();
}


void	Creature::stay()
{}

		

unsigned Creature::getAge()
{
	return this->age;
}

void	Creature::happyBirhtday()
{
	this->age++;
}

float	Creature::getX()
{
	return this->pos[0];
}

float	Creature::getY()
{
	return this->pos[1];
}
