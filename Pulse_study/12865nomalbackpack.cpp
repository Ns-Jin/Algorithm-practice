#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int things[n][2];
    vector<pair<int,int>> v;
    int a,b;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        v.push_back(pair<int,int>(a,b));
    }
    sort(v.begin(),v.end());

    for(int i=0;i<n;i++) {
        things[i][0] = v[i].first;
        things[i][1] = v[i].second;
    }

    int result_max = 0;
    int dp[100001];
    for(int i=0;i<100001;i++) {
        for(int j=0;j<n;j++) {
            
        }
    }
    cout << result_max << endl;
}