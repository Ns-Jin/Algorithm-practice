#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int dp_0[n+1];
    int dp_1[n+1];
    int dp_2[n+1];
        

    int volume[n+1];
    volume[0] = 0;

    for(int i=1;i<=n;i++) {
        cin >> volume[i];
    }

    dp_0[1] = 0;
    dp_1[1] = volume[1];
    dp_2[1] = volume[1];

    for(int i=2;i<=n;i++) {
        if(volume[i] == 0) {
            dp_1[i] = dp_1[i-1];
            dp_2[i] = dp_2[i-1];
        }
        else {
            dp_1[i] = dp_0[i-1]+ volume[i];
            dp_2[i] = dp_1[i-1] + volume[i];
        }
        dp_0[i] = max(dp_2[i-1],dp_1[i-1]);
        dp_0[i] = max(dp_0[i],dp_0[i-1]);
    }

    int temp = max(dp_0[n], dp_1[n]);

    cout << max(temp, dp_2[n]);
}