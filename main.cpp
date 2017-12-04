#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


double L_f(double h, double s)
{
    //El número de sumandos que tendrá la serie es (1/h): " << int (1/h) << " Llamémosle N.\n"
    int N = int (1/h);
    double L_f = 0;
    for (int k = 1; k < N - 1; k++)
        L_f = L_f + pow(k * h, s - 1) * sinh(-log(k * h)) * h;
    return L_f;
}

double Laplace_Simpson (double s)
{
    int DefaultIntegralN = 10000000;
    double du = 0.5 / (double) DefaultIntegralN;
    double y = sinh(0) / 2.0;
    double u = 0;
    double limit = 1.0 - 1e-10;
    while (u < limit)
    {
        u += du;
        y += 2.0 * pow(u, s - 1) * sinh(-log(u));
        u += du;
        y += pow(u, s - 1) * sinh(-log(u));
    }
    return 2.0 * y * du / 3.0;
}

int main(int argc, char** argv) 
{
    // cout << "You have entered " << argc
    //      << " arguments:" << "\n";
    // for (int i = 0; i < argc; ++i)
    //     cout << argv[i] << "\n";
    // cout << "\nHello, World!\n";

    double h = .000001;
    int K = 16;
    double pi = atan(1)*4;
    for(int i = 0; i < K; i++)
    {
        cout << "Laplace_Simpson(" << exp(i) << ") = " << Laplace_Simpson(exp(i)) << "\n";
        cout << "            L_f(" << exp(i) << ") = " << L_f(h,exp(i)) << "\n";
    }
    //cout << "L_f(h,pi) = " << L_f(h,pi) << "\n";
    return 0;
}

