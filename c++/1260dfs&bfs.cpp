#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited = {false,};
queue<int> q;

void dfs(int s) {
    visited[s] = true;
    cout << s << " ";
    for(auto iter:graph[s]) {
        if(visited[iter] == false) {
            visited[iter] = true;
            dfs(iter);
        }
    }
}

void bfs(int s) {
    visited[s] = true;
    q.push(s);
    while(!q.empty()) {
        int temp = q.front();
        cout << temp << " ";
        q.pop();
        for(auto iter:graph[temp]) {
            if(visited[iter] == false) {
                visited[iter] = true;
                q.push(iter);
            }
        }
    }
}

int main() {
    int n,m,v;
    cin >> n >> m >> v;
    graph.resize(n+1);
    visited.resize(n+1);

    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<n+1;i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout << endl;
    for(auto iter:visited) {
        iter = false;
    }
    bfs(v);
}