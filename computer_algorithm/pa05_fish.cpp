#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//잘못된 배열 순서를 올바르게 돌리는 함수
void fix_invalid(vector<int>& v,int k) {
    int s_i = -1, e_i = k-1, target_s = -1, target_e = -1;
    //잘못된 배열 순서의 시작, 끝을 저장하는 변수, 시작의 원래 위치, 끝의 원래위치를 저장하는 변수
    stack<int> s;   //뒤집을 배열을 저장할 stack
    bool end = false;   //잘못된 배열의 끝을 확인하는 변수
    for(int i=0;i<k;i++) {
        if(s_i == -1) {     //아직 잘못된 배열을 확인 못했다면
            if(-v[i] - 1 == i) {    //제자리에서 뒤집는 경우
                v[i] = -v[i];
                end = true;
                s_i = 0;
                break;
            }
            if(v[i]-1 != i) {   //배열의 시작을 알림
                s_i = i;
            }
        }
        else {
            if(v[i]-1 == i) {   //올바른 배열 순서를 만났을 때
                e_i = i-1;      //잘못된 배열의 끝을 알림
                break;
            }
        }
    }
    if(end) {
        return;
    }
    //잘못된 배열에서 뒤집을 구간 확인
    for(int i=s_i;i<=e_i;i++) {
        if(v[i] == -(e_i + 1)) {
            target_e = i;
        }
        else if(v[i] == -(s_i + 1)) {
            target_s = i;
        }
    }
    if(target_s != -1) {
        for(int i=s_i;i<=target_s;i++) {
            s.push(v[i]);
        }
        while(!s.empty()) {
            v[s_i++] = 0-s.top();
            s.pop();
        }
    }
    else if(target_e != -1) {
        for(int i=target_e;i<=e_i;i++) {
            s.push(v[i]);
        }
        while(!s.empty()) {
            v[target_e++] = 0-s.top();
            s.pop();
        }
    }
}
//해당 배열이 유효한지 확인하는 변수
bool valid(vector<int>& v, int k) {
    for(int i=0;i<k;i++) {
        if(v[i]-1 != i)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    vector<int> v(k);
    for(int i=0;i<5;i++) {
        for(int j=0;j<k;j++) {
            cin >> v[j];
        }
        fix_invalid(v,k);   //한번 배열을 수정해보고
        if(valid(v,k))      //유효한지 확인
            cout << "one" << '\n';
        else {              //유효지 않다면
            fix_invalid(v,k);   //배열 재수정
            if(valid(v,k))      //유효하면 two에 해당
                cout << "two" << '\n';
            else                //유효하지 않다면 over
                cout << "over" << '\n';
        }
    }
}