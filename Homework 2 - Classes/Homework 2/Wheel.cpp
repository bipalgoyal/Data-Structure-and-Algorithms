#include "Wheel.h"
#include <stdlib.h>

Wheel::Wheel()
{
	minValue = 1;
	maxValue = 10;
}

int Wheel::Spin()
{
	int validValue = rand() % maxValue + minValue;
	return validValue;

}

void Wheel::SetMinValue(int minValue)
{
	this->minValue = minValue;
}

void Wheel::SetMaxValue(int maxValue)
{
	this->maxValue = maxValue;
}
