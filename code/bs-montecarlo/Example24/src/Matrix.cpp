#include "Matrix.h"
#include <cmath>
#include <vector>

using namespace std;


Vector operator*(const Matrix &c, const Vector &v) {
    int d = c.size();

    // Initialise an output vector
    Vector w(d);

    // Matrix multiple the elements
    for (int j = 0; j < d; j++) {
        w[j] = 0.0;
        for (int l = 0; l < d; l++) {
            w[j] = w[j] + c[j][l] * v[l];
        }
    }
    return w;
}

Vector operator+(const Vector &v, const Vector &w) {
    int d = v.size();
    Vector U(d);
    for (int j = 0; j < d; j++) {
        U[j] = v[j] + w[j];
    }
    return U;
}

Vector operator+(const double &a, const Vector &v) {
    int d = v.size();
    Vector U(d);
    for (int j = 0; j < d; j++) {
        U[j] = a + v[j];
    }

    return U;
}


Vector operator*(const double &a, const Vector &v) {
    int d = v.size();
    Vector U(d);
    for (int j = 0; j < d; j++) {
        U[j] = a * v[j];
    }
    return U;
}

// returns Vector, elements v[j]*w[j]
Vector operator*(const Vector &v, const Vector &W) {
    int d = v.size();
    Vector U(d);
    for (int j = 0; j < d; j++) {
        U[j] = v[j] * W[j];
    }
    return U;
}


Vector exp(const Vector &v) {
    int d = v.size();
    Vector u(d);
    for (int j = 0; j < d; j++) {
        u[j] = exp(v[j]);
    }

    return u;
}

//sums the products of elements, and returns double
double operator^(const Vector &v, const Vector &w) {
    double sum = 0.0;
    int d = v.size();
    for (int j = 0; j < d; j++) {
        sum = sum + v[j] * w[j];
    }

    return sum;
}
