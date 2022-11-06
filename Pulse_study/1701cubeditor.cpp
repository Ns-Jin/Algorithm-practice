#include <iostream>
#include<string>

using namespace std;

int main() {
    string n;
    cin >> n;
    int len_n = n.length();
    string piece_string;
    int max_count = 1;
    for(int i=0;i<len_n;i++) {
        for(int j=len_n-1;j>=0;j--) {
            piece_string = n.substr(i, j-i);
            int count = 1;
            int len_p_str = j-i;
            for(int k=0;k<len_n-len_p_str;k++) {
                if(piece_string == n.substr(k, len_p_str)) {
                    count++;
                }
            }
            if(max_count < count) {
                max_count = count;
            }
        }
    }
    cout << max_count << endl;
}