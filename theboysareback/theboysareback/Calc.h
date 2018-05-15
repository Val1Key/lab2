#pragma once

#include <iostream>
#include <math.h> 
#include <conio.h>
using namespace std;
class Calc
{
private:
	int size_of_array;
	float *mas;
	int comparisons;
	void Set_comparisons();
public:
	int Get_size();
	int Get_comparisons();
	Calc(int);
	Calc(const Calc &);
	Calc(const Calc&, const Calc &);

	~Calc();
	friend istream &operator >> (istream&stream, Calc & object);
	friend ostream &operator<<(ostream&stream, Calc & object);

	bool operator == (Calc &);
	bool operator >(Calc &);//количество положителных
	bool operator <(Calc &);
	friend Calc operator-(Calc&, int);
	friend Calc operator+(Calc&, int);
	friend Calc operator *(const Calc&, const Calc&);
	friend  Calc operator /(const Calc&, const Calc&);
	Calc operator=(int);
	Calc operator=(Calc &);
};