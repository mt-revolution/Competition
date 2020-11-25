#include<bits/stdc++.h>

using namespace std;


int main() {
    int N,W;
    cin >> N >> W;

    vector<int> v(N+1), w(N+1);

    // ナップサック問題の容量W以内でk個までの価値の最大和dp[k][W]
    vector<vector<int> > dp(N+1, vector<int>(W+1, 0));

    for(int i = 0; i < N; i++) {
        cin >> v[i+1] >> w[i+1];
    }

    // 初期条件
    for(int j = 0; j <= W; j++) {
        dp[0][j] = 0;
    }

    // dp開始
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= W; j++) {
            if(j - w[i] >= 0) {
                dp[i][j] = max(dp[i-1][j - w[i]] + v[i], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[N][W] << endl;
	return 0;
}