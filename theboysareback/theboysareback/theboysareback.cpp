#include "stdafx.h"
#include<iostream>
#include<locale.h>
#include<conio.h>
#include"Calc.h"
#include"Input.h"
#include<time.h>

using namespace std;

char* message = "Нажмите любую клавишу для продолжения или ESC для выхода";
char* res = "";

int Input_arrays() {
	try {
		int size;

		srand((unsigned)time(NULL));
		//Массив А
		cout << "Введите размер массива А ==> ";
		while (InputSize(size));
		cout << "Вы ввели массив А размером ==> " << size << endl;
		Calc mas_a(size);
		cin >> mas_a;
		cout << mas_a;
		//Массив B
		cout << "Введите размер массива B ==> ";
		while (InputSize(size));
		cout << "Вы ввели массив B размером ==> " << size << endl;
		Calc mas_b(size);
		cin >> mas_b;
		cout << mas_b;

		Calc mas_x(Set_size(mas_a.Get_size(), mas_b.Get_size()));
		Calc mas_prom_res(Set_size(mas_a.Get_size(), mas_b.Get_size()));

		if (mas_a == mas_b)
		{
			res = "\t\t\t\t-25";
			cout << res << endl;
#ifdef _DEBUG
			cout << "===============================Массив А == массив B=============================\n";
			cout << res << endl;
#endif // _DEBUG
			mas_x = -25;
		}
		else 
		{
			if (mas_a < mas_b)
			{
				res = "\t\t\t\t(B^3-5)/A";
#ifdef _DEBUG
				cout << "===============================Массив А < массива B=============================\n";
				cout << res << endl;
#endif // _DEBUG
				mas_x = ((mas_b * mas_b * mas_b) - 5) / mas_a;
				res = "\t\t\t\t(B^3-5)/A";
#ifdef _DEBUG
				cout << "----------------------------Промежуточные вычисления----------------------------\n";
				mas_prom_res = ((mas_b * mas_b * mas_b) - 5);
				cout << "B^3-5 = " << mas_prom_res;
				cout << "--------------------------------------------------------------------------------\n";
#endif // _DEBUG

			}
			else
			{
				res = "\t\t\t\tA/B-1";

#ifdef _DEBUG
				cout << "===============================Массив А > массива B=============================\n";
				cout << res << endl;
				cout << "\n================================================================================\n";
#endif // _DEBUG

				mas_x = (mas_a / mas_b) - 1;

#ifdef _DEBUG
				cout << "----------------------------Промежуточные вычисления----------------------------\n";
				mas_prom_res = mas_a / mas_b;
				cout << "A/B = " << mas_prom_res;
				cout << "--------------------------------------------------------------------------------\n";
#endif // _DEBUG
			}
		}
		cout << "Результат ==> " << res;
		cout << "\nРазмер массива Х ==> " << mas_x.Get_size();
		cout << mas_x;
	}
	catch (char* ex) {
		cout << ex << endl;
	}
	cout << message;
	return (_getch());
}

int main()

{
	setlocale(LC_ALL, "Russian");
	int test_num = 0;
	const int ESC = 27;
	int exit_;
	do {
#ifdef _DEBUG
		cout << "\n\t\t\tПрограмма запущена в режиме DEBUG";
#endif // _DEBUG

		cout << "\n====================================Тест #" << ++test_num << "=====================================" << endl;
		cout << "\n\t\t\t\t    Вариант №5" << endl;
		cout << "   \t\t\t\t------------------" << endl;
		cout << "   \t\t\t\t|A/B-1,если A>B    |" << endl;
		cout << "\t\t\tX   =   |-25,если A=B      |" << endl;
		cout << "   \t\t\t\t|(B^3-5)/A,если A<B|" << endl;
		cout << "   \t\t\t\t------------------" << endl;

		exit_ = Input_arrays();
	} while (exit_ != ESC);
	return 0;
}