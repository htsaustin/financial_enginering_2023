
#include "PathDependentOption01.h"
#include <cmath>


//Some useful python bits here: https://www.codearmo.com/blog/pricing-options-monte-carlo-simulation-python
//And here https://quantipy.wordpress.com/2017/08/19/pricing-asian-arithmetic-option-using-monte-carlo-simulations/
double PathDepOption::priceByMC(BSModel model, long N) {

    double H = 0.0;

    SamplePath S(m); //Size of vector

    //Generated multiple paths, and sum the payoffs
    for (long i = 0; i < N; i++) {
        model.generateSamplePath(T, m, S);
        H += payoff(S);
    }

    //e^(-rT) is the discounting function.
    //H/N is the averaged payoff from all the simulations
    return exp(-model.r * T) * (H / N);
}

//Eqn 34, slide 100 (though from k=0)
double ArthmAsianCall::payoff(SamplePath &S) {
    double average = 0.0;

    //This seems like a weird way to do an average
    //I suppose, less storage. It looks to be a rolling average
    for (int k = 0; k < m; k++) {
        average = (k * average + S[k]) / (k + 1.0);
    }

    if (average < K) {
        return 0.0;
    }
    return average - K;
}