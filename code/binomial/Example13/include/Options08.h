#ifndef Options08_h
#define Options08_h

#include "BinModel02.h"

//Abstract class for all options, will be implemented by EurOption, and AmOption
class Option {
private :
    //steps to expiry
    int N;

public :
    void setN(int N_) {
        this->N = N_;
    }

    int getN() {
        return N;
    }

    //A function we want to override (see 'virtual')
    virtual double payoff(double z) = 0;

};

//Virtual inheritance, used to break the diamond pattern of inheritance, https://en.wikipedia.org/wiki/Virtual_inheritance
// e.g. Clazz A, B and C inherit from A, D inherits from B and C. What inherited method from Clazz A would be used?
// Honestly, composition >> inheritance so we ideally don't have to deal with this often.
class EurOption : public virtual Option {
    public:
        // pricing European option
        double priceByCRR(BinModel model);

};

class AmOption: public virtual Option  {
    public:
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
