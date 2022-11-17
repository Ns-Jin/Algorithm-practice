#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long k,n;
    cin >> k >> n;
    long long cable[k];
    for(long long i=0;i<k;i++) {
        cin >> cable[i];
    }
    sort(cable, cable+k);

    long long start = 1;
    long long end = cable[k-1];
    while(start <= end) {
        long long half = (start + end) / 2;
        long long temp = 0;
        for(long long i=0;i<k;i++) {
            temp += cable[i] / half;
        }
        if(temp >= n) {
            start = half + 1;
        }
        else {
            end = half -1;
        }
    }
    cout << end;
}