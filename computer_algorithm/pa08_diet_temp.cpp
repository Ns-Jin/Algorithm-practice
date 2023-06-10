#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isFeasible(const vector<int>& now, const vector<vector<int>>& h, const vector<int>& target) {
    int n = now.size();
    vector<int> total(4, 0); // 현재 선택된 재료들의 총량
    
    for (int i = 0; i < n; i++) {
        // cout << now[i] << " ";
        if (now[i] > 0) {
            total[0] += h[i][0];
            total[1] += h[i][1];
            total[2] += h[i][2];
            total[3] += h[i][3];
        }
    }   
    // cout << endl;
    for (int i = 0; i < 4; i++) {
        // cout << total[i] << " ";
        if (total[i] < target[i]) {
            // cout << endl;
            return false; // 어느 하나의 제약 조건이라도 만족하지 않으면 false 반환
        }
    }
    return true; // 모든 제약 조건을 만족하면 true 반환
}

int getBound(const vector<int>& now, const vector<vector<int>>& h, const vector<int>& target) {
    int bound = 0;
    int n = now.size();
    vector<int> remaining(4, 0); // 남은 재료들의 필요량
    
    for (int i = 0; i < n; i++) {
        if (now[i] == 0) {
            remaining[0] += target[0] - h[i][0];
            remaining[1] += target[1] - h[i][1];
            remaining[2] += target[2] - h[i][2];
            remaining[3] += target[3] - h[i][3];
        }
    }
    
    for (int i = 0; i < 4; i++) {
        if (remaining[i] > 0) {
            bound += remaining[i] * h[i][4];
        }
    }
    
    return bound;
}

void bandb(const vector<vector<int>>& h,const vector<int> target, vector<int>& now, vector<int>& best, int& min_cost, int index, int now_cost) {
    for(int i=0;i<h.size();i++) {
        cout << now[i] << " ";
    }
    cout <<  isFeasible(now, h, target) << endl;
    if(isFeasible(now, h, target) && now_cost < min_cost) {
        min_cost = now_cost;
        for(int i=0;i<now.size();i++) {
            best[i] = now[i];
            cout << now[i] << " ";
        }
        cout << endl;
    }
    if(index == h.size()) {   
        return;
    }
    bandb(h, target, now,best,min_cost,index+1,now_cost);
    now[index]++;
    
    int new_cost = now_cost + h[index][4];
    if(!isFeasible(now,h,target) && new_cost < min_cost) {
        int bound = getBound(now,h,target);
        if(bound < min_cost) {
            bandb(h, target, now,best,min_cost,index+1,new_cost);
        }
    }
    now[index]--;
}

int main() {
    int k;
    vector<int> target(4,0);
    cin >> k >> target[0] >> target[1] >> target[2] >> target[3];
    vector<vector<int>> h(k, vector<int>(6));
    vector<int> result(k,0);
    for(int i=0;i<k;i++) {
        cin >> h[i][0] >> h[i][1] >> h[i][2] >> h[i][3] >> h[i][4];
        h[i][5] = i;
    }

    vector<int> now(k,0);
    vector<int> best(k,0);
    int min_cost = 9999999;

    bandb(h, target, now, best, min_cost, 0, 0);
    for(int i=0;i<k;i++) {
        if(best[i] > 0) {
            cout << i+1 << " ";
        }
    }
 }