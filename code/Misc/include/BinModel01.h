#ifndef BinModel01_h
#define BinModel01_h

//Get and validate the input data.
//Use references, so we mutate the passed in values
int getInputData(double &S0, double &U, double &D, double &R);

//Compute the risk-neutral probability
double riskNeutralProbability(double U, double D, double R);

//Get the stock price at node S(n, i)
double S(double S0, double U, double D, int n, int i);


#endif
