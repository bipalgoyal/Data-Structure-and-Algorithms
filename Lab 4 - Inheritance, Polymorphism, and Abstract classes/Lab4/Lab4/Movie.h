#pragma once
#include "Show.h"
#ifndef MOVIE_H
#define MOVIE_H
class Movie : public Show
{
private:
	string credits;
public:
	void Play();

	void SetCredits(string);
	string GetCredits();

};
#endif

