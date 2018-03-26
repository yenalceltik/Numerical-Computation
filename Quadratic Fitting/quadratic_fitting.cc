
#include <iostream>
#include "quadratic_fitting.h"

int main(int argc, char** argv)
{
    string file_name = argv[1];         //getting file name from command line argument
    string solution_type;
    if (argc > 2)               //check if solution type is QR Decomp. or not
        solution_type = argv[2];
    coordinates datas = file_operations(file_name);     //we stored the data points in the tuple vectors
    if (datas.size() < 3)
        printf("You did not enter enough point!");      // N <= 2
    else
    {   
        /*  Matrix(A).vec(c) = vec(b)   => vector C consists of coefficients of eq such as a,b,c
        *   Creating matrices given data set by traversing in tuples vector
        *   If given # of data points is 3 then apply the Full Pivot LU Decomp. and find the vector c
        *   else the condition controls given command line arg, then decide to apply what solution type
        *   It uses QR or again LU Decomp. 
        *   Lastly, function calculates the backward error
        */
        MatrixXd A(datas.size(),3);         
        VectorXd B(datas.size());
        VectorXd C;
        int i=0;
        for (coordinates::iterator iter = datas.begin(); iter != datas.end(); ++iter)
        {
            A(i,0) = pow(get<0>(*iter),2);
            A(i,1) = get<0>(*iter);
            A(i,2) = 1.0;
            B(i,0) = get<1>(*iter);
            i++;
        }
        cout << "Matrix A is \n" << A << endl;
        cout << "Matrix B is \n" << B << endl;
        
        if (datas.size() == 3)
            C = A.fullPivLu().solve(B);
        else
        {
            
            if (solution_type.compare("--qr"))
                C = A.fullPivHouseholderQr().solve(B);
            else
                C = A.fullPivLu().solve(B);
        }
        cout << "Corresponding Coefficients Vector C is \n" << C << endl;
        cout << "Backward Error is " << backward_error(A, B, C) << endl;
    }
    return EXIT_SUCCESS;
}

coordinates file_operations(string file_name)
{
    coordinates data_points;
    ifstream file_datas(file_name);
    string line;
    int a, b;
    while (file_datas >> a >> b)
        data_points.push_back(make_tuple(a,b));
    file_datas.close();
    return data_points;
}

double backward_error(MatrixXd A, VectorXd B, VectorXd C)
{
    /*
    *   backward error = sum of (f(x)_i - B_i)sq
    */
    double error,f_x_i;
    int i,j;
    for (i=0; i<A.rows(); i++)
    {
        f_x_i = 0.0;
        double temp = 0.0;
        for (j=0; j<A.cols(); j++)
            temp += A(i,j) * C(j);
        f_x_i += temp;
        error += pow(f_x_i-B(i), 2.0);
    }
    return error;
}
