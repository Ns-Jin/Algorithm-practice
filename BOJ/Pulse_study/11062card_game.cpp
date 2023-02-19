#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> next_map;
vector<vector<int>> visited;
queue<pair<int,int>> q;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool isPossible(int x,int y) {
	int x_size = map.size();
	int y_size = map[0].size();
	if(x < 0 || x >= x_size) {
		return false;
	}
	if(y < 0 || y >= y_size) {
		return false;
	}
	if(map[x][y] == 1) {
		return false;
	}
	if(visited[x][y] == 1) {
		return false;
	}
	
	return true;
}

bool isPo(int x, int y) {
	int x_size = map.size();
	int y_size = map[0].size();
	if(x < 0 || x > x_size-1) {
		return false;
	}
	if(y < 0 || y >y_size-1) {
		return false;
	}
	
	return true;
}

void bfs(int x, int y) {
	visited[x][y] = 1;
	q.push(make_pair(x,y));
	while(!q.empty()) {
		int cur[2];
		cur[0] = q.front().first;
		cur[1] = q.front().second;
		q.pop();
		for(int i=0;i<4;i++) {
			int nx = cur[0] + dx[i];
			int ny = cur[1] + dy[i];
			if(isPossible(nx,ny)) {
				q.push(make_pair(nx,ny));
				visited[nx][ny] = 1;
				for(int j=0;j<4;j++) {
					int _nx = nx + dx[j];
					int _ny = ny + dy[j];
					if(isPo(_nx,_ny)) {
						next_map[_nx][_ny] = 0;
					}
				}
			}
		}
	}
}

int main(void){
	int n, n_;
	cin >> n >> n_;
	map.resize(n,vector<int>(n_,0));
	next_map.resize(n,vector<int>(n_,0));
	visited.resize(n,vector<int>(n_,0));
	for(int i=0;i<n;i++) {
		for(int j=0;j<n_;j++) {
			char temp = cin.get();
			if(temp == '\n') {
				temp = cin.get();
			}
			map[i][j] = temp - '0';
			next_map[i][j] = temp - '0';
		}
	}
	
	bfs(0,0);
	int result = 0;
	while(true) {
		bool isEnd = true;
		for(int i=0;i<n;i++) {
			if(isEnd == false) {
				break;
			}
			for (int j=0;j<n_;j++) {
				if(map[i][j] == 1) {
					isEnd = false;
					break;
				}
			}
		}
		if(isEnd) {
			break;
		}
		else {
			result++;
			for(int i=0;i<n;i++) {
				for(int j=0;j<n_;j++) {
					map[i][j] = next_map[i][j];
					visited[i][j] == 0;
				}
			}
			bfs(0,0);
		}
	}
	
	cout << result << endl;
	
	return 0;
}

