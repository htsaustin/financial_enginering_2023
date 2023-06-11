#ifndef PathDependentOption05_h
#define PathDependentOption05_h

#include "BSModel02.h"

class PathDepOption {
    public:
        //Final payoff point
        double T;
        //number of points in the path
        int m;

        //Here, N is the number of simulations
        double priceByMC(BSModel model, long N);

        virtual double payoff(SamplePath &S) = 0;
};


class ArthmAsianCall : public PathDepOption {
    public:
        //K, the strike price
        double K;

        //Constructor
        ArthmAsianCall(double T_, double K_, int m_) {
            this->T = T_;
            this->K = K_;
            this->m = m_;
        }

        double payoff(SamplePath &S);
};

#endif //PathDependentOption05_h
