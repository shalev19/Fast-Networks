#ifndef __MATRIX_H__
#define __MATRIX_H__
using namespace std;
#include <iostream>

class Matrix {
    private:
        int rows_, cols_;
        int **p;

    public:
        Matrix(int rows, int cols);
        Matrix(int** a, int rows, int cols);
        Matrix();
        ~Matrix();
        Matrix(const Matrix&);
        int getVal(int i, int j);
        void setVal(int i, int j , int val);
        int getCols();
        int getRows();
        void initMatrix();
        Matrix* islip(int N, Matrix* B, int* entries, int* exit, int iterations);
        void printMatrix();
        void allocSpace();
};


#endif