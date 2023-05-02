//
// Created by Harry Austin on 01/05/2023.
//

#include <iostream>
#include <cmath>
#include "BinModel01.h"
using namespace std;


//Get and validate the input data.
//Use references, so we mutate the passed in values
int getInputData(double &S0, double &U, double &D, double &R) {
    //Enter data:
    cout << "Enter S0: "; //Current price of the underlying asset. Cannot be less than 0.
    cin >> S0; // 100
    cout << "Enter U: "; //Up-Factor, increase in value per day. Must be greater than down-factor, and not less than -1.0
    cin >> U; // e.g. 0.05, 5% up
    cout << "Enter D: "; //Down-Factor, decrease in value per day. Cannot be less than -1.0
    cin >> D; // e.g. -0.05, 5% down
    cout << "Enter R: "; //Risk-free rate. (Coming back to this). Cannot be greater than U, or less than D
    cin >> R; // e.g. 0.1

    // 1. Make sure S0>0, (1+U)>0, (1+D)>0, (1+R)>0, U > D
    if (S0 <= 0 || U <= -1.0 || D <= -1.0 || R <= -1.0 || U <= D) {
        cout << "Illegal data ranges" << endl;
        cout << "Terminating program" << endl;
        return 1;
    }

    //2. Checking for arbitrage D<R<U; q>1, or q<0; q=(R-D)/(U - D)
    // Probability cannot be gt 100%, or lt 0
    // Arbitrage means you make money no matter what.
    if (R <= D || R >= U) {

        // Can only happen if R <=D or R>=U
        cout << "Arbitrage exists" << endl;
        cout << "Terminating program" << endl;
        return 1;
    }
    cout << "Input data checked" << endl;
    cout << "There is no Arbitrage" << endl;

    return 0;
}

//Compute the risk-neutral probability
double riskNeutralProbability(double U, double D, double R) {
    double q = (R - D) / (U - D);
    return q;
}

//Get the stock price at node S(n, i)
double S(double S0, double U, double D, int n, int i) {
    return S0 * pow(1 + U, i) * pow(1 + D, n - i);
}
