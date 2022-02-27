#include "Player.h"
#include "Wheel.h"
#include <iostream>

using namespace std;

int main() 
{
	bool isCashOut = false;
	int startTotal;
	int valueOnWheel;
	cout << "Enter the amount of money you'd like to start with: ";
	cin >> startTotal;
	cout << "Enter the number of values in the wheel (minimum 6, maximum 20): ";
	cin >> valueOnWheel;
	if (!(valueOnWheel >= 6 && valueOnWheel <= 20)) {
		cout << "Error! The number of values in the wheel must be between 6 and 20. Please restart the game." << endl;
		return -1;
	}
	Player player(startTotal, 1, valueOnWheel);
	do {
		player.PlayRound();
		cout << endl << "Your current total is: " << player.GetTotal() << endl;
		if (player.GetTotal() <= 0) {
			cout << "You have lost all money. Game ended";
			return 0;
		}
		cout << "Would you like to cash out (0 - No; 1 - Yes)?";
		cin >> isCashOut;
	} while (isCashOut == false);
	return 0;
}