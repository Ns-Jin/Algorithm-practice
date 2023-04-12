#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;
vector<bool> poll;
queue<int> result;

void bfs(int n) {
    queue<int> poll_citys;
    priority_queue<int, vector<int>, greater<int>> temp_result;
    for(int i=1;i<n+1;i++) {
        if(poll[i]) {
            poll_citys.push(i);
        }
    }
    if(poll_citys.size() == n) {
        return;
    }
    while(!poll_citys.empty()) {
        int temp = poll_citys.front();
        poll_citys.pop();
        for(int j=1;j<n+1;j++) {
            if(map[temp][j] > 0) {
                map[temp][j]--;
                map[j][temp]--;
                if(map[temp][j] == 0) {
                    if(!poll[j]) {
                        temp_result.push(j);
                        poll[j] = true;
                    }
                    map[temp][j]--;
                    map[j][temp]--;
                }
            }
        }
    }
    while(!temp_result.empty()) {
        int temp = temp_result.top();
        temp_result.pop();
        result.push(temp);
    }
    bfs(n);
}

int main() {
    int n, c1, c2;
    cin >> n >> c1 >> c2;

    map.resize(n+1, vector<int>(n+1, -1));
    poll.resize(n+1,false);
    for(int i=0;i<n-1;i++) {
        int x,y,l;
        cin >> x >> y >> l;
        map[x][y] = l;
        map[y][x] = l;
    }
    poll[c1] = true;
    poll[c2] = true;
    bfs(n);
    while(!result.empty()) {
        int temp = result.front();
        result.pop();
        cout << temp << endl;
    }
}