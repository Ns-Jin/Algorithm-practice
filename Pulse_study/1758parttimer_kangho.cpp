#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long think_tips[n];
    long long recived_tip = 0;
    for(int i=0;i<n;i++) {
        cin >> think_tips[i];
    }
    sort(think_tips, think_tips+n);
    reverse(think_tips, think_tips+n);
    for(int i=0;i<n;i++) {
        int tip = think_tips[i] - i;
        if(tip > 0){
            recived_tip += tip;
        }
        else {
            break;
        }
    }
    cout << recived_tip << endl;
}