#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

vector<vector<int>> map;    //현재 map 상태 표시 vector
vector<vector<bool>> visit;   //방문했는지 확인 vector
vector<vector<int>> dist;     //거리 계산을 위한 vector
// 이동할 수 있는 주변 위치
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0 , 1};


bool possible_move(int i, int j) {
    //이동가능한지 확인하는 함수, 맵을 벗어나는지, 방문했는지, 이동할 수 있는지
    return i >= 0 && i < map.size() && j >= 0 && j <= map[0].size() && !visit[i][j] && map[i][j] == 1;
}

void bfs(int s_i, int s_j, int e_i, int e_j) {
    //bfs로 최단 경로 확인
    queue<pair<int, int>> q;    //노드들 저장할 q
    for(int i=0;i<4;i++) {
        int t_i = s_i + dx[i];
        int t_j = s_j + dy[i];
        if(possible_move(t_i, t_j)) {   
            //이동 가능하면 q에 push, 방문처리, 거리 계산
            q.push(make_pair(t_i,t_j));
            visit[t_i][t_j] = true;
            dist[t_i][t_j] = dist[s_i][s_j] + 3;
        }
    }
    int tt_i, tt_j;
    while(!q.empty()) {
        tt_i = q.front().first;
        tt_j = q.front().second;
        for(int i=0;i<4;i++) {
            int t_i = tt_i + dx[i];
            int t_j = tt_j + dy[i];
            if(possible_move(t_i, t_j)) {
                //이동 가능하면 q에 push, 방문처리, 거리 계산
                q.push(make_pair(t_i,t_j));
                dist[t_i][t_j] = dist[tt_i][tt_j] + 3;
                visit[t_i][t_j] = true;
                if(t_i == e_i && t_j == e_j) {
                    //목적지 도달시 종료
                    return;
                }
            }
        }
        q.pop();
    }
}

int main() {
    int m,n,s, ob;
    cin >> m >> n >> s;
    map.resize(m, vector<int>(n, 1));
    dist.resize(m, vector<int>(n, 0));
    visit.resize(m, vector<bool>(n, false));
    for(int i=0;i<s;i++) {
        int t_i, t_j;
        cin >> ob >> t_i >> t_j;
        map[t_i][t_j] = 0;
    }
    int s_i, s_j, e_i, e_j;
    string tra;
    cin >> tra >> s_i >> s_j;
    cin >> tra >> e_i >> e_j;
    cin >> tra >> ob;
    for(int i=0;i<ob;i++) {
        int p1_i,p1_j,p2_i,p2_j;
        cin >> p1_i >> p1_j >> p2_i >> p2_j;
        for(int j=min(p1_i,p2_i);j<=max(p1_i,p2_i);j++) {
            for(int k=min(p1_j,p2_j);k<=max(p1_j,p2_j);k++) {
                //장애물 구역 표시
                map[j][k] = 0;
            }
        }
    }

    bfs(s_i, s_j, e_i, e_j);
    //bfs를 통해 구한 출발지로부터 목적지로의 최단거리 출력
    cout << dist[e_i][e_j] << endl;
}