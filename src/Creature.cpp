#include <Creature.hpp>

Creature::Creature(){}

Creature::Creature(int uid)
{
	(void)uid;
	//Initialize creature properties
	int i = 0;
	std::cout << uid << std::endl;
	name = genName();
	live = 1;

	//Initialize position
	pos[0] = randomFloat(0, WIDTH);
	if (pos[0] < 0)
		pos[0] *= -1.0;
	pos[1] = randomFloat(0, HEIGHT) * -1.0;
	if (pos[1] < 0)
		pos[1] *= -1.0;
	//Initialize its inputs and neurons (weights, bias) and output in a random way
	while (i < INPUT_NEURONS)
	{
		in.push_back(Input(i++));
	}


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

Creature::~Creature()
{
}

