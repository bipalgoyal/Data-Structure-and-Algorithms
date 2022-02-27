#include "Shelf.h"

Shelf::Shelf()
{
	gamesHeld = 0;
}

void Shelf::AddBoardGame(BoardGame *boardGame)
{
	if (IsFull())
	{
		throw FullShelf();
	}
	boardGames[gamesHeld] = *boardGame;
	gamesHeld++;
}

BoardGame Shelf::RemoveBoardGame()
{
	if (IsEmpty())
	{
		throw EmptyShelf();
	}
	gamesHeld--;
	return boardGames[gamesHeld];
}

int Shelf::GetGamesHeld()
{
	return gamesHeld;
}

bool Shelf::IsFull()
{
	return gamesHeld >= numGames;
}

bool Shelf::IsEmpty()
{
	return gamesHeld == 0;
}
