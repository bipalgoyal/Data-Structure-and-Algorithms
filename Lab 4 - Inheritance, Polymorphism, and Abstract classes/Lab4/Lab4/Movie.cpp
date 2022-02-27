#include "Movie.h"

void Movie::Play()
{
	cout << "Opening Credits: " << credits << endl;
}

void Movie::SetCredits(string credits)
{
	this->credits = credits;
}

string Movie::GetCredits()
{
	return credits;
}
