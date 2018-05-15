#include "stdafx.h"
#include "Complex.h"
#include <iostream>
#include <math.h>

using namespace std;

#define PI 3.14159

void Complex::Vvod() {
	cout << "¬ведите X: ";
	cin >> x;
	cout << "¬ведите Y: ";
	cin >> y;
	ShowComplex();
}

void Complex::ShowComplex() {
	if (y >= 0) {
		cout << x << "+" << y << "i\n";
	}
	else {
		cout << x << "-" << y << "i\n";
	}
}

double Complex::Modul() {
	return pow(x*x + y*y, 0.5);
}

double Complex::Argument() {
	return atan2(y, x) * 180 / PI;
}