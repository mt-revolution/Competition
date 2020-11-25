#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,K;
    cin >> N >> K;

    vector<int> num(N-1);

    // 
    vector<vector<vector<long long>>> dp(N+1, vector<vector<long long>>(3, vector<long long>(2, 0)));

    int p, q;
    int answer = 0;

    vector<int> A(N+1, 0);

    for(int i = 0; i < K; i++) {
        cin >> p >> q;
        A[p] = q;
    }

    // 初期条件
    if(A[1] == 0) {
        dp[1][0][0] = 1;
        dp[1][1][0] = 1;
        dp[1][2][0] = 1;
    } else {
        dp[1][A[1]-1][0] = 1;
    }

    // DP開始
    for(int i = 2; i <= N; i++) {
        if(A[i] == 0 || A[i] == 1) {
            dp[i][0][0] = (dp[i][0][0] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][2][0] + dp[i - 1][2][1]) % 10000; 
            dp[i][0][1] = (dp[i][0][1] + dp[i - 1][0][0]) % 10000; 
        }
        if(A[i] == 0 || A[i] == 2) {
            dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][2][0] + dp[i - 1][2][1]) % 10000; 
            dp[i][1][1] = (dp[i][1][1] + dp[i - 1][1][0]) % 10000; 
        }
        if(A[i] == 0 || A[i] == 3) {
            dp[i][2][0] = (dp[i][2][0] + dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][1][0] + dp[i - 1][1][1]) % 10000; 
            dp[i][2][1] = (dp[i][2][1] + dp[i - 1][2][0]) % 10000;
        }       
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            answer += dp[N][i][j];
        }        
    }

    cout << answer % 10000 << endl;
	return 0;
}