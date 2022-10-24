#include <iostream>

using namespace std;

int get_gcm(int a, int b) {
    if(a < b) {
        int temp = a;
        a = b; 
        b = temp;
    }
    if(b == 0) {
        return a;
    }
    else {
        return get_gcm(b, a%b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    int result[1001];
    result[1] = 3;
    for(int i=2;i<1001;i++) {
        int count = 0 ;
        for(int j=1;j<i;j++) {
            if(get_gcm(i,j) == 1) {
                count++;
            }
        }
        result[i] = result[i-1] + 2*count;
    }
    for(int i=0;i<c;i++) {
        int n;
        cin >> n;
        
        cout << result[n] << endl;
    }
}