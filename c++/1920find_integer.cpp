#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n,m;

    cin >> n;
    int A[n];
    for(int i=0;i<n;i++) {
        cin >> A[i];
    }

    cin >> m;
    int B[m];
    for(int i=0;i<m;i++) {
        cin >> B[i];
    }

    sort(A,A+n);
    sort(B,B+m);

    int last_index = 0;
    for(int i=0;i<m;i++) {
        bool found = false;
        for(int j=last_index;j<n;j++){
            if(B[i] == A[j]) {
                found = true;
                last_index++;
                break;
            }
            else if(B[i] < A[j]) {
                break;
            }
            else {
                last_index++;
            }
        }
        if(found) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}