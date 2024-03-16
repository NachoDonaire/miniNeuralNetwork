#ifndef INPUT_HPP
#define INPUT_HPP

#include <Neuron.hpp>
#include <Creature.hpp>
#include <iostream>

enum InputType {
	PX,
	PY,
	MADNESS,
	SURVIVAL
};

class Neuron;
class Creature;

class Input
{
	private:
		enum InputType		id;
		float			input;
		float			weight[NEURONS];
		float			outWeight[OUTPUT_NEURONS];
		Neuron			*neurons;
		OutNeuron		*out;
 	public:
    		Input(enum InputType i, Neuron *n);
    		Input(Input *i);
    		Input(int i, Creature *cr);
		void	setOut(OutNeuron *out);
		void	setNeuron(Neuron *n);
		OutNeuron	*getOut();
		Neuron	*getNeurons();
		void	display();
		void	ClasifyInput(Creature *cr);
		float	getInput();
		float	getWeights(int n);
		float	getOutWeights(int n);
		void	setInput(float f) {input = f;};
		enum	InputType	getId(){return id;};
    		~Input();
};

#endif
