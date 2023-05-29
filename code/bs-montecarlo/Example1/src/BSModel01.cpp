//Include io -> from terminal
#include <iostream>
#include <cmath>
#include "BSModel01.h"

using namespace std;

//Constant value of PI
const double pi = 4.0 * atan(1.0);

//Generate a random gaussian value using the Box-Mueller method
double gauss() {

    double U1 = (rand() + 1.0) / (RAND_MAX + 1.0);
    double U2 = (rand() + 1.0) / (RAND_MAX + 1.0);

    return sqrt(-2.0 * log(U1)) * cos(2.0 * pi * U2);
}



void BSModel::generateSamplePath(double T, int m, SamplePath &S) {
    //S at time t
    double St = S0;

    //Arithmetic Asian Option.
    //observation points, t0 ...tk... tm
    //Where T/m is dt, i.e. the constant sized time step.
    //Below represents Eqn (31), slide 95, where (t_i) - (t_i-1) = dt = T/m, i.e. constant
    for(int k=0; k<m; k++) {
        S[k]= St * exp((r - sigma*sigma*0.5) * (T/m) + sigma * sqrt(T/m)*gauss());
        St=S[k] ;
    }
}