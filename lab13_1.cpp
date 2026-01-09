#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[], int N, double B[])
{
    double sum = 0.0;
    double sum_sq = 0.0;
    double prod = 1.0;
    double recip_sum = 0.0;

    double mx = A[0];
    double mn = A[0];

    for(int i = 0; i < N; i++){
        sum += A[i];
        sum_sq += A[i] * A[i];
        prod *= A[i];
        recip_sum += 1.0 / A[i];

        if(A[i] > mx) mx = A[i];
        if(A[i] < mn) mn = A[i];
    }

    B[0] = sum / N;
    B[1] = sqrt(sum_sq / N - B[0] * B[0]);
    B[2] = pow(prod, 1.0 / N);
    B[3] = N / recip_sum;
    B[4] = mx;
    B[5] = mn;
}

