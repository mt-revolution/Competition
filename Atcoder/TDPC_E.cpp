#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) {
        res += m;
    }
    
    return res;
}

int main() {
	int D;
    string N;
	cin >> D >> N;

	int len = N.size();

    // 次の遷移への判定フラグがk(1:次にどの数字にも行ける、0:一定の数字以下にしか行けない)である場合のi桁目までの各桁の和 mod Dがjである数の個数dp[i][j][k]
    vector<vector<vector<long long>>> dp(len+1, vector<vector<long long>>(D, vector<long long>(2, 0)));

    // 初期条件
    dp[0][0][0] = 1;
    int lim;

    // dp開始
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < D; j++) {
            for (int k = 0; k < 2; k++) {
                // どの数字にも行けるとき
                if (k == 1) {
                    for (int d = 0; d <= 9; d++) {
                        dp[i+1][(j + d) % D][1] = (dp[i+1][(j + d) % D][1] + dp[i][j][1]) % MOD;
                    }
                // 一定の数字以下にしか行けないとき
                } else {
                    // その桁の数字未満の数字しかいけない
                    lim = N[i] - '0';

                    for (int d = 0; d < lim; d++) {
                        dp[i+1][(j + d) % D][1] = (dp[i+1][(j + d) % D][1] + dp[i][j][0]) % MOD;
                    }

                    dp[i+1][(j + lim) % D][0] = (dp[i+1][(j + lim) % D][0] + dp[i][j][0]) % MOD;
                }
            }
        }
    }

    long long answer = mod(dp[len][0][0] + dp[len][0][1] - 1, MOD);

    cout << answer << endl;
	return 0;
}