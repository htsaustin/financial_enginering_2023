#ifndef BSModel02_h
#define BSModel02_h
#include "Matrix.h"
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
using namespace std;

typedef vector<Vector> SamplePath;

class BSModel {
public :
    Vector s0;
    Vector sigma;
    Matrix c;
    double r;
    BSModel(Vector s0_, double r_, Matrix c_);

    //T is total time, and m are the number of observation points
    void generateSamplePath(double T, int m, SamplePath &s);
};

#endif //BSModel02_h