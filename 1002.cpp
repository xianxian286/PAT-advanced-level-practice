#include<iostream>
using namespace std;
int main(){
    double A[1001] = {0}, B[1001] = {0};
    int K;
    cin >> K;
    for(int i = 0; i < K; i++){
        double coefficients;
        int exponent;
        cin >> exponent >> coefficients;
        A[exponent] = coefficients;
    }

    cin >> K;
    for(int i = 0; i < K; i++){
        double coefficients;
        int exponent;
        cin >> exponent >> coefficients;
        B[exponent] = coefficients;
    }

    double sum[1001] = {0};
    int sumK = 0;
    for(int i = 0; i < 1001; i++){
        if(A[i] != 0 || B[i] != 0){
            sum[i] = A[i] + B[i];
            if(sum[i] != 0) sumK++;
        }
    }

    cout << sumK;
    for(int i = 1000; i >= 0; i--){
        if(sum[i] != 0) printf(" %d %.1lf", i, sum[i]);
    }

    return 0;
}