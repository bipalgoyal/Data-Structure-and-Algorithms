#include "Player.h"
#include <stdlib.h>
#include <string>

//documentation in lab file
bool Player::PassBall()
{
	int randomNo = rand() % 100 + 1;
	float succesfulPasses;
	if (this->passesMade == 0 || ((float)this->passesMade / (float)this->passesAttempted) == 1) {
		succesfulPasses = 50;
	}
	else {
		succesfulPasses = ((float)this->passesMade / (float)this->passesAttempted) * 100;
	}
	this->passesAttempted++;
	if (randomNo > succesfulPasses) {
		return false;
	}
	else {
		this->passesMade++;
		return true;
	}
}


int Player::TakeShot(int shot)
{
	int randNo = rand() % 100 + 1;
	float succesfulShots;
	if (this->shotsMade == 0 || (((float)this->shotsMade / (float)this->shotsTaken) * 100) == 100) {
		succesfulShots = 50;
	}
	else {
		succesfulShots = ((float)this->shotsMade / (float)this->shotsTaken) * 100;
	}
	switch (shot) {
		case 1:
			randNo = rand() % 80 + 1;
			break;
		case 2:
			randNo = rand() % 100 + 1;
			break;
		case 3:
			randNo = rand() % 120 + 1;
			break;
	}
	this->shotsTaken++;
	if (randNo < succesfulShots) {
		this->shotsMade++;
		return shot;
	}
	else {
		return 0;
	}
}

string Player::GetName()
{
	return this->name;
}

void Player::SetName(string name)
{
	this->name = name;
}

unsigned int Player::GetShotsTaken()
{
	return this->shotsTaken;
}

Player::Player()
{
	this->name = "";
	this->passesAttempted = 0;
	this->passesMade = 0;
	this->shotsMade = 0;
	this->shotsTaken = 0;
}

unsigned int Player::GetShotsMade()
{
	return this->shotsMade;
}

unsigned int Player::GetPassesAttempted()
{
	return this->passesAttempted;
}

unsigned int Player::GetPassesMade()
{
	return this->passesMade;
}

