#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;


int main() {
    int S;
    cin >> S;

    // 総和がiであるような数列の個数をMODで割ったあまりdp[i]
    vector<long long> dp(2001, 0);

    // 初期条件
    dp[0] = 1, dp[1] = 0, dp[2] = 0;

    for (int i = 3; i <= S; i++) {
        for (int j = 0; j <= i-3; j++) {
            dp[i] = (dp[i] + dp[j]) % MOD;
        }
    }

    cout << dp[S] << endl;
    return 0;
}