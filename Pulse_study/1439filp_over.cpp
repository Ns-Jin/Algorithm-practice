#include <iostream>

using namespace std;

int main() {
    string n;
    cin >> n;
    int len_n = n.length();
    int initial_n[len_n];
    int count_one = 0;  //1의 집단 개수
    int count_zero = 0;     //0의 집단 개수
    for(int i=0;i<len_n;i++){
        if(n[i] == '1') {
            initial_n[i] = 1;
        }
        else {
            initial_n[i] = 0;
        }
    }

    int pre_n = initial_n[0];
    if(pre_n == 0) {
        count_zero++;
    }
    else {
        count_one++;
    }

    for(int i=1;i<len_n;i++) {
        if(initial_n[i] != pre_n) {
            if(pre_n == 0) {
                count_one++;
            }
            else {
                count_zero++;
            }
            pre_n = initial_n[i];
        }
    }

    cout << min(count_one, count_zero) << endl;
}