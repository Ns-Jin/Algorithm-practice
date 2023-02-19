#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        int m;
        cin >>m;
        string temp[2];
        map<string, int> map_;
        for(int j=0;j<m;j++) {
            cin >> temp[0] >> temp[1];
            if(map_.find(temp[1]) == map_.end()) {
                map_.insert({temp[1],1});
            }
            else {
                map_[temp[1]]++;
            }
        }
        int result = 1;
        for (auto i : map_) {
            result *= (i.second + 1);
        }
        result -= 1;
        cout << result << '\n';
    }
}