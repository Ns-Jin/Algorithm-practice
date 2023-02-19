#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    stack<char> s;
    queue<char> q;

    bool is_tag = false;
    if(str[0] == '<') {
        is_tag = true;
    }
    for(int i=0;i<str.length();i++) {
        if(is_tag) {
            if(str[i] == '>') {
                q.push(str[i]);
                while(!q.empty()) {
                    cout << q.front();
                    q.pop();
                }
                is_tag = false;
            }
            else {
                q.push(str[i]);
            }
        }
        else {
            if(str[i] == '<') {
                while(!s.empty()) {
                    cout << s.top();
                    s.pop();
                }
                q.push(str[i]);
                is_tag = true;
            }
            else if(str[i] == ' ') {
                while(!s.empty()) {
                    cout << s.top();
                    s.pop();
                }
                cout << ' ';
            }
            else {
                s.push(str[i]);
            }
        }
    }

    if(is_tag) {
        while(!q.empty()) {
            cout << q.front();
            q.pop();
        }
    }
    else {
        while(!s.empty()) {
            cout << s.top();
            s.pop();
        }
    }
}