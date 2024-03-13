#include <OutNeuron.hpp>
#include <iostream>
#include <constants.hpp>

OutNeuron::OutNeuron()
{}

OutNeuron::OutNeuron(int i) 
{
	this->id = (enum OutputActions)i;
	this->activation = -2;
	this->bias = randisimoFloat(5, 23);
	if (bias < 0)
		bias *= -1;
	this->weight = randisimoFloat(0, 4);
	if (rand() % 2)
		this->weight *= -1;

}


void	OutNeuron::display()
{
	std::cout << "##OUTPUT NEURON##" << std::endl;
	std::cout << "Type : " << id << std::endl;
	std::cout << "Native weight : " << weight << std::endl;
	std::cout << "bias : " << bias << std::endl;
	std::cout << "activation: " << activation << std::endl;
}



OutNeuron::~OutNeuron()
{
}
