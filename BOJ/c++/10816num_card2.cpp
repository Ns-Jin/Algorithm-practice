#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> card(n);
    for(int i=0;i<n;i++) {
        cin >> card[i];
    }
    sort(card.begin(), card.end());

    int m;
    cin >> m;
    for(int i=0;i<m;i++) {
        int num;
        cin >> num;
        int start_index = 0;
        int end_index = n-1;
        if(num < card[start_index] || num > card[end_index]) {
            cout << 0 << " ";
        }
        else {
            bool isFind = false;
            int find_start = -1;
            int find_end = -1;
            while(start_index <= end_index) {
                int half_index = (start_index + end_index) / 2;
                if(num <= card[half_index]) {
                    end_index = half_index -1;
                }
                else {
                    start_index = half_index + 1;
                }
            }
            find_start = start_index;
            start_index = 0;
            end_index = n-1;
            while(start_index <= end_index) {
                int half_index = (start_index + end_index) / 2;
                if(num >= card[half_index]) {
                    start_index = half_index + 1;
                }
                else {
                    end_index = half_index - 1;
                }
            }
            find_end = end_index;
            if(find_start == -1 || find_end == -1) {
                cout << 0 << " ";
            }
            else {
                cout << find_end - find_start + 1 << " ";
            }
        }
    }

}