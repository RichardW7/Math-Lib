#include <stdio.h>
#include <vector>
#include <iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

int main () {

    vector<vector<float> > matrix1 {{ 1, 2, 3 }, { 4, 5, 6 }};
    vector<vector<float> > matrix2 {{ 10, 11 }, { 20, 21 }, { 30, 31 }};

    Matrix* m1 = new Matrix(matrix1);
    Matrix* m2 = new Matrix(matrix2);

    Matrix* m3 = m1->multiply(m2);
    m3->printMatrix();

    vector<vector<float> > matrix4 {{ -2, 1 }, { 0, 4 }};
    vector<vector<float> > matrix5 {{ 6, 5 }, { -7, 1 }};

    Matrix* m4 = new Matrix(matrix4);
    Matrix* m5 = new Matrix(matrix5);

    Matrix* m6 = m4->multiply(m5);
    m6->printMatrix();

    return 0;
}