#include<bits/stdc++.h>

using namespace std;


int main() {
    int n,m;
    cin >> n >> m;
    
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }

    // i円を払うときのコインの最小の枚数
    vector<int> dp(n+1, 1000000000);

    dp[0] = 0;

    // dp開始
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (i - c[j] >= 0) {
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }

    cout << dp[n] << endl;
	return 0;
}