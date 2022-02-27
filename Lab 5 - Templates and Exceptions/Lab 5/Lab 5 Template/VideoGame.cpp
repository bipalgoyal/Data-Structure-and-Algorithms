#include "VideoGame.h"
#include <iostream>

VideoGame::VideoGame()
{
	title = "";
	description = "";
}

VideoGame::VideoGame(string title, string description)
{
	this->title = title;
	this->description = description;
}

void VideoGame::Play()
{
	cout << "Show doesn't have anything to play, try a movie or TV show." << endl;
}

void VideoGame::Details()
{
	cout << "Title: " << title << endl;
	cout << "Description: " << description << endl;
}

void VideoGame::SetTitle(string title)
{
	this->title = title;
}

string VideoGame::GetTitle()
{
	return title;
}

void VideoGame::SetDescription(string description)
{
	this->description = description;
}

string VideoGame::GetDescription()
{
	return description;
}