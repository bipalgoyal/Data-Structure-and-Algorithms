#include <iostream>
#include "ComplexNumber.h"
#include <math.h>

using namespace std;

ComplexNumber::ComplexNumber()
{
	real = 0;
	imaginary = 0;
}

ComplexNumber::ComplexNumber(double real, double imaginary, bool isCartesian)
{
	this->real = real;
	this->imaginary = imaginary;
}

ComplexNumber::ComplexNumber(double length, double angle)
{
	real = length * cos(angle);
	imaginary = length * sin(angle);
}

void ComplexNumber::Print()
{
	cout <<endl << "Complex Number (in Rectangular form): " << real << " + " << imaginary << "i" << endl;
	cout << "Complex Number (in Polar form): (" << this->GetPolarLength() << ", " << this->GetPolarAngle() << ")" << endl;
}

double ComplexNumber::GetPolarLength()
{
	return sqrt((real * real) + (imaginary * imaginary));

}

double ComplexNumber::GetPolarAngle()
{
	if (this->imaginary == 0) {
		return 0;
	}
	else if (this->real == 0) {
		return 1.5708;
	}
	else {
		return atan(imaginary / real);
	}
}

double ComplexNumber::GetReal()
{
	return real;
}
void ComplexNumber::SetReal(double real)
{
	this->real = real;
}

double ComplexNumber::GetImaginary()
{
	return imaginary;
}
void ComplexNumber::SetImaginary(double imaginary)
{
	this->imaginary = imaginary;
}

void ComplexNumber::operator+(ComplexNumber number)
{
	this->real += number.GetReal();
	this->imaginary += number.GetImaginary();
}

void ComplexNumber::operator-(ComplexNumber number)
{
	this->real -= number.GetReal();
	this->imaginary -= number.GetImaginary();
}

ComplexNumber ComplexNumber::operator*(ComplexNumber number)
{
	ComplexNumber result;
	result.SetReal((this->real * number.GetReal()) - (this->imaginary * number.GetImaginary()));
	result.SetImaginary((this->real * number.GetImaginary()) + (this->imaginary * number.GetReal()));
	return result;
}

ComplexNumber ComplexNumber::operator/(ComplexNumber number)
{
	double real = ((this->real * number.GetReal()) + (this->imaginary * number.GetImaginary())) / pow(number.GetPolarLength(), 2);
	double imaginary = (-(this->real * number.GetImaginary()) + (this->imaginary * number.GetReal())) / pow(number.GetPolarLength(), 2);
	ComplexNumber result(real, imaginary, true);
	return result;
}

bool ComplexNumber::operator==(ComplexNumber number)
{
	if (this->real == number.GetReal() && this->imaginary == number.GetImaginary())
	{
		return true;
	}
	else
	{
		return false;
	}
}
 