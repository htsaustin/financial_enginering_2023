#ifndef Options03_h
#define Options03_h

//Get and validate the input data.
//Use references, so we mutate the passed in values
//N - steps to expiry, K - strike price
int getInputData(int &N, double &K);

//Call Payoff
//z - ???, K - strike price
double callPayoff(double z, double K);

#endif
