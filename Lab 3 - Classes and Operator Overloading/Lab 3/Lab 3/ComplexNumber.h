#pragma once
#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

class ComplexNumber
{
private:
	double real;
	double imaginary;
public:
	ComplexNumber();
	ComplexNumber(double, double, bool);
	ComplexNumber(double, double);

	void Print();
	double GetPolarLength();
	double GetPolarAngle();

	double GetReal();
	void SetReal(double);

	double GetImaginary();
	void SetImaginary(double);

	void operator +(ComplexNumber);
	void operator -(ComplexNumber);
	
	ComplexNumber operator *(ComplexNumber);
	ComplexNumber operator /(ComplexNumber);
	
	bool operator ==(ComplexNumber);

};

#endif