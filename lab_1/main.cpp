#include <iostream>
#include "Prog1.h"
using namespace Prog1;
// основная функция
int main()
{
	Line* arr = nullptr; // исходный массив
	int m,stroka; // количество строк в матрице
	double res; // полученый результат

	arr = input(m); //ввод матрицы
	if (!arr) {
		std::cout << "incorrect data" << std::endl;
		return 1;
	}
	if (minmax(arr, m, res,stroka)) { // вычисление требуемого результата
		std::cout << "Error in allocate memory" << std::endl;
		erase(arr, m);
		return 1;
	}
	std::cout << std::endl;
	output("Sourced matrix", arr, m);
	vector("Sourced vector", arr, stroka);
	std::cout << "Result: " << res << std::endl;
	erase(arr, m); // освобождение памяти
	return 0;
}