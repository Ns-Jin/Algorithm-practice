#include <iostream>

using namespace std;

class Node {
    public:
        int n;  //식별자
        Node* parent;
        Node() {
            n = 0;
            parent = nullptr;
        }
        Node(int n) {
            this->n = n;
            parent = nullptr;
        }
        Node(int n, Node* par) {
            this->n = n;
            parent = par;
        }
        void set_parent(Node* par) {
            parent = par;
        }
        int get_n() {
            return n;
        }
};

int main() {
    int n;
    int relation_peoples[2];
    int m;
    cin >> n >> relation_peoples[0] >> relation_peoples[1] >> m;
    Node nodes[n+1];
    for(int i=0;i<n+1;i++) {
        Node node(i);
        nodes[i] = node;
    }
    for(int i=0;i<m;i++) {
        int a, a_par;
        cin >> a_par >> a;
        nodes[a].set_parent(&nodes[a_par]);
    }

    Node* cur_node = &nodes[relation_peoples[0]];
    int nodes_one[m+1];     //부모 노드들
    int size_one = 0;
    while(true) {
        nodes_one[size_one] = cur_node->get_n();
        size_one++;
        if(cur_node->parent == nullptr) {
            break;
        }
        else {
            cur_node = cur_node->parent;
        }
    }
    cur_node = &nodes[relation_peoples[1]];
    int nodes_two[m+1];     //부모 노드들
    int size_two = 0;
    while(true) {
        nodes_two[size_two] = cur_node->get_n();
        size_two++;
        if(cur_node->parent == nullptr) {
            break;
        }
        else {
            cur_node = cur_node->parent;
        }
    }
    int result = m+1; //나올수있는 최대촌수 + 1
    for(int i=0;i<size_one;i++) {
        for(int j=0;j<size_two;j++) {
            if(nodes_one[i] == nodes_two[j]) {
                if(result > i+j) {
                    result = i+j;
                }
            }
        }
    }
    if(result == m+1) {
        cout << -1 << endl;
    }
    else {
        cout << result <<endl;
    }
}