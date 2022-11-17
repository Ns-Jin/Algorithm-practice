#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n,m;
    cin >> n >> m;
    long long trees[n];
    for(long long i=0;i<n;i++) {
        cin >> trees[i];
    }
    sort(trees,trees+n);

    long long start = 1;
    long long end = trees[n-1];
    while(start <= end) {
        long long half = (start + end) / 2;
        long long temp = 0;
        for(long long i=0;i<n;i++) {
            if(trees[i] > half) {
                temp += trees[i] - half;
            }
        }
        if(temp >= m) {
            start = half + 1;
        }
        else {
            end = half - 1;
        }
    }
    cout << end;
}