#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int nums[9];
    for(int i=0;i<9;i++) {
        cin >> nums[i];
    }
    sort(nums,nums+9);
    int center = nums[4] * 2;
    bool is_true = true;
    for(int i=0;i<4;i++) {
        if(center != nums[i] + nums[8-i]) {
            is_true = false;
        }
    }
    if(is_true) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}