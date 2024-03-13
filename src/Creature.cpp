#include <Creature.hpp>

Creature::Creature(){}

Creature::Creature(int uid)
{
	(void)uid;
	//Initialize creature properties
	int i = 0;
	name = genName();
	live = 1;

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
	while (i < NEURONS)
	{
		n[i] = Neuron(i);
		n[i].setOut(out);
		i++;
	}
	i = 0;
	while (i < INPUT_NEURONS)
	{
		Input why(i);
		why.setOut(out);
		why.setNeuron(n);
		in.push_back(why);
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
}




Creature::~Creature()
{
}

