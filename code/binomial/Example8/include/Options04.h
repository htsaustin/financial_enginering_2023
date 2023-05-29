#ifndef Options04_h
#define Options04_h
#include "BinModel02.h"

//Get and validate the input data.
//Use references, so we mutate the passed in values
//N - steps to expiry, K - strike price
int getInputData(int &N, double &K);


//Price with CRR (Cox, Ross, & Rubinstein) -  European Options
//S0 - asset price, K - strike price
double priceByCRR(BinModel model, int N, double K,
                  double (*Payoff)(double z, double K));

//Call Payoff
//z - value of stock, K - strike price
double callPayoff(double z, double K);

//put Payoff
//z - value of stock, K - strike price
double putPayoff(double z, double K);

#endif
