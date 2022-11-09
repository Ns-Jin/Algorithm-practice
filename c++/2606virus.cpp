#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited = {false,};
queue<int> q;
int result = -1;

void dfs(int s) {   //s: start computer
    result++;
    visited[s] = true;
    for(auto iter:graph[s]) {
        if(visited[iter] == false) {
            dfs(iter);
        }
    }
}

void bfs(int s) {
    result++;
    visited[s] = true;
    q.push(s);
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        for(auto iter:graph[temp]) {
            if(visited[iter] == false) {
                visited[iter] = true;
                result++;
                q.push(iter);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int c;  //연결된 쌍의 수
    cin >> c;

    graph.resize(n+1);
    visited.resize(n+1);

    for(int i=0;i<c;i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);
    cout << result << endl;
}
