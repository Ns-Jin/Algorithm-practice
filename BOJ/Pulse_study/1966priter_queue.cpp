#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int test_case;
    cin >> test_case;

    for(int i=0;i<test_case;i++) {
        int n,m;
        cin >> n >> m;

        int importances[10] = {0,0,0,0,0,0,0,0,0,0};    //0~9중요도 개수
        int target_importance = 0;  //타겟의 중요도
        queue<int> q;
        for(int j=0;j<n;j++) {
            int temp;
            cin >> temp;
            q.push(temp);
            if(j == m) {    //m번째 놓인 타겟의 중요도 확인
                target_importance = temp; 
            }
            importances[temp] += 1;     //해당 중요도 갯수 증가
        }

        int target_index = m;   //타겟 인덱스
        int top_importance = 0;     
        for(int j=9;j>=0;j--) {         //현재 가장큰 중요도 확인
            if(importances[j] != 0) {
                top_importance = j;
                break;
            }
        }

        int count = 0;
        while(true) {
            if(target_index == 0) {     //queue의 맨앞에 타겟이 왔을때
                if(top_importance == target_importance) {   //타겟의 중요도가 가장 큰 중요도 일때
                    count++;
                    break;
                }
                else {      //그렇지 않다면 맨뒤로 보내기
                    int temp = q.front();
                    q.pop();
                    q.push(temp);
                    target_index = q.size()-1;
                }
            }
            else {  
                if(top_importance == q.front()) {       //맨앞에 가장큰 중요도가있다면 빼주기
                    q.pop();
                    count++;
                    target_index--;
                    importances[top_importance] = importances[top_importance] - 1;
                    for(int j=9;j>=0;j--) {
                        if(importances[j] != 0) {
                            top_importance = j;     //새로운 가장 큰 중요도 찾기
                            break;
                        }
                    }
                }
                else {      //그렇지 않다면 맨뒤로 보내기
                    int temp = q.front();
                    q.pop();
                    q.push(temp);
                    if(target_index > 0) {
                        target_index--;
                    }
                    else {
                        target_index = q.size()-1;
                    }
                }
            }  
        }

        cout << count << endl;
    }

}