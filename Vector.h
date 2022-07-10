#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <stdio.h>
#include <iostream>
#include <math.h>
// #include <Vector.h>

using namespace std;

class Vector {

    public:
        vector<float> components;
        int dim;

        //Constructors
        Vector (int dim) {
            this->dim = dim;
            vector<float> v(3,0);
            this->components = v;
        };

        Vector (vector<float> &v) {
            this->dim = v.size();
            this->components = v;
        };

        //Destructor
        ~Vector () {
            // delete(this);
        }

        //Add
        Vector* operator + (const Vector* v) {
            if (this->dim != v->dim) {
                cout << "Cannot add vectors in different spaces.\n";
            } 

            Vector *temp = new Vector(3);

            for (int i = 0; i < temp->dim; i++) {
                temp->components.at(i) = this->components.at(i) + v->components.at(i);
            }

            return temp;
        };

        //Subtract
        Vector* operator - (const Vector* v) {
            if (this->dim != v->dim) {
                cout << "Cannot add vectors in different spaces.\n";
            } 

            Vector *temp = new Vector(3);

            for (int i = 0; i < temp->dim; i++) {
                temp->components.at(i) = this->components.at(i) - v->components.at(i);
            }

            return temp;
        };

        //Cross
        Vector* operator * (const Vector* v) {
            Vector* temp = new Vector(3);

            if (this->dim == 3 && v->dim == 3) {

                float x = (this->components.at(1) * v->components.at(2)) - (this->components.at(2) * v->components.at(1));
                float y = (this->components.at(2) * v->components.at(0)) - (this->components.at(0) * v->components.at(2));
                float z = (this->components.at(0) * v->components.at(1)) - (this->components.at(1) * v->components.at(0));

                temp->components.at(0) = x;
                temp->components.at(1) = y;
                temp->components.at(2) = z;
            } else {
                cout << "Can only cross 3rd and 7th dimensional vectors.\n";
            }

            return temp;
        };

        //Dot
        float operator % (const Vector v) {
            float dotproduct = 0;

            if (this->dim != v.dim) {
                cout << "Cannot add vectors in different spaces.\n";
                return -1;
            } 

            for (int i = 0; i < this->dim; i++) {
                dotproduct += (this->components.at(i) * v.components.at(i));
            }

            return dotproduct;
        };

        void printVector () {
            cout << "<";

            for (int i = 0; i < this->dim; i++) {
                cout << this->components.at(i);
                if (i < this->dim - 1) {
                    cout << ", ";
                }
            }
            cout << ">\n";
        };

        void scale (const float x) {

            for (int i = 0; i < this->dim; i++) {
                this->components.at(i) *= x;
            }

        };

        float magnitude () {
            float magnitude = 0;

            for (int i = 0; i < this->components.size(); i++) {
                magnitude += (this->components.at(i) * this->components.at(i));
            };

            return sqrt(magnitude);
        }

        Vector* unitVector () {
            float magnitude = this->magnitude();

            vector<float> unitVector;

            for (int i = 0; i < this->dim; i++) {
                unitVector.push_back(this->components.at(i)/magnitude);
            };

            return new Vector(unitVector);
        }
};

#endif