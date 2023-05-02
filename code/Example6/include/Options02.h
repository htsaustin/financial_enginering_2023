#ifndef Options02_h
#define Options02_h

//Get and validate the input data.
//N - steps to expiry, K - strike price
//Note, these are now pointers.
int getInputData(int *ptrN, double *ptrK);

//Price with CRR (Cox, Ross, & Rubinstein) -  European Options
//S0 - asset price, U - up rate, D - down rate, R - risk neutral rate, N - steps to expiry, K - strike price
double priceByCRR(double S0, double U, double D, double R, int N, double K);

//Call Payoff
//z - ???, K - strike price
double callPayoff(double z, double K);

#endif
