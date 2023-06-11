
#include "PathDependentOption05.h"
#include <cmath>


double PathDepOption::priceByMC(BSModel model, long N) {

    double H = 0.0;

    SamplePath S(m); //Size of vector

    //Generated multiple paths, and sum the payoffs
    for (long i = 0; i < N; i++) {
        model.generateSamplePath(T, m, S);
        H = (i * H + payoff(S)) / (i+1.0);
    }

    //e^(-rT) is the discounting function.
    return exp(-model.r * T) * H;
}

double ArthmAsianCall::payoff(SamplePath &s) {
    double average = 0.0;
    int d=s[0].size();

    //Initialise a unit vector
    Vector one(d);
    for (int i = 0; i < d; i++) {
        one[i] = 1.0;
    }

    for (int k = 0; k < m; k++) {
        average = (k * average + (one ^ s[k])) / (k + 1.0);
    }

    if (average < K) {
        return 0.0;
    }
    return average - K;
}