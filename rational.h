#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

using namespace std;

class Rational
{
    public:
    Rational();
    Rational(int numerator, int denominator);
    Rational(int numerator);
    Rational(Rational &a);


    int numerator_;
    int denominator_;


    int getNumerator();
    int getDenominator();
    void simplify();

    void add(Rational &other);
    void sub(Rational &other);
    void mul(Rational &other);
    void div(Rational &other);
    void less(Rational &other);
    void neg(Rational &other);
    void print(Rational r);

    Rational operator+(Rational &other);
    Rational operator-(Rational &other);
    Rational operator+(Rational &other, Rational &other2);


    Rational operator-(Rational &other, Rational &other2);

    Rational operator*(Rational &other, Rational &other2);

    Rational operator/(Rational &other, Rational &other2);



};

#endif
