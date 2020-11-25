#include<bits/stdc++.h>

using namespace std;

int main() {
	int N, M;
    cin >> N >> M;

    vector<int> D(N+1), C(M+1);

    int answer = 2000000000;

    // 都市0からiまでちょうどj日で移動するときの疲労度の合計の最小値dp[i][j]
    vector<vector<int>> dp(N+1, vector<int>(M+1, 2000000000));


    for(int i = 1; i <= N; i++) {
        cin >> D[i];
    }

    for(int i = 1; i <= M; i++) {
        cin >> C[i];
    }

    // 初期条件
    for(int j = 0; j <= M; j++) {
        dp[0][j] = 0;
    }
    

    // dp開始
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {            
            dp[i][j] = min(dp[i][j-1], dp[i-1][j-1] + D[i] * C[j]);            
        }
    }
    
    // 答えはdp[N][j]の最小値
    for(int j = 1; j <= M; j++) {
        answer = min(answer, dp[N][j]);
    }

    cout << answer << endl;
	return 0;
}