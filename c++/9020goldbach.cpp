#include<iostream>

using namespace std;

int main() {
    int prime_nums[10001];
    int len_prime_nums = 0;
    for(int i=2;i<10001;i++) {
        bool is_prime = true;
        for(int j=2;j<i;j++) {
            if(i%j == 0) {
                is_prime = false;
                break;
            }
        }
        if(is_prime) {
            prime_nums[len_prime_nums] = i;
            len_prime_nums++;
        }
    }
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n;
        cin >> n;
        int result_num;
        int find_index;
        for(int j=0;j<len_prime_nums-1;j++) {
            if(prime_nums[j] >= n/2) {
                find_index = j;
                break;
            }
        }
        for(int l=0;l<len_prime_nums-1-find_index;l++) {
            bool find_prime_pa = false;
            for(int j=find_index;j>=0;j--) {
                bool find_prime = false;
                int find_num = n - prime_nums[find_index];
                for(int k=find_index;k>=0;k--) {
                    if(prime_nums[k] == find_num) {
                        find_prime = true;
                        break;
                    }
                    else if(prime_nums[k] < find_num) {
                        break;
                    }
                }
                if(find_prime) {
                    find_prime_pa = true;
                    result_num = prime_nums[find_index];
                    break;
                }
            }
            if(find_prime_pa) {
                break;
            }
        }
        
        cout << n - result_num << " " << result_num << endl;
    }
}