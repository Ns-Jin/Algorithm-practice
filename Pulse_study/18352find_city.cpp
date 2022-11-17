#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> cities;
vector<int> shortest_distance;
queue<int> visit;

void bfs(int s_city) {
    int distance = 0;
    visit.push(s_city);
    shortest_distance[s_city] = distance;
    while(!visit.empty()) {
        int temp = visit.front();
        distance = shortest_distance[temp] + 1;
        visit.pop();
        for(auto iter:cities[temp]) {
            if(shortest_distance[iter] == -1) {
                shortest_distance[iter] = distance;
                visit.push(iter);
            }
        }
    }
}

int main() {
    int n,m,k,x;
    cin >> n >> m >> k >> x;
    cities.resize(n+1);
    shortest_distance.resize(n+1, -1);

    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        cities[a].push_back(b);
    }
    bfs(x);
    bool is_find = false;
    for(int i=1;i<n+1;i++) {
        if(shortest_distance[i] == k) {
            is_find = true;
            cout << i << endl;
        }
    }
    if(is_find == false) {
        cout << -1 << endl;
    }

}   