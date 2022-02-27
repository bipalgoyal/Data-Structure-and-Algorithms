#pragma once
#include <string>
#include <iostream>
#ifndef BOARDGAME_H
#define BOARDGAME_H
using namespace std;

class BoardGame
{
private:
	string title;
	string description;
public:
	BoardGame();
	BoardGame(string, string);

	virtual void Play();

	void Details();

	void SetTitle(string);
	string GetTitle();

	void SetDescription(string);
	string GetDescription();
};

#endif
