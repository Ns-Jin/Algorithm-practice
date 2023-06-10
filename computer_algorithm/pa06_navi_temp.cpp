#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visit;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0 , 1};

int count = 0;

int f(int s_i, int s_j, int e_i, int e_j) {
    int h = sqrt(pow(abs(e_j-s_j),2) + pow(abs(e_i - s_i),2));
    int g = abs(e_j-s_j) + abs(e_i - s_i);
    
    return h + g;
}

void a_star(int s_i, int s_j, int e_i, int e_j) {
    if(s_i == e_i && s_j == e_j) {
        return;
    }
    count += 3;
    cout << count << " " << s_i << " " << s_j << endl;
    int min = 0;
    int min_i, min_j;
    for(int i=0;i<4;i++) {
        int t_i = s_i + dx[i];
        int t_j = s_j + dy[i];
        if(t_i >= 0 && t_i < map.size() && t_j >= 0 && t_j <= map[0].size()) {
            if(!visit[t_i][t_j] && map[t_i][t_j] == 1) {
                if(min == 0 || (min != 0 && min > f(t_i, t_j, e_i, e_j))) {
                    min_i = t_i;
                    min_j = t_j;
                    min = f(min_i, min_j, e_i, e_j);
                }
            }
        }
    }
    visit[min_i][min_j] = true;
    a_star(min_i, min_j, e_i, e_j);
}

int main() {
    int m,n,s, ob;
    cin >> m >> n >> s;
    map.resize(m, vector<int>(n, 1));
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
        for(int j=p1_i;j<=p2_i;j++) {
            for(int k=p1_j;k<=p2_j;k++) {
                map[j][k] = 0;
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << map[i][j];
        }
        cout << endl;
    }

    a_star(s_i, s_j, e_i, e_j);
    cout << count << endl;
}