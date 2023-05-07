#ifndef Options05_h
#define Options05_h

#include "BinModel02.h"

//Abstract class for european options, will be extended by 'call' and 'put'
class EurOption {
    private :
        //steps to expiry
        int N;
        //pointer to payoff function
        double (*payoff)(double z,double K);


    public :
        void setN(int N_) {
            this->N = N_;
        }

        void setPayoff(double (*payoff_)(double z, double K)) {
            this->payoff = payoff_;
        }

    // pricing European option
    double priceByCRR(BinModel model, double K);

};

//computing call payoff
double callPayoff(double z, double K);

//European call option class
class Call : public EurOption {
    private:
        double K; //Strike price
    public:
        //Constructor declaration, and pass relevant payoff function as arg
        Call() {
            setPayoff(callPayoff);
        }
        double getK() {
            return K;
        }
        int getInputData();
};

//computing put payoff
double putPayoff(double z, double K);

//European put option class
class Put: public EurOption {
    private :
        double K; //strike price
    public :
        Put() {
            setPayoff(putPayoff);
        }
        double getK() {
            return K;
        }
        int getInputData();
};


#endif
