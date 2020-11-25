#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;


int main() {
    long long A,B,C,D;
    cin >> A >> B >> C >> D;

    if (B<C || D<A) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}