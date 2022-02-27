#pragma once
using namespace std;

#ifndef WHEEL_H
#define WHEEL_H

class Wheel {
	int minValue;
	int maxValue;
public:
	Wheel();
	int Spin();
	void SetMinValue(int);
	void SetMaxValue(int);
};

#endif