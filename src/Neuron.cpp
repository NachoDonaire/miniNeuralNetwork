#include <Neuron.hpp>
#include <constants.hpp>
#include <iostream>

Neuron::Neuron()
{
}

Neuron::Neuron(int i) : id(i)
{
	bias = randisimoFloat(5, 23);
	if (bias < 0)
		bias *= -1;
	activation = -2;
}

void	Neuron::setOut(OutNeuron *o)
{
	this->out = o;
}

void	Neuron::display()
{
	std::cout << "##NEURON" << std::endl;
	std::cout << "id : " << id;
	std::cout << "bias : " << bias;
	std::cout << "activation : " << activation;
	int	i = 0;
	std::cout << " ---- OUTIN:" << std::endl;
	while (i < OUTPUT_NEURONS)
		out[i++].display();
	std::cout << "  END OF ---- OUTIN:" << std::endl;
}

Neuron::~Neuron()
{
}

