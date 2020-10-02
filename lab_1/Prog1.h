#pragma once
namespace Prog1 {
	// ��������� ��� ������� ������ �������
	struct Line {
		int n; // ���������� ��������� � ������
		double* a; // ������ ���������
	};

	// ������ ������� ����� ������ ��������
	template <class T>
	int getNum(T& a)
	{
		std::cin >> a;
		if (!std::cin.good()) // ���������� ������ ����� ��� ����� �����
			return -1;
		return 1;
	}
	// ������� ���������
	inline int isgreater(double a, double b)
	{
		return a > b;
	}
	inline int isless(double a, double b)
	{
		return a < b;
	}
	// ��������� �������
	Line* input(int&); // ���� �������
	void output(const char* msg, Line a[], int m); // ����� �������
	Line* erase(Line*& a, int m); // ������������ ������
	int minmax(Line a[], int m, double&, int& stroka); // ���������� �������� ����������
	double minmax(double a[], int m); // ���������� min/max ��������
	 void vector(const char* msg, Line a[], int stroka);
}