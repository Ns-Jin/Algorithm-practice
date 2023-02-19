#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int result[N];

    result[0] = 0;
    int min, max;
    cin >> min;
    max = 0;
    for(int i=1;i<N;i++) {
        int temp;
        cin >> temp;
        if(temp <= min) {
            min = temp;
            result[i] = result[i-1];
        }
        else {
            if(temp-min > result[i-1]) {
                result[i] = temp - min;
            }
            else {
                result[i] = result[i-1];
            }
        }
    }
    for(int i=0;i<N-1;i++) {
        cout << result[i] << ' ';
    }
    cout << result[N-1] << endl;
}