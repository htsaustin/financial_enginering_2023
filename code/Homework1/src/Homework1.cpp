//Include io -> from terminal
#include <iostream>
#include <cmath>

using namespace std;

//Fast calculation of CRR formula factorials
//See formula on slide 34, and here: https://www.linkedin.com/pulse/python-implementation-binomial-stock-option-pricing-sheikh-pancham
double newtonSymb(int N, int i) {
    if (i <0 || i>N) {
        return 1;
    }

    double result = 1;
    for (int j = 1; j <= i; j++) {
        result = result * (N - i + j) / j;
    }

    return result;
}

int main() {

    cout << "newtonSymb(5, 3): "<< newtonSymb(5, 3);
    return 0;
}
