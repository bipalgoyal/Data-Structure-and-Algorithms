#pragma once
#include "Show.h"
#ifndef TV_H
#define TV_H
class TV : public Show
{
private:
	//assume row means season and col means episode
	string information[4][10];
public:
	TV();
	void Play();
	void Details();
};
#endif

