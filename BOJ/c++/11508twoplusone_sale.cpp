#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int dairys[n];
    for(int i=0;i<n;i++) {
        cin >> dairys[i];
    }
    sort(dairys,dairys+n);
    reverse(dairys,dairys+n);

    int cost = 0;
    for(int i=0;i<n-n%3;i+=3) {
        cost += dairys[i] + dairys[i+1];
    }
    if(n%3 == 1) {
        cost += dairys[n-1];
    }
    else if(n%3 == 2) {
        cost += dairys[n-1] + dairys[n-2];
    }

    cout << cost;

}