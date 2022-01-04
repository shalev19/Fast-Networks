#include <stdio.h>
#include <ostream>
#include "matrix.h"

using namespace std;
#define SIZE 5



int main(){
    Matrix* B = new Matrix(SIZE,SIZE);
    Matrix* S;
    int *entries = new int[SIZE];
    int *exits = new int[SIZE];
    int iterations = 4;

    //enter the graph arcs.
    B->setVal(0,0,1);
    B->setVal(0,2,1);
    B->setVal(1,1,1);
    B->setVal(1,2,1);
    B->setVal(1,4,1);
    B->setVal(2,4,1);
    B->setVal(3,0,1);
    B->setVal(3,2,1);
    B->setVal(3,3,1);
    B->setVal(4,1,1);
    B->setVal(4,3,1);

    //enter the pointer values.
    entries[0] = 0;
    entries[1] = 2;
    entries[2] = 2;
    entries[3] = 1;
    entries[4] = 4;

    exits[0] = 1;
    exits[1] = 2;
    exits[2] = 2;
    exits[3] = 0;
    exits[4] = 0;

    cout<<"The requests graph:"<<endl;
    B->printMatrix();
    cout << endl;

    S = B->islip(SIZE,B,entries,exits,iterations);

    cout<<"The result graph:"<<endl;
    S->printMatrix();
    cout << endl;

    cout<<"Exit | Entry | Number"<<endl;
    cout<<"--------------------"<<endl;
    for(int i=0 ; i<SIZE; i++){
        cout<<" "<<exits[i]<<"   |\t"<<entries[i]<<"    |\t"<<i<<endl;
    }


    //free all the allocation
    delete B;
    delete S;
    delete[] exits;
    delete[] entries;

    return 0;
}