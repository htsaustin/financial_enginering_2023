#ifndef Options06_h
#define Options06_h

#include "BinModel02.h"

//Abstract class for european options, will be extended by 'call' and 'put'
class EurOption {
    private :
        //steps to expiry
        int N;

    public :
        void setN(int N_) {
            this->N = N_;
        }

        //A function we want to override (see 'virtual')
        virtual double payoff(double z) = 0;

    // pricing European option
    double priceByCRR(BinModel model);

};

//European call option class
class Call: public EurOption {
    private:
        double K; //Strike price
    public:
        int getInputData();

        // The below declarations are equivalent, but we prefer 'override' (according to internet)
        // virtual double payoff(double z);
        double payoff(double z) override;
};

//European put option class
class Put: public EurOption {
    private :
        double K; //strike price
    public :
        int getInputData();

        double payoff(double z) override;
};

//European DoubleDigital option class
class DoubleDigital: public EurOption {
private:
    double K1; //First strike price
    double K2; //Second strike price
public:
    int getInputData();

    // The below declarations are equivalent, but we prefer 'override' (according to internet)
    // virtual double payoff(double z);
    double payoff(double z) override;
};

#endif
