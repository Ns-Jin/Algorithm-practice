#include <iostream>
#include <string>

using namespace std;

string isVps(string vps_case);

int main()
{
    int T = 0;
    cin >> T;

    string vps_case;
    for(int i=0;i<T;i++) {
        cin >> vps_case;
        cout << isVps(vps_case) << endl;
    }

}

string isVps(string vps_case) {
    int len_str = vps_case.length();

    int necssary_right_par = 0;
    string result = "YES";

    for(int i=0;i<len_str;i++) {
        if(necssary_right_par == 0){
            if(vps_case[i] == ')') {
                result = "NO";
            }
            else if(vps_case[i] == '(') {
                necssary_right_par++;
            }
        }
        else {
            if(vps_case[i] == ')') {
                necssary_right_par--;
            }
            else if(vps_case[i] == '(') {
                necssary_right_par++;
            }
        }
    }

    if(necssary_right_par != 0) {
        result = "NO";
    }

    return result;
}