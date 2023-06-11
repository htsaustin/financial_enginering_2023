#include <iostream>
#include <cmath>
#include "BSModel02.h"

using namespace std;

//Constant value of PI
const double pi = 4.0 * atan(1.0);

//Generate a random gaussian value using the Box-Mueller method
double gauss() {

    double U1 = (rand() + 1.0) / (RAND_MAX + 1.0);
    double U2 = (rand() + 1.0) / (RAND_MAX + 1.0);

    return sqrt(-2.0 * log(U1)) * cos(2.0 * pi * U2);
}


//Generate a vector of random gaussian values using the Box-Mueller method
Vector gauss(int d) {
    Vector Z(d);
    for (int j = 0; j < d; j++) {
        Z[j] = gauss();
    }
    return Z;
}


BSModel::BSModel(Vector s0_ , double r_ , Matrix c_) {
    this -> s0 = s0_;
    this -> r = r_;
    this -> c = c_;

    srand(time(NULL));

    int d = s0.size();
    sigma.resize(d);

    for (int j=0; j<d; j++) {
        sigma[j] = sqrt(c[j] ^ c[j]);
    }
}


void BSModel::generateSamplePath(double T, int m, SamplePath &s) {
    //S at time t
    Vector St = s0;
    int d=s0.size();

    // Implementation of slides 136-138
    for(int k=0; k<m; k++) {
        s[k]= St * exp((T/m) * (r + (-0.5)*sigma*sigma) + sqrt(T/m)*(c*gauss(d)));
        St=s[k];
    }
}