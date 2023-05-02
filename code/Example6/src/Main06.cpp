//Include io -> from terminal
#include <iostream>
#include <cmath>
#include "BinModel01.h"
#include "Options02.h"

using namespace std;

int main() {

    // Define the in memory location.
    // We can use &S0 to point to the address later.
    double S0, U, D, R;

    //Parse and validate input data
    if (getInputData(S0, U, D, R) == 1) return 1;


    double K; //Strike price
    int N; //Steps to expiry
    cout << "Enter call option date: " << endl;
    getInputData(&N, &K);


    //Compute the risk - neutral probability
    double q = riskNeutralProbability(U, D, R);
    cout << "Risk - neutral probability q = " << q << endl;

    cout << "European call option price = "
         << priceByCRR(S0, U, D, R, N, K)
         << endl << endl;

    return 0;
}
