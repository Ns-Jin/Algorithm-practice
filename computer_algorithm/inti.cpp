#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int getmanhattan(const vector<int> &a, pair<int,int> &b){
    int distance=0;
    distance+=abs(a[0]-b.first);
    distance+=abs(a[1]-b.second);
    return distance;
}

struct Node{
    vector<int> path;
    vector<int> rider;
    pair<int,int> xy;
    int bound;
    int distance;
    Node(vector<int> p, vector<int> r, pair<int,int> xy, int b, int d): path(p), rider(r), xy(xy), bound(b), distance(d){}
};

struct comparenode {
    bool operator()(const Node& n1, const Node& n2) {
        return n1.bound < n2.bound;
    }
};

vector<int> getnext(const vector<vector<int>> &nodes, const vector<int>& path, vector<int> rider){
    int min_nextd=INT_MAX, vi;
    pair<int,int> curxy;
    if(path.empty())    curxy=make_pair(500, 500);
    else                curxy=make_pair(nodes[path.back()][0], nodes[path.back()][1]);

    if(rider.size()<2){
        for(int i=0; i<nodes.size(); i+=2){
            if(nodes[i][2]==1) continue;
            int nextd = getmanhattan({nodes[i][0], nodes[i][1]}, curxy);
            if(nextd<min_nextd){
                min_nextd=nextd;
                vi=i;
            }
        }
        if(rider.size()==1){
            int nextd = getmanhattan({nodes[rider[0]][0], nodes[rider[0]][1]}, curxy);
            if(nextd<min_nextd){
                min_nextd=nextd;
                vi=rider[0];
            }else if(nextd==min_nextd && rider[0]<vi){
                min_nextd=nextd;
                vi=rider[0];
            }
        }
    }else{
        sort(rider.begin(), rider.end());
        for(int r: rider){
            int nextd = getmanhattan({nodes[r][0], nodes[r][1]}, curxy);
            if(nextd<min_nextd){
                min_nextd=nextd;
                vi=r;
            }
        }
    }
    return vector<int>{vi, min_nextd};
}

int calbound(const vector<vector<int>> &nodes, const vector<int>& path, const vector<int> &rider, int distance){
    int bound=0; vector<int> mypath=path, myrider=rider;
    pair<int,int> curxy;
    if(path.empty())    curxy=make_pair(500, 500);
    else                curxy=make_pair(nodes[path.back()][0], nodes[path.back()][1]);

    bound+=distance;
    vector<int> vi=getnext(nodes, path, rider);
    bound+=vi[1];
    if(vi[0]%2==0)  myrider.push_back(vi[0]);
    else            myrider.erase(find(myrider.begin(), myrider.end(), vi[0]));
    mypath.push_back(vi[0]);

    while(mypath.size()<nodes.size()){
        vi=getnext(nodes, path, rider);
        bound+=vi[1];
        if(vi[0]%2==0)  myrider.push_back(vi[0]);
        else            myrider.erase(find(myrider.begin(), myrider.end(), vi[0]));
        mypath.push_back(vi[0]);
    } 

    return bound;
}

void branchandbound(const vector<vector<int>> &nodes){
    vector<int> optimalpath; int min_distance=INT_MAX; 
    priority_queue<Node, vector<Node>, comparenode> pq;
    Node root({}, {}, make_pair(500, 500), calbound(nodes, {}, {}, 0), 0);
    pq.push(root);

    while(!pq.empty()){
        Node cnode=pq.top(); 
        pq.pop();
        if(cnode.bound > min_distance)  continue;
        if(cnode.rider.size()<2){
            for(int i=0; i<nodes.size(); i+=2){
                if(find(cnode.path.begin(), cnode.path.end(), i)==cnode.path.end()){
                    Node newnode(cnode.path, cnode.rider, cnode.xy,cnode.bound, cnode.distance);
                    newnode.path.push_back(i);
                    newnode.distance+=getmanhattan(nodes[newnode.path.back()], newnode.xy);
                    if(newnode.path.size()==nodes.size()){
                        if(newnode.distance<min_distance){
                            min_distance=newnode.distance;
                            optimalpath=newnode.path;
                        }
                    }else{
                        newnode.xy=make_pair(nodes[newnode.path.back()][0], nodes[newnode.path.back()][1]);
                        newnode.rider.push_back(i);
                        newnode.bound=calbound(nodes, newnode.path, newnode.rider, newnode.distance);
                        if(newnode.bound<min_distance)  pq.push(newnode);
                    }
                }
            }
            for(int r:cnode.rider){
                Node newnode(cnode.path, cnode.rider, cnode.xy,cnode.bound, cnode.distance);
                newnode.path.push_back(r);
                newnode.distance+=getmanhattan(nodes[newnode.path.back()], newnode.xy);
                if(newnode.path.size()==nodes.size()){
                    if(newnode.distance<min_distance){
                        min_distance=newnode.distance;
                        optimalpath=newnode.path;
                    }
                }else{
                    newnode.xy=make_pair(nodes[newnode.path.back()][0], nodes[newnode.path.back()][1]);
                    newnode.rider.erase(find(newnode.rider.begin(), newnode.rider.end(), r));
                    newnode.bound=calbound(nodes, newnode.path, newnode.rider, newnode.distance);
                    if(newnode.bound<min_distance)  pq.push(newnode);
                }
            }
        }
        for(int r:cnode.rider){
            Node newnode(cnode.path, cnode.rider, cnode.xy,cnode.bound, cnode.distance);
            newnode.path.push_back(r);
            newnode.distance+=getmanhattan(nodes[newnode.path.back()], newnode.xy);
            if(newnode.path.size()==nodes.size()){
                if(newnode.distance<min_distance){
                    min_distance=newnode.distance;
                    optimalpath=newnode.path;
                }
            }else{
                newnode.xy=make_pair(nodes[newnode.path.back()][0], nodes[newnode.path.back()][1]);
                newnode.rider.erase(find(newnode.rider.begin(), newnode.rider.end(), r));
                newnode.bound=calbound(nodes, newnode.path, newnode.rider, newnode.distance);
                if(newnode.bound<min_distance)  pq.push(newnode);
            }
        }
    }

    for(int i :optimalpath){
        cout << i << " ";
    }
    cout << "\n" << min_distance;
}

int main(){ 
    int n; vector<vector<int>> nodes;                                                                           // 0:x, 1:y, 3:visited 
    cin >> n;
    for(int i=0; i<n; i++){
        vector<int> n1(3, 0), n2(3, 0);
        cin >> n1[0] >> n1[1] >> n2[0] >> n2[1];
        nodes.push_back(n1);
        nodes.push_back(n2);
    }

    branchandbound(nodes);

    return 0;
}