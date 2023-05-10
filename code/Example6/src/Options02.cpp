#include <iostream>
#include <cmath>
#include "Options02.h"
#include "BinModel01.h"
using namespace std;

//Passing in pointers here.
//Assign the value to the pointer location
//ptrN is the pointer, and *ptrN is the value contained
int getInputData(int* ptrN, double* ptrK) {
    cout << "Enter steps to expiry, N: ";
    cin >> *ptrN;
    cout << "Enter strike price, K: ";
    cin >> *ptrK;
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

        //Declaring with a '*' means it is a pointer (not the same as dereferencing a pointer)
        //Note, this is 'reasonable' syntax for get a pointer to a location in an array - see: https://www.tutorialspoint.com/cplusplus/cpp_pointer_to_an_array.htm
        *(price + i) = callPayoff(z, K);
    }

    //Now back-calculate from end value to initial, to get the value at n=0, i=0
    //First, run through the previous value of N...
    for (int n = N - 1; n >= 0; n--) {

        //For each value i, at this timestep n, calculate the 'risk-neutral' expectation.
        //Overwrite the previous value, we don't need it.
        for (int i = 0; i <= n; i++) {
            //More use of array pointer operations - e.g.  '*(price + i) + 1'  points to 'price[i + 1]'
            price[i] = (q * (*(price + i + 1)) + (1-q) * (*(price + i))) / (1 + R);  //Slides, Eqn. (16)
        }
    }

    //pointer to the zero-th location in the array.
    // We're starting to head down the crazy world of pointer arithmetic
    return *price;

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
