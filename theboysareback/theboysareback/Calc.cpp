#include "stdafx.h"
#include<iostream>
#include"Input.h"
#include"Calc.h"
#include "Complex.h"
#include<time.h>
using namespace std;

inline int Rand() {

	int num = -1000 + rand() % 2000;
	return num;
}

Calc::Calc(int _size) :comparisons(0)
{
	size_of_array = _size;
	if (_size == 1) {
		mas = new float;
	}
	else
	{
		mas = new float[_size];
	}
}


Calc::Calc(const Calc &object_1, const Calc &object_2)
{
	if (object_1.size_of_array > object_2.size_of_array)
		this->size_of_array = object_1.size_of_array;
	else
		this->size_of_array = object_2.size_of_array;
	if (this->size_of_array == 1)
	{
		mas = new float;
	}
	else
	{
		mas = new float[this->size_of_array];
	}
}

Calc::Calc(const Calc&object)
{
	this->size_of_array = object.size_of_array;
	this->mas = new float[object.size_of_array];
	for (int i = 0; i < size_of_array; i++)
	{
		mas[i] = object.mas[i];
	}
}

//Деструктор
Calc::~Calc()
{
	if (size_of_array == 1) {
		delete mas;
	}
	else delete[]mas;
}

//Легенда
void Calc::Set_comparisons()
{
	int count = 0;
	for (int i = 0; i < size_of_array; i++) {
		if ((int)mas[i] % 2 == 0) {
			count++;
		}
	}
	this->comparisons = count;
}

int Calc::Get_comparisons()
{
	return this->comparisons;
}

istream & operator >> (istream &stream, Calc& object)
{
	if (object.size_of_array < 10) {
		for (int i = 0; i < object.size_of_array; i++)
		{
			int f = 0, g=0;
			cout << "Ввод элемента #" << i + 1 << "\nНажмите любую клавишу для продолжения или 1 для ввода комплексного числа.\n";
			g = _getch();
			if (g!=49)
			Check_input(object.mas[i]);
			else
			{
				Complex num;
				num.Vvod();
				cout << "Модуль комплексного числа =" << num.Modul() << "\n";
				f = num.Modul();
				object.mas[i] = f;
			}
		}
	}

	else {
		cout << "Выполняется автоматическое заполнение массива==>\n";
		for (int i = 0; i < object.size_of_array; i++)
		{
			object.mas[i] = Rand();
		}
	}
	object.Set_comparisons();
	return stream;
}

ostream & operator<<(ostream & stream, Calc & object)
{
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	for (int i = 0; i < object.size_of_array; i++)
	{
		stream << object.mas[i] << "\t";
	}
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return stream;
}

bool Calc::operator==(Calc &object)
{
	bool res = true;
	if (this->size_of_array == object.size_of_array)
	{
		//for (int i = 0; i < object.size_of_array; i++) {
		//	if (mas[i] != object.mas[i]) {
		//		res = false;
		//	}
		//}
	}
	else { res = false; }
	return res;
}

bool Calc::operator>(Calc &object)
{
	if (size_of_array == 1 && object.size_of_array == 1) {
		return *mas > *object.mas;
	}
	else {
		if (this->size_of_array == object.size_of_array)
		{
			return(Get_comparisons() > object.Get_comparisons());
		}
		else
		{
			//проверка на длину массива
			if (this->size_of_array > object.size_of_array) {
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool Calc::operator< (Calc & object)
{
	if (size_of_array == 1 && object.size_of_array == 1) {
		return *mas < *object.mas;
	}
	else {
		if (this->size_of_array == object.size_of_array)
		{
			return(Get_comparisons() < object.Get_comparisons());
		}
		else
		{
			//проверка на длину массива
			if (this->size_of_array < object.size_of_array) {
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

Calc operator-(Calc&object, int num)
{
	Calc c(object);
	long double check;
	for (int i = 0; i < object.size_of_array; i++)
	{
		check = 1.0*object.mas[i] - num;
		if (check > INT_MAX || check < INT_MIN) {
			throw "Переполнение при вычислении разницы!";
		}
		else
		{
			c.mas[i] = object.mas[i] - num;
		}
	}
	return c;
}

Calc operator+(Calc&object, int num)
{
	Calc c(object);
	long double check;
	for (int i = 0; i < object.size_of_array; i++)
	{
		check = 1.0*object.mas[i] + num;
		if (check > INT_MAX || check < INT_MIN) {
			throw "Переполнение при вычислении суммы!";
		}
		else
		{
			c.mas[i] = object.mas[i] + num;
		}
	}
	return c;
}


Calc operator*(const Calc&object_1, const Calc& object_2)
{
	Calc new_mas(object_1, object_2);
	long double check;

	for (int q = 0, w = 0, k = 0; k < new_mas.size_of_array; q++, w++, k++) {
		if (q == object_1.size_of_array)
			q = 0;
		if (w == object_2.size_of_array)
			w = 0;
		check = 1.0*object_1.mas[q] * object_2.mas[w];

		if (check > INT_MAX || check < INT_MIN)
		{
			throw "Переполнение при вычислении умножения!";
		}
		else
		{
			new_mas.mas[k] = object_1.mas[q] * object_2.mas[w];
		}
	}
	return new_mas;
}

Calc operator/(const Calc&object_1, const Calc& object_2)
{
	Calc new_mas(object_1, object_2);
	long double check;
	for (int i = 0, q = 0, w = 0; i < new_mas.size_of_array; i++, q++, w++)
	{
		if (q == object_1.size_of_array)
			q = 0;
		if (w == object_2.size_of_array)
			w = 0;
		if (object_2.mas[w] == 0)
			throw "Ошибка деления на ноль!";
		check = 1.0*object_1.mas[q] / object_2.mas[w];
		if (check > INT_MAX || check < INT_MIN)
		{
			throw "Переполнение при вычислении деления!";
		}
		else new_mas.mas[i] = object_1.mas[q] / object_2.mas[w];
	}
	return new_mas;
}


Calc Calc::operator=(Calc &object)
{
	for (int i = 0; i < this->size_of_array; i++)
	{
		this->mas[i] = object.mas[i];
	}
	return *this;
}

Calc Calc:: operator=(int num)
{
	Calc new_mas(this->size_of_array);
	for (int i = 0; i < this->size_of_array; i++)
	{
		this->mas[i] = num;
	}
	return *this;
}

int Calc::Get_size() { return this->size_of_array; }