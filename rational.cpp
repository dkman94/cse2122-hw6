//include header file and other things
#include "rational.h"
#include <iostream>
#include <cassert>
#include <stdlib.h>

using namespace std;

// recursively find the greatest common divsor
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b,a % b);
}

//empty constructor equal to 0
Rational::Rational()
{
	numerator_ = 0;
	denominator_ = 1;
}

//constructor with rational equal to numerator
Rational::Rational(int numerator)
{
	numerator_ = numerator;
	denominator_ = 1;
}

//rational number with numerator and denominator. simplify using the simplify function
Rational::Rational(int numerator, int denominator)
{
	numerator_ = numerator;
	denominator_ = denominator;
	simplify();
}

//get the numerator value(private variable) using a get function
int Rational::getNumerator() const
{
	return numerator_;
}

//get the denominator(private variable) using a get function
int Rational::getDenominator() const
{
	return denominator_;
}

//print the rational with numerator/denominator
void Rational::print()
{
	if (denominator_ == 1)
		cout << numerator_;
	else
		cout << numerator_ << "/" << denominator_;
}

//compare two rationals
int Rational::compare(const Rational &other) const
{
//create two ints to store the cross multiplication products
	int r1, r2;
//r1 stores first cross multiplication
	r1 = numerator_ * other.getDenominator();
//r2 stores the second cross multiplication
	r2 = denominator_ * other.getNumerator();
//if the first is less then the second, return -1 because it is less than
	if (r1 < r2)
		return -1;
//return 0 if they are equal
	else if (prod1 == prod2)
		return 0;
//return 1 if the they are equal
	else
		return 1;
}

//function to simplify the rational
void Rational::simplify()
{
//initialize variables to store the numerator, denominator, and gcd
	int a1, a2, g;
//asert that the denominator is not zero or else the rational is not possible
	assert(denominator_ != 0);
//set variables initiailized earlier
	a1 = numerator_;
	a2 = denominator_;
//find gcd using gcd funciton created earlier
	g = gcd(a1,a2);
//divide by the greatest common divisor
	a1 = a1 / g;
	a2 = a2 / g;
//if the denominator is less than zero(is negative) then set the numerator to negative, and the denominator to positive
	if (a2 < 0)
	{
		a2 = -a2;
	    a1 = -a1;
	}
//reset the numerator and denominator values
	numerator_ = a1;
	denominator_ = a2;
}

//add two rationals
void Rational::add(const Rational &other)
{
//use the equation: a/b + c/d = (a*d + b*c) / (b*d)
	numerator_ = numerator_ * other.getDenominator() + denominator_ *other.getNumerator();
	denominator_ = denominator_ * other.getDenominator();
	simplify();
}

//subtract two rationals
void Rational::sub(const Rational & a)
{
//use the equation: a/b - c/d = (a*d - b*c) / (b*d)
	numerator_ = numerator_ * a.getDenominator() - denominator_ * a.getNumerator();
	denominator_ = denominator_ * a.getDenominator();
	simplify();
}

//multiply two rationals
void Rational::mul(const Rational &other)
{
//(a/b) * (c/d) = (a*c) / (b*d)
	numerator_ = numerator_ * other.getNumerator();
	denominator_ = denominator_ * other.getDenominator();
	simplify();
}

//divide two rationals
void Rational::div(const Rational &other)
{
//(a/b) / (c/d) = (a*d) / (c*b)
	numerator_ = numerator_ * other.getDenominator();
	denominator_ = denominator_ * other.getNumerator();
	simplify();
}

//negativize the rationals
void Rational::neg(const Rational &other)
{
//numerator becomes negative, and denominator becomes positive
    numerator_= numerator_*-1;
    denominator_=abs(denominator_);
    simplify();
}

//if it is less than
bool Rational::less(const Rational &other)
{
//find the double ratio values of the rationals
    double ratio1 = double(numerator_)/double(denominator_);
    double ratio2 = double(other.getNumerator())/double(other.getNumerator());
//if 1 is less, then less() is true else false
    if(ratio1 < ratio2)
        return true;
    else
        return false;
}

//plus operator of 1 is just the rational
Rational operator+(const Rational &other)
{
	return other;
}

//minus operator of rational is just the negative of the rational
Rational operator-(const Rational &a)
{
	Rational b(a);
	b.mul(Rational(-1));
	return b;
}

//plus operator of 2 is found by just adding the two
Rational operator+(const Rational &a, const Rational &b)
{
	Rational c(a);
	c.add(b);
	return c;
}

//subtraction operator of the 2 is found by jsut subtracting the two
Rational operator-(const Rational & a, const Rational & b)
{
	Rational c(a);
	c.sub(b);
	return c;
}

//multiplication operator found by multiplity them
Rational operator*(const Rational & a, const Rational & b)
{
	Rational c(a);
	c.mul(b);
	return c;
}

//divide using the divisor operator
Rational operator/(const Rational & a, const Rational & b)
{
	Rational c(a);
	c.div(b);
	return c;
}

//less than operator is found using the compare function
bool operator<(const Rational &r1, const Rational &r2)
{
	return (r1.compare(r2) < 0);
}

/*
bool operator==(const Rational &r1, const Rational &r2)
{
	return (r1.compare(r2) == 0);
}

bool operator<=(const Rational &r1, const Rational &r2)
{
	return (r1.compare(r2) <= 0);
}

bool operator>(const Rational &r1, const Rational &r2)
{
	return (r1.compare(r2) > 0);
}

bool operator>=(const Rational &r1, const Rational &r2)
{
	return (r1.compare(r2) >= 0);
}

bool operator!=(const Rational &r1, const Rational &r2)
{
	return (r1.compare(r2) != 0);
}

*/
