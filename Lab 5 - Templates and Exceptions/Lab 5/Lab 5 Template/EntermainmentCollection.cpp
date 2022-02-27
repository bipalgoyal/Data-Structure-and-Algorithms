#include "EntertainmentCollection.h"

EntertainmentCollection::EntertainmentCollection()
{
	gamesHeld = 0;
}

void EntertainmentCollection::AddBoardGame(BoardGame* boardGame)
{
	if (IsFull())
	{
		throw FullShelf();
	}
	boardGames[gamesHeld] = *boardGame;
	gamesHeld += 1;
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
