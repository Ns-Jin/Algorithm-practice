#include <iostream>
#include <queue>

using namespace std;

class student {
    private:
        int candidate;
        int last_candidate; 
    public:
        student() {
            this->candidate = 0;
            this->last_candidate = 0;
        }
        int get_candidate() {
            return this->candidate;
        }
        int get_last_candidate() {
            return this->last_candidate;
        }
        student& operator++(int i);
};

student& student::operator++(int i) {
    this->candidate++;
    this->last_candidate = i;
}

int main() {
    
    int n,k;

    cin >> n;
    cin >> k;
    student
    for(int i=0;i<k;i++) {
        int can;
        cin >> can;

    }
}