//
// Created by Harry Austin on 01/05/2023.
//

#include <iostream>
#include <cmath>
#include "Options01.h"
#include "BinModel01.h"
using namespace std;



int getInputData(int &N, double &K) {
    cout << "Enter steps to expiry, N: ";
    cin >> N;
    cout << "Enter strike price, K: ";
    cin >> K;
    cout << endl;

    return 0;
}

//Here, we appear to be populating our binomial tree?
double priceByCRR(double S0, double U, double D, double R, int N, double K) {
    double q = riskNeutralProbability(U, D, R);
    double price[N+1]; //Define price array with N+1 values

    //Populate the array with the stock-value, S(N, i). i.e. end date N, for each i.
    for (int i = 0; i <= N; i++) {
        //calculate value z=S(n,i)
        double z = S(S0, U, D, N, i);
        price[i] = callPayoff(z, K);
    }

    //Now back-calculate from end value to initial, to get the value at n=0, i=0
    //First, run through the previous value of N...
    for (int n = N - 1; n >= 0; n--) {

        //For each value i, at this timestep n, calculate the 'risk-neutral' expectation.
        //Overwrite the previous value, we don't need it.
        for (int i = 0; i <= n; i++) {
            price[i] = (q * price[i+1] + (1-q) * price[i]) / (1 + R);  //Slides, Eqn. (16)
        }
    }

    return price[0];

}

//Determine the payoff.
//If value (z) > strike price (K), the difference is profit
//If value (z) < strike price (K), we don't make a loss, we simply don't exercise the option, therefore, 0.
double callPayoff(double z, double K) {
    if (z > K) {
        return z - K;
    }
    return 0;
}
