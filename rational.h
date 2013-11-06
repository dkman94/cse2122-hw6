#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

//create the rational class
class Rational
{
    //public methods and variables
public:
//empty constructor
	Rational();
//constructor w/ numerator and denominator
	Rational(int numerator, int denominator);
//constructor with only numerator and denominator equal to 1
	Rational(int numerator);

//getNumerator method
	int getNumerator() const;
//getDenominator method
	int getDenominator() const;
//compare two rationals wether number is less, equal to , or greater than
	int compare(const Rational &other) const;
//print the rational
	void print() ;  // uses default argument

//simply the fraction to lowest terms using gcd function
	void simplify();
//add two rationals
	void add(const Rational &other);
//subtract two rationals
	void sub(const Rational &other);
//multiple two rationals
	void mul(const Rational &other);
//divide two rationals
	void div(const Rational &other);
//find if a rational is less than another
    bool less(const Rational &other);
//find the negative of a rational
	void neg(const Rational &other);
//private variables for the numerator and denominator of the rational
private:
	int numerator_;
	int denominator_;
};


//addition operator
Rational operator+(const Rational & a);
//subtraction operator
Rational operator-(const Rational & a);
//addition of two rationals operator
Rational operator+(const Rational & a, const Rational & b);
//subtraction of two rationals operator
Rational operator-(const Rational & a, const Rational & b);
//multiplication of two rationals operator
Rational operator*(const Rational & a, const Rational & b);
//divison of two two rationals operator
Rational operator/(const Rational & a, const Rational & b);

// relational operators
bool operator<(const Rational & a, const Rational & b);


#endif
