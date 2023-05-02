#ifndef Options03_h
#define Options03_h

//Get and validate the input data.
//Use references, so we mutate the passed in values
//N - steps to expiry, K - strike price
int getInputData(int &N, double &K);

//Price with CRR (Cox, Ross, & Rubinstein) -  European Options
//S0 - asset price, U - up rate, D - down rate, R - risk neutral rate, N - steps to expiry, K - strike price
//Note, we're adding a function pointer here. Snazzy.
double priceByCRR(double S0, double U, double D, double R, int N, double K,
                  double (*Payoff)(double z, double K));

//Call Payoff
//z - ???, K - strike price
double callPayoff(double z, double K);

//put Payoff
//z - ???, K - strike price
double putPayoff(double z, double K);

#endif
