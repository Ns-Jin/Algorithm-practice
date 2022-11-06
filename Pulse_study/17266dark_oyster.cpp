#include <iostream>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    
    int location_street_light[m];
    for(int i=0;i<m;i++) {
        cin >> location_street_light[i];
    }

    int pre_location = location_street_light[0];
    int max_first_last = max(location_street_light[0], n-location_street_light[m-1]);  //처음,끝 가로등 간격중 큰값
    int max_interval = 0;
    for(int i=0;i<m;i++) {  //가로등 사이 거리가 가장 큰 값 구하기
        if(location_street_light[i] - pre_location > max_interval) {
            max_interval = location_street_light[i] - pre_location;
        }
        pre_location = location_street_light[i];
    }
    //가장큰 간격에 대해 필요한 최소 가로등 높이 구하기
    if(max_interval % 2 == 0) {
        max_interval = max_interval / 2;
    }
    else {
        max_interval = max_interval/2 + 1;
    }
    
    cout << max(max_first_last, max_interval);
}