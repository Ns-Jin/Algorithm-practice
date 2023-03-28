#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> coordi(n);
    vector<int> result(n);

    for(int i=0;i<n;i++) {
        cin >> coordi[i].first;
        coordi[i].second = i;
    }

    sort(coordi.begin(), coordi.end());

    int pre_n = coordi[0].first;
    int count = 0;
    
    for(int i=0;i<n;i++) {
        if(pre_n < coordi[i].first) {
            count++;
        }
        result[coordi[i].second] = count;
        pre_n = coordi[i].first;
    }

    for(int i=0;i<n;i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}