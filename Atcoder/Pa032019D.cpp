#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    

    // 0=R, 1=B, 2=W, 3=#
    vector<vector<int>> color(5, vector<int>(N, 1000000000));
    
    char c;
    vector<int> count(3, 0);
    int answer = 1000000000;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < N; j++) {
            cin >> c;
            if(c == 'R') {
                color[i][j] = 0;
            } else if(c == 'B') {
                color[i][j] = 1;
            } else if(c == 'W') {
                color[i][j] = 2;
            } else if(c == '#') {
                color[i][j] = 3;
            }
        }
    }
    
    // j列目を色k(0=R, 1=B, 2=W)で塗り替えるときにi列目までで塗り替えるマス目の合計の最小値dp[j][k]
    vector<vector<int>> dp(N+1, vector<int>(3, 1000000000));

    // 初期条件
    for(int k = 0; k < 3; k++) {
        count[k] = 0;
        for(int i = 0; i < 5; i++) {
            if(color[i][0] != k) {
                count[k] += 1;
            }
        }
        dp[1][k] = min(dp[1][k], count[k]);
    }

    // DP開始
    for(int j = 2; j <= N; j++) {
        for(int k = 0; k < 3; k++) {
            count[k] = 0;
            
            for(int i = 0; i < 5; i++) {                
                if(color[i][j-1] != k) {
                    count[k] += 1;
                }
            }
        }

        dp[j][0] = min({dp[j][0], dp[j-1][1] + count[0], dp[j-1][2] + count[0]});
        dp[j][1] = min({dp[j][1], dp[j-1][0] + count[1], dp[j-1][2] + count[1]});
        dp[j][2] = min({dp[j][2], dp[j-1][0] + count[2], dp[j-1][1] + count[2]});
    }

    // 答えはdp[N][k]の最小値
    for(int k = 0; k < 3; k++) {
        answer = min(answer, dp[N][k]);
    }

    cout << answer << endl;
	return 0;
}