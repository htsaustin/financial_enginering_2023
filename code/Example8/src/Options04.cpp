#include <iostream>
#include <cmath>
#include "Options04.h"
#include "BinModel02.h"
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

//Here, we appear to be populating our binomial tree/mutating vector
double priceByCRR(BinModel model, int N, double K,
                  double (*Payoff)(double z, double K)) {

    double q = model.riskNeutProd();
    double price[N+1]; //Define price array with N+1 values

    //Populate the array with the stock-value, S(N, i). i.e. end date N, for each i.
    for (int i = 0; i <= N; i++) {
        //calculate value z=S(n,i)
        double z = model.S(N, i);

        //No pointers here. Just assign the array value directly, with the output of the passed in function
        price[i] = Payoff(z, K);
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
double callPayoff(double z, double K) {
    if (z > K) {
        return z - K;
    }
    return 0;
}

//Jumping ahead (shouldn't add this until example 8)
double putPayoff (double z, double K) {
    if (z < K) {
        return K-z;
    }
    return 0;
}