#include<iostream>
#include <string>

using namespace std;

int main(){

    int n = 0;
    cin >> n;

    int deque[n];
    int start_idx = 0;
    int end_idx = -1;
    bool isEmpty = true;

    for(int i=0;i<n;i++) {
        int elemnet;
        string command;
        cin >> command;

        if (start_idx > end_idx) {
            isEmpty = true;
        }
        else {
            isEmpty = false;
        }

        if(command == "push_back") {
            cin >> elemnet;
            deque[end_idx + 1] = elemnet;
            end_idx++;
        }

        else if(command == "push_front") {
            cin >> elemnet;
            for(int j=end_idx;j>=start_idx;j--) {
                deque[j+1] = deque[j];
            }
            deque[start_idx] = elemnet;
            end_idx++;
        }

        else if(command == "pop_front") {
            if (isEmpty) {
                cout << -1 << endl;
            }
            else {
                cout << deque[start_idx] << endl;
                start_idx++;
            }
        }

        else if(command == "pop_back") {
            if (isEmpty) {
                cout << -1 << endl;
            }
            else {
                cout << deque[end_idx] << endl;
                end_idx--;
            }
        }

        else if(command == "size") {
            cout << end_idx - start_idx + 1 << endl;
        }

        else if(command == "empty") {
            if (isEmpty) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }

        else if(command == "front") {
            if (isEmpty) {
                cout << -1 << endl;
            }
            else {
                cout << deque[start_idx] << endl;
            }
        }
        
        else if(command == "back") {
            if (isEmpty) {
                cout << -1 << endl;
            }
            else {
                cout << deque[end_idx] << endl;
            }
        }

    }

    return 0;
}
