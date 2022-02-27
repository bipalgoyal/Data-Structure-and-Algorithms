#include "Player.h"
#include <iostream>
#include <dos.h>
using namespace std;

void DisplayPlayerStats(Player);
int PlayerOptions();
void OppositionHasBall(int&, int&);

int main() {	
	Player players[5];

	players[0].SetName("Adam");
	players[1].SetName("Joey");
	players[2].SetName("Simon");
	players[3].SetName("Chandler");
	players[4].SetName("Jared");

	int teamScore = 0;
	int oppositionScore = 0;
	int noOfPossessions = 1;
	int currentPlayer = rand() % 4;

	cout << "Game starts with Team 1" <<endl;
	cout << "Ball in possession of " << players[currentPlayer].GetName() << endl;
	DisplayPlayerStats(players[currentPlayer]);

	while (noOfPossessions <= 20) {
		int option = PlayerOptions();
		int takeShotResult;
		switch (option) {
			case 1:
				int shot;
				cout << "Enter value of shot (1, 2, or 3): ";
				cin >> shot;
				takeShotResult = players[currentPlayer].TakeShot(shot);
				if (takeShotResult == 0) {
					cout << players[currentPlayer].GetName() << " misses shot." << endl;
					int random50 = rand() % 100 + 1;
					if (random50 <= 50) {
						cout << players[currentPlayer].GetName() << " rebounded the ball" << endl;
						cout << "---------------------------------------" << endl << endl;
					}
					else {
						cout << players[currentPlayer].GetName() << " lost the ball, opposition gets it now" <<endl << endl;
						cout << "---------------------------------------" << endl << endl;
						OppositionHasBall(oppositionScore, noOfPossessions);
					}
				}
				else {
					cout << players[currentPlayer].GetName() << " makes a shot and scores, opposition gets it now" <<endl << endl;
					cout << "---------------------------------------" << endl << endl;
					teamScore = teamScore + takeShotResult;
					OppositionHasBall(oppositionScore, noOfPossessions);
				}
				break;
			case 2:
				int newPlayer;
				if (players[currentPlayer].PassBall()) {
					cout << "Who to pass to (1, 2, 3, 4, 5)?";
					cin >> newPlayer;
					currentPlayer = newPlayer;
					cout << "Ball in possession of " << players[currentPlayer].GetName() << endl;
					DisplayPlayerStats(players[currentPlayer]);
				}
				else {
					cout << "Ball Lost while passing" << endl <<endl;
					cout << "---------------------------------------" << endl << endl;
					OppositionHasBall(oppositionScore, noOfPossessions);
				}
				break;
			case 3:
				for (int j = 0; j < 5; j++) {
					DisplayPlayerStats(players[j]);
				}
				break;
			case 4:
				cout << "Team Score: " << teamScore << endl;
				cout << "Opposition Score: " << oppositionScore << endl;
				cout << "Possession Left: " << 21 - noOfPossessions << endl;
				cout << "---------------------------------------" << endl << endl;
				break;
		}
	}
	cout << "Final Team Score: " << teamScore << endl;
	cout << "Final Opposition Score: " << oppositionScore << endl;
	cout << "Game over!" << endl;
	return 0;
}

void DisplayPlayerStats(Player player) {
	cout << "Current stats of " << player.GetName() << ": " << endl;
	cout << "Shots Taken: " << player.GetShotsTaken() << endl;
	cout << "Shots Made: " << player.GetShotsMade() << endl;
	cout << "Passes Taken: " << player.GetPassesAttempted() << endl;
	cout << "Passes Made: " << player.GetPassesMade() << endl;
	cout << "---------------------------------------" <<endl << endl;
}

int PlayerOptions()
{
	int option;
	cout << "Here are your options: " << endl;
	cout << "1. Shoot" << endl;
	cout << "2. Pass" << endl;
	cout << "3. See Player Stats for entire Team" << endl;
	cout << "4. See current score" << endl;
	cout << "Enter your option: ";
	cin >> option;
	cout << "---------------------------------------" << endl << endl;
	return option;
}

void OppositionHasBall(int &oppositionScore, int &noOfPossessions) {
	cout << "Opposition has ball" << endl;
	bool ballLost = false;
	while (!ballLost) {
		cout << "Opposition takes shot" << endl;
		int random60 = rand() % 100 + 1;
		if (random60 <= 60) {
			cout << "Opposition made the shot, increasing score by 1." << endl;
			oppositionScore++;
			ballLost = true;
		}
		else {
			cout << "Opposition missed the shot." << endl;
			int random50 = rand() % 100 + 1;
			if (random50 <= 50) {
				cout << "Opposition rebounded the ball" << endl;
			}
			else {
				cout << "Ball transferred to other team" << endl;
				ballLost = true;
			}
		}
	}
	cout << "---------------------------------------" << endl << endl;
	noOfPossessions++;
}

