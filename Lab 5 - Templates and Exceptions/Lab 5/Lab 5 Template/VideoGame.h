#pragma once
#include <string>
#ifndef VIDEOGAME_H
#define VIDEOGAME_H

using namespace std;

class VideoGame
{
private:
	string title;
	string description;
public:
	VideoGame();
	VideoGame(string, string);

	virtual void Play();

	void Details();

	void SetTitle(string);
	string GetTitle();

	void SetDescription(string);
	string GetDescription();
};

#endif

