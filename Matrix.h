#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "Vector.h"

using namespace std;

class Matrix {

    public:
        vector<vector<float> > matrix;

        int m;
        int n;

        Matrix (int m, int n) {
            this->m = m;
            this->n = n;

            vector<vector<float> > matrix(m, vector<float>(n, 0));

            this->matrix = matrix;
        };

        Matrix (vector<vector<float> > matrix) {
            this->matrix = matrix;
            this->m = matrix.size();
            this->n = matrix.at(0).size();
        };

        void printMatrix () {
            for (int i = 0; i < m; i++) {
                cout << "| ";
                for (int j = 0; j < n; j++){
                    cout << this->matrix.at(i).at(j);
                    if (j < n - 1) {
                        cout << " ";
                    }
                }
                cout << " |\n";
            }
            cout << "\n";
        };

        void rref () {

        };

        Matrix* multiply (Matrix* matrix) {

            int m, n;

            Matrix* first;
            Matrix* second;

            if (this->m == matrix->n) {
                n = this->n;
                m = matrix->m;

                first = new Matrix(this->matrix);
                second = new Matrix(matrix->matrix);

            } else if (this->n == matrix->m) {
                m = this->m;
                n = matrix->n;

                first = new Matrix(matrix->matrix);
                second = new Matrix(this->matrix);

            } else {
                cout << "Incompatible.\n";
                return this;
            }

            first->printMatrix();
            second->printMatrix();

            int i = 0;
            int column = 0;

            vector<float> row;
            vector<vector<float>> newMatrix;

            while (i < first->m) {
                vector<float> temp;
                Vector* v1 = new Vector(first->matrix.at(i));

                for (int j = 0; j < second->m; j++) {
                    temp.push_back(second->matrix[j][column]);
                }

                Vector* v2 = new Vector(temp);
                row.push_back(*v1 % *v2);
                column++;

                if (column == second->n) {
                    newMatrix.push_back(row);
                    row.clear();
                    column = 0;
                    i++;
                }
            }

            return new Matrix(newMatrix);
        };

        Matrix* transpose () {

            Matrix* matrix = new Matrix(this->n, this->m);

            for (int i = 0; i < this->m; i++) {
                for (int j = 0; j < this->n; j++) {
                    matrix->matrix[j][i] = this->matrix[i][j];
                }
            }

            return matrix;
        };

        void inverse () {

        };

        void adjugate () {

        };

        void scale () {

        };

        void discriminant () {

        };
};

#endif