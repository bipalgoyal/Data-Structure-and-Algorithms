#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Book
{
	string title;
	string firstName;
	string lastName;
	int wordCount;
	int letterFrequency[26];
	int lineCount;
};

int main()
{
	bool wantsToContinue = false;
	do {
		string fileName;
		ifstream readFromFile;
		string line;
		Book book = { "", "", "", 0, {}, 0 };
		string content;
		ofstream writeToFile;
		int totalCharacters = 0;
		bool seeLetterFrequency;

		// Name of file and confirm it opens
		do {
			cout << "Enter name of file to be processed: ";
			cin >> fileName;
			readFromFile.open(fileName);
			if (!readFromFile.is_open())
			{
				cout << "Error, enter new filename." << endl;
			}
		} while (!readFromFile.is_open());

		// Get title and author
		getline(readFromFile, book.title);
		readFromFile >> book.firstName;
		readFromFile >> book.lastName;
		do {
			getline(readFromFile, line);
		} while (line.find("Contents") != -1);

		// Read through content
		while (getline(readFromFile, line))
		{
			if (line != "")
			{
				content += line;
				book.lineCount += 1;
				book.wordCount += 1;
				for (int i = 0; i < line.length(); i++)
				{
					if (line[i] == ' ')
					{
						book.wordCount += 1;
					}
				}
			}
		}

		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < content.length(); j++) {
				if (content[j] == i + 97 || content[j] == i + 65) {
					book.letterFrequency[i]++;
					totalCharacters++;
				}
			}
		}
		writeToFile.open("CardCatalog.txt", ios::app);
		writeToFile << "Title: " << book.title << endl;
		writeToFile << "Full Author: " << book.firstName + " " + book.lastName << endl;
		writeToFile << "Author First Name: " << book.firstName << endl;
		writeToFile << "Author Last Name: " << book.lastName << endl;
		writeToFile << "Word Count: " << book.wordCount << endl;
		writeToFile << "Line Count: " << book.lineCount << endl;

		writeToFile.close();
		readFromFile.close();

		cout << "See Letter Frequency? (1-yes, 0-no)";
		cin >> seeLetterFrequency;

		if (seeLetterFrequency)
		{
			for (int i = 0; i < 26; i++)
			{
				char c = i + 97;
				double percent = ((double)book.letterFrequency[i] / (double)totalCharacters) * 100;
				cout << c << ": " << percent << "%" << endl;
			}
		}
		cout << "Do you want to process another book? (1-yes, 0-no)";
		cin >> wantsToContinue;
	} while (wantsToContinue);

	return 0;
}