
#include "grad_descent.h"

int main(int argc, char** argv){
  VectorXd inX(2);
  if (argc < 2){
    help();
    return EXIT_FAILURE;
  }
  else{
    string vc = argv[1];
    if (argc == 2 && !vc.compare("-1")){
      inX(0) = 1.2;     inX(1) = 1.2;
      cout << "Local minimum vector of given Rosenbrock function with starting [1.2   1.2] is\n" << iter(inX).format(HeavyFmt) << endl;
    }
    else if (argc == 2 && !vc.compare("-2")) {
      inX(0) = -1.2;    inX(1) = 1.0;
      cout << "Local minimum vector of given Rosenbrock function with starting [-1.2   1.0] is\n" << iter(inX).format(HeavyFmt) << endl;
    }
    else if (!vc.compare("--help"))  {   help();  }
    else
      clog << "Non determined command line argument type\n";
  }
  return EXIT_SUCCESS;
}

//Given function 100(x1-x2^2)^2 - (1-x1^2)
double f(VectorXd x){
  return ( (100.0*pow((x(1)-(x(0)*x(0))),2)) + pow((1 - x(0)),2.0));
}

/*
*All Partial Derivatives was calculated in the Exercise Part 'a'
*Partial derivate of Rosenbrock w.r.t x1 assigned to grad(0)
*Similarly, Partial derivate of Rosenbrock w.r.t x2 assigned to grad(1)
*Returning result vector of gradient vector with given parameter x vector
*/
VectorXd gradF(VectorXd x){
  VectorXd grad(2);
  grad(0) = (-400*x(0)*(x(1)-pow(x(0),2)) - 2*(1-x(0)));
  grad(1) = (200*(x(1)-pow(x(0),2)));
  return grad;
}

void displayFeat(VectorXd x,int var){
  string sep1 = "************************\n";
  string sep2 = "\n----------\n";
  cout << sep1 << "=>>" << var << ".iteration\n" << sep1 << "x:" << sep2 << x.format(HeavyFmt) << sep2 << "f(x):"<< sep2  << f(x) << sep2 << "GradF" << sep2 << gradF(x).format(HeavyFmt) << endl;
}

/*
*Current x vector calculated based Previous x vector using the formula of Grad.Descent
*APLHA,EPS2 and EPS1 was already declared in the header file as constant
*EPS2 check norm of current x vector was identified 1e-4
*Similarly, checking conditions control after every loop has done
*/
VectorXd iter(VectorXd inX){
  VectorXd currX(2);
  VectorXd prevX(2);
  currX = inX;
  double funcValue;
  int k = 0;
  do{
    prevX = currX;
    currX += (-1 * ALPHA) * gradF(prevX);
    funcValue = abs(f(currX) - f(prevX));
    if (k%100 == 0)
      displayFeat(currX,k);
    k++;
  }while ((k <= 45000) && (currX.norm() >= EPS2) && (funcValue > EPS1));
  return currX;
}

void help(){
  clog << "[-1] for starting with [1.2   1.2] \n[-2] for [-1.2   1.0]\n  \n[--help] for all commands" << endl;
}
