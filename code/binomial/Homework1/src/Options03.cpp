#include <iostream>
#include "Options03.h"
using namespace std;

//Passing in pointers here.
//Assign the value to the pointer location
int getInputData(int& N, double& K) {
    cout << "Enter steps to expiry, N: ";
    cin >> N;
    cout << "Enter strike price, K: ";
    cin >> K;
    cout << endl;

    return 0;
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
