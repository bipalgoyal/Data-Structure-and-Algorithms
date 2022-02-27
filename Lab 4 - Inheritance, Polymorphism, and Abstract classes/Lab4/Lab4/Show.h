#pragma once
#include <string>
#include <iostream>
#ifndef SHOW_H
#define SHOW_H
using namespace std;

class Show
{
private:
	string title;
	string description;
public:
	Show();
	Show(string, string);

	virtual void Play();

	void Details();

	void SetTitle(string);
	string GetTitle();

	void SetDescription(string);
	string GetDescription();
};

#endif