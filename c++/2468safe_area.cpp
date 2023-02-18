#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector <int>> map;
vector<vector <bool>> visited;
vector<vector <bool>> submerged;
queue<pair<int, int>> q;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void reset(int n, int height) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            visited[i][j] = false;
            if(map[i][j] <= height) {
                submerged[i][j] = true;
            }
            else {
                submerged[i][j] = false;
            }
        }
    }
}

void bfs(int i, int j) {
    visited[i][j] = true;
    q.push(make_pair(i,j));

    while(!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();

        for(int k=0;k<4;k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if(!(nx < 0 || ny < 0 || nx >= map.size() || ny >= map.size())) {
                if(!submerged[nx][ny] && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }

}

int main() {
    int n;
    cin >> n;

    map.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n));
    submerged.resize(n, vector<bool>(n));

    int max_area = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> map[i][j];
            if(max_area < map[i][j]) {
                max_area = map[i][j];
            }
        }
    }
    
    int max_safety_area = 0;
    int count = 0;
    for(int k=0;k<max_area;k++) {
        reset(n, k);
        count = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(!submerged[i][j] && !visited[i][j]) {
                    bfs(i,j);
                    count++;
                }
            }
        }

        if(count > max_safety_area) {
            max_safety_area = count;
        }
    }

    cout << max_safety_area;
}