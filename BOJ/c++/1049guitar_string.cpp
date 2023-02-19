#include <iostream>

using namespace std;

int main() {
    int n, m;
    int min_result = 1001;

    cin >> n >> m;

    int min_package = 1001;
    int min_piece = 1001;
    for(int i=0;i<m;i++) {
        int package, piece;
        cin >> package >> piece;

        if(package < min_package) {
            min_package = package;
        }
        if(piece < min_piece) {
            min_piece = piece;
        }
    }

    bool package_is_cheap;
    if(min_package < min_piece*6) {
        package_is_cheap = true;
    }

    if(package_is_cheap) {
        min_result = min_package*(n/6) + min_piece*(n%6);
        if(min_result > min_piece*n) {
            min_result = min_piece*n;
        }
        if(min_result > min_package*(n/6+1)) {
            min_result = min_package*(n/6+1);
        }
    }
    else {
        min_result = min_piece*n;
    }

    cout << min_result << endl;

}