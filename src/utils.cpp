#include <Network.hpp>

float	randomFloat(float min, float max)
{
	float distance = ((rand() % (int)(max - min)) / (max - min) + ((float)(rand() % (int)max) - 1));
	if (rand()  % 2 == 0)
		distance *= -1;
	return (distance);
}

float	randisimoFloat(float min, float max)
{
	if (min == 0.0 && max == 1.0)
		return (randomFloat(0, 100) / 100);

		
	float pivote =(float) (rand() % (int)(max - min) - 1);
	float neoMin = (min == 0) ?  pivote :  (pivote + (float)(rand() % (int)min));
	float random =  neoMin + randomFloat(0, 100) / 100;

	return random;
}

float sigmoid(float x)
{
    return 1.0 / (1.0 + exp(-x));
}

