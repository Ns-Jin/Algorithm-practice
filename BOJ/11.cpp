#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin >> n;
    vector<int> time(n+1,0);
    for(int i=0;i<n;i++) {
        int s,e;
        cin >> s >> e;
        time[s]++;
        time[e]++;
    }
    cin >> q;
    for(int i=0;i<q;i++) {
        int temp;
        cin >> temp;
        cout << temp << '\n';
    }
}