#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
    cin >> N;

    vector<int> a(N+1), b(N+1), c(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    // i日目に活動j(0:A,1:B,2:C)をしたときのi日目までの幸福度の総和の最大値dp[i][j]
    vector<vector<int>> dp(N+1, vector<int>(3, 0));

    // 初期条件
    dp[1][0] = a[1], dp[1][1] = b[1], dp[1][2] = c[1];
    
    // dp開始
    for (int i = 2; i <= N; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];
    }

    int answer = max({dp[N][0], dp[N][1], dp[N][2]});

    cout << answer << endl;
	return 0;
}