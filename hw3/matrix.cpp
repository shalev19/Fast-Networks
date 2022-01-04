#include <stdexcept>
#include "matrix.h"

#define EPS 1e-10

using std::ostream;  using std::istream;  using std::endl;


Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols)
{

    allocSpace();
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            p[i][j] = 0;
        }
    }
}

Matrix::Matrix(int** a, int rows, int cols) : rows_(rows), cols_(cols)
{
    allocSpace();
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            p[i][j] = a[i][j];
        }
    }
}

Matrix::Matrix() : rows_(1), cols_(1)
{
    allocSpace();
    p[0][0] = 0;
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows_; i++) {
        delete[] p[i];
    }
    delete[] p;
}

Matrix::Matrix(const Matrix& m) : rows_(m.rows_), cols_(m.cols_)
{
    allocSpace();
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            p[i][j] = m.p[i][j];
        }
    }
}


void Matrix::allocSpace()
{
    p = new int*[rows_];
    for (int i = 0; i < rows_; i++) {
        p[i] = new int[cols_];
    }
}

void Matrix::printMatrix(){
    for (int i = 0; i < rows_; i++){
        for (int j = 0; j < cols_; j++){
            cout << p[i][j] << " ";
        }
        // Newline for new row
        cout << endl;
    }
}

void  Matrix::initMatrix(){
    for (int i = 0; i < rows_; i++){
        for (int j = 0; j < cols_; j++){
            p[i][j] = 0;
        }
    }
}

Matrix* Matrix::islip(int N, Matrix* B, int* entrances, int* exit, int iterations){
    int point;
    Matrix* S = new Matrix(N,N);

    for(int iter=0; iter<iterations; iter++){

        //loop for grant level

        for(int i=0; i<N;i++){
            point = exit[i];
            for(int j=0; j<N; j++){
                if (B->p[point][i]){ //if there is line between the exit.
                    S->p[point][i] = 1;
                    break;
                }
                else if(point<N-1){ //check the next entry.
                    point++;
                }
                else point=0;  //if you get to the N entry, start from 0 again.
            }
        } //end of grant level.


        //loop for accept level
        for(int i=0; i<N; i++){
            point = entrances[i];
            for(int j=0; j<N; j++){
                if (S->p[i][point]){ //if there is line between the entry, choose by the order of the pointer.
                    for(int k=0; k<N; k++){ //delete all the lines from this entry that didnt chose this time.
                        if(k != point){
                            S->p[i][k] = 0;
                        }
                    }
                    break;
                }
                else if(point<N-1){ //check the next entry.
                    point++;
                }
                else point=0;  //if you get to the N entry, start from 0 again.
            }
        } //end of accept level.

        if(iter==0){
            //update the pointers only after the first iteration.
            for(int m=0; m<N; m++){
                for(int j=0; j<N; j++){
                    if(S->p[m][j]){
                        if(j+1 < N) entrances[m] = j+1;
                        else entrances[m] = 0;
                        if(m+1<N) exit[j] = m+1;
                        else exit[j] = 0;
                    }
                }
            }
        }
        for(int m=0; m<N; m++){ //remove the lines that served.
            for(int j=0; j<N; j++){
                if(S->p[m][j]){
                    for(int k=0; k<N; k++){  //this loop remove the lines from the not available exits and entrances
                        B->p[m][k] = 0;
                        B->p[k][j] = 0;
                    }
                }
            }
        }
    }

    return S;
}

int  Matrix::getVal(int i, int j){
    if(i<rows_ && i >= 0 && j<cols_ && j >= 0)
        return p[i][j];
    else return -1;
}


void Matrix::setVal(int i, int j , int val){
    if(i<rows_ && i >= 0 && j<cols_ && j >= 0)
        p[i][j] = val;

    else cout<<"index ERROR"<<endl;
}

int Matrix::getCols(){
    return cols_;
}
int Matrix::getRows(){
    return rows_;
}

