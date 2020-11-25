#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,W;
    cin >> N >> W;

    vector<long long> w(N+1), v(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    // 1からiまでの品物の中で価値の和がj以上の品物の重さの総和の最小値dp[i][j]
    vector<vector<long long>> dp(N+1, vector<long long>(100001, 2000000000));

    // 初期条件
    dp[0][0] = 0;

    // dp開始
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 100001; j++) {
            // 品物が入る場合、入れる場合と入れない場合を比べて重さが小さい方を取る
            if (j - v[i] >= 0) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j - v[i]] + w[i]);
            // 品物が入らない場合
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    long long answer = 0;

    for (int j = 100000; j >= 1; j--) {
        if (dp[N][j] <= W) {
            answer = j;
            break;
        }
    }

    cout << answer << endl;
	return 0;
}