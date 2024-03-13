#ifndef OUTNEURON_HPP
#define OUTNEURON_HPP

enum OutputActions {
	MOVE_EAST,
	MOVE_WEST,
	MOVE_NORTH,
	MOVE_SOUTH,
	MOVE_RANDOM
};

class OutNeuron
{
	private:
		enum OutputActions	id;
		float			weight;
		float			bias;
		float			activation;
 	public:
    		OutNeuron(int i);
    		OutNeuron();
		void	display();
    		~OutNeuron();
};

#endif
