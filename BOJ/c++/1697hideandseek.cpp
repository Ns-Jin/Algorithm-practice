#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> space;
queue<int> q;
vector<bool> visit;

bool possible(int n) {
    if (n < 0 || n > 100000) {
        return false;
    }
    else if (visit[n] == true) {
        return false;
    }

    return true;
}

void temp(int n) {
    if(possible(n)) {
        q.push(n);
        visit[n] = true;
        space[n] = space[q.front()] + 1;
    }
}

void push(int now_space) {
    temp(now_space + 1);
    temp(now_space - 1);
    temp(now_space * 2);
}

int bfs(int n, int k) {
    int now_space = n;
    space[now_space] = 0;
    visit[now_space] = true;
    q.push(now_space);
    push(now_space);
    q.pop();

    while(!q.empty()) {
        push(q.front());
        q.pop();
    }

    return space[k];
}

int main() {
    int n,k, result;
    cin >> n >> k;

    space.resize(100001);
    visit.resize(100001);
    

    result = bfs(n, k);

    cout << result << endl;
}