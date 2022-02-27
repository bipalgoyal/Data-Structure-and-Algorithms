#include "Player.h"
#include <iostream>
Player::Player()
{
	total = 0;
	wheel = Wheel();
}
Player::Player(int total, int minValue, int maxValue)
{
	this->total = total;
	wheel.SetMinValue(minValue);
	wheel.SetMaxValue(maxValue);
}
void Player::PlayRound()
{
	int bet, betChange;
	cout << endl << "New Round Begins!" << endl;
	cout << "Enter your bet for this round (must be lower than your current total): ";
	cin >> bet;
	if (bet > this->total) {
		cout << "Error! Bet can't be greater than total!" << endl;
		return;
	}
	int playerSpin = wheel.Spin();
	cout << endl << "Player has rolled #" << playerSpin << endl;
	cout << "Would you like to change your bet?" << endl;
	cout << "1. None" << endl;
	cout << "2. Double wager" << endl;
	cout << "3. Halve wager" << endl;
	cout << "Enter your choice (1 to 3): ";
	cin >> betChange;
	if (betChange == 1) {
		cout << "Standard wager! " << endl;
		int houseSpin = wheel.Spin();
		cout << "House has rolled #" << houseSpin << endl;
		if (playerSpin > houseSpin) {
			cout << "Player's roll is higher. Player wins this wager";
			this->total += bet;
		}
		else {
			cout << "Player's roll is lower. House wins this wager";
			this->total -= bet;
		}
	} 
	else if (betChange == 2) {
		cout << "Double Wager" << endl;
		int houseSpinA = wheel.Spin();
		cout << "House has rolled #" << houseSpinA << endl;
		if (houseSpinA >= playerSpin) {
			cout << "House rolls higher than Player. House wins the double wager" << endl;
			this->total -= 2 * bet;
		}
		else {
			int houseSpinB = wheel.Spin();
			cout << "House has rolled #" << houseSpinB << endl;
			if (houseSpinB >= playerSpin)
			{
				cout << "House rolls higher than Player. House wins the double wager" << endl;
				this->total -= 2 * bet;
			}
			else {
				cout << "Player rolls are bigger than both of house rolls. Player wins the double wager" << endl;
				this->total += 2 * bet;
			}
		}
	}
	else if (betChange == 3) {
		cout << "Half Wager" << endl;
		int houseSpinA = wheel.Spin();
		cout << "House has rolled #" << houseSpinA << endl;
		int houseSpinB = wheel.Spin();
		cout << "House has rolled #" << houseSpinB << endl;
		if (houseSpinA >= playerSpin && houseSpinB >= playerSpin) {
			cout << "House rolls both higher than Player. House wins the half wager" << endl;
			this->total -= 0.5 * bet;
		}
		else if (houseSpinA < playerSpin && houseSpinB < playerSpin) {
			cout << "Player rolls both higher than House. Player wins the half wager" << endl;
			this->total += 0.5 * bet;
		}
		else {
			cout << "No body wins half wager." << endl;
		}
	}
}
void Player::SetTotal(int total)
{
	this->total = total;
}

int Player::GetTotal()
{
	return total;
}
