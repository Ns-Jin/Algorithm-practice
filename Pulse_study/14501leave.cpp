#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int schedule[n][2];

    for(int i=0;i<n;i++) {
        cin >> schedule[i][0] >> schedule[i][1];
    }

    int dp[n+1] = {0,};
    for(int i=n-1;i>=0;i--) {
        if(i+schedule[i][0] > n) {     //일이 퇴사기간을 넘기면
            dp[i] = dp[i+1];
        }
        else {
            dp[i] = max(dp[i+1], schedule[i][1] + dp[i + schedule[i][0]]); //i+Ti
        }
    }

    cout << dp[0] << endl;
}