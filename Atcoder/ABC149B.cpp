#include<bits/stdc++.h>

using namespace std;

int main() {
    long long A,B,K;
    cin >> A >> B >> K;

    if (K <= A) {
        A -= K;
    } else if (K > A && K <= A+B) {
        B -= K-A;
        A = 0;
    } else {
        A = 0;
        B = 0;
    }

    cout << A << " " << B << endl;
    return 0;
}