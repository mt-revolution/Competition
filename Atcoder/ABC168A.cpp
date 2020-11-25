#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
    cin >> N;

    int digit_one = N % 10;
    
    if (digit_one == 2 || digit_one == 4 || digit_one == 5 || digit_one == 7 || digit_one == 9) {
        cout << "hon" << endl;
    } else if (digit_one == 0 || digit_one == 1 || digit_one == 6 || digit_one == 8) {
        cout << "pon" << endl;
    } else {
        cout << "bon" << endl;
    }
	return 0;
}