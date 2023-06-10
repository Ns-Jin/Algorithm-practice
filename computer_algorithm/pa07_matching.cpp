#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int q = 30011;
int rk(string, string);
int kmp(string, string);
int bm(string, string);

int main() {
    int line = 0;
    string pattern, text;
    cin >> line;
    for(int i=0;i<line;i++) {
        //해당 라인수 만큼 문자열 입력받아서 하나로 합치기
        string temp;
        cin >> temp;
        pattern += temp;
    }
    cin >> line;
    for(int i=0;i<line;i++) {
        //해당 라인수 만큼 문자열 입력받아서 하나로 합치기
        string temp;
        cin >> temp;
        text += temp;
    }
    
    //해당 결과 값 비교를 위해 pair로 결과값, 해당 번호를 저장
    vector<pair<int, int>> result(3);
    result[0] = make_pair(rk(pattern, text), 1);
    result[1] = make_pair(kmp(pattern, text), 2);
    result[2] = make_pair(bm(pattern, text), 3);
    sort(result.begin(),result.end());      //결과 값을 바탕으로 정렬

    //결과값 순서 비교후 정답형식에 맞게 출력
    if(result[0].first == result[1].first) {
        cout << 0 << " " << 0;
        if(result[1].first == result[2].first) {
            cout << " " << 0 << endl;
        }
        else {
            cout << " " << result[2].second << endl;
        }
    }
    else {
        cout << result[0].second << " ";
        if(result[1].first == result[2].first) {
            cout << 0 << " " << 0 << endl;
        }
        else {
            cout << result[1].second << " " << result[2].second << endl;
        }
    }
}

int rk(string pattern, string text) {
    int pattern_size = pattern.length();  //패턴 크기
    int text_size = text.length();  //문자 크기
    long long p = 0;    //pattern의 해싱값
    int count = pattern_size;       //결과값, 패턴의 해싱 계산을 하므로 미리 초기화
    vector<long long> dp(text_size-pattern_size + 1,0);     //문자열을 한카씩 옮겨가며 계산한 결과 저장 vector
    long long d = 2;    //d값
    long long h = 1;    //가장 높은 차수의 d^m-1값
    for(int i=0;i<pattern_size-1;i++) {
        h = (h*d) % q;      //d^m-1 % q 값을 구함
    }
    for(int i=0;i<pattern_size;i++) {
        //이전 값에 새로운 값을 더하는 식으로 진행, dp식
        p = (d*p+(pattern[i]-'A')) % q;
        dp[0] = (d*dp[0]+(text[i]-'A')) % q;
    }
    count++; //dp[0]과 한번 비교하므로 ++
    if(p == dp[0])
        return count;   //문자열 일치하면 리턴
    for(int i=1;i<text_size-pattern_size + 1;i++) {
        //이전 결과값들을 통해 수치계산및 비교
        dp[i] = (d*(dp[i-1] - h*(text[i-1]-'A')) + (text[i+pattern_size-1]-'A')) % q;
        if(dp[i] < 0)
            dp[i] = (dp[i] + q) % q;
        count++;
        if(p == dp[i])
            return count;
    }
    return count;
}

int kmp(string pattern, string text) {
    int pattern_size = pattern.length();
    int text_size = text.length();
    int count = 0;
    vector<int> lps(pattern_size, -1);  //가장 긴 접두, 접미사 저장 벡터
    int temp = 0;
    for(int i=1;i<pattern_size;i++) {
        int temp = lps[i-1];    //이전의 가장긴 접두,접미사 가져옴

        while((pattern[i] != pattern[temp+1]) && temp>=0) { 
            temp = lps[temp]; //접미 부분의 index를 가져옴
        }

        if(pattern[i] == pattern[temp+1]) {
            //접미, 접두사가 더 길어질 수 있으면 LPS 값을 업데이트
            lps[i] = temp+1;
        }
        else {
            //없으면 -1로 설정
            lps[i] = -1;
        }
    }
    int i=0;
    int j=0;

    while(i<text_size && j <pattern_size) {
        if(text[i] == pattern[j]) {
            if(j == pattern_size) {
                //일치하는데 패턴의 끝에 도달한다면(모든 문자열 일치) 리턴
                return count;
            }
            i++;
            j++;
            //뒤로 더 확인
        }
        else if(j==0) { //처음부터 일치 안하면 다음 문자부터 비교 시작
            i++;
        }
        else {     //중간에 일치 안하면 lps를 통해 적당히 비교위치 옮기기
            j = lps[j-1] + 1;
        }
        count++;
    }

    return count;
}

int bm(string pattern, string text) {
    int pattern_size = pattern.length();
    int text_size = text.length();
    int count = 0;
    vector<int> jump(256, -1);  //점프 테이블 초기화
    for(int i=0;i<pattern_size;i++) {
        jump[pattern[i]-'A'] = i;   //패턴 문자가 몇번째 index에 존재했는지, 이를 기반으로 점프를 진행
    }
    int i=0,j;
    while(i<(text_size - pattern_size)) {
        j = pattern_size-1; //패턴 문자열의 끝부터 비교시작
        while (j>=0 && pattern[j] == text[i+j]) {
            j--;    //문자 일치시 패턴, text의 index감소
            count++;
        }
        if(j<0) {
            //문자열이 모두 일치하면 리턴
            return count;
        }
        else {
            //중간에 문자열이 일치하지 않는다면 점프테이블을 이용하여 점프
            i += max(1, j-jump[text[i+j]-'A']);
        }
        count++;
    }

    return count;
}