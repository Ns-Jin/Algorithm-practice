#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    string n;
    cin >> n;
    long long sum_digit = 0;
    int num_count[10] = {};

    for(int i=0;i<n.length();i++) {
        int num = n[i] - '0';
        num_count[num]++;
        sum_digit += num;
    }

    if(num_count[0] != 0 && sum_digit % 3 == 0) {
        for(int i=9;i>=0;i--) {
            int count = num_count[i];
            for(int j=0;j<count;j++) {
                cout << i;
            }
        }
        cout << endl;
    }
    else {
        cout << -1 << endl;
    }
}