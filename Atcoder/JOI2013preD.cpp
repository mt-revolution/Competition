#include<bits/stdc++.h>

using namespace std;

int main() {
	int D, N;
    cin >> D >> N;

    vector<int> T(D+1);
    vector<int> A(N+1), B(N+1), C(N+1);

    // i日目に服jを選んだときのi日目までの服の派手さの差の絶対値の合計の最大値dp[i][j]
    vector<vector<int>> dp(D+1, vector<int>(N+1, 0));
    
    int answer = 0;

    for(int i = 1; i <= D; i++) {
        cin >> T[i];
    }

    for(int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    // 初期条件

    // for(int j = 1; j <= N; j++) {
    //     if(T[1] >= A[j] && T[1] <= B[j]) {
    //         dp[1][j] = max(dp[1][j], C[j]);
    //     }
    // }

    // for(int j = 1; j <= N; j++) {
    //     if(T[2] >= A[j] && T[2] <= B[j]) {
    //         for(int k = 1; k <= N; k++) {
    //             if(T[1] >= A[k] && T[1] <= B[k]) {
    //                 dp[2][j] = max(dp[2][j], abs(C[k] - C[j]));
    //             }
    //         }
    //     }
    // }

    // dp開始
    for(int i = 2; i <= D; i++) {
        for(int j = 1; j <= N; j++) {
            if(T[i] >= A[j] && T[i] <= B[j]) {
                for(int k = 1; k <= N; k++) {
                    if(T[i-1] >= A[k] && T[i-1] <= B[k]) {
                        dp[i][j] = max(dp[i][j], dp[i-1][k] + abs(C[k] - C[j]));
                    }
                }
            }
        }
    }
    
    // 答えはdp[D][j]の最大値
    for(int j = 1; j <= N; j++) {
        answer = max(answer, dp[D][j]);
    }

    cout << answer << endl;
	return 0;
}