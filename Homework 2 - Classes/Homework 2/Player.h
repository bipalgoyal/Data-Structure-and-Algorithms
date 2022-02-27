#pragma once
#include "Wheel.h"
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
	int total;
public:
	Player();
	Player(int, int, int);

	Wheel wheel;
	void PlayRound();
	void SetTotal(int);
	int GetTotal();
};

#endif