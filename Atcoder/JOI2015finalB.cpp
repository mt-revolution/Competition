#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
    cin >> N;

    vector<long long> A(2*N+1);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = N+1; i <= 2*N; i++) {
        A[i] = A[i-N];
    }

    // A[0] = A[N], A[N+1] = A[1];

    // i番目からj番目までの残りのケーキの中で自分が選ぶケーキの大きさの合計の最大値dp[i][j]
    vector<vector<long long>> dp(2*N+1, vector<long long>(2*N+1, 0));

    // 初期条件
    for (int i = 1; i <= 2*N; i++) {
        dp[i][i] = A[i];
    }

    // dp開始
    // for (int i = 1; i <= N-1; i++) {
    //     for (int j = i+1; j <= N; j++) {
    //         // JOIのターン
    //         if (N - (j-i+1) % 2 == 1) {
    //             dp[i][j] = max(dp[i+1][j] + A[i], dp[i][j-1] + A[j]);
    //         } else { // IOIのターン
    //             if (A[i] > A[j]) {
    //                 dp[i][j] = dp[i+1][j];
    //             } else {
    //                 dp[i][j] = dp[i][j-1];
    //             }
    //         }
    //     }
    // }
    
    // for (int i = 1; i <= N-1; i++) {
    //     for (int j = N; j >= i+1; j--) {
    //         // JOIのターン
    //         if (N - (j-i+1) % 2 == 1) {
    //             dp[i][j] = max(dp[i+1][j] + A[i], dp[i][j-1] + A[j]);
    //         } else { // IOIのターン
    //             if (A[i] > A[j]) {
    //                 dp[i][j] = dp[i+1][j];
    //             } else {
    //                 dp[i][j] = dp[i][j-1];
    //             }
    //         }
    //     }
    // }

    for(int w = 1; w <= N; w++) {
        for(int i = N; i >= 1; i--) {
            int j = i + w;
            
            // JOIのターン
            if (N - (j-i+1) % 2 == 1) {
                dp[i][j] = max(dp[i+1][j] + A[i], dp[i][j-1] + A[j]);
            } else { // IOIのターン
                if (A[i] > A[j]) {
                    dp[i][j] = dp[i+1][j];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
    

    cout << dp[1][N] << endl;
	return 0;
}