#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
public:
	void Vvod();
	double Modul();
	double Argument();

private:
	double x;
	double y;
	void ShowComplex();
};

#endif