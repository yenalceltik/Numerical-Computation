
#ifndef main_h
#define main_h

#include <cstdlib>
#include <fstream>
#include <cmath>
#include <tuple>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>

#include "Eigen/Dense"
#include "Eigen/Eigenvalues"
#include "Eigen/QR"

using namespace Eigen;
using namespace std;

typedef vector< tuple<float,float> > coordinates;     //list of (x,y) pair as another type
coordinates file_operations(string);
double backward_error(MatrixXd,VectorXd,VectorXd);

#endif /* main_h */
