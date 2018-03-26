
#ifndef grad_descent_h
#define grad_descent_h

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <math.h>
#include "Eigen/Dense"

using namespace Eigen;
using namespace std;
IOFormat HeavyFmt(FullPrecision, 0, ", ", ";\n", "[", "]", "[", "]");

const double ALPHA = 0.001;     //Step size
const double EPS1 = 1e-18;      //Checking condition for differences between func. values
const double EPS2 = 1e-4;       //Checking norm of x vector

double f(VectorXd);
VectorXd gradF(VectorXd);
VectorXd iter(VectorXd);
void displayFeat(VectorXd,int);
void help();

#endif    /* grad_descent_h */
