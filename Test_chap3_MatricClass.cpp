// matrixMultiplication.cpp - 2���� ����� 1�������� ����, + ���� 
#include <iostream>
using namespace std;
#include <stdlib.h>
#include "time.h"
// ���� ��Ŀ� ���Ͽ�add, sub, mult, transpose �����ϴ� �ڵ�
class Matrix {
public:
	Matrix(int row, int col);
	//~Matrix() { delete[]Term; }
	int GetData();
	Matrix Transpose();
	int Display(); // ��� ���: A[rows][cols] ���
	Matrix Add(Matrix b);
	Matrix Multiply(Matrix b);

private:
	int rows, cols;
	//int Term[rows][cols];
	int* Term;// a[i][j] = i * cols + j
};


int main()
{
	Matrix a(2, 3); Matrix a1(2, 3); Matrix a2(2, 3);
	Matrix b(3, 4);
	Matrix c(2, 4);
	srand(time(NULL));
	cout << "matrix a[2][3]�� �Է�: " << endl;
	a.GetData();
	a.Display();

	cout << "matrix a1[2][3]�� �Է�: " << endl;
	a1.GetData();
	a1.Display();

	a2 = a.Add(a1);
	cout << "a2 = a + a1" << endl;
	a2.Display();

	cout << "matrix b[3][4]�� �Է�: " << endl;
	b.GetData();
	b.Display();

	Matrix d(4, 3);
	d = b.Transpose();
	cout << "Transpose() of Matrix b" << endl;
	d.Display();

	cout << "Multiply of Matrix a,b" << endl;
	c = a.Multiply(b);
	c.Display();

	system("pause");
	return 0;
}

