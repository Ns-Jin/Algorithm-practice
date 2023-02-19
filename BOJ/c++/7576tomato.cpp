#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> tomato;
vector<vector<bool>> riped;

void bfs(int s) {

}

int main() {
    int m,n;
    cin >> m >> n;

    tomato.resize(n);
    riped.resize(n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int temp;
            cin >> temp;
            tomato[i].push_back(temp);
        }
    }
    
}