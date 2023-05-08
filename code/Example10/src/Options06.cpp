#include <iostream>
#include <cmath>
#include "Options06.h"
#include "BinModel02.h"
using namespace std;

//Passing in pointers here.
//Assign the value to the pointer location
int Call::getInputData() {
    cout << "Enter call option data :" << endl ;
    int N;
    cout << "Enter steps to expiry, N: ";
    cin >> N;
    setN(N);
    cout << "Enter strike price, K: ";
    cin >> K;
    cout << endl;

    return 0;
}

int Put::getInputData() {
    cout << "Enter put option data :" << endl ;
    int N;
    cout << "Enter steps to expiry, N: ";
    cin >> N;
    setN(N);
    cout << "Enter strike price, K: ";
    cin >> K;
    cout << endl;

    return 0;
}

//Here, we appear to be populating our binomial tree/mutating vector
double EurOption::priceByCRR(BinModel model) {

    double q = model.riskNeutProd();
    double price[N+1]; //Define price array with N+1 values

    //Populate the array with the stock-value, S(N, i). i.e. end date N, for each i.
    for (int i = 0; i <= N; i++) {
        //calculate value z=S(n,i)
        double z = model.S(N, i);

        //No pointers here. Just assign the array value directly, with the output of the passed in function
        price[i] = payoff(z);
    }

    //Now back-calculate from end value to initial, to get the value at n=0, i=0
    //First, run through the previous value of N...
    for (int n = N - 1; n >= 0; n--) {

        //For each value i, at this timestep n, calculate the 'risk-neutral' expectation.
        //Overwrite the previous value, we don't need it.
        for (int i = 0; i < n; i++) {
            price[i] = (q * price[i + 1] + (1-q) * price[i]) / (1 + model.getR());  //Slides, Eqn. (16)
        }
    }

    // No pointers, just first value in array
    return price[0];

}

//Determine the payoff.
//If value (z) > strike price (K), the difference is profit
//If value (z) < strike price (K), we don't make a loss, we simply don't exercise the option, therefore, 0.
//Implement some virtual functions...
double Call::payoff(double z) {
    if (z > K) {
        return z - K;
    }
    return 0;
}

double Put::payoff(double z) {
    if (z < K) {
        return K-z;
    }
    return 0;
}

