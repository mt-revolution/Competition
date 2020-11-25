#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;


int main() {
	int H,W;
    cin >> H >> W;

    vector<vector<char>> board(H+2, vector<char>(W+2, '#'));
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> board[i][j];
        }
    }

    // (1,1)から(i,j)までの経路の数dp[i][j]
    vector<vector<long long>> dp(H+2, vector<long long>(W+2, 0));

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            // 初期条件
            if (i == 1 && j == 1) {
                dp[i][j] = 1;
                continue;
            }

            if (board[i][j] == '#') {
                dp[i][j] = 0;
            } else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }

    cout << dp[H][W] << endl;
	return 0;
}