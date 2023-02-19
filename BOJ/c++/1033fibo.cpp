#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    long long c0[41];
    c0[0] = 1;
    c0[1] = 0;
    c0[2] = 1;
    c0[3] = 1;
    for(int i=4;i<41;i++) {
        c0[i] = c0[i-1] + c0[i-2];
    }

    long long c1[41];
    c1[0] = 0;
    c1[1] = 1;
    c1[2] = 1;
    c1[3] = 2;
    for(int i=4;i<41;i++) {
        c1[i] = c1[i-1] + c1[i-2];
    }

    long long count_0 = 0;
    long long count_1 = 0;

    for(int i=0;i<t;i++) {
        int n;
        cin >> n;
        count_0 = c0[n];
        count_1 = c1[n];
        cout << count_0 << " " << count_1 << endl;
    }
}