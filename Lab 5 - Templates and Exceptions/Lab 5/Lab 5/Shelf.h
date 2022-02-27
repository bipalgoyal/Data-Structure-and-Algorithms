#pragma once
#include "BoardGame.h"
#ifndef SHELF_H
#define SHELF_H

using namespace std;

const int numGames = 10;

class Shelf
{
private:
	BoardGame boardGames[numGames];
	int gamesHeld;
public:
	class FullShelf
	{};
	class EmptyShelf
	{};

	Shelf();

	void AddBoardGame(BoardGame*);
	BoardGame RemoveBoardGame();

	int GetGamesHeld();

	bool IsFull();
	bool IsEmpty();
};

#endif
