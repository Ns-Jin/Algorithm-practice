#include <iostream>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int moneys[n];
    int max_money = 0;
    for(int i=0;i<n;i++) {
        cin >> moneys[i];
        if(max_money < moneys[i]) {
            max_money = moneys[i];
        }
    }

    
}