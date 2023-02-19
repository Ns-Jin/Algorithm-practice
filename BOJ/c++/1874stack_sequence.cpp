#include<iostream>
#include<queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int sequence[n+1] = {0,};

    int high_in_stack = 0;
    for(int i=0;i<n;i++) {
        int input;
        cin >> input;

        if(high_in_stack < input) {
            for(int j=high_in_stack+1;j<=input;j++) {
                cout << '+' << '\n';
                sequence[j] = 1;
            }
            cout << '-' << '\n';
            sequence[input] = 0;
            high_in_stack = input;
        }
        else {
            for(int j=high_in_stack-1;j>=input;j--) {
                if(sequence[j] == 1) {
                    cout << '-' << '\n';
                    sequence[j] = 0;
                }
            }
        }
    }
}