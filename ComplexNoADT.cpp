# ifndef COMPLEX_NUMBER_H
# define COMPLEX_NUMBER_H
class ComplexNumber
{
	int real_part;
	int imaginary_part;
public:
	ComplexNumber();
	ComplexNumber(int, int);
	ComplexNumber(const ComplexNumber&);
	ComplexNumber operator+(ComplexNumber&);
	ComplexNumber operator-(ComplexNumber&);
	ComplexNumber operator*(ComplexNumber&);
	void display();
	ComplexNumber& operator++();
	ComplexNumber operator++(int);
	ComplexNumber operator+(int);
};
# endif


//--------------------------------------------------------------
# include <iostream>
using namespace std;
# include "ComplexNumber.h"
ComplexNumber::ComplexNumber()
{
	real_part = 0;
	imaginary_part = 0;
}
ComplexNumber::ComplexNumber(int r, int i)
{
	real_part = r;
	imaginary_part = i;
}
ComplexNumber::ComplexNumber(const ComplexNumber&)
{
	cout << "cpyCons" << this << endl;
}
ComplexNumber ComplexNumber::operator+(ComplexNumber& compNum)
{
	ComplexNumber sum;
	sum.real_part = real_part + compNum.real_part;
	sum.imaginary_part = imaginary_part + compNum.imaginary_part;
	return sum;
}
ComplexNumber ComplexNumber:: operator-(ComplexNumber& compNum)
{
	ComplexNumber diff;
	diff.real_part = real_part - compNum.real_part;
	diff.imaginary_part = imaginary_part - compNum.imaginary_part;
	return diff;
}
ComplexNumber ComplexNumber::operator*(ComplexNumber& compNum)
{
	ComplexNumber multiply;
	multiply.real_part = (real_part * compNum.real_part) - (imaginary_part * compNum.imaginary_part);
	multiply.imaginary_part = (real_part * compNum.imaginary_part) + (imaginary_part * compNum.real_part);
	return multiply;
}

void ComplexNumber::display()
{
	if (imaginary_part > 0)
	{
		cout << real_part << "+" << imaginary_part << "i";
	}
	else
	{
		cout << real_part << imaginary_part << "i";
	}
}
ComplexNumber& ComplexNumber::operator++()
{
	real_part = real_part + 1;
	imaginary_part = imaginary_part + 1;
	return *this;
}
ComplexNumber ComplexNumber::operator++(int)
{
	ComplexNumber x = *this;
	real_part++;
	imaginary_part++;
	return x;
}
ComplexNumber ComplexNumber::operator+(int val)
{
	ComplexNumber sum;
	sum.real_part = real_part + val;
	sum.imaginary_part = imaginary_part + val;
	return sum;
}