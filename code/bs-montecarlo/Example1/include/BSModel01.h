#ifndef BSModel01
#define BSModel01

#include <vector>
#include <cstdlib>
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
        this -> srand(time(NULL));
    }

    void GenerateSamplePath(double T, int m, SamplePath &S);
};

#endif