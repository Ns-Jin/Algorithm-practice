#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    string n;
    cin >> n;
    priority_queue<int> pq;
    int sum_digit = 0;
    bool is_include_zero = false;
    int result = 0;

    for(int i=0;i<n.length();i++) {
        pq.push(n[i]-'0');
        sum_digit = n[i] - '0';
        if((n[i]-'0') == 0) {
            is_include_zero = true;
        }
    }

    if(is_include_zero && sum_digit % 3 == 0) {
        while(!pq.empty()) {
            cout << pq.top();
            pq.pop();
        }
    }
    else {
        cout << -1 << endl;
    }
}