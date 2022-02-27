#include "TV.h"

TV::TV()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 10; j++) {
			information[i][j] = "Sample information for season #" + to_string(i + 1) + " episode #" + to_string(j+1);
		}
	}
}

void TV::Play()
{
	int seasonNo, episodeNo;
	cout << "Enter the season number (1 to 4): ";
	cin >> seasonNo;
	cout << "Enter the episode number (1 to 10): ";
	cin >> episodeNo;
	cout << endl;
	cout << "Details of Season #" << seasonNo << " Episode #" << episodeNo << ":" << endl;
	cout << information[seasonNo - 1][episodeNo - 1];
}

void TV::Details()
{
	int seasons = sizeof information / sizeof information[0];
	Show::Details();
	cout << "Number of seasons: " << seasons << endl;
}
