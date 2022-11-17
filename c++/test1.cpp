#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> test;
int main() {
    for(int i=0;i<5;i++) {
        string tt = "Test";
        test.push_back(vector<string>());
        test[i].push_back(tt);
    }
    for(int i=0;i<5;i++) {
        cout << test[i][0] << endl;
    }
}