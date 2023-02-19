#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<pair<int,string>> dict;
    for(int i=1;i<=n;i++) {
        string temp;
        cin >> temp;
        dict.push_back(make_pair(i, temp));
    }
    for(int i=0;i<m;i++) {

    }
}