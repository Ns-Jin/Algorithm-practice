#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int k,m;
    cin >> k >> m;
    int charger[k];
    for(int i=0;i<k;i++) {
        cin >> charger[i];
    }
    for(int i=0;i<m;i++) {
        int p, c;
        cin >> p >> c;
        int range_begin = p-c;
        int range_end = p+c;
        int count = 0;
        for(int j=0;j<k;j++) {
            if(charger[j] >= range_begin && charger[j] <= range_end) {
                count++;
            }
        }
        cout << count << endl;
    }
}