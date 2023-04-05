#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    queue<pair<int, int>> result;  //만든 숫자 1개와 숫자합 임의 저장소
    vector<bool> used_num(10);  //0~9까지 숫자 사용했는지 판별
    int max = 988;  //최대 탐색범위
    if(max > n/2) {
        max = n/2;  //실 탐색범위
    }
    for(int i=12;i<max;i++) {
        bool correct = true;    //진행상황에 문제가 없는지 확인
        int sum = 0;    //숫자들 합
        int num = i; 
        if(num/100 == 0 && num%10 == 0) {
            //숫자 하나가 두자리 수 일때, 0으로 끝나면 안된다.
            continue;
        }
        if (num/100 == 0 && (n-num)/100 == 0) {
            //숫자 하나가 두자리 수 일때, 나머지 숫자도 두자리면 안된다.
            continue;
        }
        if((n-num)/1000 == 1) {
            //숫자 하나가 4자리수이면 안된다
            continue;
        }
        if(num/100 == 0) {
            //두자리수이면 0을 사용했다고 가정한다
            used_num[0] = true;
        }
        while(num/10 != 0) {
            //자리수를 하나씩 확인하여 사용안한건지 판별한다
            if(used_num[num%10]) {
                correct = false;
                break;
            }
            used_num[num%10] = true;
            sum += num%10;
            num = num/10;
        }
        if(used_num[num]) {
            correct = false;
        }
        else {
            used_num[num] = true;
            sum += num;
        }
        if (correct) {
            //숫자조합 하나가 조건에 부합할때, 해당 페어 숫자 조합을 확인한다.
            int pair = n-i;
            while(pair/10 != 0) {
                if(used_num[pair%10]) {
                    correct = false;
                    break;
                }
                used_num[pair%10] = true;
                sum += pair%10;
                pair = pair/10;
            }
            if(used_num[pair]) {
                correct = false;
            }
            else {
                sum += pair;
            }
            if(correct) {
                /*두 숫자 조합모두 조건에 부합하면
                result에 저장하는데, sum값이 큰것들로 갱신한다*/
                if (result.empty()) {
                    result.push(make_pair(i,sum));
                }
                else if(result.back().second < sum){
                    while(!result.empty()) {
                        result.pop();
                    }
                    result.push(make_pair(i,sum));
                }
                else if(result.back().second == sum) {
                    result.push(make_pair(i,sum));
                }
            }
        }
        for(int j=0;j<10;j++) {
            //사용한 숫자를 초기화한다
            used_num[j] = false;
        }
    }
    if(result.empty()) {
        //결과에 부합한게 없으면 -1 출력
        cout << -1 << endl;
    }
    else {
        int min = 10;
        int min_result = -1;
        int sum = result.back().second;
        while(!result.empty()) {
            //숫자 조합내에 가장 작은 숫자를 포함하는 것을 결과로 둔다
            int num = result.front().first;
            if(num/100 == 0) {
                //애초에 0으로 시작하는 2자리수조합은 정답이 되므로 break
                min_result = num;
                break;
            }
            while(num/10 != 0) {
                if(min > num) {
                    min = num;
                    min_result = result.front().first;
                }
                num = num/10;
            }
            if(min > num) {
                min = num;
                min_result = result.front().first;
            }
            result.pop();
        }
        if (min_result / 100 == 0) {
            //첫번째 숫자가 2자리수면 앞에 0을 붙힌다
            cout << 0;
        }
        cout << min_result << " " << n - min_result << " " << sum << endl;
    }
}