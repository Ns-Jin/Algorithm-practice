#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited = {false,};
vector<vector<int>> graph;
vector<int> visit;

void dfs(int s_node) {
    visit.push_back(s_node);
    visited[s_node] = true;
    for(auto iter:graph[s_node]) {
        if(visited[iter] == false) {
            dfs(iter);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,r;
    cin >> n >> m >> r;
    
    visited.resize(n+1);
    graph.resize(n+1);
    
    for(int i=0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<n+1;i++) {
        sort(graph[i].begin(), graph[i].end(), greater<>());
    }
    dfs(r);

    int result[n+1] = {0,};
    for(int i=0;i<visit.size();i++) {
        result[visit[i]] = i+1;
    }
    for(int i=1;i<n+1;i++) {
        cout << result[i] << '\n';
    }
}