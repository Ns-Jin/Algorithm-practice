#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<bool>> visited;
queue<pair<int, int>> q;
priority_queue<int, vector<int>, greater<int>> results;
vector<vector<int>> map;

bool possible_adjacent(int x, int y) {
    if(x < 0 || x >= visited.size() || y < 0 || y >= visited.size()) {
        return false;
    }
    if(map[x][y] == 0) {
        return false;
    }
    if(visited[x][y]) {
        return false;
    }
    return true;
}
void bfs(int x, int y) {
    int result = 1;
    visited[x][y] = true;
    q.push(make_pair(x,y));
    while(!q.empty()) {
        int temp_x = q.front().first;
        int temp_y = q.front().second;
        q.pop();
        if(possible_adjacent(temp_x-1,temp_y)) {
            q.push(make_pair(temp_x-1,temp_y));
            visited[temp_x-1][temp_y] = true;
            result++;
        }
        if(possible_adjacent(temp_x+1,temp_y)) {
            q.push(make_pair(temp_x+1,temp_y));
            visited[temp_x+1][temp_y] = true;
            result++;
        }
        if(possible_adjacent(temp_x,temp_y-1)) {
            q.push(make_pair(temp_x,temp_y-1));
            visited[temp_x][temp_y-1] = true;
            result++;
        }
        if(possible_adjacent(temp_x,temp_y+1)) {
            q.push(make_pair(temp_x,temp_y+1));
            visited[temp_x][temp_y+1] = true;
            result++;
        }
    }
    results.push(result);
}

int main() {
    int n;
    cin >> n;
    visited.resize(n, vector<bool>(n,false));
    map.resize(n, vector<int>(n,0));
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(map[i][j] == 1 && visited[i][j] == false) {
                bfs(i,j);
            }
        }
    }
    cout << results.size() << endl;
    while(!results.empty()) {
        cout << results.top() << endl;
        results.pop();
    }
}