/* Project2.cpp
 * Ima Student
 * EE312, Spring 2017
 * Project 2, Matrix Multiplication
 */

#include <stdio.h>
#include <stdint.h>
#include "MatrixMultiply.h"
#include <stdlib.h>




void multiplyMatrices(
        double a[],
        const uint32_t a_rows,
        const uint32_t a_cols,
        double b[],
        const uint32_t b_cols,
        double c[]) {

    int k =0;
    int i =0;
    int j =0;


    while ( i < a_rows) {
        j =0;
        while (j < b_cols){

            k =0;
            c[i*b_cols +j] = 0;
            while ( k < a_cols) {
                c[i * b_cols + j] += a[i * a_cols + k] * b[k * b_cols + j];
                k++;
            }
            j++;
        }
        i++;
    }

    return;

    // https://en.wikipedia.org/wiki/Row-_and_column-major_order
}




double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {

    int k =0; // for the "k loop"
    int i =0; // rows
    int j =0; // columns
    int r =0; //for the malloc

    double** matrix = (double**)malloc(a_rows*sizeof(double*));

    for (r = 0; r < a_rows; r++) {
        matrix[r] = (double*)malloc(b_cols*sizeof(double));

    }

    while ( i < a_rows) {
        j =0;
        while (j < b_cols){

            k =0;
            matrix[i][j] = 0;
            while ( k < a_cols) {
                matrix[i][j] += a[k][j] * b[i][k];
                k++;
            }
            j++;
        }
        i++;
    }

    return (matrix);

    // https://en.wikipedia.org/wiki/Row-_and_column-major_order
}





// https://en.wikipedia.org/wiki/Transpose
double** transposeMatrix(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols) {

    double** matrix = (double**)malloc(a_cols*sizeof(double*));

    for (int r = 0; r < a_cols; r++) {
        matrix[r] = (double*)malloc(a_rows*sizeof(double));
    }

    for (int i =0; i< a_cols; i++){
        for(int j=0; j< a_rows; j++){

            matrix[i][j] = a[j][i];
        }
    }


    return (matrix);
}


