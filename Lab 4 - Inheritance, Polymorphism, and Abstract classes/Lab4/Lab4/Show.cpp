#include "Show.h"

Show::Show()
{
	title = "";
	description = "";
}

Show::Show(string title, string description)
{
	this->title = title;
	this->description = description;
}

void Show::Play()
{
	cout << "Show doesn't have anything to play, try a movie or TV show." << endl;
}

void Show::Details()
{
	cout << "Title: " << title << endl;
	cout << "Description: " << description << endl;
}

void Show::SetTitle(string title)
{
	this->title = title;
}

string Show::GetTitle()
{
	return title;
}

void Show::SetDescription(string description)
{
	this->description = description;
}

string Show::GetDescription()
{
	return description;
}
