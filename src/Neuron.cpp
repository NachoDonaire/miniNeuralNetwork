#include <Neuron.hpp>
#include <constants.hpp>
#include <iostream>

Neuron::Neuron()
{
}

Neuron::Neuron(int i) : id(i)
{
	int y = 0;

	bias = randisimoFloat(5, 23);
	if (bias < 0)
		bias *= -1;
	activation = -2;
	while (y < OUTPUT_NEURONS)
		weights[y++] = randisimoFloat(0, 4);
	//weight = randisimoFloat(0, 4);
}

Neuron::Neuron(Neuron *n)
{
	id = n->getId();
	out = new OutNeuron(n->getOut());
	bias = n->getBias();
	int i = 0;
	while (i < OUTPUT_NEURONS)
	{
		weights[i] = n->getWeights(i);
		i++;
	}
	sum = 0;
	activation = -2;
}

void	Neuron::setOut(OutNeuron *o)
{
	this->out = o;
}

void	Neuron::setSum(float s)
{
	this->sum = s;
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

