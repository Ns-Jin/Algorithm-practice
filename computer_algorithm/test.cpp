#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b) {
    // float a_value = (a[0]/mp + a[1]/mf + a[2]/ms + a[3]/mv) / a[4];
    // float b_value = (b[0]/mp + b[1]/mf + b[2]/ms + b[3]/mv) / b[4];
    float a_value = static_cast<float>(a[0] + a[1] + a[2] + a[3]) / a[4];
    float b_value = static_cast<float>(b[0] + b[1] + b[2] + b[3]) / b[4];
    return a[4] > b[4];
}


int main() {
    int k, mp, mf, ms, mv;
    cin >> k >> mp >> mf >> ms >> mv;
    vector<vector<int>> h(k, vector<int>(6));
    vector<int> result(k,0);
    for(int i=0;i<k;i++) {
        cin >> h[i][0] >> h[i][1] >> h[i][2] >> h[i][3] >> h[i][4];
        h[i][5] = i;
    }

    sort(h.begin(),h.end(),comp);
    int min_cost = 99999999;
    int max_val = 0;
    vector<int> now_val(4,0);
    int sum_now_val = 0;
    int now_cost = 0;
    int now_index = 0;
    vector<bool> in(k,false);

    while(true) {
        if(now_index == k) {
            break;
        }
        if(now_val[0] < mp || now_val[1] < mf || now_val[2] < ms || now_val[3] + h[now_index][3] < mv) {
            now_cost += h[now_index][4];
            for(int i=0;i<4;i++) {
                now_val[i] += h[now_index][i];
                sum_now_val += now_val[i];
            }
            in[h[now_index][5]] = true;
            now_index++;
        }
        else {
            
        }
        float bound = now_cost;
        for (int i = now_index; i < k; i++) {
            int remaining_mp = mp - now_val[0];
            int remaining_mf = mf - now_val[1];
            int remaining_ms = ms - now_val[2];
            int remaining_mv = mv - now_val[3];

            // Estimate the remaining value using the remaining items with the highest value-to-cost ratio
            float remaining_value = 0.0;
            for (int j = i; j < k; j++) {
                float ratio = static_cast<float>(h[j][0]) / h[j][4] + static_cast<float>(h[j][1]) / h[j][4] + static_cast<float>(h[j][2]) / h[j][4] + static_cast<float>(h[j][3]) / h[j][4];
                remaining_value += ratio * min(min(remaining_mp / h[j][4], remaining_mf / h[j][4]), min(remaining_ms / h[j][4], remaining_mv / h[j][4]));
            }

            // Update the bound by adding the remaining value to the current cost
            bound += remaining_value;
            // cout << "bound: " << bound << endl;
            // for(int p=0;p<k;p++) {
            //     if(in[p]) {
            //         cout << p+1 << " ";
            //     }
            // }
            // If the bound exceeds the minimum cost found so far, break the loop
            if (bound > min_cost) {
                break;
            }
        }
        if (bound > min_cost) {
            break;
        }
        else {
            sum_now_val = 0;
           for(int i=0;i<4;i++) {
                now_val[i] -= h[now_index-1][i];
            }
            now_cost -= h[now_index-1][4];
            in[h[now_index-1][5]] = false;
        }

        if(now_cost < min_cost) {
            min_cost = now_cost;
            max_val = sum_now_val;
        }
        else if(now_cost == min_cost) {
            if(max_val < sum_now_val) {
                min_cost = now_cost;
                max_val = sum_now_val;
            }
        }
    }
    for(int i=0;i<k;i++) {
        if(in[i]) {
            cout << i+1 << " ";
        }
    }

 }