#include <iostream>

using namespace std;

int main() {
    int input,output;

    cin >> input >> output;
   
    int count = 1;      //연산 횟수
    while(true) {
        if(output == input) {       //output을 나누다가 input과 같아지면 break
            break;
        }
        else if(output < input) {   //output을 나누다가 input보다 작아지면 count -1로 만들고 break
            count = -1;
            break;
        }
        else if(output / 10 != 0) { //output이 1의 자릿수가 아닐경우
            if(output % 10 == 1) {  //맨 뒤 자리수가 1일때
                output = output/10;     //1제거
                count++;        
            }
            else if(output % 2 == 1) {  //2로 나누었을때 안나누어지는경우
                count = -1;
                break;
            }
            else {      //2로 나누어 떨어질때
                output = output/2;
                count++;
            }
        }
        else {  //output이 1의 자릿수일때
            if(output % 2 == 1) {  //2로 나누었을때 안나누어지는경우
                count = -1;
                break;
           }
            else {      //2로 나누어 떨어질때
                output = output/2;
                count++;
            }
        }
    }

    cout << count << endl;
}