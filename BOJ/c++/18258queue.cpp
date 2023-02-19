#include<iostream>
#include<string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int queue[n] = {0,};
    int queue_back_index = -1;
    int queue_front_index = 0;

    for(int i=0;i<n;i++) {
        string command;
        cin >> command;

        if(command == "push") {
            int push_int;
            cin >> push_int;
            queue[queue_back_index + 1] = push_int;
            queue_back_index++;
        }
        else if(command == "pop") {
            if(queue_back_index - queue_front_index == -1) {
                cout << -1 << '\n';
            }
            else {
                cout << queue[queue_front_index] << '\n';
                queue_front_index++;
            }
        }
        else if(command == "size") {
            cout << queue_back_index - queue_front_index + 1<< '\n';
        }
        else if(command == "empty") {
            if(queue_back_index - queue_front_index == -1) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if(command == "front") {
            if(queue_back_index - queue_front_index == -1) {
                cout << -1 << '\n';
            }
            else {
                cout << queue[queue_front_index] << '\n';
            }
        }
        else if(command == "back") {
            if(queue_back_index - queue_front_index == -1) {
                cout << -1 << '\n';
            }
            else {
                cout << queue[queue_back_index] << '\n';
            }
        }
    }
}