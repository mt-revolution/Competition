#include<bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) {
        res += m;
    }
    
    return res;
}


int main() {
    int N,K;
    cin >> N >> K;

    vector<int> L(K), R(K);

    for (int i = 0; i < K; i++) {
        cin >> L[i] >> R[i];
    }

    // マスiに行く方法の数をMODで割ったあまりdp[i]
    vector<long long> dp(N+1, 0);

    // 累積和
    vector<long long> dp_sum(N+1, 0);

    // 初期条件
    dp[1] = 1;
    dp_sum[0] = 0, dp_sum[1] = 1;

    for (int i = 2; i <= N; i++) {
        // それぞれの区間について
        for (int k = 0; k < K; k++) {
            // 移動が出来る場合
            if (i - L[k] >= 1) {
                // 最大の幅まで移動できる場合
                if (i - R[k] >= 1) {
                    dp[i] = mod(dp[i] + dp_sum[i-L[k]] - dp_sum[i-R[k]-1], MOD);
                // それ以外
                } else {
                    dp[i] = mod(dp[i] + dp_sum[i-L[k]] - dp_sum[0], MOD);
                }
            }            
        }

        // 累積和を更新
        dp_sum[i] = (dp_sum[i-1] + dp[i]) % MOD;
    }

    cout << dp[N] << endl;
    return 0;
}