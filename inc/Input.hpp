#ifndef INPUT_HPP
#define INPUT_HPP

#include <Neuron.hpp>

enum InputType {
	HOLA,
	HOLA2,
	HOLA3,
	HOLA4,
	HOLA5
};

class Neuron;

class Input
{
	private:
		enum InputType	id;
		Neuron		*neurons;
		//OutputNeuron	*out;
 	public:
    		Input(enum InputType i, Neuron *n);
    		Input(int i);
    		~Input();
};

#endif
