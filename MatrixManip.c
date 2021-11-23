#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Recursive_Math.h"

int main(int argc, char **argv){
    if (argc != 4){
        printf("Usage: %s Input_File Operation Output_File\n", argv[0]);
        return 0;
    }

    Matrix *pMatrix = createMatrix(argv[1]);

    if (strcmp(argv[2], "DET") == 0){
        if (pMatrix->numRows != pMatrix->numCols){
            printf("Determinant of given matrix is undefined\n");
            return 0;
        }
        FILE *fp = fopen(argv[3], "w");
        double pMatrixDET = matrixDeterminant(pMatrix);
        fprintf(fp, "DET = %lf", pMatrixDET);
        fclose(fp);
        freeMatrix(pMatrix);
    }

    else if (strcmp(argv[2], "ADJ") == 0){
        int adjunctRow, adjunctCol;
        printf("Enter adjunct row and column:\n");
        scanf("%d %d", &adjunctRow, &adjunctCol);
        Matrix *pMatrixAdjunct = matrixAdjunct(pMatrix, adjunctRow, adjunctCol);
        FILE *fp = fopen(argv[3], "w");
        fprintf(fp, "%d,%d adjunct =\n", adjunctRow, adjunctCol);
        for (int i = 0; i < pMatrixAdjunct->numRows; i++){
            for (int j = 0; j < pMatrixAdjunct->numCols; j++){
                fprintf(fp, "%d\t", pMatrixAdjunct->matrixData[i][j]);
            }
            fprintf(fp, "\n");
        }
        fclose(fp);
        freeMatrix(pMatrixAdjunct);
    }

    else if(strcmp(argv[2], "COPY") == 0){
        printMatrix(pMatrix, argv[3]);
        freeMatrix(pMatrix);
    }

    else {
        printf("Unable to complete command\n");
        return 0;
    }

    return 0;
}