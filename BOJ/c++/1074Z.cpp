#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n,r,c;
    cin >> n >> r >> c;
    int count = 0;
    while(n > 0) {
        int mid = pow(2,n-1);
        bool isLeft = false;
        bool isUp = false;
        if(r < mid) {
            isUp = true;
        }
        if(c < mid) { 
            isLeft = true;
        }
        if(isUp) {
            if(!isLeft) {
                count += pow(2,n)*pow(2,n)/4;
                c -= mid;
            }
        }
        else {
            if(isLeft) {
                count += 2 * pow(2,n)*pow(2,n)/4;
                r -= mid;
            }
            else {
                count += 3 * pow(2,n)*pow(2,n)/4;
                r -= mid;
                c -= mid;
            }
        }
        n = n-1;
    }
    cout << count << endl;
}