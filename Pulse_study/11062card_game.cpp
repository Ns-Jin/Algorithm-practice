#include <iostream>
#include<deque>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n;
        cin >> n;
        deque<int> dq;
        int temp;
        for(int j=0;j<n;j++){
            cin >> temp;
            dq.push_back(temp);
        }
        int geunwoo = 0;
        int myeongwoo = 0;
        int turn  = 0;
        while(dq.size() > 2) {
            if(turn%2 == 0) {    //근우턴
                if(dq.front() < dq.back()) {
                    geunwoo += dq.back();
                    dq.pop_back();
                }
                else if(dq.front() > dq.back()) {
                    geunwoo += dq.front();
                    dq.pop_front();
                }
                else {  //같을때 적은쪽 선택     
                    int temp = dq.back();
                    dq.pop_back();
                    int back_value = dq.back();
                    dq.push_back(temp);
                    temp = dq.front();
                    dq.pop_front();
                    if(back_value < dq.front()) {
                        geunwoo += dq.back();
                        dq.pop_back();
                    }
                    else {
                        geunwoo += temp;
                    }
                }
            }
            else {
                if(dq.front() < dq.back()) {
                    myeongwoo += dq.back();
                    dq.pop_back();
                }
                else if(dq.front() > dq.back()) {
                    myeongwoo += dq.front();
                    dq.pop_front();
                }
                else {  //같을때 적은쪽 선택     
                    int temp = dq.back();
                    dq.pop_back();
                    int back_value = dq.back();
                    dq.push_back(temp);
                    temp = dq.front();
                    dq.pop_front();
                    if(back_value < dq.front()) {
                        myeongwoo += dq.back();
                        dq.pop_back();
                    }
                    else {
                        myeongwoo += temp;
                    }
                }
            }
            turn++;
        }
        while(!dq.empty()) {
            if(turn%2 == 0) {
                if(dq.front() < dq.back()) {
                    geunwoo += dq.back();
                    dq.pop_back();
                }
                else {
                    geunwoo += dq.front();
                    dq.pop_front();
                }
            }
            else {
                if(dq.front() < dq.back()) {
                    myeongwoo += dq.back();
                    dq.pop_back();
                }
                else {
                    myeongwoo += dq.front();
                    dq.pop_front();
                }
            }
        }
        
        cout << geunwoo << endl;
    }
}