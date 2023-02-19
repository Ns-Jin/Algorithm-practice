#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sequence[n];

    for(int i=0;i<n;i++) {
        cin >> sequence[i];
    }

    int max_integer = sequence[0];

    int dp[n];
    dp[0] = 1;
    int result = 0;
    for(int i=1;i<=n;i++) {
        dp[i] = 1;
        for(int j=1;j<i;j++) {
            if(sequence[i] > sequence[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(dp[i], result);
    }

    cout << result << endl;
}