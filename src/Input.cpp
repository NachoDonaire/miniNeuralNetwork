#include <Input.hpp>
#include <constants.hpp>


Input::Input(enum InputType i, Neuron *n)
{
	int	y = 0;

	id = i;
	n = new Neuron[NEURONS];
	while (y < NEURONS)
	{
		y++;

	}

}

Input::Input(int i)
{
	id = (enum InputType) i;

}

Input::~Input()
{}