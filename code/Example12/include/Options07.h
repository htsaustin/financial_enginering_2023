#ifndef Options07_h
#define Options07_h

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

class AmOption {
    private :
        //steps to expiry
        int N;

    public :
        void setN(int N_) {
            N = N_;
        }

    virtual double payoff(double z) = 0;

    // pricing American option
    double priceBySnell(BinModel model);
};


//European call option class
class Call : public EurOption, public AmOption {
    private:
        double K; //Strike price
    public:
        double getK() {
            return K;
        }
        int getInputData();

        // The below declarations are equivalent, but we prefer 'override' (according to internet)
        // virtual double payoff(double z);
        double payoff(double z) override;
};

//European put option class
class Put: public EurOption, public AmOption {
    private :
        double K; //strike price
    public :
        double getK() {
            return K;
        }
        int getInputData();

        double payoff(double z) override;
};


#endif
