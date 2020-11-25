#include<bits/stdc++.h>
 
using namespace std;

const long long MOD = 1000000007;

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) {
        res += m;
    }
    
    return res;
}
 
int main() {
	int N;
    cin >> N;

    vector<long long> A(N+1);
    vector<long long> A_sum(N+1);

    A_sum[0] = 0;
    long long answer = 0;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A_sum[i] = (A_sum[i-1] + A[i]) % MOD;
    }

    for (int i = 1; i <= N-1; i++) {
        answer += mod(A[i] * (A_sum[N] - A_sum[i]), MOD);
        answer %= MOD;
    }

    cout << answer << endl;
	return 0;
}