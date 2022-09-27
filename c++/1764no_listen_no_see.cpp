#include<iostream>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    set<string> no_listen;
    set<string> no_see;

    for(int i=0;i<n;i++) {
        string name;
        cin >> name;
        no_listen.insert(name);
    }

    for(int i=0;i<m;i++) {
        string name;
        cin >> name;
        no_see.insert(name);
    }

    set<string> result;
    set_intersection(no_listen.begin(),no_listen.end(),no_see.begin(),no_see.end(),inserter(result, result.begin()));

    cout << result.size() << '\n';
    for(set<string>::iterator it = result.begin(); it != result.end(); it++) {
        cout << *it << '\n';
    }
}