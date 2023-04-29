#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void fix_invalid(vector<int>& v,int k) {
    int s_i = -1, target_s = -1, target_e = -1, e_i = k-1;
    stack<int> s;
    bool end = false;
    for(int i=0;i<k;i++) {
        if(s_i == -1) {
            if(-v[i] - 1 == i) {
                v[i] = -v[i];
                end = true;
                s_i = 0;
                break;
            }
            if(v[i]-1 != i) {
                s_i = i;
            }
        }
        else {
            if(v[i]-1 == i) {
                e_i = i-1;
                break;
            }
        }
    }
    if(end) {
        return;
    }
    for(int i=s_i;i<=e_i;i++) {
        if(v[i] == -(e_i + 1)) {
            target_e = i;
        }
        else if(v[i] == -(s_i + 1)) {
            target_s = i;
        }
    }
    if(target_s != -1) {
        for(int i=s_i;i<=target_s;i++) {
            s.push(v[i]);
        }
        while(!s.empty()) {
            v[s_i++] = 0-s.top();
            s.pop();
        }
    }
    else if(target_e != -1) {
        for(int i=target_e;i<=e_i;i++) {
            s.push(v[i]);
        }
        while(!s.empty()) {
            v[target_e++] = 0-s.top();
            s.pop();
        }
    }
}
bool valid(vector<int>& v, int k) {
    for(int i=0;i<k;i++) {
        if(v[i]-1 != i)
            return false;
    }
    return true;
}

int main() {
    int k;
    cin >> k;
    vector<int> v(k);
    for(int i=0;i<5;i++) {
        for(int j=0;j<k;j++) {
            cin >> v[j];
        }
        fix_invalid(v,k);
        if(valid(v,k))
            cout << "one" << '\n';
        else {
            fix_invalid(v,k);
            if(valid(v,k))
                cout << "two" << '\n';
            else
                cout << "over" << '\n';
        }
    }
}