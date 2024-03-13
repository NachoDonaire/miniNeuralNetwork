#ifndef NEURON_HPP
#define NEURON_HPP

#include <OutNeuron.hpp>

class Neuron
{
	private:
		unsigned	id;
		OutNeuron	*out;
		float		bias;
		float		activation;
 	public:
    		Neuron();
		void	setOut(OutNeuron *o);
		void	display();
    		Neuron(int i);
    		~Neuron();
};

#endif
