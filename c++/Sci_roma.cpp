#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int calc(string s) {
    if(s == "I") {
        return 1;
    }
    else if(s == "V") {
        return 5;
    }
    else if(s == "X") {
        return 10;
    }
    else if(s == "L") {
        return 50;
    }
    else if(s == "C") {
        return 100;
    }
    else if(s == "IV") {
        return 4;
    }
    else if(s == "IX") {
        return 9;
    }
    else if(s == "XL") {
        return 40;
    }
    else if(s == "XC") {
        return 90;
    }
    return 0;
}

int main() {
    string roma;
    getline(cin, roma);
    stack<char> s;
    int result = 0;
    for(int i=0;i<int(roma.length());i++) {
        if(s.empty()) {
            if(roma[i] == 'X') {
                s.push(roma[i]);
            }
            else if(roma[i] == 'I') {
                s.push(roma[i]);
            }
            else if(roma[i] == 'V') {
                result += calc("V");
            }
            else if(roma[i] == 'L') {
                result += calc("L");
            }
            else if(roma[i] == 'C') {
                result += calc("C");
            }
        }
        else {
            if(s.top() == 'I') {
                if(roma[i] == 'V') {
                    result += calc("IV");
                    s.pop();
                }
                else if(roma[i] == 'X') {
                    result += calc("IX");
                    s.pop();
                }
                else {
                    string temp;
                    temp += s.top();
                    result += calc(temp);
                    s.pop();
                    if(roma[i] == 'I') {
                        s.push(roma[i]);
                    }
                    else {
                        temp = "";
                        temp += roma[i];
                        result += calc(temp);
                    }
                }
            }
            else if(s.top() == 'X') {
                if(roma[i] == 'L') {
                    result += calc("XL");
                    s.pop();
                }
                else if(roma[i] == 'C') {
                    result += calc("XC");
                    s.pop();
                }
                else {
                    string temp;
                    temp += s.top();
                    result += calc(temp);
                    s.pop();
                    if(roma[i] == 'I' || roma[i] == 'X') {
                        s.push(roma[i]);
                    }
                    else {
                        temp = "";
                        temp += roma[i];
                        result += calc(temp);
                    }
                }
            }
        }
    }
    if(!s.empty()) {
        string temp;
        temp += s.top();
        result += calc(temp);
    }
    cout << result << endl;
}