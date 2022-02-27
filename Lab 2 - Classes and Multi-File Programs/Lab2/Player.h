#pragma once

#include <string>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H


class Player {
	private:
		string name;
		unsigned int shotsTaken;
		unsigned int shotsMade;
		unsigned int passesAttempted;
		unsigned int passesMade;
	public:
		bool PassBall();
		int TakeShot(int);

		string GetName();
		void SetName(string);

		unsigned int GetShotsTaken();
		unsigned int GetShotsMade();
		unsigned int GetPassesAttempted();
		unsigned int GetPassesMade();

		Player();

};
#endif