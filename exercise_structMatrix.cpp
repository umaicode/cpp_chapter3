// matrixMultiplication.cpp - 2���� ����� struct���� ���� 
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
// ���� ��Ŀ� ���Ͽ�add, sub, mult, transpose �����ϴ� �ڵ�
struct Matrix {
	int rows;
	int cols;
	int* Term;
};

int getData(struct Matrix* a);
int showData(struct Matrix* a);// ��� ���: A[rows][cols] ���
void add(struct Matrix*, struct Matrix*, struct Matrix*);
void transpose(struct Matrix*, struct Matrix*);
bool multiply(struct Matrix*, struct Matrix*, struct Matrix*);
void free(struct Matrix*);

int getData(struct Matrix* a) {
	int rows = a->rows; int cols = a->cols;
	a->Term = (int*)calloc(rows * cols, sizeof(int));

	return 0;
}
int showData(struct Matrix* a) {
	int rows = a->rows; int cols = a->cols;

	return 1;
}
void add(struct Matrix* a, struct Matrix* b, struct Matrix* c) {
	if (a->rows != b->rows || a->cols != b->cols) {
		printf("a, b�� incompatiable matrix\n");
		return;
	}

	return;

}
//*
void transpose(struct Matrix* a, struct Matrix* a1) {


}
bool multiply(struct Matrix* a, struct Matrix* b, struct Matrix* c) {
	if (a->cols != b->rows) {
		printf("incompatible matrices");
		return false;
	}
	struct Matrix bXpose = { b->cols, b->rows };
	getData(&bXpose);
	transpose(b, &bXpose);
	showData(&bXpose);


	free(&bXpose);
	return true;
}
void free(struct Matrix* m) {
	
}
//*/
int main()
{
	struct Matrix a = { 2,3,0 }, b = { 2,3,0 }, c = { 2,3,0 }, d = { 3,4,0 }, e = { 2,4,0 };
	srand(time(NULL));
	printf("matrix a[2][3]�� �Է�: \n");
	getData(&a);
	showData(&a);
	printf("matrix b[2][3]�� �Է�: \n");
	getData(&b);
	showData(&b);
	getData(&c);
	add(&a, &b, &c);
	showData(&c);
	printf("matrix d[3][4]�� �Է�: \n");
	getData(&d);
	showData(&d);
	//*
	getData(&e);
	multiply(&a, &d, &e);
	showData(&e);
	free(&a); free(&b); free(&c); free(&d); free(&e);
	//*/
	system("pause");
	return 0;
}

