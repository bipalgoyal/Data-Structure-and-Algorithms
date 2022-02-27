
#include "EntertainmentCollection.h"
#include "VideoGame.h"

int main()
{
	int choice;
	bool quit = false;
	EntertainmentCollection<VideoGame> games;
	VideoGame tempGame;
	VideoGame* game;
	string title;
	string description;
	do
	{
		cout << "Press 1 to add." << endl
			<< "Press 2 remove." << endl
			<< "Press 3 see how many." << endl
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
				// Add game
				game = new VideoGame();
				cout << "Enter name of game: ";
				getline(cin,title);
				game->SetTitle(title);
				cout << "Enter Description: ";
				getline(cin, description);
				game->SetDescription(description);
				games.Add(game);
				cout << "Added game." << endl;
			}
			catch (EntertainmentCollection<VideoGame>::FullEntertainmentCollection)
			{
				cout << "Error. Full. Cannot add new." << endl;
			}
			break;
		case 2:
			try
			{
				// Remove game
				tempGame = games.Remove();
				cout << "Removed game: " << endl;
				cout << tempGame.GetTitle() << ", " << tempGame.GetDescription() << endl;
			}
			catch (EntertainmentCollection<VideoGame>::EmptyEntertainmentCollection)
			{
				cout << "Error. empty. Nothing to remove." << endl;
			}
			break;
		case 3:
			// See amount of games on shelf
			cout << "Size: " << games.CurrentSize() << endl;
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