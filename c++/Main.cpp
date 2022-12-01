#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

vector<long long> dp_3;

int main() {
    long long dp[6] = {0,};
    dp[1] = 3;
    dp[2] = 9;
    dp[3] = 26;
    dp[4] = 76;
    dp[5] = 226; 
    long long n;
    cin >> n;
    
    if(n < 6) {
        cout << dp[n] << endl;
    }
    else {
        dp_3.resize(n);
        dp_3[0] = 1;
        dp_3[1] = 3;
        dp_3[2] = 9;
        dp_3[3] = 27;
        for(long long i=4;i<n;i++) {
            dp_3[i] = dp_3[i-1] * 3 % 1000000007;
        }
        long long result = 0;
        result = dp_3[n] - (2*dp_3[n-3]) % 1000000007 + 1;
        cout << result << endl;
    }
}