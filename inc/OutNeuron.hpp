#ifndef OUTNEURON_HPP
#define OUTNEURON_HPP

enum OutputActions {
	MOVE_EAST,
	MOVE_WEST,
	MOVE_NORTH,
	MOVE_SOUTH,
	MOVE_RANDOM, 
	STAY,
	MOVE_CENTER
};

class OutNeuron
{
	private:
		enum OutputActions	id;
		float			weight;
		float			bias;
		float			activation;
		float			sum;
 	public:
    		OutNeuron(int i);
    		OutNeuron();
    		OutNeuron(OutNeuron *o);
		void	setSum(float t);
		void	setActivation(float t){activation = t;};
		void	display();
		enum OutputActions	getId() { return this->id; };
		float	getBias() {return bias;};
		float	getActivation() {return activation;};
    		~OutNeuron();
};

#endif
