#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> r(n), c(n);
    for(int i = 0; i < n; i++) {
        cin >> r[i] >> c[i];
    }

    // 行列M_iからM_jまでの積の計算回数の最小値dp[i][j]
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    // 初期条件
    for(int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }


    // dp開始
    int j;

    for(int l = 2; l <= n; l++) {
        for(int i = 1; i <= n-l+1; i++) {
            j = i + l - 1;
            for(int k = i; k < j; k++) {
                if(k == i) {
                    dp[i][j] = dp[i][k] + dp[k+1][j] + r[i-1] * r[k] * c[j-1];
                } else {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + r[i-1] * r[k] * c[j-1]);
                }
            }
        }
    }

    cout << dp[1][n] << endl;
	return 0;
}