#include <iostream>
#include <cmath>
#include <vector>
#include "Options09.h"
#include "BinModel02.h"
using namespace std;

//compare two doubles, with floating point precision. Comparing to 9 d.p.
//True if equal, false if not
bool compare(double value1, double value2) {
    return std::abs(value1 - value2) < std::pow(10, -10);
}

//Passing in pointers here.
//Assign the value to the pointer location
int Call::getInputData() {
    cout << "Enter call option data :" << endl ;
    int N;
    cout << "Enter steps to expiry, N: ";
    cin >> N;
    EurOption::setN(N);
    AmOption::setN(N);
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
    EurOption::setN(N);
    AmOption::setN(N);
    cout << "Enter strike price, K: ";
    cin >> K;
    cout << endl;

    return 0;
}

//Here, we appear to be populating our binomial tree/mutating vector
double EurOption::priceByCRR(BinModel model) {

    // Need to access the private member, use a getter
    int N = getN();

    double q = model.riskNeutProd();

    //Define price vector(!) with N+1 values. This was previously an array.
    //A vector is similar to a java ArrayList, and is automatically resizable
    vector<double> price(N+1);

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
        for (int i = 0; i <= n; i++) {
            price[i] = (q * price[i + 1] + (1-q) * price[i]) / (1 + model.getR());  //Slides, Eqn. (16)
        }
    }

    // No pointers, just first value in array
    return price[0];

}


//Here, we appear to be populating our binomial tree/mutating vector
double AmOption::priceBySnell(BinModel model,
                              BinLattice<double>& priceTree,
                              BinLattice<bool>& stoppingTree) {

    // Need to access the private member, use a getter
    int N = getN();

    double q = model.riskNeutProd();

    //Size the stopping/pricing trees. These are 2D arrays
    priceTree.setN(N);
    stoppingTree.setN(N);

    //The 'continuation' value - i.e. the average of up/down.
    //We'll compare this to the payoff value later, to determine which to store
    double contValue;

    //Populate the array with the stock-value, S(N, i). i.e. end date N, for each i.
    for (int i = 0; i <= N; i++) {
        //calculate value z=S(n,i)
        double z = model.S(N, i);

        double payoffValue = payoff(z);
        //Set the pricing tree with initial values
        priceTree.setNode(N, i, payoffValue);

        //Modification!
        //For clarity, we don't exercise if the payoff is zero.
        if (compare(payoffValue, 0)) {
            stoppingTree.setNode(N, i, false);
        } else {
            stoppingTree.setNode(N, i, true);
        }
    }

    //Now back-calculate from end value to initial, to get the value at n=0, i=0
    //First, run through the previous value of N...
    for (int n = N - 1; n >= 0; n--) {

        //For each value i, at this timestep n, calculate:
        // * the price
        // * the continuation value (average of up/down), i.e. the 'risk-neutral' expectation
        // Now we can compare the two, and store the greater
        //We don't overwrite previous values any longer, as we store all intermediate values in the tree for inspection
        for (int i = 0; i <= n; i++) {
            //Store down whether we'd 'stop' in this scenario

            contValue = (q * priceTree.getNode(n + 1, i + 1) + (1-q) * priceTree.getNode(n + 1, i)) / (1 + model.getR());

            double payoffValue = payoff(model.S(n, i));

            //This is a modification of the examples in the PDF, to better define the stopping values.
            //We should stop if the payoff value (z) is greater than the contValue and greater than zero
            //Store the greater value.
            if (compare(contValue, payoffValue)) {
                //Equal, but non-zero. Let's not stop.
                priceTree.setNode(n, i, payoffValue);
                stoppingTree.setNode(n, i, false);
            } else if (contValue > payoffValue) {
                //If the average of up/down is greater than the payoff now, do should not exercise our option. i.e. stop = false.
                priceTree.setNode(n, i, contValue);
                stoppingTree.setNode(n, i, false);
            } else if (payoffValue > contValue) {
                //If the payoff is greater than average of up/down is greater, exercise our option. i.e. stop = true.
                priceTree.setNode(n, i, payoffValue);
                stoppingTree.setNode(n, i, true);
            } else {
                cout << "Unexpected outcome" << endl;
            }
        }
    }

    // Return first value in price array
    return priceTree.getNode(0, 0);

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

