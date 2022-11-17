#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n;
    int a_n[n];
    for(int i=0;i<n;i++) {
        cin >> a_n[i];
    }
    sort(a_n, a_n+n);

    cin >> m;
    for(int i=0;i<m;i++) {
        int num;
        int start_index = 0;
        int end_index = n-1;

        cin >> num;
        if(num < a_n[start_index] || num > a_n[end_index]) {
            cout << 0 << '\n';
        }
        else {
            while(start_index <= end_index) {
                int half_index = (start_index + end_index) / 2;
                if(num == a_n[half_index]) {
                    cout << 1 << '\n';
                    break;
                }
                else if(num < a_n[half_index]) {
                    end_index = half_index -1;
                }
                else {
                    start_index = half_index + 1;
                }
            }
            if(start_index > end_index) {
                cout << 0 << '\n';
            }
        }
    }
}