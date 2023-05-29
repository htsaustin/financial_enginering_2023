//Include io -> from terminal
#include <iostream>
#include <cmath>
#include "../include/BinModel01.h"

using namespace std;

int main() {

    // Define the in memory location.
    // We can use &S0 to point to the address later.
    double S0, U, D, R;

    //Parse and validate input data
    if (getInputData(S0, U, D, R) == 1) return 1;

    //Compute the risk - neutral probability
    double q = riskNeutralProbability(U, D, R);
    cout << "Risk - neutral probability q = " << q << endl;

    //Compute stock price at n=3, i =2;
    int n = 3;
    int i = 2;
    cout << " S(" << n << "," << i << ") = " << S(S0, U, D, n, i) << endl;
    char x;
    cin >> x;
    return 0;

}
