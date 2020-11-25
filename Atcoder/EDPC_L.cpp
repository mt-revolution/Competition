#include<bits/stdc++.h>

using namespace std;


int main() {
	int N;
    cin >> N;

    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // 区間[a_l, a_r)が残っている場合での最適な行動をとった場合のX-Yの最大値dp[l][r]
    vector<vector<long long>> dp(N+1, vector<long long>(N+1, 0));

    // 初期条件
    for (int l = 0; l < N; l++) {
        dp[l][l] = 0;
    }

    // dp開始
    for (int len = 1; len <= N; len++) {
        for (int l = 0; l + len <= N; l++) {
            int r = l + len;

            // 先手
            if ((N-len) % 2 == 0) {
                dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r-1]);
            } else { //後手
                dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r-1]);
            }
        }
    }

    cout << dp[0][N] << endl;
	return 0;
}