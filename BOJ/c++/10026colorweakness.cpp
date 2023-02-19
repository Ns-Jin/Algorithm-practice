#include<iostream>
#include<string>

using namespace std;

int main() {
    int n;
    cin >> n;
    char painting[n][n];
    for(int i=0;i<n;i++) {
        string temp;
        cin >> temp;
        for(int j=0;j<n;j++) {
            painting[i][j] = temp[j];
        }
    }
    char counting_char[3];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(painting[i][j])
        }

    }
}