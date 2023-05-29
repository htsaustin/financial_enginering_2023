#ifndef BinLattice02
#define BinLattice02

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//Note, we skipped BinLattice01 as it was a concrete case of BinLattice02, and not used in any examples
template<typename T> class BinLattice {

private :
    int N;
    //Classic 'list of list' created a 2D array
    vector<vector<T>> lattice;
public :
    void setN(int N_) {
        this->N = N_;
        lattice.resize(N + 1);
        for (int n = 0; n <= N; n++) lattice[n].resize(n + 1);
    }

    void setNode(int n, int i, T x) { lattice[n][i] = x; }

    T getNode(int n, int i) { return lattice[n][i]; }

    void display() {
        // Set formatting options on output - 'fixed' means 6dp, precision 3
        cout << setiosflags(ios::fixed) << setprecision(3);
        for (int n = 0; n <= N; n++) {
            for (int i = 0; i <= n; i++)
                //Set the 'width' on output.
                cout << setw(7) << getNode(n, i);
            cout << endl;
        }
        cout << endl;
    }
};

#endif //BinLattice02
