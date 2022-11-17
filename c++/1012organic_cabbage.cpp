#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> land;
vector<vector<bool>> visited;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool possible_adjacent(int x, int y) {
    if(x < 0 || x >= land.size() || y < 0 || y >= land[0].size()) {
        return false;
    }
    if(land[x][y] == 0) {
        return false;
    }
    if(visited[x][y]) {
        return false;
    }
    return true;
}

void dfs(int a, int b) {
    visited[a][b] = true;
    for(int i=0;i<4;i++) {
        if(possible_adjacent(a+dx[i], b+dy[i])) {
            dfs(a+dx[i], b+dy[i]);
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int width, height, location;
        cin >> width >> height >> location;

        int count = 0;
        land.clear();
        visited.clear();
        land.resize(height, vector<int>(width, 0));
        visited.resize(height, vector<bool>(width, false));

        for(int j=0;j<location;j++) {
            int temp[2];
            cin >> temp[0] >> temp[1];
            land[temp[1]][temp[0]] = 1;
        }
        for (int j=0;j<height;j++) {
            for(int k=0;k<width;k++) {
                if(land[j][k] == 1 && visited[j][k] == false) {
                    dfs(j,k);
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}