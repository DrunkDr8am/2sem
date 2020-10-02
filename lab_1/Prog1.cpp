#include <iostream>
#include "Prog1.h"
namespace Prog1 {
	// функция ввода
	Line* input(int& rm)
	{
		const char* pr = ""; // будущее сообщение об ошибке
		Line* lines = nullptr; // динамический массив строк матрицы
		int m; // количество строк матрицы
		// сначала вводим количество строк
		do {
			std::cout << pr << std::endl;
			std::cout << "Enter number of lines: --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(m) < 0) // обнаружена ошибка ввода или конец файла
				return nullptr;
		} while (m < 1);
		// выделяем память под массив структур - строк матрицы
		try {
			lines = new Line[m];
		}
		catch (std::bad_alloc& ba)
		{
			std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
			return nullptr;
		}
		for (int i = 0; i < m; i++) {
			// теперь для каждой строки матрицы вводим количество столбцов
			pr = "";
			do {
				std::cout << pr << std::endl;
				std::cout << "Enter number of items in line #" << (i + 1) << " --> ";
				pr = "You are wrong; repeat please!";
				if (getNum(lines[i].n) < 0) { // обнаружена ошибка ввода или конец файла
					erase(lines, i); // освобождение памяти, занятой ранее введенными строками
					return nullptr;
				}
			} while (lines[i].n < 1);


			// и выделяем необходимую память под элементы строки
			try {
				lines[i].a = new double[lines[i].n];
			}
			catch (std::bad_alloc& ba)
			{
				std::cout << "------ too many items in matrix: " << ba.what() << std::endl;
				erase(lines, i);
				return nullptr;
			}
			// теперь можно вводить сами элементы данной строки матрицы
			std::cout << "Enter items for matrix line #" << (i + 1) << ":" << std::endl;
			for (int j = 0; j < lines[i].n; j++) {
				if (getNum(lines[i].a[j]) < 0) { // обнаружена ошибка ввода или конец файла
					erase(lines, i + 1); // освобождение памяти, занятой ранее введенными строками
					return nullptr;
				}
			}
		}
		// формируем результат - количество строк в матрице
		rm = m;
		return lines;
	}
	// функция вывода
	void output(const char* msg, Line* a, int m)
	{
		int i, j;
		std::cout << msg << ":\n";
		for (i = 0; i < m; ++i) {
			for (j = 0; j < a[i].n; ++j)
				std::cout << a[i].a[j] << " ";
			std::cout << std::endl;
		}
	}
	void vector(const char* msg, Line a[], int stroka)
	{
		int i, j;
		std::cout << msg << ":\n";
			for (j = 0; j < a[stroka].n; ++j)
				std::cout << a[stroka].a[j] << " ";
	}
	// функция освобождения занятой памяти
	Line* erase(Line*& lines, int m)
	{
		int i;
		for (i = 0; i < m; i++)
			delete[] lines[i].a;
		delete[] lines;
		return nullptr;
	}
	// функция вычисления главного результата
	int minmax(struct Line lines[], int m, double& res, int& stroka)
	{
		double* s = nullptr;
		double g=0;
		try {
			s = new double[m]; // вектор для получения max элементов в строке - по строкам
		}
		catch (std::bad_alloc& ba)
		{
			std::cout << ba.what() << std::endl;
			return 1;
		}
		int i;
		for (i = 0; i < m; i++)
			s[i] = minmax(lines[i].a, lines[i].n);
		for (i = 0; i < m; i++)
		{
			if (s[i] > g)
			{
				g = s[i];
				stroka = i;
			}
		}
		res = g;
		delete[] s;
		return 0;
	}
	// функция вычисления min/max элемента вектора
	double minmax(double a[], int m)
	{
		double res = 0, k = 0;
		int i,j;
		for (j = 0; j < m; ++j)
		{
			res = 0;
			for (i = 0; i < m; ++i)
			{
				if (a[j] == a[i])
				{
					res++;
				}
			}
			if (res >= k)
			{
				k = res;
			}
		}
		return k;
	}
}