#include "rational.h"
#include <iostream>
#include <cassert>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a%b);
}


int Rational::getNumerator()
{
    return numerator_;
}

int Rational::getDenominator()
{
    return denominator_;
}

void Rational::simplify()
{
    int a,b,g;
    assert(denominator_ != 0);

    a = numerator_;
    b = denominator_;
    g = gcd(a,b);

    a = a/g;
    b = b/g;
    if(b < 0)
    {
        b = -b;
        a = -a;
    }
    numerator_ = a;
    denominator_ = b;
}

void Rational::print(Rational r)
{
   if (denominator_ == 1)
        cout <<"The Answ. is: "<<numerator_<<endl;
   else
        cout <<"The Answ. is: "<<numerator_<<"/"<<denominator_;
}

void Rational::add(Rational &other)
{
    numerator_ = numerator_*other.getDenominator() + denominator_*other.getNumerator();
    denominator_ = denominator_*other.getDenominator();
    simplify();
}

void Rational::sub(Rational &other)
{
    numerator_ = numerator_*other.getDenominator() - denominator_*other.getNumerator();
    denominator_ = denominator_*other.getDenominator();
    simplify();
}

void Rational::mul(Rational &other)
{
    numerator_ = numerator_*other.getNumerator();
    denominator_ = denominator_*other.getDenominator();
    simplify();
}

void Rational::div(Rational &other)
{
    numerator_ = numerator_*other.getDenominator();
    denominator_ = denominator_*other.getNumerator();
    simplify();
}

Rational operator+(Rational &inp)
{
    return inp;
}

Rational operator+(Rational &i1, Rational &i2)
{
    Rational i3(i1);
    i3.add(i2);
    return i3;
}

Rational operator-(Rational &inp)
{
    //Rational a = Rational(-1);
    Rational i2(inp);
    i2.mul(-1));
    return i2;
}


