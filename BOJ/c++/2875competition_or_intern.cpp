#include <iostream>

using namespace std;

int main() {
    int n,m,k;
    cin >> n >> m >> k;

    int team;

    if(n >= m*2) {
        team = m;
        n = n - m*2;
        m = 0; 
    }
    else {
        team = n/2;
        n = n%2;
        m = m-team;
    }
    k = k - (n + m);

    if(k<=0) {
        cout << team << endl;
    }
    else {
        while(k>0) {
            team--;
            k = k-3;
        }
        cout << team << endl;
    }
}