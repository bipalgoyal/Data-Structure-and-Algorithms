#include "BoardGame.h"

BoardGame::BoardGame()
{
	title = "";
	description = "";
}

BoardGame::BoardGame(string title, string description)
{
	this->title = title;
	this->description = description;
}

void BoardGame::Play()
{
	cout << "Show doesn't have anything to play, try a movie or TV show." << endl;
}

void BoardGame::Details()
{
	cout << "Title: " << title << endl;
	cout << "Description: " << description << endl;
}

void BoardGame::SetTitle(string title)
{
	this->title = title;
}

string BoardGame::GetTitle()
{
	return title;
}

void BoardGame::SetDescription(string description)
{
	this->description = description;
}

string BoardGame::GetDescription()
{
	return description;
}