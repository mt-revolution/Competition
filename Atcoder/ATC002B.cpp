#include<bits/stdc++.h>

using namespace std;

int64_t mod(int64_t N, int64_t M, int64_t P) {
    if(P == 0) {
        return 1;
    } else if(P % 2 == 0) {
        int64_t tmp = mod(N, M, P/2);
        return (tmp * tmp) % M;
    } else {
        return (mod(N, M, P-1) * N) % M;
    }
}

int main() {
    int64_t N, M, P;
    cin >> N >> M >> P;

    cout << mod(N, M, P) << endl;

	return 0;
}