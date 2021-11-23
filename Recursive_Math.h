#ifndef _RECURSIVE_MATH_H_
#define _RECURSIVE_MATH_H_

typedef struct _matrix{
int numRows;
int numCols;
int **matrixData;
} Matrix;

double matrixDeterminant(Matrix *matrix);

Matrix *createMatrix(char *filename);

Matrix *matrixAdjunct(Matrix *matrix, int minorRow, int minorCol);

void printMatrix(Matrix *matrix, char *output_filename);

void freeMatrix(Matrix *pMatrix);


#endif