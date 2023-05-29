//Include io -> from terminal
#include <iostream>
#include <cmath>
#include "BinModel02.h"
#include "Options09.h"

using namespace std;

int main() {

    BinModel model;

    //Parse and validate input data
    if (model.getInputData() == 1) return 1;


    Call option1;
    //Get input data...
    option1.getInputData();

    //Interestingly, it appears that the price of an american options == european options for R=0 (potentially for all R?)
    //Enjoy the first couple of paragraphs here: http://www.stat.uchicago.edu/~lalley/Courses/391/Lecture15.pdf
    //We can see the value of the Put does vary with the value of R for Eur and Am options.
    cout << "European call option price = "
         << option1.priceByCRR(model)
         << endl << endl;
    cout << "American call option price = "
         << option1.priceBySnell(model)
         << endl << endl;

    Put option2;
    option2.getInputData();

    cout << "European put option price = "
         << option2.priceByCRR(model)
         << endl << endl;
    cout << "American put option price = "
         << option2.priceBySnell(model)
         << endl << endl;


    return 0;
}
