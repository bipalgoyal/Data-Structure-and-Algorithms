#include <iostream>
#include "ComplexNumber.h"
using namespace std;

int main() {
	int choice;
	double inputReal, inputImaginary;
	bool reRun = true;
	cout << "Input for a complex number" <<endl;
	cout << "Enter the real component of your number: ";
	cin >> inputReal;
	cout << "Enter the imaginary component of your number: ";
	cin >> inputImaginary;
	ComplexNumber primaryComplex (inputReal, inputImaginary, true);
	do {
		cout << endl << "------------------------------------" << endl;
		cout << "Available Options:" << endl;
		cout << "1. Addition" << endl;
		cout << "2. Subtraction" << endl;
		cout << "3. Multiplication" << endl;
		cout << "4. Division" << endl;
		cout << "5. Equality" << endl;
		cout << "6. Exit" << endl;
		cout << "------------------------------------" << endl;
		cout << endl << "Enter your choice: ";
		cin >> choice;
		if (choice >= 1 && choice <= 5) {

			cout <<endl << "------------------------------------" << endl;
			cout << "Input for a complex number" << endl;
			cout << "Enter the real component of your number: ";
			cin >> inputReal;
			cout << "Enter the imaginary component of your number: ";
			cin >> inputImaginary;
		}
		ComplexNumber secondaryComplex(inputReal, inputImaginary, true);
		ComplexNumber result;
		switch (choice) {
		case 1:
			primaryComplex + secondaryComplex;
			cout <<endl << "------------------------------------" << endl;
			cout << "Results of Addition: ";
			primaryComplex.Print();
			break;
		case 2:
			primaryComplex - secondaryComplex;
			cout << endl << "------------------------------------" << endl;
			cout << "Results of Subtraction: ";
			primaryComplex.Print();
			break;
		case 3:
			result = primaryComplex * secondaryComplex;
			cout << endl << "------------------------------------" << endl;
			cout << "Results of Multiplication: ";
			result.Print();
			break;
		case 4:
			result = primaryComplex / secondaryComplex;
			cout << endl << "------------------------------------" << endl;
			cout << "Results of Division: ";
			result.Print();
			break;
		case 5:

			cout << endl << "------------------------------------" << endl;
			if (primaryComplex == secondaryComplex) {
				cout << "The complex numbers are equal." <<endl;
			}
			else {
				cout << "The complex numbers are not equal" <<endl;
			}
			break;
		case 6:
			reRun = false;
		}

	} while (reRun);

	double inputLength, inputAngle;
	cout << endl << "------------------------------------" << endl;
	cout <<endl << "Test for polar input" << endl;
	cout << "Input for a complex number" << endl;
	cout << "Enter the length of your number: ";
	cin >> inputLength;
	cout << "Enter the angle (in radians) of your number: ";
	cin >> inputAngle;
	ComplexNumber number(inputLength, inputAngle);
	number.Print();
	return 0;
}