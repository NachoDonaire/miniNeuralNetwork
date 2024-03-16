#ifndef NEURON_HPP
#define NEURON_HPP

#include <OutNeuron.hpp>
#include <constants.hpp>

class Neuron
{
	private:
		unsigned	id;
		OutNeuron	*out;
		float		bias;
		float		weights[OUTPUT_NEURONS];
		float		sum;
		float		activation;
 	public:
    		Neuron();
    		Neuron(Neuron *n);
		OutNeuron	*getOut(){return out;};
		void	setOut(OutNeuron *o);
		float	getBias() {return bias;};
		float	getActivation() {return activation;};
		float	getWeights(int n) { return weights[n];};
		void	display();
		void	setSum(float s);
		unsigned	getId() {return id;};
		void	setActivation(float s) {this->activation = s;};
    		Neuron(int i);
    		~Neuron();
};

#endif
