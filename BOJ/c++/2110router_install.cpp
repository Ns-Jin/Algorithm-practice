#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n,c;
    cin >> n >> c;

    int houses[n];
    for(int i=0;i<n;i++) {
        cin >> houses[i];
    }
    sort(houses, houses+n);

    int start_index = 0;
    int end_index = n-1;
    while(start_index <= end_index) {
        int half_index = (start_index + end_index) / 2;
        int gap = houses[half_index] - houses[start_index];
        for(int i=houses[start_index];i) 
    }
}