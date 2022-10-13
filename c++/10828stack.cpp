#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int stack[n] = {0,};
    int stack_size = 0;

    for(int i=0;i<n;i++) {
        string command;
        cin >> command;

        if(command == "push") {
            int push_int;
            cin >> push_int;
            stack[stack_size] = push_int;
            stack_size++;
        }
        else if(command == "pop") {
            if(stack_size == 0) {
                cout << -1 << endl;
            }
            else {
                cout << stack[stack_size-1] << endl;
                stack[stack_size-1] = 0;
                stack_size--;
            }
        }
        else if(command == "size") {
            cout << stack_size << endl;
        }
        else if(command == "empty") {
            if(stack_size == 0) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        else if(command == "top") {
            if(stack_size == 0) {
                cout << -1 << endl;
            }
            else {
                cout << stack[stack_size-1] << endl;
            }
        }
        
    }
}