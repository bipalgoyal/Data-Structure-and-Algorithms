
#include "Shelf.h"

int main()
{
	int choice;
	bool quit = false;
	Shelf shelf;
	BoardGame tempGame;
	BoardGame *game;
	string title;
	string description;
	do
	{
		cout << "Press 1 to add a board game to the shelf." << endl
			<< "Press 2 remove a board game from the shelf." << endl
			<< "Press 3 see how many board games are currently on the shelf." << endl
			<< "Press 4 to quit." << endl;
		cout << "Choice: ";
		cin >> choice;
		cin.ignore();
		cout << "-------------------------------------" << endl;
		switch (choice)
		{
		case 1:
			try
			{
				// Add board game
				game = new BoardGame();
				cout << "Enter name of game: ";
				getline(cin, title);
				game->SetTitle(title);
				cout << "Enter Description: ";
				getline(cin, description);
				game->SetDescription(description);
				shelf.AddBoardGame(game);
				cout << "Added board game." << endl;
			}
			catch (Shelf::FullShelf)
			{
				cout << "Error. Full Shelf. Cannot add new board game." << endl;
			}
			break;
		case 2:
			try
			{
				// Remove board game
				tempGame = shelf.RemoveBoardGame();
				cout << "Removed board game: " << endl;
				cout << tempGame.GetTitle() << ", " << tempGame.GetDescription() << endl;
			}
			catch (Shelf::EmptyShelf)
			{
				cout << "Error. Shelf is empty. Nothing to remove." << endl;
			}
			break;
		case 3:
			// See amount of board games on shelf
			cout << "Board games currently on shelf: " << shelf.GetGamesHeld() << endl;
			break;
		case 4:
			// Quit
			quit = true;
			break;
		}
		cout << "-------------------------------------" << endl;
	} while (quit == false);

	return 0;
}