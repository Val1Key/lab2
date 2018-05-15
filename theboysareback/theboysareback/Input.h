#pragma once
#include<fstream>
#include<iostream>
using namespace std;

template<class T>
bool InputSize(T &size)
{
	ifstream my_cin("CON");
	while (!(my_cin >> size))
	{
		cout << "Ошибка ввода! Повторите еще раз\n";
		my_cin.clear();
		while (my_cin.get() != '\n') continue;
	}
	if (size < 1 || size>1000) {
		cout << "Ошибка размера массива!\nВведите размер в диапазоне 1<=размер<=1000\n";
		return true;
	}
	return false;
}

template<class T>
void Check_input(T& num)
{
	ifstream my_inp("CON");
	while (!(my_inp >> num)) {
		cout << "Ошибка ввода! Повторите еще раз\n";
		my_inp.clear();
		while (my_inp.get() != '\n') continue;
	}
}

template<class T>
int Set_size(T size_1, T size_2) { return (size_1 + size_2) / 2; }