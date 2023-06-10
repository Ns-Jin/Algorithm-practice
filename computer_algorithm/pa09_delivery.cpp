#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Node {
    //상태트리 를 나타낼 노드
    int level, distance, bound, count;
    //트리의 level, 지금까지 총 거리, 해당노드에서 bound, 현재 픽업한 음식 갯수
    vector<int> path;   //현재 노드까지의 경로
    bool operator<(const Node& other) const {
        return bound>other.bound;
    }
    //pq를 위한 operator
};
int bound(Node& node, int n, const vector<vector<int>>& dis) {
    int result = node.distance;
    int min = 10000;
    int i = 1;
    //마지막 경로에서 아직 방문안한 곳까지의 최소 거리
    //주의점: 아직 픽업안하고 배달가면안됨, 픽업을 2개 초과하면 안됨
    while(i<2*n+1) {
        if((i<n+1 && count(node.path.begin(),node.path.end(),i) == 0 && node.count < 2) || (i>n && i < 2*n+1 && count(node.path.begin(),node.path.end(),i-n) != 0 && count(node.path.begin(),node.path.end(),i) == 0)) {
            if(dis[node.path.back()][i]<min)
                min = dis[node.path.back()][i];
        }
        i++;
    }
    result+=min;
    i=1;
    //방문안한 곳에서 방문안한 다른곳으로 까지의 최소거리
    while(i<2*n+1) {
        if((i<n+1 && count(node.path.begin(),node.path.end(),i) == 0 && node.count < 2) || (i>n && i < 2*n+1 && count(node.path.begin(),node.path.end(),i-n) != 0 && count(node.path.begin(),node.path.end(),i) == 0)) {
            int j=0;
            min = 10000;
            while(j<2*n+1) {
                if((i!=j && (i<n+1 && count(node.path.begin(),node.path.end(),i) == 0 && node.count < 2) || (i>n && i < 2*n+1 && count(node.path.begin(),node.path.end(),i-n) != 0 && count(node.path.begin(),node.path.end(),i) == 0)) || (j==0 && i!=0)) {
                    if(dis[i][j]<min)
                        min = dis[i][j];
                }
                j++;
            }
            result+=min;
        }
        i++;
    }
    return result;
}

int travel(int n, const vector<vector<int>>& dis, vector<int>& order) {
    priority_queue<Node> pq;    //best branch and bound를 위한 pq
    Node u,v;   //현재, 나아갈 노드
    v.level = 0;
    v.path.push_back(0);
    v.distance = 0;
    v.bound = bound(v,n,dis);
    v.count = 0;
    //노드 초기화
    int min_dis = 99999999;
    //최소거리, 결과값 초기화
    pq.push(v);
    while(!pq.empty()) {
        //bound값이 가장 작은 곳부터 탐색
        v = pq.top();
        pq.pop();
        int i=1;
        while(i<2*n+1) {
            if((i<n+1 && count(v.path.begin(),v.path.end(),i) == 0 && v.count < 2) || (i>n && i < 2*n+1 && count(v.path.begin(),v.path.end(),i-n) != 0 && count(v.path.begin(),v.path.end(),i) == 0)) {
                //방문할 수 있는 노드이면
                if(i<n+1)
                    u.count = v.count + 1;
                else
                    u.count = v.count - 1;
                u.level = v.level + 1;
                u.path = v.path;
                u.path.push_back(i);
                u.distance = v.distance + dis[v.path.back()][i];
                if(u.level == 2*n) {
                    //마지막 리프에 도착하면
                    if(u.distance < min_dis) {
                        //최소값인지 비교하고 최신화
                        min_dis = u.distance;
                        order = u.path;
                    }
                    else if(u.distance == min_dis) {
                        //만약 같다면 사전식으로 정렬
                        int k=0;
                        while(k<order.size() && order[k] == u.path[k])
                            k++;
                        int t1 = order[k];
                        if(t1 > n)
                            t1 = -1*(t1-n);
                        int t2 = u.path[k];
                        if(t2 > n) 
                            t2 = -1*(t2-n);
                        if(t1 > t2) {
                            min_dis = u.distance;
                            order = u.path;
                        }
                    }
                }
                else {
                    //리프가 아니면 bound값 확인후 유망하면 가지 뻗기
                    u.bound = bound(u,n,dis);
                    if(u.bound < min_dis)
                        pq.push(u);
                }
            }
            i++;
        }
    }
    return min_dis; 
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> food(n,vector<int>(4,0));
    for(int i=0;i<n;i++) {
        cin >> food[i][0] >> food[i][1] >> food[i][2] >> food[i][3];
    }
    vector<vector<int>> dis(2*n+1,vector<int>(2*n+1,0));
    //각 정점사이의 거리 정보를 나타내는 벡터
    vector<int> temp(2);
    vector<int> temp2(2);
    for(int i=0;i<2*n+1;i++) {
        if(i==0) {
            temp[0] = 500;
            temp[1] = 500;
        }
        else if(i>0 && i<=n) {
            temp[0] = food[i-1][0];
            temp[1] = food[i-1][1];
        }
        else {
            temp[0] = food[i-n-1][2];
            temp[1] = food[i-n-1][3];
        }
        for(int j=0;j<2*n+1;j++) {
            if(j==0) {
                temp2[0] = 500;
                temp2[1] = 500;
            }
            else if(j>0 && j<=n) {
                temp2[0] = food[j-1][0];
                temp2[1] = food[j-1][1];
            }
            else {
                temp2[0] = food[j-n-1][2];
                temp2[1] = food[j-n-1][3];
            }
            dis[i][j] = abs(temp[0] - temp2[0]) + abs(temp[1] - temp2[1]);
        }
    }
    vector<int> order(2*n+1);
    int result = travel(n,dis,order);
    for(int i=1;i<2*n+1;i++) {
        if(order[i] > n) {
            order[i] = n-order[i];
        }
        cout << order[i] << " ";
    }
    cout << endl << result << endl;
}