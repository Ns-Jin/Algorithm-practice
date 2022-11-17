#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> maze;
vector<vector<bool>> visited;
vector<vector<int>> count;
queue<pair<int,int>> q;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool possible_adjacent(int x, int y) {
    if(x < 0 || x >= maze.size() || y < 0 || y >= maze[0].size()) {
        return false;
    }
    if(maze[x][y] == 0) {
        return false;
    }
    if(visited[x][y]) {
        return false;
    }
    return true;
}

void bfs(int sx, int sy) {
    visited[sx][sy] = true;
    q.push(make_pair(sx,sy));
    count[sx][sy] = 1;
    while(!q.empty()) {
        int cur_location[2];
        cur_location[0] = q.front().first;
        cur_location[1] = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            if(possible_adjacent(cur_location[0] + dx[i], cur_location[1] + dy[i])) {
                q.push(make_pair(cur_location[0] + dx[i], cur_location[1] + dy[i]));
                visited[cur_location[0] + dx[i]][cur_location[1] + dy[i]] = true;
                count[cur_location[0] + dx[i]][cur_location[1] + dy[i]] = count[cur_location[0]][cur_location[1]] + 1;
            }
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    maze.resize(n, vector<int>(m,0));
    count.resize(n, vector<int>(m,0));
    visited.resize(n, vector<bool>(m,false));

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%1d", &maze[i][j]);
        }
    }
    bfs(0,0);
    cout << count[n-1][m-1] << endl;
}