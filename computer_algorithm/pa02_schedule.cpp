#include <iostream>
#include <vector>

using namespace std;

int getMaxByDivideAndConquer(const vector<int>& temp, int low, int high) {
    if(low == high) {
        return temp[low];  //1개만 남을때까지 분할하면 리턴
    }
    int mid = (low + high) / 2;
    //mid를 기준으로 좌측어느 부분에서 mid까지의 합중 최대구간을 구하기
    int sum = 0, left = -999999, right = -999999;
    for(int i=mid;i>=low;i--) { //low~mid까지 구간의 최대합 구하기
        sum += temp[i];
        left = max(left, sum);
    }
    //mid를 기준으로 mid+1부터 최대구간을 구하기
    sum = 0;
    for(int i=mid+1;i<=high;i++) {
        sum += temp[i];
        right = max(right, sum);
    }
    //mid를 기준으로 나누었을 때 왼쪽이나 오른쪽에 최대 구간합이 있는 경우
    int result = max(getMaxByDivideAndConquer(temp,low,mid), getMaxByDivideAndConquer(temp,mid+1,high));
    
    /*반으로 나누었을때, [좌측 or 우측 한곳에만 최대 구간이 몰려있는 경우]
    와 [mid값을 중간으로 좌,우측 모두 구간으로 가지는 최대구간인 경우]
    를 비교하여 더 큰 구간을 찾는다.*/
    return max(result, left+right);
}

int main() {
    int p,n,m;

    cin >> p >> n >> m;
    vector<int> v(n, p);    //기본 연구량으로 시간대 초기화

    for(int i=0;i<m;i++) {  //입력받기
        int t;
        cin >> t;
        for(int j=0;j<t;j++) {
            int low, high, noise;
            cin >> low >> high >> noise;
            for(int k=low;k<high;k++) {
                v[k] += noise;      //입력받은 구간에 대해 소음을 반영해서 연구량 갱신
            }
        }
    }
    cout << getMaxByDivideAndConquer(v,0,n-1);    //분할정복으로 최대 구간합 구하기
}