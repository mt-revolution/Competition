#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,K;
    cin >> N >> K;

    vector<int> h(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }

    // 足場iに辿り着くまでに支払うコストの総和の最小値dp[i]
    vector<int> dp(N+1, 1500000000);

    // 初期条件
    dp[1] = 0;
    

    // dp開始
    for (int i = 2; i <= N; i++) {
        for (int k = 1; k <= K; k++) {
            if (i - k < 1) {
                break;
            }
            
            dp[i] = min(dp[i], dp[i-k] + abs(h[i-k] - h[i]));
        }
    }

    cout << dp[N] << endl;
	return 0;
}