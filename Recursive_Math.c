#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Recursive_Math.h"

double matrixDeterminant(Matrix *matrix){
    if (matrix->numRows == 2){
    return (matrix->matrixData[0][0] * matrix->matrixData[1][1]) 
    - (matrix->matrixData[0][1] * matrix->matrixData[1][0]);
    }  
    else {
        double arr[matrix->numRows];
        for (int i = 0; i < matrix->numRows; i++){
            arr[i] = matrix->matrixData[0][i] * matrixDeterminant(matrixAdjunct(matrix, 0, i));
        }
        double sum = 0;
    for (int i = 0; i < matrix->numRows; i++){
        sum += (arr[i] * pow(-1, i));
        
    }
    return sum;
    }
    
}

Matrix *matrixAdjunct(Matrix *matrix, int adjunctRow, int adjunctCol){
    Matrix *Adjunct = malloc(sizeof(Matrix));
    Adjunct->numRows = matrix->numRows - 1;
    Adjunct->numCols = matrix->numCols - 1;
    Adjunct->matrixData = malloc(sizeof(int *) * Adjunct->numRows);
        
    for (int i = 0; i < Adjunct->numRows; i++){
        Adjunct->matrixData[i] = malloc(sizeof(int) * Adjunct->numCols);
    }
    int PassedAdjunctRow = 0; //If == 0, haven't passed adjunct row. If 1, have passed.
    
    for (int i = 0; i < matrix->numRows; i++){
        int PassedAdjunctCol = 0;
        if (i == adjunctRow){
            PassedAdjunctRow = 1;
            continue;
        }
        for (int j = 0; j < matrix->numCols; j++){
            if (j == adjunctCol) {
                PassedAdjunctCol = 1;
                continue;
            }
            Adjunct->matrixData[i - PassedAdjunctRow][j - PassedAdjunctCol]
            = matrix->matrixData[i][j];
        }
    }
    return Adjunct;
}

Matrix *createMatrix(char *filename){
    FILE *fp = fopen(filename, "r");
    Matrix *matrix = malloc(sizeof(Matrix));
    fscanf(fp, "%d %d", &matrix->numRows, &matrix->numCols);
    matrix->matrixData = malloc(sizeof(int *) * matrix->numRows);
    for (int i = 0; i < matrix->numRows; i++){
        matrix->matrixData[i] = malloc(sizeof(int) * matrix->numCols);
        for (int j = 0; j < matrix->numRows; j++){
            fscanf(fp, "%d", &matrix->matrixData[i][j]);
        }
    }
    fclose(fp);
    return matrix;
}

void printMatrix(Matrix *matrix, char *output_filename){
    FILE *fp = fopen(output_filename, "w");
    fprintf(fp, "%d %d\n", matrix->numRows, matrix->numCols);
    for (int i = 0; i < matrix->numRows; i++){
        for (int j = 0; j < matrix->numCols; j++){
        fprintf(fp, "%d\t", matrix->matrixData[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void freeMatrix(Matrix *pMatrix){
    for (int i = 0; i < pMatrix->numRows; i++){
        free(pMatrix->matrixData[i]);
    }
    free(pMatrix->matrixData);
    free(pMatrix);
}