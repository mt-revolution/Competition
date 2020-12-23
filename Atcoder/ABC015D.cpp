#include<bits/stdc++.h>

using namespace std;


int main() {
	int W;
    int N,K;
    cin >> W >> N >> K;
    
    vector<int> A(N), B(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    // スクリーンショットiまでみたときの幅j以内、枚数k以内の重要度の合計の最大値dp[i][j][k]
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(W+1, vector<int>(K+1, 0)));

    // dp開始
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            for (int k = 0; k <= K; k++) {
                // まだスクリーンショットの幅と枚数に余裕があるとき
                if (j - A[i-1] >= 0 && k - 1 >= 0) {
                    dp[i][j][k] = max({dp[i][j][k], dp[i-1][j][k], dp[i-1][j - A[i-1]][k-1] + B[i-1]});  
                // 余裕がないとき
                } else {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                }
            }
        }
    }

    cout << dp[N][W][K] << endl;
	return 0;
}