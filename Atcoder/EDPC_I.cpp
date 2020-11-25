#include<bits/stdc++.h>

using namespace std;


int main() {
	int N;
    cin >> N;

    vector<double> p(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }

    // 最初のi枚投げたときに表がj枚出る確率
    vector<vector<double>> dp(N+1, vector<double>(N+1, 0.0));

    // 初期条件
    dp[1][1] = p[1], dp[1][0] = 1-p[1];

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][j] * (1-p[i]);
                continue;
            }
            
            dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1-p[i]);
        }
    }

    double answer = 0.0;

    for (int j = N/2 + 1; j <= N; j++) {
        answer += dp[N][j];
    }
    
    cout << fixed << setprecision(10) << answer << endl;
	return 0;
}