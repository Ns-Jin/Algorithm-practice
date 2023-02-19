#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    int n,m;
    cin >> n >> m;

    int lalpa[m];
    for(int i=0;i<m;i++) {
        cin >> lalpa[i];
    }

    int scab_count = 0;
    for(int i=1;i<n;i++) {
        int other_streamer[m];
        for(int i=0;i<m;i++) {
            cin >> other_streamer[i];
        }

        int gap = 0;
        for(int i=0;i<m;i++) {
            gap += abs(lalpa[i] - other_streamer[i]);
        }
        if(gap > 2000) {
            scab_count++;
        }
    }

    int judgment = 0;
    if(n%2 == 0) {
        judgment = n/2;
    }
    else {
        judgment = (n-1) /2;
    }

    if(scab_count >= judgment) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}