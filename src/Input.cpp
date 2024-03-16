#include <Input.hpp>
#include <constants.hpp>


Input::Input(enum InputType i, Neuron *n)
{
	int	y = 0;

	id = i;
	while (y < NEURONS)
	{
		y++;

	}

}

Input::Input(Input *i)
{
	id = i->getId();
	input = i->getInput();
	int	y = 0;
	while (y < NEURONS)
	{
		weight[y] = i->getWeights(y);
		y++;
	}
	neurons = new Neuron(i->getNeurons());
	out = new OutNeuron(i->getOut());
}

void	Input::ClasifyInput(Creature *cr)
{
	if (this->id == PX)
		this->input = cr->getX();
	else if (this->id == PY)
		this->input = cr->getY();
	else if (this->id == MADNESS)
		this->input = randisimoFloat(0, 6);
	else if (this->id == SURVIVAL)
		this->input = randisimoFloat(0, 6);
}


void	Input::setOut(OutNeuron *outi)
{
	out = outi;
}

void	Input::setNeuron(Neuron *n)
{
	neurons = n;
}


Neuron *Input::getNeurons()
{
	return this->neurons;
}

OutNeuron	*Input::getOut()
{
	return this->out;
}

Input::Input(int i, Creature *cr)
{
	int y = 0;
	id = (enum InputType) i;
	input = randisimoFloat(0, 5);
	while (y < NEURONS)
		weight[y++] = randisimoFloat(0, 4);
	y = 0;
	while (y < OUTPUT_NEURONS)
		outWeight[y++] = randisimoFloat(0, 4);
	this->ClasifyInput(cr);

}

float	Input::getWeights(int n)
{
	return weight[n];
}

float	Input::getOutWeights(int n)
{
	return outWeight[n];
}

Input::~Input()
{}

void	Input::display()
{
	std::cout << "id : " << id << std::endl;
	std::cout << "input : " << input << std::endl;
	int i = 0;
	while (i < NEURONS)
		neurons[i++].display();
}


float	Input::getInput()
{
	return this->input;
}
