#include<bits/stdc++.h>

using namespace std;


int main() {
    int H,N;
    cin >> H >> N;
    
    vector<int> A(N), B(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    // 残りの体力がiになるまでに消耗する魔力の合計の最小値
    vector<int> dp(H+1, 1000000000);

    // 初期条件
    dp[H] = 0;

    // dp開始
    for (int i = H; i > 0; i--) {
        // それぞれの魔法について魔力の合計を求めて最小ならば置き換える
        for (int j = 0; j < N; j++) {
            // 体力が0以下になるとき
            if (i - A[j] <= 0) {
                dp[0] = min(dp[0], dp[i] + B[j]);
            } else {
                dp[i - A[j]] = min(dp[i - A[j]], dp[i] + B[j]);
            }
        }
    }

    cout << dp[0] << endl;
	return 0;
}