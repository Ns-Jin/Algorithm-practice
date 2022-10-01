#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
    string begin_string;
    cin >> begin_string;
    stack<char> front;
    stack<char> back;
    for(int i=0;i<begin_string.length();i++) {
        front.push(begin_string[i]);
    }

    int m;
    cin >> m;
    for(int i=0;i<m;i++) {
        char command;
        cin >> command;
        
        switch (command) {
            case 'L':
                if(!front.empty()) {
                    char temp = front.top();
                    front.pop();
                    back.push(temp);
                }        
                break;

            case 'D':
                if(!back.empty()) {
                    char temp = back.top();
                    back.pop();
                    front.push(temp);
                }
                break;
            
            case 'B':
                if(!front.empty()) {
                    front.pop();
                }
                break;
            
            case 'P':
                char add_char;
                cin >> add_char;
                front.push(add_char);
                break;
        }
    }
    while(!front.empty()) {
        char temp = front.top();
        front.pop();
        back.push(temp);
    }
    while(!back.empty()) {
        cout << back.top();
        back.pop();
    }
    cout << endl;
}