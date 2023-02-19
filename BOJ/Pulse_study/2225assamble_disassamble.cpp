#include <iostream>

using namespace std;

long long factorial(long long n) {
    if(n == 0) {
        return 1;
    }
    else {
        return n*factorial(n-1) % 1000000000;
    }
}

long long comb_with_repetition(long long n, long long k) {
    return factorial(n+k-1)/factorial(k)/factorial(n-1);
}

int main() {
    long long n,k;
    cin >> n >> k;

    cout << factorial(n+k-1)  <<" "<< factorial(n) <<" "<< factorial(k-1) << endl;
    cout << comb_with_repetition(k,n);
}