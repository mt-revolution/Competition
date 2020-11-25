#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,W;
    cin >> N >> W;

    vector<long long> w(N+1), v(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    // 1からiまでの品物の中で重さの和がj以下の品物の価値の総和の最大値dp[i][j]
    vector<vector<long long>> dp(N+1, vector<long long>(W+1, 0));

    // dp開始
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            // 品物が入る場合、入れる場合と入れない場合を比べて価値が大きい方を取る
            if (j - w[i] >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + v[i]);
            // 品物が入らない場合
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[N][W] << endl;
	return 0;
}