//Include io -> from terminal
#include <iostream>
#include <cmath>
#include "BinModel02.h"
#include "Options05.h"

using namespace std;

int main() {

    BinModel model;

    //Parse and validate input data
    if (model.getInputData() == 1) return 1;


    Call option1;
    //Get input data...
    option1.getInputData();

    cout << "European call option price = "
         << option1.priceByCRR(model, option1.getK())
         << endl << endl;

    Put option2;
    option2.getInputData();

    cout << "European put option price = "
         << option2.priceByCRR(model, option2.getK())
         << endl << endl;

    return 0;
}
