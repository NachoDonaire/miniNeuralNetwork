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

Input::Input(int i)
{
	id = (enum InputType) i;

}

Input::~Input()
{}
