#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int prime_nums[2000];
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
        int result = 0;
        
        if(n>5000) {
            for(int j=len_prime_nums-1;j>0;j--) {
                if(find(prime_nums,prime_nums+len_prime_nums,n-prime_nums[j]) != prime_nums + len_prime_nums) {
                    if(n%prime_nums[j] == 0 || n - result == prime_nums[j]) {
                        result = prime_nums[j];
                        break;
                    }
                    else {
                        result = prime_nums[j];
                    }
                }
            } 
        }
        else {
            for(int j=0;j<len_prime_nums;j++) {
                if(find(prime_nums,prime_nums+len_prime_nums,n-prime_nums[j]) != prime_nums + len_prime_nums) {
                    if(n%prime_nums[j] == 0 || n - result == prime_nums[j]) {
                        result = prime_nums[j];
                        break;
                    }
                    else {
                        result = prime_nums[j];
                    }
                }
            }
        }
        if(result < n-result) {
            cout << result << " " << n-result << endl;
        }
        else {
            cout << n-result << " " << result << endl; 
        }
    }
}