#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int i=0;i<t;i++) {
        int n;
        cin >> n;
        int sticker[2][n+1];
        for(int j=1;j<n+1;j++) {
            cin >> sticker[0][j];
        }
        for(int j=1;j<n+1;j++) {
            cin >> sticker[1][j];
        }

        int dp_one[n+1];
        int dp_two[n+1];

        dp_one[0] = 0;
        dp_two[0] = 0;
        dp_one[1] = sticker[0][1];
        dp_two[1] = sticker[1][1];
        dp_one[2] = dp_two[1] + sticker[0][2];
        dp_two[2] = dp_one[1] + sticker[1][2];

        for(int j=3;j<=n;j++) {
            dp_one[j] = max(dp_two[j-1], dp_two[j-2])  + sticker[0][j];
            dp_two[j] = max(dp_one[j-1], dp_one[j-2])  + sticker[1][j];
        }

        cout << max(dp_one[n],dp_two[n]) << endl;

    }
}