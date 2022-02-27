#include <iostream>
#include "Show.h"
#include "TV.h"
#include "Movie.h"
using namespace std;

void CallShowDetailsAndPlay(Show *);
void CallShowDetailsAndPlay(Show);


int main() 
{
	int choice;
	do {
		int option;
		cout << "Here are your options: " << endl;
		cout << "1. Show Instance" << endl;
		cout << "2. Movie Instance" << endl;
		cout << "3. TV Show Instance" << endl;
		cout << "4. Movie declared as Show Instance" << endl;
		cout << "5. TV Show declared as Show Instance" << endl;
		cout << endl << "Please enter your choice (1 to 5): ";
		cin >> option;
		if (option == 1) {
			Show show("Pokemon", "An anime series");
			show.Details();
			show.Play();
			CallShowDetailsAndPlay(show);
		}
		else if (option == 2) {
			Movie movie;
			movie.SetTitle("Avengers");
			movie.SetDescription("A action movie based in the MCU");
			movie.SetCredits("Sample credits for avengers");
			movie.Details();
			movie.Play();
			CallShowDetailsAndPlay(movie);
		}
		else if (option == 3) {
			TV tv;
			tv.SetTitle("Sample TV Show");
			tv.SetDescription("Sample Description");
			tv.Details();
			tv.Play();
			CallShowDetailsAndPlay(tv);
		}
		else if (option == 4) {
			Show* movie = new Movie();
			movie->SetTitle("Avengers");
			movie->SetDescription("A action movie based in the MCU");
			movie->Details();
			movie->Play();
			CallShowDetailsAndPlay(movie);
		}
		else if (option == 5) {
			Show* tv = new TV();
			tv->SetTitle("Sample TV Show");
			tv->SetDescription("Sample Description");
			tv->Details();
			tv->Play();
			CallShowDetailsAndPlay(tv);
		}
		cout << "Do you want to continue from start again (1 for yes, 0 for no)? ";
		cin >> choice;
		cout << "------------------------------------------" << endl << endl;
	} while (choice);
	return 0;
}

void CallShowDetailsAndPlay(Show *show) {
	cout << endl << "-------Calling from CallShowDetailsAndPlay function----------" << endl;
	show->Details();
	show->Play();
	cout << endl;
}

void CallShowDetailsAndPlay(Show show) {
	cout << endl << "-------Calling from CallShowDetailsAndPlay function----------" << endl;
	show.Details();
	show.Play();
	cout << endl;
}
