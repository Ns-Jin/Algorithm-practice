#include <iostream>
#include <algorithm>

using namespace std;

class student {
    private:
        int distinguisher;      //학생 식별 번호 
        int candidate;      //추천수
        int last_candidate;     //마지막 추천받은 시간(for문의 i요소로 판별, 작을수록 오래된것으로 봄)
    public:
        student() {    
            this->distinguisher = 0;
            this->candidate = 0;
            this->last_candidate = 1001;
        }
        student(int can,int last_can) {
            this->distinguisher = can;
            this->candidate = 1;
            this->last_candidate = last_can;
        }
        int get_distinguisher() {
            return this->distinguisher;
        }
        int get_candidate() {
            return this->candidate;
        }
        int get_last_candidate() {
            return this->last_candidate;
        }
        void plus_candidate(int i) {        //추천수 증가
            this->candidate++;
            this->last_candidate = i;
        }
};

int main() {
    
    int n,k;

    cin >> n;
    cin >> k;

    student students[n];    //사진틀
    int frame_count = 0;    //사진이 게시된 수, 최대: n
    for(int i=0;i<k;i++) {
        int can;        //추천학생
        cin >> can;

        bool inFrame = false;
        for(int j=0;j<frame_count;j++) {
            if(students[j].get_distinguisher() == can) {
                students[j].plus_candidate(i);  //이미 사진틀안에 있으면 추천수 +1
                inFrame = true;
                break;
            } 
        }
        if(!inFrame) {      //사진틀에 없는 학생을 추천받을시
            student temp(can,i);
            if(frame_count < n) {       //사진틀이 꽉차지 않았을 경우
                students[frame_count] = temp;
                frame_count++;
            }
            else {      //사진틀이 꽉찼을 경우
                student min = students[0];
                int min_index = 0;
                for(int j=0;j<n;j++) {      //최소 추천수를 받은 학생을 찾는 과정
                    if(students[j].get_candidate() < min.get_candidate()) {     //최소 추천수와 비교, 최신화
                        min = students[j];
                        min_index = j;
                    }
                    else if(students[j].get_candidate() == min.get_candidate()) {   //최소 추천수와 같은경우 더 오래된 학생을 최소 추천수 학생으로 최신화
                        if(students[j].get_last_candidate() < min.get_last_candidate()) {
                            min = students[j];
                            min_index = j;
                        }
                    }
                }
                students[min_index] = temp;     //최소 추천수를 받을 학생을 몰아내고 새로운 추천받은 학생을 그 자리에 추가
            }
        }
    }
    int result[n];
    for(int i=0;i<n;i++) {
        result[i] = students[i].get_distinguisher();
    }
    sort(result,result+n);
    for(int i=0;i<n-1;i++) {
        if(result[i] != 0) {
            cout << result[i] << " ";
        }
    }
    cout << result[n-1] << endl;
}