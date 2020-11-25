#include<bits/stdc++.h>

using namespace std;

int main() {
	int R,C,K;
    cin >> R >> C >> K;

    int r,c;
    long long v;

    vector<vector<long long>> goods(R+2, vector<long long>(C+2, 0));

    for (int i = 0; i < K; i++) {
        cin >> r >> c >> v;
        goods[r][c] = v;
    }

    // (i,j)にいるときに同じ行でk個拾った状況でのアイテムの価値の合計の最大値
    vector<vector<vector<long long>>> dp(R+2, vector<vector<long long>>(C+2, vector<long long>(4, 0)));

    // dp開始
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            dp[i][j][0] = max({dp[i][j-1][0], dp[i-1][j][0], dp[i-1][j][1], dp[i-1][j][2], dp[i-1][j][3]});

            // アイテムがあるとき
            if (goods[i][j] != 0) {
                dp[i][j][1] = max({dp[i][j-1][0] + goods[i][j], dp[i][j-1][1], dp[i-1][j][0] + goods[i][j], dp[i-1][j][1] + goods[i][j], dp[i-1][j][2] + goods[i][j], dp[i-1][j][3] + goods[i][j]});
                dp[i][j][2] = max({dp[i][j-1][1] + goods[i][j], dp[i][j-1][2]});
                dp[i][j][3] = max({dp[i][j-1][2] + goods[i][j], dp[i][j-1][3]});
            // アイテムがないとき
            } else {
                dp[i][j][1] = dp[i][j-1][1];
                dp[i][j][2] = dp[i][j-1][2];
                dp[i][j][3] = dp[i][j-1][3];
            }
        }
    }

    long long answer = max({dp[R][C][0], dp[R][C][1], dp[R][C][2], dp[R][C][3]});

    cout << answer << endl;
	return 0;
}