#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    // フィボナッチ数列の第n項の値dp[n]
    vector<int> dp(n+1, 0);

    // 初期条件
    dp[0] = 1, dp[1] = 1;

    // dp開始
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n] << endl;
	return 0;
}