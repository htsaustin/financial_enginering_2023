#ifndef Matrix_h
#define Matrix_h

#include <vector>

using namespace std;

//Custom vector type, to represent a mathematical vector
typedef vector<double> Vector;
//Custom vector type, to represent a mathematical matrix, a vector of vectors
typedef vector<Vector> Matrix;


//Define the matrix operations we care about
Vector operator*(const Matrix& c, const Vector& v);
Vector operator*(const double& a, const Vector& v);
Vector operator+(const double& a, const Vector& v);
Vector operator+(const Vector& v, const Vector& w);
Vector operator*(const Vector& v, const Vector& w);
Vector exp(const Vector& v);
double operator^(const Vector& v, const Vector& w);

#endif