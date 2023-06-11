//Include io -> from terminal
#include <iostream>
#include <cmath>
#include "PathDependentOption05.h"

using namespace std;

int main() {
    int d = 3;
    Vector s0(d);
    s0[0] = 40.0;
    s0[1] = 60.0;
    s0[2] = 100.0;
    double r = 0.02;
    Matrix c(d);

    for (int i=0; i<d; i++) {
        c[i].resize(d);
    }

    c[0][0] =  0.1;  c[0][1] = -0.1;  c[0][2] = 0.0;
    c[1][0] = -0.1;  c[1][1] =  0.2;  c[1][2] = 0.0;
    c[2][0] =  0.0;  c[2][1] =  0.0;  c[2][2] = 0.3;

    BSModel Model(s0, r, c);
    double T = 1.0 / 12.0, K = 200.0; // Expiry is 1 month.
    int m = 30; // Daily observations for one month!
    ArthmAsianCall Option(T, K, m);
    long N = 30000;
    cout << "Asian Call Price = "
         << Option.priceByMC(Model, N) << endl;
    return 0;
}