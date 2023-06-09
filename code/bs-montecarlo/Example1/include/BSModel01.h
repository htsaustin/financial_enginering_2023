#ifndef BSModel01_h
#define BSModel01_h

#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
using namespace std;

typedef vector<double> SamplePath;

class BSModel {
public :
    double S0;
    double r;
    double sigma;

    BSModel(double S0_, double r_, double sigma_) {
        this -> S0 = S0_;
        this -> r = r_;
        this -> sigma = sigma_;

        //Set random seed
        srand(time(NULL));
    }

    //T is total time, and m are the number of observation points
    void generateSamplePath(double T, int m, SamplePath &S);
};

#endif //BSModel01_h