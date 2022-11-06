#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 0;
    cin >> n;
    int sequence[n];
    for(int i=0;i<n;i++) {
        cin >> sequence[i];
    }

    stack<int> s;
    queue<char> q;
    int last_num = 0;
    string result;
    for(int i=0;i<n;i++) {
        if(sequence[i] > last_num) {
            for(int j=last_num;j<sequence[i];j++) {
                s.push(j);
                last_num++;
                q.push('+');
            }
            s.pop();
            q.push('-');
        }
        else if(!s.empty() && sequence[i] <= s.top()) {
            while(sequence[i] < s.top()) {
                if(s.empty()) {
                    break;
                }
                s.pop();
                q.push('-');
            }
            if(!s.empty()) {
                s.pop();
                q.push('-');
            }
            
        }
        else {
            result = "NO";
            break;
        }
    }

    if(result == "NO") {
        cout << result << '\n';
    }
    else {
        while(!q.empty()) {
            cout << q.front() << '\n';
            q.pop();
        }
    }

    return 0;
}