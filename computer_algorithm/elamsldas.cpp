#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> target(4,0);

bool comp(vector<int> a, vector<int> b) {
    float a_value = 0;
    float b_value = 0;
    for(int i=0;i<4;i++) {
        if (target[i] > a[i])
            a_value += static_cast<float>(target[i] - a[i]) / target[i];
        else
            a_value += 1;
        if (target[i] > b[i])
            b_value += static_cast<float>(target[i] - b[i]) / target[i];
        else
            b_value += 1;
    }
    a_value = a_value / a[4];
    b_value = b_value / b[4];
    return a_value > b_value;
}

struct Node {
    int level, bound, cost;
    int mp, mf, ms, mv;
    queue<int> sel;
    int min_index;
    bool operator<(const Node& other) const {
        return bound > other.bound;
    }
};
struct temp_result {
    priority_queue<int, vector<int>, greater<int>> way;
    int cost;
    int sum;
};

int bound(Node u, int k, vector<int>& target, vector<vector<int>>& h) {
    if(u.mp >= target[0] && u.mf >= target[1] && u.ms >= target[2] && u.mv >= target[3]) {
        return 99999999;
    }
    int temp_bound = u.cost;
    int j = u.level + 1;
    int totmp = u.mp;
    int totmf = u.mf;
    int totms = u.ms;
    int totmv = u.mv;

    while((j<k) && ((totmp + h[j][0] < target[0]) || (totmf + h[j][1] < target[1]) || (totms + h[j][2] < target[2]) || (totmv + h[j][3] < target[3]))) {
        totmp += h[j][0];
        totmf += h[j][1];
        totms += h[j][2];
        totmv += h[j][3];
        temp_bound += h[j][4];
        j++;
    }
    if(j<k) {
        temp_bound += static_cast<float>(target[0] + target[1] + target[2] + target[3] - totmp - totmf - totms - totmv) * h[j][4] / (h[j][0] + h[j][1] + h[j][2] + h[j][3]);
    }

    return temp_bound;
}

void bandb(vector<int>& target, vector<vector<int>>& h, int k, priority_queue<int, vector<int>, greater<int>>& result) {
    sort(h.begin(), h.end(), comp);
    priority_queue<Node> q;
    Node u,v;

    u.level = -1;
    u.mf = 0;
    u.mp = 0;
    u.ms = 0;
    u.mv = 0;
    u.cost = 0;
    u.min_index = 99999998;
    q.push(u);

    temp_result re;
    re.cost = 99999998;
    re.sum = 0;

    while(!q.empty()) {
        u = q.top();
        q.pop();
        if(u.level == -1) {
            v.level = 0;
        }
        if(u.level == k-1) {
            continue;
        }
        v.level = u.level + 1;
        v.cost = u.cost + h[v.level][4];
        v.mp = u.mp + h[v.level][0];
        v.mf = u.mf + h[v.level][1];
        v.ms = u.ms + h[v.level][2];
        v.mv = u.mv + h[v.level][3];
        v.sel = u.sel;
        v.sel.push(h[v.level][5]);
        if(u.min_index > h[v.level][5]) {
            v.min_index = h[v.level][5];
        }
        else {
            v.min_index = u.min_index;
        }
        if(v.mp >= target[0] && v.mf >= target[1] && v.ms >= target[2] && v.mv >= target[3]) {
            if(v.cost < re.cost || (v.cost == re.cost && v.mv + v.mf + v.mp + v.ms > re.sum) || (v.cost == re.cost && v.mv + v.mf + v.mp + v.ms == re.sum && v.min_index < re.way.top()) ) {
                re.cost = v.cost;
                re.sum = v.mv + v.mf + v.mp + v.ms;
                queue<int> temp = v.sel;
                while(!re.way.empty()) {
                    re.way.pop();
                }
                while(!temp.empty()) {
                    re.way.push(temp.front());
                    temp.pop();
                }
            }
        }
        else {
            v.bound = bound(v,k,target,h);
            if(v.bound <= re.cost) {
                q.push(v);
            }
        }
        v.cost = u.cost;
        v.mf = u.mf;
        v.ms = u.ms;
        v.mp = u.mp;
        v.mv = u.mv;
        v.sel = u.sel;
        v.min_index = u.min_index;
        v.bound = bound(v,k,target,h);
        if(v.bound <= re.cost) {
            q.push(v);
        }
    }
    result = re.way;
}

int main() {
    int k;
    cin >> k;
    cin >> target[0] >> target[1] >> target[2] >> target[3];
    vector<vector<int>> h(k, vector<int>(6));
    for(int i=0;i<k;i++) {
        cin >> h[i][0] >> h[i][1] >> h[i][2] >> h[i][3] >> h[i][4];
        h[i][5] = i;
    }
    priority_queue<int, vector<int>, greater<int>> result;
    bandb(target, h, k, result);
    if(result.size() == 0) {
        cout << 0 << endl;
    }
    else {
        while(!result.empty()) {
            cout << result.top() + 1 << " ";
            result.pop();
        }
        cout << endl;
    }
 }