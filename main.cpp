#include "rational.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{



	int e,f;

	cout << "Enter 1 random integers for : numerator" << endl;
	cin >> e;

	cout << "Enter 1 random integers for : denominator" << endl;
	cin >> f;

	Rational a;
	Rational b(e);
	Rational c(e,f);
	Rational d;


    cout<<"a = ";
    a.print();
	cout << endl;

	cout<<"b = ";
	b.print();
	cout << endl;

	cout<<"c = ";
	c.print();
	cout << endl;

	d = a - c;
	cout << "a - c = ";
	d.print();
	cout << endl;


	d = a + b * c;
	cout << "a + b * c = ";
	d.print();
	cout << endl;

	if(a.less(c))
        cout<<"a is less than c"<<endl;
    else
        cout<<"c is less than a"<<endl;

	return 0;
}
