#include "Stack.h"
#include "Queue.h"
#include <fstream>
using namespace std;

int main()
{
	try {
		string wordFromFile;
		string fileName = "test.txt";
		ifstream readFromFile;
		
		//Open your file
		do {
			/*cout << "Enter name of file to be processed: ";
			cin >> fileName;*/
			readFromFile.open(fileName);
			if (!readFromFile.is_open())
			{
				cout << "Error, enter new filename." << endl;
			}
		} while (!readFromFile.is_open());
		
		//Get number of words from file (used to initialize size of queue)
		int count = 0;
		while (readFromFile >> wordFromFile)
		{
			count++;
		}
		readFromFile.close();

		//re-open file to start from beginning again
		readFromFile.open(fileName);

		//Add all words to queue
		Queue<string> queue(count);
		while (readFromFile >> wordFromFile)
		{
			queue.Push(wordFromFile);
		}

		//go through queue to get each word
		while (!queue.IsEmpty()) {
			string data = queue.Pop();

			//declare a stack for each word
			Stack<char> stack(data.length());
			//get each character as an item in the stack
			for (int i = 0; i < data.length(); i++) {
				stack.Push(new char(data[i]));
			}
			//print each word in reverse order
			while (!stack.IsEmpty()) {
				char* ch = stack.Pop();
				cout << *ch;
				delete ch;
			}
			cout << ' ';
		}
	}
	catch (Stack<int>::EmptyStackException) {
		cout << "Empty Stack";
	} 
	catch (Stack<int>::FullStackException) {
		cout << "Full Stack";
	}
	catch (Queue<int>::EmptyQueueException) {
		cout << "Empty Queue";
	}
	catch (Queue<int>::FullQueueException) {
		cout << "Full Queue";
	}
	return 0;
}