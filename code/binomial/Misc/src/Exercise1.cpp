//Include io -> from terminal
#include <iostream>
#include <cmath>

using namespace std;

//Note - the location of '&' is unimportant here for references. (see below)
void interchange(double& a, double &b) {
    double x = a;
    a = b;
    b = x;
}

//Exercise 1 - interchange two variables
int main() {

    double arg1 = 1.0;
    double arg2 = 2.0;

    interchange(arg1, arg2);

    cout << "Argument 1 value: " + to_string(arg1) << endl;
    cout << "Argument 2 value: " + to_string(arg2) << endl;

    return 0;
}
