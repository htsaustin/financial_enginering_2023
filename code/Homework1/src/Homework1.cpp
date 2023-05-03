//Include io -> from terminal
#include <iostream>
#include <cmath>
#include "BinModel01.h"
#include "Options03.h"

using namespace std;

//Fast calculation of CRR formula factorials
//See formula on slide 34, and here: https://www.linkedin.com/pulse/python-implementation-binomial-stock-option-pricing-sheikh-pancham
double newtonSymb(int N, int i) {
    if (i <0 || i>N) {
        return 1;
    }

    double result = 1;
    for (int j = 1; j <= i; j++) {
        result = result * (N - i + j) / j;
    }

    return result;
}

int main() {

    cout << "newtonSymb(5, 3): "<< newtonSymb(5, 3);


    //From slide 12/3
    // h_call(S) = (S - K)^+, i.e. the 0 or +ve value
    // ...and...
    // S(n, i) = S(0)(1+U)^i (1+D)^(n-i)
    //          --> S(N, i) = S(0)(1+U)^i (1+D)^(N-i)
    //          --> H(N, i) = h(S(N, i)) = h (S(0)(1+U)^i (1+D)^(N-i))


    //putting into slide 34, eqn 19...
    // q = risk neutral probability



    // Define the in memory location.
    // We can use &S0 to point to the address later.
    double S0, U, D, R;

    //Parse and validate input data
    if (getInputData(S0, U, D, R) == 1) return 1;


    double K; //Strike price
    int N; //Steps to expiry
    cout << "Enter call option date: " << endl;
    getInputData(N, K);


    //Compute the risk - neutral probability
    double q = riskNeutralProbability(U, D, R);
    cout << "Risk - neutral probability q = " << q << endl;


    //TODO - implement here.

    return 0;
}
